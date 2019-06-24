#ifndef __1553B_H_PRIVATE__
#define __1553B_H_PRIVATE__

#include "1553b.h"

/* ----------------------------------------------------------------------------------------- */

/* BC/RT�ڴ����� */
#define B1553_MEM_CONF_A                    0x0000  /*  */
#define B1553_MEM_CONF_B                    0x2000  /* REG CFG1.D13 CURRENT AREA B/A */

/* ----------------------------------------------------------------------------------------- */
/* 1553BоƬ����ģʽ */
#define B1553_MODE_IDLE                     0x00    /* Idle */
#define B1553_MODE_BC_NORMAL                0xE1    /* Non-ENHANCED BC (See Note)  */
#define B1553_MODE_BC_ENHANCED              0xD2    /* ENHANCED BC                 */
#define B1553_MODE_WORD1_MONI               0xC3    /* Word Monitor                */
#define B1553_MODE_WORD2_MONI               0xB4    /* Word Monitor                */
#define B1553_MODE_MSG_MONI                 0xA5    /* Message Monitor             */
#define B1553_MODE_RT_NORMAL                0x96    /* Non-ENHANCED RT             */
#define B1553_MODE_RT_ENHANCED              0x87    /* ENHANCED RT                 */
#define B1553_MODE_RT_MT                    0x78    /* Enhanced RT/Message Monitor */

/* 1553B�Ĵ�����ַ���� */
#define B1553_REG_BASE                      0x0000u /* �Ĵ�����ַ */
#define B1553_REG_INT_MASK                  0x0000u /* �ж����μĴ���(RD/WR) */
#define B1553_REG_CONF1                     0x0001u /* ���üĴ���#1 (RD/WR) */
#define B1553_REG_CONF2                     0x0002u /* ���üĴ���#2 (RD/WR) */
#define B1553_REG_START_RST                 0x0003u /* ��ʼ/��λ�Ĵ���(WR) */
#define B1553_REG_CMD_STACK_PTR             0x0003u /* �����ջָ��Ĵ���(RD) */
#define B1553_REG_BC_CTRW                   0x0004u /* BC�����ּĴ��� */
#define B1553_REG_RT_SA_CTRW                0x0004u /* RT�ӵ�ַ�����ּĴ���2(RD/WR) */
#define B1553_REG_TIME_TAG                  0x0005u /* ʱ���ǼĴ���(RD/WR) */
#define B1553_REG_INT_ST                    0x0006u /* �ж�״̬�Ĵ���(RD) */
#define B1553_REG_CONF3                     0x0007u /* ���üĴ���#3(RD/WR) */
#define B1553_REG_CONF4                     0x0008u /* ���üĴ���#4(RD/WR) */
#define B1553_REG_CONF5                     0x0009u /* ���üĴ���#5(RD/WR) */
#define B1553_REG_RT_DAT_STK_PTR            0x000Au /* RT���ݶ�ջ��ַ�Ĵ���(RD/WR) */
#define B1553_REG_MT_DAT_STK_PTR            0x000Au /* MT���ݶ�ջ��ַ�Ĵ���(RD/WR) */
#define B1553_REG_BC_FRM_TIME_REM           0x000Bu /* BC֡ʱ��ʣ��Ĵ���(RD) */
#define B1553_REG_BC_TIME_REM_NMSG          0x000Cu /* BC��Ϣʱ��ʣ��Ĵ���(RD) */
#define B1553_REG_BC_FTIME                  0x000Du /* BC֡ʱ��Ĵ��� (RD/WR) */
#define B1553_REG_RT_LAST_CMD               0x000Du /* RT���һ�������ּĴ��� (RD/WR) */
#define B1553_REG_MT_TRIGGER_WORD           0x000Du /* MT�������ּĴ��� (RD/WR) */
#define B1553_REG_RT_STW                    0x000Eu /* RT״̬�ּĴ���(RD) */
#define B1553_REG_RT_BITW                   0x000Fu /* RT�Բ����ּĴ���(RD) */

/* 1553B�Ĵ���λ���� */

/* CONVENIENT_FOR_LOOKUP
void Reg_Interrupt_Mask_0x00(){} */
/* ----------------------------------------------------------------------------------------- */
/* 1553B�ж����μĴ���(0x00) */
#define REG_INTMK_D15_RSERVED               0x8000u /* 15 RESERVED                        */
#define REG_INTMK_D14_RAM_PERR              0x4000u /* 14 RAM PARITY ERROR                */
#define REG_INTMK_D13_TX_TOUT               0x2000u /* 13 BC/RT TRANSMITTER TIMEOUT       */
#define REG_INTMK_D12_CMD_ROLL              0x1000u /* 12 BC/RT COMMAND STACK ROLLOVER    */
#define REG_INTMK_D11_MT_CMD_ROLL           0x0800u /* 11 MT COMMAND STACK ROLLOVER       */
#define REG_INTMK_D10_MT_DATA_ROLL          0x0400u /* 10 MT DATA STACK ROLLOVER          */
#define REG_INTMK_D09_HDSHAKE_FAIL          0x0200u /* 9  HANDSHAKE FAILURE               */
#define REG_INTMK_D08_BC_RETRY              0x0100u /* 8  BC RETRY                        */
#define REG_INTMK_D07_RT_ADDR_PERR          0x0080u /* 7  RT ADDRESS PARITY ERROR         */
#define REG_INTMK_D06_TIME_TAG_ERR          0x0040u /* 6  TIME TAG ROLLOVER               */
#define REG_INTMK_D05_RT_CIRC_ROLL          0x0020u /* 5  RT CIRCULAR BUFFER ROLLOVER     */
#define REG_INTMK_D04_BC_MSG_EOM            0x0010u /* 4  BC MSG EOM                      */
#define REG_INTMK_D04_RT_CTRL_EOM           0x0010u /* 4  RT SUBADDRESS CONTROL WORD EOM  */
#define REG_INTMK_D03_BC_EOF                0x0008u /* 3  BC END OF FRAME                 */
#define REG_INTMK_D02_FORMAT_ERR            0x0004u /* 2  FORMAT ERROR                    */
#define REG_INTMK_D01_BC_ST_SET             0x0002u /* 1  BC STATUS SET                   */
#define REG_INTMK_D01_RT_MD_CODE            0x0002u /* 1  RT MODE CODE                    */
#define REG_INTMK_D01_MT_TRIGGER            0x0002u /* 1  MT PATTERN TRIGGER              */
#define REG_INTMK_D00_EOM                   0x0001u /* 0  END OF MESSAGE                  */

/* CONVENIENT_FOR_LOOKUP
void Reg_Configure_1_0x01(){} */
/* ----------------------------------------------------------------------------------------- */
/* 1553B���üĴ���#1(RD/WR) */

/* BCģʽ */
#define REG_CFG1_D15_BC_RT_SELECT           0x8000u /* 15 RT/BC-MT*                        */
#define REG_CFG1_D14_BC_MT_SELECT           0x4000u /* 14 MT/BC-RT*                        */
#define REG_CFG1_D13_BC_AREA_B_SELECT       0x2000u /* 13 CURRENT AREA B/A*                */
#define REG_CFG1_D12_BC_MSG_STOP_ERR        0x1000u /* 12 MESSAGE STOP-ON-ERROR            */
#define REG_CFG1_D11_BC_FRAME_STOP_ERR      0x0800u /* 11 FRAME STOP-ON-ERROR              */
#define REG_CFG1_D10_BC_ST_SET_STOM         0x0400u /* 10 STATUS SET STOP-ON-MESSAGE       */
#define REG_CFG1_D09_BC_ST_SET_STOF         0x0200u /* 9  STATUS SET STOP-ON-FRAME         */
#define REG_CFG1_D08_BC_FRAME_AUTO          0x0100u /* 8  FRAME AUTO-REPEAT                */
#define REG_CFG1_D07_BC_EXTL_TRIGGER        0x0080u /* 7 EXTERNAL TRIGGER ENABLED          */
#define REG_CFG1_D06_BC_INTL_TRIGGER        0x0040u /* 6 INTERNAL TRIGGER ENABLED          */
#define REG_CFG1_D05_BC_MSG_GAPTIMER        0x0020u /* 5 INTER-MESSAGE GAP TIMER ENABLED   */
#define REG_CFG1_D04_BC_RETRY_EN            0x0010u /* 4 RETRY ENABLED                     */
#define REG_CFG1_D03_BC_DBL_RETRY           0x0008u /* 3 Double/SINGLE* RETRY              */
#define REG_CFG1_D02_BC_ENABLED             0x0004u /* 2 BC ENABLED(Read Only)             */
#define REG_CFG1_D01_BC_FRAME_IN_PROG       0x0002u /* 1 BC FRAME IN PROGRESS(Read Only)   */
#define REG_CFG1_D00_BC_MSG_IN_PROG         0x0001u /* 0 BC MESSAGE IN PROGRESS(Read Only) */

/* RTģʽ */
#define REG_CFG1_D15_RT_RT_SELECT           0x8000u /* 15 RT/BC-MT*                         */
#define REG_CFG1_D14_RT_MT_SELECT           0x4000u /* 14 MT/BC-RT*                         */
#define REG_CFG1_D13_RT_AREA_B_SELECT       0x2000u /* 13 CURRENT AREA B/A*                 */
#define REG_CFG1_D12_RT_MSG_MONI_EN         0x1000u /* 12 MESSAGE MONITOR ENABLED           */
#define REG_CFG1_D11_RT_NOT_DYN_BUS         0x0800u /* 11 DYNAMIC BUS CONTROL ACCEPTANCE*   */
#define REG_CFG1_D10_RT_NOT_BUSY            0x0400u /* 10 BUSY*                             */
#define REG_CFG1_D09_RT_NOT_SERVICE_REQ     0x0200u /* 9  SERVICE REQUEST*                  */
#define REG_CFG1_D08_RT_NOT_SUBSYS_FLAG     0x0100u /* 8  SUBSYSTEM FLAG*                   */
#define REG_CFG1_D07_RT_NOT_RTFLAG          0x0080u /* 7  RTFLAG*(enhanced mode Only)       */
#define REG_CFG1_D06_RT_INTL_TRIGGER        0x0040u /* 6  NOT USED                          */
#define REG_CFG1_D05_RT_MSG_GAPTIMER        0x0020u /* 5  NOT USED                          */
#define REG_CFG1_D04_RT_NOT_USED            0x0010u /* 4  NOT USED                          */
#define REG_CFG1_D03_RT_NOT_USED            0x0008u /* 3  NOT USED                          */
#define REG_CFG1_D02_RT_NOT_USED            0x0004u /* 2  NOT USED                          */
#define REG_CFG1_D01_RT_NOT_USED            0x0002u /* 1  NOT USED                          */
#define REG_CFG1_D00_RT_MSG_IN_PRO          0x0001u /* 0  RT MESSAGE IN PROGRESS(Read Only) */

/* MTģʽ */
#define REG_CFG1_D15_MT_RT_SELECT           0x8000u /* 15 RT/BC-MT*                    */
#define REG_CFG1_D14_MT_MT_SELECT           0x4000u /* 14 MT/BC-RT*                    */
#define REG_CFG1_D13_MT_AREA_B_SELECT       0x2000u /* 13 CURRENT AREA B/A*            */
#define REG_CFG1_D12_MT_MSG_MONI_EN         0x1000u /* 12 MESSAGE MONITOR ENABLED      */
#define REG_CFG1_D11_MT_TRIG_EN             0x0800u /* 11 TRIGGER ENABLED WORD         */
#define REG_CFG1_D10_MT_START_ON_TRIG       0x0400u /* 10 START-ON-TRIGGER             */
#define REG_CFG1_D09_MT_STOP_ON_TRIG        0x0200u /* 9  STOP-ON-TRIGGER              */
#define REG_CFG1_D08_MT_NOT_USED            0x0100u /* 8  NOT USED                     */
#define REG_CFG1_D07_MT_EX_TRIG_EN          0x0080u /* 7  EXTERNAL TRIGGER ENABLED     */
#define REG_CFG1_D06_MT_NOT_USED            0x0040u /* 6  NOT USED                     */
#define REG_CFG1_D05_MT_NOT_USED            0x0020u /* 5  NOT USED                     */
#define REG_CFG1_D04_MT_NOT_USED            0x0010u /* 4  NOT USED                     */
#define REG_CFG1_D03_MT_NOT_USED            0x0008u /* 3  NOT USED                     */
#define REG_CFG1_D02_MT_MONI_EN_R           0x0004u /* 2  MONITOR ENABLED(Read Only)   */
#define REG_CFG1_D01_MT_MONI_TRIG           0x0002u /* 1  MONITOR TRIGGERED(Read Only) */
#define REG_CFG1_D00_MT_MSG_IN_PRO          0x0001u /* 0  TRIGGER ACTIVE(Read Only)    */

/* CONVENIENT_FOR_LOOKUP
void Reg_Configure_2_0x02(){} */
/* ----------------------------------------------------------------------------------------- */
/* 1553B���üĴ���#2(RD/WR) */
#define REG_CFG2_D15_EHD_INT                0x8000u /* 15 ENHANCED INTERRUPTS          */
#define REG_CFG2_D14_RAM_PTY_EN             0x4000u /* 14 RAM PARITY ENABLE            */
#define REG_CFG2_D13_BUSY_LUT_EN            0x2000u /* 13 BUSY LOOK UP TABLE ENABLE    */
#define REG_CFG2_D12_DBL_BUF_EN             0x1000u /* 12 RX SA DOUBLE BUFFER ENABLE   */
#define REG_CFG2_D11_INVALID_DATA           0x0800u /* 11 OVERWRITE INVALID DATA       */
#define REG_CFG2_D10_256_DISBL              0x0400u /* 10 256-WORD BOUNDR DISBL        */
#define REG_CFG2_D09_TTAG_R2                0x0200u /* 9 TIME TAG RESOLUTION 2 (TTR2)  */
#define REG_CFG2_D08_TTAG_R1                0x0100u /* 8 TIME TAG RESOLUTION 1 (TTR1)  */
#define REG_CFG2_D07_TTAG_R0                0x0080u /* 7 TIME TAG RESOLUTION 0 (TTR0)  */
#define REG_CFG2_D06_CLEAR_TTAG_SYN         0x0040u /* 6 CLEAR TIME TAG ON SYNCHRONIZE */
#define REG_CFG2_D05_LOAD_TTAG_SYN          0x0020u /* 5 LOAD TIME TAG ON SYNCHRONIZE  */
#define REG_CFG2_D04_INT_AUTO_CLEAR         0x0010u /* 4 INTERRUPT STATUS AUTO CLEAR   */
#define REG_CFG2_D03_LEVEL_INT              0x0008u /* 3 LEVEL/PULSE INTERRUPT REQUEST */
#define REG_CFG2_D02_CLEAR_SR               0x0004u /* 2 CLEAR SERVICE REQUEST         */
#define REG_CFG2_D01_EHD_RT_MEMM            0x0002u /* 1 ENHANCED RT MEMORY MANAGEMENT */
#define REG_CFG2_D00_SEP_BCST_DATA          0x0001u /* 0 SEPARATE BROADCAST DATA       */

/* CONVENIENT_FOR_LOOKUP
void Reg_Start_Reset_0x03(){} */
/* ----------------------------------------------------------------------------------------- */
/* 1553B�����������Ĵ���(WR) */
#define REG_START_D15_D07_RESERVED          0x0000u /* 15~7 RESERVED         */
#define REG_START_D06_BC_STOM               0x0040u /* 6 BC STOP-ON-MESSAGE  */
#define REG_START_D06_MT_STOM               0x0040u /* 6 MT STOP-ON-MESSAGE  */
#define REG_START_D05_BC_STOF               0x0020u /* 5 BC STOP-ON-FRAME    */
#define REG_START_D04_TTAG_CLOCK            0x0010u /* 4 TIME TAG TEST CLOCK */
#define REG_START_D03_TTAG_RESET            0x0008u /* 3 TIME TAG RESET      */
#define REG_START_D02_INT_RESET             0x0004u /* 2 INTERRUPT RESET     */
#define REG_START_D01_BC_START              0x0002u /* 1 BC START            */
#define REG_START_D01_MT_START              0x0002u /* 1 MT START            */
#define REG_START_D00_RESET                 0x0001u /* 0 RESET               */

/* CONVENIENT_FOR_LOOKUP
void Reg_BCRT_Ctrl_Word_0x04(){} */
/* ----------------------------------------------------------------------------------------- */
/* 1553B BC�����ּĴ���(RD/WR) */
#define REG_BC_CTW_D15_RESERVED             0x8000u /* 15 RESERVED                  */
#define REG_BC_CTW_D14_MSGERR_MASK          0x4000u /* 14 MESSAGE ERR MASK          */
#define REG_BC_CTW_D13_SERACQ_MASK          0x2000u /* 13 SERVICE REQUEST BIT MASK  */
#define REG_BC_CTW_D12_SUBBUSY_MASK         0x1000u /* 12 SUBSYS BUSY BIT MASK      */
#define REG_BC_CTW_D11_SUBFLG_MASK          0x0800u /* 11 SUBSYS FLAG BIT MASK      */
#define REG_BC_CTW_D10_TERFLG_MASK          0x0400u /* 10 TERMINAL FLAG BIT MASK    */
#define REG_BC_CTW_D09_REVDFLG_MASK         0x0200u /* 9 RESERVED BITS MASK         */
#define REG_BC_CTW_D08_RETRY_EN             0x0100u /* 8 RETRY ENABLED              */
#define REG_BC_CTW_D07_CHNL_AB              0x0080u /* 7 BUS CHANNEL A/B*           */
#define REG_BC_CTW_D06_OFF_TEST             0x0040u /* 6 OFF LINE SELF TEST         */
#define REG_BC_CTW_D05_BRDCAST_MASK         0x0020u /* 5 MASK BROADCAST BIT         */
#define REG_BC_CTW_D04_EOMINT_EN            0x0010u /* 4 EOM INTERRUPT ENABLE       */
#define REG_BC_CTW_D03_1553AB_SELE          0x0008u /* 3 1553A/B SELECT             */
#define REG_BC_CTW_D02_MODE_FORMAT          0x0004u /* 2 MODE CODE FORMAT           */
#define REG_BC_CTW_D01_BRD_FORMAT           0x0002u /* 1 BROADCAST FORMAT           */
#define REG_BC_CTW_D00_RT2RT_FORMAT         0x0001u /* 0 RT-TO-RT FORMAT            */

/* 1553B RT�ӵ�ַ�����ּĴ���(RD/WR) */
#define REG_RT_SACW_D15_RX_DBUF_EN          0x8000u /* 15 RX: DOUBLE BUFFER ENABLE       */
#define REG_RT_SACW_D14_TX_EOM_INT          0x4000u /* 14 TX: EOM INT                    */
#define REG_RT_SACW_D13_TX_CIRC_BUF_INT     0x2000u /* 13 TX: CIRC BUF INT               */
#define REG_RT_SACW_D12_TX_MM2              0x1000u /* 12 TX: MEMORY MANAGEMENT 2 (MM2)  */
#define REG_RT_SACW_D11_TX_MM1              0x0800u /* 11 TX: MEMORY MANAGEMENT 1 (MM1)  */
#define REG_RT_SACW_D10_TX_MM0              0x0400u /* 10 TX: MEMORY MANAGEMENT 0 (MM0)  */
#define REG_RT_SACW_D09_RX_EOM_INT          0x0200u /* 9 RX: EOM INT                     */
#define REG_RT_SACW_D08_RX_CIRC_BUF_INT     0x0100u /* 8 RX: CIRC BUF INT                */
#define REG_RT_SACW_D07_RX_MM2              0x0080u /* 7 RX: MEMORY MANAGEMENT 2 (MM2)   */
#define REG_RT_SACW_D06_RX_MM1              0x0040u /* 6 RX: MEMORY MANAGEMENT 1 (MM1)   */
#define REG_RT_SACW_D05_RX_MM0              0x0020u /* 5 RX: MEMORY MANAGEMENT 0 (MM0)   */
#define REG_RT_SACW_D04_BCST_EOM_INT        0x0010u /* 4 BCST: EOM INT                   */
#define REG_RT_SACW_D03_BCST_CIRC_BUF_INT   0x0008u /* 3 BCST: CIRC BUF INT              */
#define REG_RT_SACW_D02_BCST_MM2            0x0004u /* 2 BCST: MEMORY MANAGEMENT 2 (MM2) */
#define REG_RT_SACW_D01_BCST_MM1            0x0002u /* 1 BCST: MEMORY MANAGEMENT 1 (MM1) */
#define REG_RT_SACW_D00_BCST_MM0            0x0001u /* 0 BCST: MEMORY MANAGEMENT 0 (MM0) */

/* CONVENIENT_FOR_LOOKUP
void Reg_Interrupt_Status_0x06(){} */
/* ----------------------------------------------------------------------------------------- */
/* 1553B�ж�״̬�Ĵ���(RD/WR) */
#define REG_INT_ST_D15_MASTER               0x8000u /* 15 MASTER INTERRUPT               */
#define REG_INT_ST_D14_RAM_ERR              0x4000u /* 14 RAM PARITY ERROR               */
#define REG_INT_ST_D13_TRAN_TOUT            0x2000u /* 13 TRANSMITTER TIMEOUT            */
#define REG_INT_ST_D12_CMD_ROLL             0x1000u /* 12 BC/RT COMMAND STACK ROLLOVER   */
#define REG_INT_ST_D11_MTCMD_ROLL           0x0800u /* 11 MT COMMAND STACK ROLLOVER      */
#define REG_INT_ST_D10_MT_DATA_ROLL         0x0400u /* 10 MT DATA STACK ROLLOVER         */
#define REG_INT_ST_D09_HDSHAKE              0x0200u /* 9  HANDSHAKE FAILURE              */
#define REG_INT_ST_D08_BC_RETRY             0x0100u /* 8  BC RETRY                       */
#define REG_INT_ST_D07_RT_ADDR_ERR          0x0080u /* 7  RT ADDRESS PARITY ERROR        */
#define REG_INT_ST_D06_TIME_TAG_ERR         0x0040u /* 6  TIME TAG ROLLOVER              */
#define REG_INT_ST_D05_RT_BUF_ROLL          0x0020u /* 5  RT CIRCULAR BUFFER ROLLOVER    */
#define REG_INT_ST_D04_RT_CTRL_EOM          0x0010u /* 4  RT SUBADDRESS CONTROL WORD EOM */
#define REG_INT_ST_D03_BC_EOF               0x0008u /* 3  BC END OF FRAME                */
#define REG_INT_ST_D02_FMAT_ERR             0x0004u /* 2  FORMAT ERROR                   */
#define REG_INT_ST_D01_BC_STATUS            0x0002u /* 1  BC STATUS SET                  */
#define REG_INT_ST_D01_RT_MODE              0x0002u /* 1  RT MODE CODE                   */
#define REG_INT_ST_D01_MT_TRIGGER           0x0002u /* 1  MTPATTERN TRIGGER              */
#define REG_INT_ST_D00_EOM                  0x0001u /* 0  END OF MESSAGE                 */

/* CONVENIENT_FOR_LOOKUP
void Reg_Configure_3_0x07(){} */
/* ----------------------------------------------------------------------------------------- */
/* 1553B���üĴ���#3(RD/WR) */
#define REG_CFG3_D15_ENHANCED_EN            0x8000u /* 15 ENHANCED MODE ENABLE         */
#define REG_CFG3_D14_BCRT_CMDSTK_SIZE1      0x4000u /* 14 BC/RT COMMAND STACK SIZE 1   */
#define REG_CFG3_D13_BCRT_CMDSTK_SIZE0      0x2000u /* 13 BC/RT COMMAND STACK SIZE 0   */
#define REG_CFG3_D12_MT_CMDSTK_SIZE_1       0x1000u /* 12 MT COMMAND STACK SIZE 1      */
#define REG_CFG3_D11_MT_CMDSTK_SIZE_0       0x0800u /* 11 MT COMMAND STACK SIZE 0      */
#define REG_CFG3_D10_MT_DATSTK_SIZE_2       0x0400u /* 10 MT DATA STACK SIZE 2         */
#define REG_CFG3_D09_MT_DATSTK_SIZE_1       0x0200u /* 9  MT DATA STACK SIZE 1         */
#define REG_CFG3_D08_MT_DATSTK_SIZE_0       0x0100u /* 8  MT DATA STACK SIZE 0         */
#define REG_CFG3_D07_RT_ILL_DIS             0x0080u /* 7  ILLEGALIZATION DISABLED      */
#define REG_CFG3_D06_RT_OVERRIDE_T_ERR      0x0040u /* 6  OVERRIDE MODE T/R* ERROR     */
#define REG_CFG3_D05_RT_ALT_ST_EN           0x0020u /* 5  ALTERNATE STATUS WORD ENABLE */
#define REG_CFG3_D04_ILL_TRAN_DIS           0x0010u /* 4  ILLEGAL RX TRANSFER DISABLE  */
#define REG_CFG3_D03_BUSY_TRAN_EN           0x0008u /* 3  BUSY RX TRANSFER ENABLE      */
#define REG_CFG3_D02_RT_FFW_EN              0x0004u /* 2  RTFAIL*)/RTFLAG* WRAP ENABLE */
#define REG_CFG3_D01_1553A_EN               0x0002u /* 1  1553A MODE CODES ENABLE      */
#define REG_CFG3_D00_RT_EHD_HDL             0x0001u /* 0  ENHANCED MODE CODE HANDLING  */

/* CONVENIENT_FOR_LOOKUP
void Reg_Configure_4_0x08(){} */
/* ----------------------------------------------------------------------------------------- */
/* 1553B���üĴ���#4(RD/WR) */
#define REG_CFG4_D15_RT_EXBW_EN             0x8000u /* 15 EXTERNAL BIT WORD ENABLE           */
#define REG_CFG4_D14_RT_INBW_BUSY           0x4000u /* 14 INHIBIT BIT WORD IF BUSY           */
#define REG_CFG4_D13_RT_MODE_OV_BUSY        0x2000u /* 13 MODE COMMAND OVERRIDE BUSY         */
#define REG_CFG4_D12_BC_EXPD_CW_EN          0x1000u /* 12 EXPANDED BC CONTROL WORD ENABLE    */
#define REG_CFG4_D11_BC_BCST_MK_EN          0x0800u /* 11 BROADCAST MASK ENABLED/XOR*        */
#define REG_CFG4_D10_RETRY_MSG_ERR          0x0400u /* 10 RETRY IF 1553A AND MESSAGE ERROR   */
#define REG_CFG4_D09_RETRY_ST_SET           0x0200u /*  9 RETRY IF STATUS SET                */
#define REG_CFG4_D08_FST_RETRY_ALT          0x0100u /*  8 FIRST RETRY ALT/SAME* BUS          */
#define REG_CFG4_D07_SEC_RETRY_ALT          0x0080u /*  7 SECOND RETRY ALT/SAME* BUS         */
#define REG_CFG4_D06_VALID_MSG_ERR          0x0040u /*  6 VALID IF MESSAGE ERROR BIT/NO DATA */
#define REG_CFG4_D05_VALID_BUSY_BIT         0x0020u /*  5 VALID BUSY BIT/NO DATA             */
#define REG_CFG4_D04_MT_TAG_OPTION          0x0010u /*  4 MONITOR TIME GAP OPTION            */
#define REG_CFG4_D03_RTADDR_CFG5            0x0008u /*  3 LATCH RT ADDRESS WITH CFG REG #5   */
#define REG_CFG4_D02_TM2                    0x0004u /*  2 TEST MODE 2                        */
#define REG_CFG4_D01_TM1                    0x0002u /*  1 TEST MODE 1                        */
#define REG_CFG4_D00_TM0                    0x0001u /*  0 TEST MODE 0                        */

/* CONVENIENT_FOR_LOOKUP
void Reg_Configure_5_0x09(){} */
/* ----------------------------------------------------------------------------------------- */
/* 1553B���üĴ���#5(RD/WR) */
#define REG_CFG5_D15_12M_SELT               0x8000u /* 15 12 MHZ CLOCK SELECT          */
#define REG_CFG5_D14_SNGL_SELT              0x4000u /* 14 SINGLE-ENDED SELECT          */
#define REG_CFG5_D13_EXT_TX_A               0x2000u /* 13 EXTERNAL TX INHIBIT A        */
#define REG_CFG5_D12_EXT_TX_B               0x1000u /* 12 EXTERNAL TX INHIBIT B        */
#define REG_CFG5_D11_EXPD_CROSS_EN          0x0800u /* 11 EXPANDED CROSSING ENABLED    */
#define REG_CFG5_D10_RTIME_SELE1            0x0400u /* 10 RESPONSE TIMEOUT SELECT 1    */
#define REG_CFG5_D09_RTIME_SELE0            0x0200u /*  9 RESPONSE TIMEOUT SELECT 0    */
#define REG_CFG5_D08_GAP_CHK_EN             0x0100u /*  8 GAP CHECK ENABLED            */
#define REG_CFG5_D07_BCST_DIS               0x0080u /*  7 BROADCAST DISABLED           */
#define REG_CFG5_D06_RT_A_LATCH             0x0040u /*  6 RT ADDR LATCH/TRANSPARENT*   */
#define REG_CFG5_D05_RT_A4_R                0x0020u /*  5 RT ADDRESS 4(read only)      */
#define REG_CFG5_D04_RT_A3_R                0x0010u /*  4 RT ADDRESS 3(read only)      */
#define REG_CFG5_D03_RT_A2_R                0x0008u /*  3 RT ADDRESS 2(read only)      */
#define REG_CFG5_D02_RT_A1_R                0x0004u /*  2 RT ADDRESS 1(read only)      */
#define REG_CFG5_D01_RT_A0_R                0x0002u /*  1 RT ADDRESS 0(read only)      */
#define REG_CFG5_D00_RT_ADDRPTY_R           0x0001u /*  0 RT ADDRESS PARITY(read only) */

/* ----------------------------------------------------------------------------------------- */
/* ����ǿ��BC�ڴ����� */

/* BC�ڴ�̶���ַ���� */
#define BC_MEM_A_STK                    0x0000  /* Aջ����ַ */
#define BC_MEM_A_STKPTR                 0x0100  /* Aջ����ջָ�� */
#define BC_MEM_B_STK                    0x0F00  /* Bջ����ַ */
#define BC_MEM_B_STKPTR                 0x0104  /* Bջ����ջָ�� */
#define BC_MEM_MSGBLK_BASE              0x0108  /* A/Bջ����Ϣ����ʼ��ַ */

/* BC��Ϣ�� */
#define BC_MEM_MSGBLK_SIZE              38u     /* ջ���洢��Ϣ��Ĵ�С */
#define BC_MEM_MSGBLK_NUM               64u     /* ջ���洢�����Ϣ���� */

/* BC�ڴ������� */
#define BC_MEMCONF_STKBASE()            (s1553BbcMemConf.stkBase    )   /* A/Bջ����ַ */
#define BC_MEMCONF_STKPTR()             (s1553BbcMemConf.stkPtr     )   /* A/Bջ����ջָ�� */
#define BC_MEMCONF_MSGCNT()             (s1553BbcMemConf.stkPtr + 1u)   /* A/Bջ����Ϣ���� */
#define BC_MEMCONF_INIT_STKPTR()        (s1553BbcMemConf.stkPtr + 2u)   /* A/Bջ����ʼ����ջָ�� */
#define BC_MEMCONF_INIT_MSGCNT()        (s1553BbcMemConf.stkPtr + 3u)   /* A/Bջ����ʼ����Ϣ���� */

/* ��Ϣ��������
   1. ��Ϣ��״̬��
   2. ��Ϣʱ������
   3. ��Ϣ���ʱ��
   4. ��Ϣ���ַ
*/
#define BC_MEM_BLKDESC(nmsg)            (BC_MEMCONF_STKBASE() + ((nmsg) << 2u))
#define BC_MEM_BLKDESC_STATUS(nmsg)     (BC_MEMCONF_STKBASE() + ((nmsg) << 2u) + 0u)
#define BC_MEM_BLKDESC_TIMETAG(nmsg)    (BC_MEMCONF_STKBASE() + ((nmsg) << 2u) + 1u)
#define BC_MEM_BLKDESC_GAPTIME(nmsg)    (BC_MEMCONF_STKBASE() + ((nmsg) << 2u) + 2u)
#define BC_MEM_BLKDESC_BLKPTR(nmsg)     (BC_MEMCONF_STKBASE() + ((nmsg) << 2u) + 3u)

/* ��Ϣ���и�����λ�� */
#define MSG_BLK_CTRLWD(msgAddr)         ((msgAddr) + 0u)    /* ��Ϣ���п����� */
#define MSG_BLK_CMD(msgAddr)            ((msgAddr) + 1u)    /* ��Ϣ���������� */

#define MSG_BLK_DATA_BC2RT(msgAddr)     ((msgAddr) + 2u)    /* ��Ϣ���������� */

#define MSG_BLK_STATUS_RT2BC(msgAddr)   ((msgAddr) + 3u)    /* ��Ϣ����״̬�� */
#define MSG_BLK_DATA_RT2BC(msgAddr)     ((msgAddr) + 4u)    /* ��Ϣ���������� */

/* ��Ϣ���ʱ�� */
#define BC_MSG_GAPTIME  0xF     /* ����15us�϶�С����Ϣ����ʱ��,��оƬĬ����Ϣ���ʱ��12.3us */
/* ----------------------------------------------------------------------------------------- */
/* BC�ڴ������� */
typedef struct TAG_1553B_BC_MEM_CONFIG
{
    unsigned int confID;                 /* A/Bջ�����ñ�־,ȡֵ B1553_MEM_CONF_A/B1553_MEM_CONF_B */

    unsigned int stkBase;                /* A/Bջ����ַ */
    unsigned int stkPtr;                 /* A/Bջ����ջָ�� */
} S1553BBCMemConf;

/* BC��RT��Ϣ��ʽ */
typedef struct TAG_1553B_BCRT_MSG
{
    unsigned short ctrlwd;                 /* ��Ϣ���п����� */
    unsigned short cmd;                    /* ��Ϣ���������� */
    unsigned short data[32];               /* ��Ϣ���������� */
} S1553BBCMsg;

/* ��ȡоƬ�ڴ��Ĵ�����ֵ */
#define B1553_READ(offno, addrbase)         \
	ADDR_READ16((addrbase) + ((offno) << 2u))

/* ��оƬ�ڴ��Ĵ���д��ֵ */
#define B1553_WRITE(offno, val32, addrbase) \
	ADDR_WRITE(((addrbase) + ((offno) << 2u)), ((val32) & 0xFFFFu))

/* ��ȡоƬ�Ĵ�����ֵ */
#define BusgReadReg(regno, regBase)                 \
	B1553_READ((regno), (regBase))

/* ��оƬ�Ĵ���д��ֵ */
#define BusgWriteReg(regno, regv32, regBase)        \
	B1553_WRITE((regno), (regv32), (regBase))

/* ��ȡоƬ��RAM��ֵ */
#define BusgReadMem(offset, memBase)                \
	B1553_READ((offset), (memBase))

/* ��оƬ��RAMд��ֵ */
#define BusgWriteMem(offset, memv32, memBase)       \
	B1553_WRITE((offset), (memv32), (memBase))

/* ��ȡ1553B����Ϣ���� */
#define BusgReadBlock(buf, blkAddr, len16, memBase) \
	B1553ReadBlock((buf), (blkAddr), (len16), (memBase))

/* д��1553B����Ϣ���� */
#define BusgWriteBlock(blkAddr, buf, len16, memBase)\
	B1553WriteBlock((blkAddr), (buf), (len16), (memBase))

#endif  /* STD_1553_REG_H */
