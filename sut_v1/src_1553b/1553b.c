#include "sys.h"
#include "io.h"
#include "1553b_private.h"

/* BC�ڴ������� */
S1553BBCMemConf s1553BbcMemConf;

/* BC����Ϣ���ַӳ��� */
unsigned int s1553BbcMsgBlkAddr[BC_MEM_MSGBLK_NUM] =
{
	/* ����38��˫�ֽ��� */

	0x0108, /* ��Ϣ��0  */
	0x012E, /* ��Ϣ��1  */
	0x0154, /* ��Ϣ��2  */
	0x017A, /* ��Ϣ��3  */
	0x01A0, /* ��Ϣ��4  */
	0x01C6, /* ��Ϣ��5  */
	0x01EC, /* ��Ϣ��6  */
	0x0212, /* ��Ϣ��7  */
	0x0238, /* ��Ϣ��8  */
	0x025E, /* ��Ϣ��9  */
	0x0284, /* ��Ϣ��10 */
	0x02AA, /* ��Ϣ��11 */
	0x02D0, /* ��Ϣ��12 */
	0x02F6, /* ��Ϣ��13 */
	0x031C, /* ��Ϣ��14 */
	0x0342, /* ��Ϣ��15 */
	0x0368, /* ��Ϣ��16 */
	0x038E, /* ��Ϣ��17 */
	0x03B4, /* ��Ϣ��18 */
	0x03DA, /* ��Ϣ��19 */
	0x0400, /* ��Ϣ��20 */
	0x0426, /* ��Ϣ��21 */
	0x044C, /* ��Ϣ��22 */
	0x0472, /* ��Ϣ��23 */
	0x0498, /* ��Ϣ��24 */
	0x04BE, /* ��Ϣ��25 */
	0x04E4, /* ��Ϣ��26 */
	0x050A, /* ��Ϣ��27 */
	0x0530, /* ��Ϣ��28 */
	0x0556, /* ��Ϣ��29 */
	0x057C, /* ��Ϣ��30 */
	0x05A2, /* ��Ϣ��31 */
	0x05C8, /* ��Ϣ��32 */
	0x05EE, /* ��Ϣ��33 */
	0x0614, /* ��Ϣ��34 */
	0x063A, /* ��Ϣ��35 */
	0x0660, /* ��Ϣ��36 */
	0x0686, /* ��Ϣ��37 */
	0x06AC, /* ��Ϣ��38 */
	0x06D2, /* ��Ϣ��39 */
	0x06F8, /* ��Ϣ��40 */
	0x071E, /* ��Ϣ��41 */
	0x0744, /* ��Ϣ��42 */
	0x076A, /* ��Ϣ��43 */
	0x0790, /* ��Ϣ��44 */
	0x07B6, /* ��Ϣ��45 */
	0x07DC, /* ��Ϣ��46 */
	0x0802, /* ��Ϣ��47 */
	0x0828, /* ��Ϣ��48 */
	0x084E, /* ��Ϣ��49 */
	0x0874, /* ��Ϣ��50 */
	0x089A, /* ��Ϣ��51 */
	0x08C0, /* ��Ϣ��52 */
	0x08E6, /* ��Ϣ��53 */
	0x090C, /* ��Ϣ��54 */
	0x0932, /* ��Ϣ��55 */
	0x0958, /* ��Ϣ��56 */
	0x097E, /* ��Ϣ��57 */
	0x09A4, /* ��Ϣ��58 */
	0x09CA, /* ��Ϣ��59 */
	0x09F0, /* ��Ϣ��60 */
	0x0A16, /* ��Ϣ��61 */
	0x0A3C, /* ��Ϣ��62 */
	0x0A62  /* ��Ϣ��63 */
};

/* ��Ϣ֡������ */
S1553BBCMsg sBusgMsg[BC_MEM_MSGBLK_NUM];

/* BCоƬ���м�� */
unsigned int B1553BCIsIdle(unsigned int regBase)
{
	unsigned int conf1;
	unsigned int idle;

	/* ��ȡ���üĴ���1��ֵ */
	conf1 = B1553_READ(B1553_REG_CONF1, regBase);

	if ((conf1 & REG_CFG1_D01_BC_FRAME_IN_PROG) == REG_CFG1_D01_BC_FRAME_IN_PROG)
	{
		idle = conf1;
	}
	else
	{
		/* 0����״̬ */
		idle = 0;
	}

	return idle;
}

/* BC�ڴ����� */
unsigned int B1553BCMemConfig(unsigned int configID, unsigned int regBase)
{
	unsigned int valReg;

	/* ��ȡ���üĴ���#1 */
	valReg = B1553_READ(B1553_REG_CONF1, regBase);

	if (configID == B1553_MEM_CONF_A)
	{
		/* ջ��Aƫ�Ƶ�ַ */
		s1553BbcMemConf.stkBase = BC_MEM_A_STK;

		/* ջ��Aָ��ƫ�Ƶ�ַ */
		s1553BbcMemConf.stkPtr = BC_MEM_A_STKPTR;

		/* ��ջ��A */
		valReg = valReg & (~REG_CFG1_D13_BC_AREA_B_SELECT);
	}
	else
	{
		/* ջ��Bƫ�Ƶ�ַ */
		s1553BbcMemConf.stkBase = BC_MEM_B_STK;

		/* ջ��Bָ��ƫ�Ƶ�ַ */
		s1553BbcMemConf.stkPtr = BC_MEM_B_STKPTR;

		/* ��ջ��B */
		valReg = valReg | REG_CFG1_D13_BC_AREA_B_SELECT;
	}

	/* �������üĴ���#1 */
	B1553_WRITE(B1553_REG_CONF1, valReg, regBase);

	/* �����ڴ�����IDΪA���� */
	s1553BbcMemConf.confID = configID;

	return configID;
}

/* ��ȡ1553B����Ϣ���� */
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

/* д��1553B����Ϣ���� */
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

/* GNC����BC�ӿ�оƬ��ʼ��(JKR63825) */
void B1553InitBC(unsigned int memSize, unsigned int regBase, unsigned int memBase)
{
	unsigned int mem;
	unsigned int regVal;

	/* 1553BоƬ��λ */
	regVal = REG_START_D00_RESET;
	BusgWriteReg(B1553_REG_START_RST, regVal, regBase);

	/* 1553B�ڴ����� */
	if (memSize == _16KB)
	{
		/* ��ʼ���ڴ��� */
		for (mem=0; mem<memSize; mem++)
		{
			BusgWriteMem(mem, 0x00, memBase);
		}
	}
	else
	{
		/* ��Ҫ��������ʼ�� */
		for (mem=0; mem<_1KB; mem++)
		{
			BusgWriteMem(mem, 0x0, memBase);
		}

		/* ��ջ����ʼ�� */
		/* */
	}

	/* ���üĴ���#3����:0x8000(ע�������������Conf.#3) */           /* ??? ���üĴ���ȡֵ�������� */
	regVal = REG_CFG3_D15_ENHANCED_EN;
	BusgWriteReg(B1553_REG_CONF3, regVal, regBase);

	/* ���üĴ���#2����: 256�ֱ߽��ֹ; tagΪ8us; ���崥�� */
	regVal = REG_CFG2_D10_256_DISBL |
		REG_CFG2_D08_TTAG_R1   |
		REG_CFG2_D07_TTAG_R0;

	BusgWriteReg(B1553_REG_CONF2, regVal, regBase);

	/* ���üĴ���#4����:0x1000 */
	regVal = REG_CFG4_D12_BC_EXPD_CW_EN |
		REG_CFG4_D06_VALID_MSG_ERR |
		REG_CFG4_D05_VALID_BUSY_BIT;

	BusgWriteReg(B1553_REG_CONF4, regVal, regBase);

	/* ���üĴ���#5����: ��ʱ��Ӧ50.5us; */
	regVal = REG_CFG5_D11_EXPD_CROSS_EN | REG_CFG5_D10_RTIME_SELE1;
	BusgWriteReg(B1553_REG_CONF5, regVal, regBase);

	/* ���üĴ���#1����: ��Ϣ�������ʹ��; A���� */
	regVal = REG_CFG1_D05_BC_MSG_GAPTIMER;
	BusgWriteReg(B1553_REG_CONF1, regVal, regBase);

	/* ջ��A/B���ã�Ĭ��ΪA���� */
	B1553BCMemConfig(B1553_MEM_CONF_A, regBase);

	return;
}


/* 1553B����BC�˹�����Ϣ֡ */
void B1553MsgFrameBuild(unsigned int cntMsg, unsigned int baseMem)
{
	unsigned int im;           /* ��Ϣ��������� */
	unsigned int msgAddr;      /* ��Ϣ���׵�ַ */
	unsigned int cntData;

	/* Ϊÿ����Ϣ����1553B�ڴ� */
	for (im=0; im<cntMsg; im++)
	{
		/* ��im����Ϣ���׵�ַ */
		msgAddr = s1553BbcMsgBlkAddr[im];

		/* ��Ϣ���ʱ��,��Ϣ����������3���� */
		BusgWriteMem(BC_MEM_BLKDESC_GAPTIME(im), BC_MSG_GAPTIME, baseMem);

		/* ��Ϣ��ָ��,��Ϣ����������4���� */
		BusgWriteMem(BC_MEM_BLKDESC_BLKPTR(im), msgAddr, baseMem);

		/* ��Ϣ�������,��Ϣ���е�1���� */
		BusgWriteMem(MSG_BLK_CTRLWD(msgAddr), sBusgMsg[im].ctrlwd, baseMem);

		/* ��Ϣ��������,��Ϣ���е�2����, */
		BusgWriteMem(MSG_BLK_CMD(msgAddr), sBusgMsg[im].cmd, baseMem);

		/* BC->RT��Ϣ�����ݴ��� */
		if (B1553_CMDWORD_TRCV(sBusgMsg[im].cmd) == B1553_RT_RECV)
		{
			/* ��ȡ�����ָ��� */
			cntData = B1553_CMDWORD_CNTD(sBusgMsg[im].cmd);

			if (cntData == 0)
			{
				cntData = 32;
			}

			/* ��Ϣ��������,��Ϣ���е�3���� */
			BusgWriteBlock(MSG_BLK_DATA_BC2RT(msgAddr), &sBusgMsg[im].data[0], cntData, baseMem);
		}
	}

	return;
}

/* 1553B����BC��������Ϣ֡���� */
void B1553MsgFrameStart(unsigned int cntMsg, unsigned int baseReg, unsigned int baseMem)
{
	unsigned int count;

	/* ���ö�ջָ�� */
	BusgWriteMem(BC_MEMCONF_STKPTR(), BC_MEMCONF_STKBASE(), baseMem);

	/* ���ö�ջ��Ϣ���� */
	count = 0xFFFF - (cntMsg & 0xFFFF);
	BusgWriteMem(BC_MEMCONF_MSGCNT(), count, baseMem);

	/* ����BC����Ϣ���� */
	BusgWriteReg(B1553_REG_START_RST, REG_START_D01_BC_START, baseReg);

	return;
}

/* 1553B����BC����Ϣ֡�����ȴ� */
unsigned int B1553MsgFrameWait(unsigned int frameEnd, unsigned int baseReg, unsigned int n1us)
{
	unsigned int cnt100us;   /* Ҫ����ʱ����100us */
	unsigned int cnt;

	cnt100us = n1us / 100 + 1;
	cnt = 0;

	do
	{
		/* ��ʱ100us */
		SYS_Delay(100);

		/* BCоƬ���м�� */
		if (frameEnd > 0)
		{
			frameEnd = B1553BCIsIdle(baseReg);
		}

		cnt++;
	} while ((cnt < cnt100us) && (frameEnd != 0x0));

	return frameEnd;
}

/* ����1553B��Ϣ������ */
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

			/* ��Ϣ��������,��Ϣ���е�3���� */
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

	/* ��ȡ��Ϣ���ַ(��Ϣ�������4����) */
	msgAddr = BusgReadMem(BC_MEM_BLKDESC_BLKPTR(msgIdx), BUSG_MEM_BASE);
	
	/* ��ȡ��Ϣ������ */
	msgCmd = BusgReadMem(MSG_BLK_CMD(msgAddr), BUSG_MEM_BASE);

	/* ��ȡ��Ϣ�������ֳ��� */
	msgLen = B1553_CMDWORD_CNTD(msgCmd);
	if (msgLen == 0)
	{
		msgLen = 32u;
	}

	BusgReadBlock(recvBuf, MSG_BLK_DATA_RT2BC(msgAddr), msgLen, BUSG_MEM_BASE);

	return msgCmd;
}
