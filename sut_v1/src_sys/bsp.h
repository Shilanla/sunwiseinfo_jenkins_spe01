#ifndef __BSP_SOC_2008_H__
	#define __BSP_SOC_2008_H__
	
	#define SPARC_NUMBER_OF_REGISTER_WINDOWS 8

	#define SPARC_PSR_CWP_MASK  0x07              /* bits  0 -  4 */
	#define CPU_STACK_FRAME_L0_OFFSET             0x00
	#define CPU_STACK_FRAME_L2_OFFSET             0x08
	#define CPU_STACK_FRAME_L4_OFFSET             0x10
	#define CPU_STACK_FRAME_L6_OFFSET             0x18
	#define CPU_STACK_FRAME_I0_OFFSET             0x20
	#define CPU_STACK_FRAME_I2_OFFSET             0x28
	#define CPU_STACK_FRAME_I4_OFFSET             0x30
	#define CPU_STACK_FRAME_I6_FP_OFFSET          0x38

	#define SPARC_PSR_CWP_MASK  0x07              /* bits  0 -  4 */
	#define SPARC_PSR_ET_MASK   0x00000020        /* bit   5 */
	#define SPARC_PSR_S_MASK    0x00000080        /* bit   7 */
	#define SPARC_PSR_PIL_MASK  0x00000F00        /* bits  8 - 11 */
	#define SPARC_PSR_EF_MASK   0x00001000        /* bit  12 */
	#define SPARC_PSR_EC_MASK   0x00002000        /* bit  13 */
	#define SPARC_PSR_ICC_MASK  0x00F00000        /* bits 20 - 23 */
	#define SPARC_PSR_VER_MASK  0x0F000000        /* bits 24 - 27 */
	#define SPARC_PSR_IMPL_MASK 0xF0000000        /* bits 28 - 31 */


	#define CPU_STACK_FRAME_L0_OFFSET             0x00
	#define CPU_STACK_FRAME_L2_OFFSET             0x08
	#define CPU_STACK_FRAME_L4_OFFSET             0x10
	#define CPU_STACK_FRAME_L6_OFFSET             0x18
	#define CPU_STACK_FRAME_I0_OFFSET             0x20
	#define CPU_STACK_FRAME_I2_OFFSET             0x28
	#define CPU_STACK_FRAME_I4_OFFSET             0x30
	#define CPU_STACK_FRAME_I6_FP_OFFSET          0x38
	#define CPU_STRUCTURE_RETURN_ADDRESS_OFFSET   0x40
	#define CPU_STACK_FRAME_SAVED_ARG0_OFFSET     0x44
	#define CPU_STACK_FRAME_SAVED_ARG1_OFFSET     0x48
	#define CPU_STACK_FRAME_SAVED_ARG2_OFFSET     0x4c
	#define CPU_STACK_FRAME_SAVED_ARG3_OFFSET     0x50
	#define CPU_STACK_FRAME_SAVED_ARG4_OFFSET     0x54
	#define CPU_STACK_FRAME_SAVED_ARG5_OFFSET     0x58
	#define CPU_STACK_FRAME_PAD0_OFFSET           0x5c
	#define CPU_MINIMUM_STACK_FRAME_SIZE          0x60

	
	/*通用宏定义*/
	#define ENABLE					0x1			/*使能*/
	#define	DISABLE					0x0			/*禁止*/
	#define SYSTRUE					0xeb90146f
	#define SYSFALSE				0x0
	
	/*和CACHE相关宏定义*/
	#define	CACHE_FROZEN		0x01		/*CACHE冻结*/
	#define	CACHE_ENABLE		0x03		/*CACHE使能*/
	#define	CACHE_DISABLE		0x00		/*CACHE禁止*/
	#define CACHE_FT_DISABLE	0x00		/*无容错校验*/
	#define CACHE_FT_ENABLE		0x01		/*4位校验*/
		
	/*和浮点寄存器相关宏定义*/
	#define	 FLOAT_ENABLE			0x1			/*浮点使能 */ 	
	#define	 FLOAT_DISABLE			0x0			/*浮点禁止 */

	
/*----------------------处理器基本配置----------------------*/

	/*处理器时钟频率配置,单位Hz*/
	#define CPU_FREQ							45000000
		
/*----------------------浮点单元相关配置----------------------*/

	/*A.浮点运算陷阱使能/禁止--FLOAT_ENABLE:浮点陷阱使能;FLOAT_DISABLE:浮点陷阱禁止*/
#ifdef FSR /*最终版本的软件中需要关闭所有FPU的TRAP*/
	#define	NVM										FLOAT_ENABLE								/*非法运算浮点陷阱使能*/
	#define	OFM										FLOAT_ENABLE								/*上溢浮点陷阱使能*/
	#define	UFM										FLOAT_DISABLE								/*下溢浮点陷阱禁止*/
	#define	DZM										FLOAT_ENABLE								/*除零浮点陷阱使能*/
	#define	NXM										FLOAT_DISABLE								/*不精确浮点陷阱禁止*/
#else
	#define	NVM										FLOAT_DISABLE								/*非法运算浮点陷阱使能*/
	#define	OFM										FLOAT_DISABLE								/*上溢浮点陷阱使能*/
	#define	UFM										FLOAT_DISABLE								/*下溢浮点陷阱禁止*/
	#define	DZM										FLOAT_DISABLE								/*除零浮点陷阱使能*/
	#define	NXM										FLOAT_DISABLE								/*不精确浮点陷阱禁止*/
#endif	
	/*----------------------CACHE相关配置----------------------*/
		
	/*A.指令CACHE使能/状态--CACHE_FROZEN:CACHE冻结;CACHE_ENABLE:CACHE使能;CACHE_DISABLE:CACHE禁止*/					
	#define	CACHE_I_STATUS			CACHE_DISABLE	
	
	/*B.数据CACHE使能/状态--CACHE_FROZEN:CACHE冻结;CACHE_ENABLE:CACHE使能;CACHE_DISABLE:CACHE禁止*/					
	#define	CACHE_D_STATUS			CACHE_DISABLE	
	
	/*C.SNOOP功能使能/禁止--ENABLE:使能;DISABLE:禁止*/
	#define	CACHE_SNOOP					ENABLE			
	
	/*D.指令CACHE取值使能/禁止--ENABLE:使能;DISABLE:禁止*/			
	#define	CACHE_I_CATCH				ENABLE	
	
	/*E.中断时数据CACHE冻结使能/禁止--ENABLE:使能;DISABLE:禁止*/					
	#define	CACHE_D_INT					ENABLE			
	
	/*F.中断时指令CACHE冻结使能/禁止--ENABLE:使能;DISABLE:禁止*/					
	#define	CACHE_I_INT					ENABLE			
	
	/*G.CACHE FT方案--CACHE_FT_DISABLE:无容错校验;CACHE_FT_ENABLE:实现4位校验*/
	#define	CACHE_FT						CACHE_FT_DISABLE		

	/*H.CACHE寄存器文件测试使能位--ENABLE:可通过ASI 0xf读出整数运算单元寄存器文件校验;DISABLE:禁止读出*/	
	#define CACHE_RFT						DISABLE
	

	/*----------------------系统栈栈底（高地址）地址配置----------------------*/

	#define BSPSTACK							0xec000		/*系统堆栈基地址（高地址）相对于RAM基地址（0x40000000）的偏移地址*/

	/*-------------处理器内部内存映射定义，适用于LEON2和LEON3，不可随意更改-------------*/	
		
	#define BSPMECBASE				0x80000000  		/*the base address of system registers */
	#define BSPROMBASE				0x0					/*the base address of boot rom*/
	#define BSPRAMBASE				0x40000000    		/*the base address of ram */
	
	#define BSPMINSTACKSIZE			0x60				/*the minimum stack size */

	
	/*--------------------------LEON3处理器内部主要部件的AHB/APB总线内存映射，适用于SOC2008-------------------------*/	
	
	#define BSP_AMBA_MEMORY_BASEADDR	0x0					/*内存控制寄存器基地址-BSPMECBASE*/
	#define BSP_AMBA_INTR_BASEADDR		0x200				/*中断控制寄存器基地址-BSPMECBASE*/
	#define BSP_AMBA_TIMER_BASEADDR		0x300				/*定时器控制寄存器基地址-BSPMECBASE*/
	#define BSP_AMBA_GPIO_BASEADDR		0x800				/*GPIO控制寄存器基地址-BSPMECBASE*/		
	#define BSP_AMBA_UART1_BASEADDR		0x100				/*UART1控制寄存器基地址-BSPMECBASE*/
	#define BSP_AMBA_UART2_BASEADDR		0x900				/*UART2控制寄存器基地址-BSPMECBASE*/	
	#define BSP_AMBA_AHB_BASEADDR		0xf00				/*AHB状态寄存器基地址---BSPMECBASE*/
	#define BSP_AMBA_WDT_BASEADDR		(BSP_AMBA_TIMER_BASEADDR+0x50)		/*看门狗定时器寄存器基地址-BSPMECBASE（TIMER 5 in SOC2008）*/

	/*--------------------------常用寄存器地址定义，适用于LEON3-------------------------*/	
		
	/*定时器控制寄存器*/
	#define BSP_GPT_REG			(BSP_AMBA_TIMER_BASEADDR+0x10)			/*GPT寄存器基址-BSPMECBASE*/		
	#define BSP_RTCT_REG		(BSP_AMBA_TIMER_BASEADDR+0x20)			/*RTCT寄存器基址-BSPMECBASE*/		

	#define BSP_TIMER_SR		(BSP_AMBA_TIMER_BASEADDR+0x00)			/*定时器分频器寄存器基址-BSPMECBASE*/				

	#define BSP_GPT_CR			BSP_GPT_REG													/*GPT计数器寄存器,为了与TSC695表示方式统一*/			

	/*中断控制寄存器*/
	#define BSP_INTR_MKR		(BSP_AMBA_INTR_BASEADDR+0x40)				/*中断屏蔽寄存器-BSPMECBASE*/				
	#define BSP_INTR_CLR		(BSP_AMBA_INTR_BASEADDR+0x0C)				/*中断清除寄存器-BSPMECBASE*/			
	#define BSP_INTR_TGR		(BSP_AMBA_INTR_BASEADDR+0x08)				/*中断强制触发寄存器-BSPMECBASE*/			
	#define BSP_INTR_PEND		(BSP_AMBA_INTR_BASEADDR+0x04)				/*中断挂起寄存器-BSPMECBASE*/
		
	/*数据CACHE刷新使能/禁止--ENABLE:使能;DISABLE:禁止*/
	#define	CACHE_D_REFRESH			ENABLE			
	
	/*指令CACHE刷新使能/禁止--ENABLE:使能;DISABLE:禁止*/
	#define	CACHE_I_REFRESH			ENABLE	
	
	/*----------------------自动配置CPU寄存器实际设置值----------------------*/
	
	/*CACHE控制寄存器*/		
	#define BSPCCR_INIT			(	(CACHE_RFT << 29)|				\
									(CACHE_SNOOP << 23)|			\
									(CACHE_D_REFRESH << 22)|		\
									(CACHE_I_REFRESH << 21)|		\
									((CACHE_FT & 0x3) << 19)|		\
									((CACHE_I_CATCH) << 16)|		\
									(CACHE_D_INT << 5)|				\
									(CACHE_I_INT << 4)|				\
									((CACHE_D_STATUS & 0x3) << 2)|	\
									(CACHE_I_STATUS & 0x3))
	
	/*浮点寄存器*/	                            	
	#define BSPFSR_INIT	(	(NVM << 27)|	\
	 						(OFM << 26)|	\
	 						(UFM << 25)|	\
	 						(DZM << 24)|	\
	 						(NXM << 23))

#endif	/* __BSP_SOC_2008_H__ */
