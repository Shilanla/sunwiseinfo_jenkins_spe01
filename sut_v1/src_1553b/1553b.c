#include "sys.h"
#include "io.h"
#include "1553b_private.h"

/* BC内存区配置 */
S1553BBCMemConf s1553BbcMemConf;

/* BC端消息块地址映射表 */
unsigned int s1553BbcMsgBlkAddr[BC_MEM_MSGBLK_NUM] =
{
	/* 步长38个双字节字 */

	0x0108, /* 消息块0  */
	0x012E, /* 消息块1  */
	0x0154, /* 消息块2  */
	0x017A, /* 消息块3  */
	0x01A0, /* 消息块4  */
	0x01C6, /* 消息块5  */
	0x01EC, /* 消息块6  */
	0x0212, /* 消息块7  */
	0x0238, /* 消息块8  */
	0x025E, /* 消息块9  */
	0x0284, /* 消息块10 */
	0x02AA, /* 消息块11 */
	0x02D0, /* 消息块12 */
	0x02F6, /* 消息块13 */
	0x031C, /* 消息块14 */
	0x0342, /* 消息块15 */
	0x0368, /* 消息块16 */
	0x038E, /* 消息块17 */
	0x03B4, /* 消息块18 */
	0x03DA, /* 消息块19 */
	0x0400, /* 消息块20 */
	0x0426, /* 消息块21 */
	0x044C, /* 消息块22 */
	0x0472, /* 消息块23 */
	0x0498, /* 消息块24 */
	0x04BE, /* 消息块25 */
	0x04E4, /* 消息块26 */
	0x050A, /* 消息块27 */
	0x0530, /* 消息块28 */
	0x0556, /* 消息块29 */
	0x057C, /* 消息块30 */
	0x05A2, /* 消息块31 */
	0x05C8, /* 消息块32 */
	0x05EE, /* 消息块33 */
	0x0614, /* 消息块34 */
	0x063A, /* 消息块35 */
	0x0660, /* 消息块36 */
	0x0686, /* 消息块37 */
	0x06AC, /* 消息块38 */
	0x06D2, /* 消息块39 */
	0x06F8, /* 消息块40 */
	0x071E, /* 消息块41 */
	0x0744, /* 消息块42 */
	0x076A, /* 消息块43 */
	0x0790, /* 消息块44 */
	0x07B6, /* 消息块45 */
	0x07DC, /* 消息块46 */
	0x0802, /* 消息块47 */
	0x0828, /* 消息块48 */
	0x084E, /* 消息块49 */
	0x0874, /* 消息块50 */
	0x089A, /* 消息块51 */
	0x08C0, /* 消息块52 */
	0x08E6, /* 消息块53 */
	0x090C, /* 消息块54 */
	0x0932, /* 消息块55 */
	0x0958, /* 消息块56 */
	0x097E, /* 消息块57 */
	0x09A4, /* 消息块58 */
	0x09CA, /* 消息块59 */
	0x09F0, /* 消息块60 */
	0x0A16, /* 消息块61 */
	0x0A3C, /* 消息块62 */
	0x0A62  /* 消息块63 */
};

/* 消息帧缓冲区 */
S1553BBCMsg sBusgMsg[BC_MEM_MSGBLK_NUM];

/* BC芯片空闲检测 */
unsigned int B1553BCIsIdle(unsigned int regBase)
{
	unsigned int conf1;
	unsigned int idle;

	/* 读取配置寄存器1的值 */
	conf1 = B1553_READ(B1553_REG_CONF1, regBase);

	if ((conf1 & REG_CFG1_D01_BC_FRAME_IN_PROG) == REG_CFG1_D01_BC_FRAME_IN_PROG)
	{
		idle = conf1;
	}
	else
	{
		/* 0空闲状态 */
		idle = 0;
	}

	return idle;
}

/* BC内存配置 */
unsigned int B1553BCMemConfig(unsigned int configID, unsigned int regBase)
{
	unsigned int valReg;

	/* 读取配置寄存器#1 */
	valReg = B1553_READ(B1553_REG_CONF1, regBase);

	if (configID == B1553_MEM_CONF_A)
	{
		/* 栈区A偏移地址 */
		s1553BbcMemConf.stkBase = BC_MEM_A_STK;

		/* 栈区A指针偏移地址 */
		s1553BbcMemConf.stkPtr = BC_MEM_A_STKPTR;

		/* 置栈区A */
		valReg = valReg & (~REG_CFG1_D13_BC_AREA_B_SELECT);
	}
	else
	{
		/* 栈区B偏移地址 */
		s1553BbcMemConf.stkBase = BC_MEM_B_STK;

		/* 栈区B指针偏移地址 */
		s1553BbcMemConf.stkPtr = BC_MEM_B_STKPTR;

		/* 置栈区B */
		valReg = valReg | REG_CFG1_D13_BC_AREA_B_SELECT;
	}

	/* 更新配置寄存器#1 */
	B1553_WRITE(B1553_REG_CONF1, valReg, regBase);

	/* 设置内存配置ID为A配置 */
	s1553BbcMemConf.confID = configID;

	return configID;
}

/* 读取1553B块消息数据 */
void B1553ReadBlock(volatile unsigned short *rdbuf16, unsigned int msgBlkAddr, unsigned int len16, unsigned int baseMem)
{
	unsigned int rd;
	volatile unsigned int *rdAddr32;

	rdAddr32 = ABSUI_TO_VADDR32(baseMem + (msgBlkAddr << 2u));

	for (rd=0; rd<len16; rd++)
	{
		rdbuf16[rd] = rdAddr32[rd] & 0xFFFF;
	}

	return;
}

/* 写入1553B块消息数据 */
void B1553WriteBlock(unsigned int msgBlkAddr, const unsigned short *wrbuf16, unsigned int len16, unsigned int baseMem)
{
	unsigned int wr;
	volatile unsigned int *wrAddr32;

	wrAddr32 = ABSUI_TO_VADDR32(baseMem + (msgBlkAddr << 2u));

	for (wr=0; wr<len16; wr++)
	{
		wrAddr32[wr] = wrbuf16[wr];
	}

	return;
}

/* GNC总线BC接口芯片初始化(JKR63825) */
void B1553InitBC(unsigned int memSize, unsigned int regBase, unsigned int memBase)
{
	unsigned int mem;
	unsigned int regVal;

	/* 1553B芯片复位 */
	regVal = REG_START_D00_RESET;
	BusgWriteReg(B1553_REG_START_RST, regVal, regBase);

	/* 1553B内存清零 */
	if (memSize == _16KB)
	{
		/* 初始化内存区 */
		for (mem=0; mem<memSize; mem++)
		{
			BusgWriteMem(mem, 0x00, memBase);
		}
	}
	else
	{
		/* 重要数据区初始化 */
		for (mem=0; mem<_1KB; mem++)
		{
			BusgWriteMem(mem, 0x0, memBase);
		}

		/* 堆栈区初始化 */
		/* */
	}

	/* 配置寄存器#3设置:0x8000(注意必需首先设置Conf.#3) */           /* ??? 配置寄存器取值重新梳理 */
	regVal = REG_CFG3_D15_ENHANCED_EN;
	BusgWriteReg(B1553_REG_CONF3, regVal, regBase);

	/* 配置寄存器#2设置: 256字边界禁止; tag为8us; 脉冲触发 */
	regVal = REG_CFG2_D10_256_DISBL |
		REG_CFG2_D08_TTAG_R1   |
		REG_CFG2_D07_TTAG_R0;

	BusgWriteReg(B1553_REG_CONF2, regVal, regBase);

	/* 配置寄存器#4设置:0x1000 */
	regVal = REG_CFG4_D12_BC_EXPD_CW_EN |
		REG_CFG4_D06_VALID_MSG_ERR |
		REG_CFG4_D05_VALID_BUSY_BIT;

	BusgWriteReg(B1553_REG_CONF4, regVal, regBase);

	/* 配置寄存器#5设置: 超时响应50.5us; */
	regVal = REG_CFG5_D11_EXPD_CROSS_EN | REG_CFG5_D10_RTIME_SELE1;
	BusgWriteReg(B1553_REG_CONF5, regVal, regBase);

	/* 配置寄存器#1设置: 消息间隔设置使能; A配置 */
	regVal = REG_CFG1_D05_BC_MSG_GAPTIMER;
	BusgWriteReg(B1553_REG_CONF1, regVal, regBase);

	/* 栈区A/B配置：默认为A配置 */
	B1553BCMemConfig(B1553_MEM_CONF_A, regBase);

	return;
}


/* 1553B总线BC端构建消息帧 */
void B1553MsgFrameBuild(unsigned int cntMsg, unsigned int baseMem)
{
	unsigned int im;           /* 消息描述块计数 */
	unsigned int msgAddr;      /* 消息的首地址 */
	unsigned int cntData;

	/* 为每个消息分配1553B内存 */
	for (im=0; im<cntMsg; im++)
	{
		/* 第im个消息的首地址 */
		msgAddr = s1553BbcMsgBlkAddr[im];

		/* 消息间隔时间,消息块描述符第3个字 */
		BusgWriteMem(BC_MEM_BLKDESC_GAPTIME(im), BC_MSG_GAPTIME, baseMem);

		/* 消息块指针,消息块描述符第4个字 */
		BusgWriteMem(BC_MEM_BLKDESC_BLKPTR(im), msgAddr, baseMem);

		/* 消息块控制字,消息块中第1个字 */
		BusgWriteMem(MSG_BLK_CTRLWD(msgAddr), sBusgMsg[im].ctrlwd, baseMem);

		/* 消息块命令字,消息块中第2个字, */
		BusgWriteMem(MSG_BLK_CMD(msgAddr), sBusgMsg[im].cmd, baseMem);

		/* BC->RT消息有数据传输 */
		if (B1553_CMDWORD_TRCV(sBusgMsg[im].cmd) == B1553_RT_RECV)
		{
			/* 获取数据字个数 */
			cntData = B1553_CMDWORD_CNTD(sBusgMsg[im].cmd);

			if (cntData == 0)
			{
				cntData = 32;
			}

			/* 消息块数据字,消息块中第3个字 */
			BusgWriteBlock(MSG_BLK_DATA_BC2RT(msgAddr), &sBusgMsg[im].data[0], cntData, baseMem);
		}
	}

	return;
}

/* 1553B总线BC端启动消息帧传输 */
void B1553MsgFrameStart(unsigned int cntMsg, unsigned int baseReg, unsigned int baseMem)
{
	unsigned int count;

	/* 设置堆栈指针 */
	BusgWriteMem(BC_MEMCONF_STKPTR(), BC_MEMCONF_STKBASE(), baseMem);

	/* 设置堆栈消息个数 */
	count = 0xFFFF - (cntMsg & 0xFFFF);
	BusgWriteMem(BC_MEMCONF_MSGCNT(), count, baseMem);

	/* 启动BC端消息传输 */
	BusgWriteReg(B1553_REG_START_RST, REG_START_D01_BC_START, baseReg);

	return;
}

/* 1553B总线BC端消息帧结束等待 */
unsigned int B1553MsgFrameWait(unsigned int frameEnd, unsigned int baseReg, unsigned int n1us)
{
	unsigned int cnt100us;   /* 要求延时几个100us */
	unsigned int cnt;

	cnt100us = n1us / 100 + 1;
	cnt = 0;

	do
	{
		/* 延时100us */
		SYS_Delay(100);

		/* BC芯片空闲检测 */
		if (frameEnd > 0)
		{
			frameEnd = B1553BCIsIdle(baseReg);
		}

		cnt++;
	} while ((cnt < cnt100us) && (frameEnd != 0x0));

	return frameEnd;
}

/* 生成1553B消息命令字 */
unsigned int B1553MsgCmdGen(unsigned int addr, unsigned int tr, unsigned int samc, unsigned int salen)
{
	unsigned int msgCmd;
	unsigned int cntd;

	msgCmd = 0x0000u;
	cntd = salen % 32u;

	B1553_CMDWORD_ADDR_SET(msgCmd, addr);
	B1553_CMDWORD_TRCV_SET(msgCmd, tr);
	B1553_CMDWORD_SAMC_SET(msgCmd, samc);
	B1553_CMDWORD_CNTD_SET(msgCmd, cntd);

	return msgCmd;
}

unsigned int B1553MsgRegister(unsigned int cntMsg, unsigned short ctrlwd, unsigned short cmd, unsigned short data[])
{
	unsigned int i;
	unsigned int cntData;

	if (cntMsg < BC_MEM_MSGBLK_NUM)
	{
		sBusgMsg[cntMsg].ctrlwd = ctrlwd;
		sBusgMsg[cntMsg].cmd = cmd;

		if (B1553_CMDWORD_TRCV(cmd) == B1553_RT_RECV)
		{
			cntData = B1553_CMDWORD_CNTD(cmd);

			if (cntData == 0)
			{
				cntData = 32;
			}

			/* 消息块数据字,消息块中第3个字 */
			for (i = 0; i < cntData; i++)
			{
				sBusgMsg[cntMsg].data[i] = data[i];
			}
		}

		return (cntMsg + 1);
	}
	else
	{
		return cntMsg;
	}
}

unsigned int Read1553Msg(unsigned short recvBuf[], unsigned int msgIdx)
{
	unsigned int msgAddr;
	unsigned int msgCmd;
	unsigned int msgLen;

	/* 获取消息块地址(消息描述块第4个字) */
	msgAddr = BusgReadMem(BC_MEM_BLKDESC_BLKPTR(msgIdx), BUSG_MEM_BASE);
	
	/* 获取消息命令字 */
	msgCmd = BusgReadMem(MSG_BLK_CMD(msgAddr), BUSG_MEM_BASE);

	/* 获取消息中数据字长度 */
	msgLen = B1553_CMDWORD_CNTD(msgCmd);
	if (msgLen == 0)
	{
		msgLen = 32u;
	}

	BusgReadBlock(recvBuf, MSG_BLK_DATA_RT2BC(msgAddr), msgLen, BUSG_MEM_BASE);

	return msgCmd;
}
