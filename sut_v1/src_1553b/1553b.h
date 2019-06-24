#ifndef __1553B_H__
#define __1553B_H__

/* 字节大小定义 */
#define _512B                       512     /*  512 bytes */
#define _1KB                        1024    /*  1K= 1024 bytes */
#define _2KB                        2048    /*  2K= 2048 bytes */
#define _4KB                        4096    /*  4K= 4096 bytes */
#define _8KB                        8192    /*  8K= 8192 bytes */
#define _16KB                       16384   /* 16K=16384 bytes */

/* ----------------------------------------------------------------------------------------- */
/* RT子地址 */
#define RT_SA00                             0u
#define RT_SA01                             1u
#define RT_SA02                             2u
#define RT_SA03                             3u
#define RT_SA04                             4u
#define RT_SA05                             5u
#define RT_SA06                             6u
#define RT_SA07                             7u
#define RT_SA08                             8u
#define RT_SA09                             9u
#define RT_SA10                             10u
#define RT_SA11                             11u
#define RT_SA12                             12u
#define RT_SA13                             13u
#define RT_SA14                             14u
#define RT_SA15                             15u
#define RT_SA16                             16u
#define RT_SA17                             17u
#define RT_SA18                             18u
#define RT_SA19                             19u
#define RT_SA20                             20u
#define RT_SA21                             21u
#define RT_SA22                             22u
#define RT_SA23                             23u
#define RT_SA24                             24u
#define RT_SA25                             25u
#define RT_SA26                             26u
#define RT_SA27                             27u
#define RT_SA28                             28u
#define RT_SA29                             29u
#define RT_SA30                             30u
#define RT_SA31                             31u

/* ----------------------------------------------------------------------------------------- */
/* RT控制字中消息类型 */
#define B1553_RT_RECV                       0u      /* RT端接收数据 */
#define B1553_RT_TRAN                       1u      /* RT端发送数据 */
#define B1553_RT_BROAD                      2u      /* RT端广播方式 */
#define B1553_RT_DBLBUF                     3u      /* RT端接收双缓存方式 */

/* BC控制字位定义 */
#define BC_CTW_D15_RESERVED             0x8000      /* 15(MSB) RESERVED                  */
#define BC_CTW_D14_MSGERR_MASK          0x4000      /* 14 MESSAGE ERROR MASK (S10)       */
#define BC_CTW_D13_SERACQ_MASK          0x2000      /* 13 SERVICE REQUEST BIT MASK (S08) */
#define BC_CTW_D12_SUBBUSY_MASK         0x1000      /* 12 SUBSYS BUSY BIT MASK (S03)     */
#define BC_CTW_D11_SUBFLG_MASK          0x0800      /* 11 SUBSYS FLAG BIT MASK (S02)     */
#define BC_CTW_D10_TERFLG_MASK          0x0400      /* 10 TERMINAL FLAG BIT MASK (S00)   */
#define BC_CTW_D09_REVDFLG_MASK         0x0200      /* 9 RESERVED BITS MASK              */
#define BC_CTW_D08_RETRY_EN             0x0100      /* 8 RETRY ENABLED                   */
#define BC_CTW_D07_CHNL_AB              0x0080      /* 7 BUS CHANNEL A/B*                */
#define BC_CTW_D06_OFF_TEST             0x0040      /* 6 OFF LINE SELF TEST              */
#define BC_CTW_D05_BRDCAST_MASK         0x0020      /* 5 MASK BROADCAST BIT              */
#define BC_CTW_D04_EOMINT_EN            0x0010      /* 4 EOM INTERRUPT ENABLE            */
#define BC_CTW_D03_1553AB_SELE          0x0008      /* 3 1553A/B SELECT                  */
#define BC_CTW_D02_MODE_FORMAT          0x0004      /* 2 MODE CODE FORMAT                */
#define BC_CTW_D01_BRD_FORMAT           0x0002      /* 1 BROADCAST FORMAT                */
#define BC_CTW_D00_RT2RT_FORMAT         0x0001      /* 0(LSB) RT-TO-RT FORMAT            */

/* 总线协议中控制字通道定义 */
#define B1553_CHNL_A                    BC_CTW_D07_CHNL_AB  /* 总线传输选择通道A */
#define B1553_CHNL_B                    0x0000              /* 总线传输选择通道B */

/* ----------------------------------------------------------------------------------------- */

#define BUSG_FRAME_WAIT_TIME 20000
#define BUSG_MEM_SIZE _16KB
#define BUSG_REG_BASE 0x21000000
#define BUSG_MEM_BASE 0x21004000

/* ----------------------------------------------------------------------------------------- */
/* 1553B消息命令字 */
/* 15-11 REMOTE TERMINAL ADDRESS */
/* 10-10 1:TRANSMIT/0:RECEIVE */
/* 9 - 5 SUBADDRESS/MODE CODE */
/* 4 - 0 DATA WORD COUNT/MODE CODE */
#define B1553_CMDWORD_ADDR(cmdw)            (((cmdw) >> 11u) & 0x1Fu)
#define B1553_CMDWORD_TRCV(cmdw)            (((cmdw) >> 10u) & 0x01u)
#define B1553_CMDWORD_SAMC(cmdw)            (((cmdw) >>  5u) & 0x1Fu)
#define B1553_CMDWORD_CNTD(cmdw)            ((cmdw)          & 0x1Fu)

#define B1553_CMDWORD_ADDR_SET(cmdw, addr)  ((cmdw) = ((cmdw) & (~(0x1Fu << 11u))) | (((addr) & 0x1Fu) << 11u))
#define B1553_CMDWORD_TRCV_SET(cmdw, trcv)  ((cmdw) = ((cmdw) & (~(0x01u << 10u))) | (((trcv) & 0x01u) << 10u))
#define B1553_CMDWORD_SAMC_SET(cmdw, samc)  ((cmdw) = ((cmdw) & (~(0x1Fu <<  5u))) | (((samc) & 0x1Fu) <<  5u))
#define B1553_CMDWORD_CNTD_SET(cmdw, cntd)  ((cmdw) = ((cmdw) & (~(0x1Fu       ))) | (((cntd) & 0x1Fu)       ))

/* ----------------------------------------------------------------------------------------- */

void B1553InitBC(unsigned int memSize, unsigned int regBase, unsigned int memBase);
void B1553MsgFrameBuild(unsigned int cntMsg, unsigned int baseMem);
void B1553MsgFrameStart(unsigned int cntMsg, unsigned int baseReg, unsigned int baseMem);
unsigned int B1553MsgFrameWait(unsigned int frameEnd, unsigned int baseReg, unsigned int n1us);
unsigned int B1553MsgCmdGen(unsigned int addr, unsigned int tr, unsigned int samc, unsigned int salen);
unsigned int B1553MsgRegister(unsigned int cntMsg, unsigned short ctrlwd, unsigned short cmd, unsigned short data[]);

unsigned int Read1553Msg(unsigned short recvBuf[], unsigned int msgIdx);

#endif
