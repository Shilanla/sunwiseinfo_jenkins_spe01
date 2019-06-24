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

	
	/*ͨ�ú궨��*/
	#define ENABLE					0x1			/*ʹ��*/
	#define	DISABLE					0x0			/*��ֹ*/
	#define SYSTRUE					0xeb90146f
	#define SYSFALSE				0x0
	
	/*��CACHE��غ궨��*/
	#define	CACHE_FROZEN		0x01		/*CACHE����*/
	#define	CACHE_ENABLE		0x03		/*CACHEʹ��*/
	#define	CACHE_DISABLE		0x00		/*CACHE��ֹ*/
	#define CACHE_FT_DISABLE	0x00		/*���ݴ�У��*/
	#define CACHE_FT_ENABLE		0x01		/*4λУ��*/
		
	/*�͸���Ĵ�����غ궨��*/
	#define	 FLOAT_ENABLE			0x1			/*����ʹ�� */ 	
	#define	 FLOAT_DISABLE			0x0			/*�����ֹ */

	
/*----------------------��������������----------------------*/

	/*������ʱ��Ƶ������,��λHz*/
	#define CPU_FREQ							45000000
		
/*----------------------���㵥Ԫ�������----------------------*/

	/*A.������������ʹ��/��ֹ--FLOAT_ENABLE:��������ʹ��;FLOAT_DISABLE:���������ֹ*/
#ifdef FSR /*���հ汾���������Ҫ�ر�����FPU��TRAP*/
	#define	NVM										FLOAT_ENABLE								/*�Ƿ����㸡������ʹ��*/
	#define	OFM										FLOAT_ENABLE								/*���縡������ʹ��*/
	#define	UFM										FLOAT_DISABLE								/*���縡�������ֹ*/
	#define	DZM										FLOAT_ENABLE								/*���㸡������ʹ��*/
	#define	NXM										FLOAT_DISABLE								/*����ȷ���������ֹ*/
#else
	#define	NVM										FLOAT_DISABLE								/*�Ƿ����㸡������ʹ��*/
	#define	OFM										FLOAT_DISABLE								/*���縡������ʹ��*/
	#define	UFM										FLOAT_DISABLE								/*���縡�������ֹ*/
	#define	DZM										FLOAT_DISABLE								/*���㸡������ʹ��*/
	#define	NXM										FLOAT_DISABLE								/*����ȷ���������ֹ*/
#endif	
	/*----------------------CACHE�������----------------------*/
		
	/*A.ָ��CACHEʹ��/״̬--CACHE_FROZEN:CACHE����;CACHE_ENABLE:CACHEʹ��;CACHE_DISABLE:CACHE��ֹ*/					
	#define	CACHE_I_STATUS			CACHE_DISABLE	
	
	/*B.����CACHEʹ��/״̬--CACHE_FROZEN:CACHE����;CACHE_ENABLE:CACHEʹ��;CACHE_DISABLE:CACHE��ֹ*/					
	#define	CACHE_D_STATUS			CACHE_DISABLE	
	
	/*C.SNOOP����ʹ��/��ֹ--ENABLE:ʹ��;DISABLE:��ֹ*/
	#define	CACHE_SNOOP					ENABLE			
	
	/*D.ָ��CACHEȡֵʹ��/��ֹ--ENABLE:ʹ��;DISABLE:��ֹ*/			
	#define	CACHE_I_CATCH				ENABLE	
	
	/*E.�ж�ʱ����CACHE����ʹ��/��ֹ--ENABLE:ʹ��;DISABLE:��ֹ*/					
	#define	CACHE_D_INT					ENABLE			
	
	/*F.�ж�ʱָ��CACHE����ʹ��/��ֹ--ENABLE:ʹ��;DISABLE:��ֹ*/					
	#define	CACHE_I_INT					ENABLE			
	
	/*G.CACHE FT����--CACHE_FT_DISABLE:���ݴ�У��;CACHE_FT_ENABLE:ʵ��4λУ��*/
	#define	CACHE_FT						CACHE_FT_DISABLE		

	/*H.CACHE�Ĵ����ļ�����ʹ��λ--ENABLE:��ͨ��ASI 0xf�����������㵥Ԫ�Ĵ����ļ�У��;DISABLE:��ֹ����*/	
	#define CACHE_RFT						DISABLE
	

	/*----------------------ϵͳջջ�ף��ߵ�ַ����ַ����----------------------*/

	#define BSPSTACK							0xec000		/*ϵͳ��ջ����ַ���ߵ�ַ�������RAM����ַ��0x40000000����ƫ�Ƶ�ַ*/

	/*-------------�������ڲ��ڴ�ӳ�䶨�壬������LEON2��LEON3�������������-------------*/	
		
	#define BSPMECBASE				0x80000000  		/*the base address of system registers */
	#define BSPROMBASE				0x0					/*the base address of boot rom*/
	#define BSPRAMBASE				0x40000000    		/*the base address of ram */
	
	#define BSPMINSTACKSIZE			0x60				/*the minimum stack size */

	
	/*--------------------------LEON3�������ڲ���Ҫ������AHB/APB�����ڴ�ӳ�䣬������SOC2008-------------------------*/	
	
	#define BSP_AMBA_MEMORY_BASEADDR	0x0					/*�ڴ���ƼĴ�������ַ-BSPMECBASE*/
	#define BSP_AMBA_INTR_BASEADDR		0x200				/*�жϿ��ƼĴ�������ַ-BSPMECBASE*/
	#define BSP_AMBA_TIMER_BASEADDR		0x300				/*��ʱ�����ƼĴ�������ַ-BSPMECBASE*/
	#define BSP_AMBA_GPIO_BASEADDR		0x800				/*GPIO���ƼĴ�������ַ-BSPMECBASE*/		
	#define BSP_AMBA_UART1_BASEADDR		0x100				/*UART1���ƼĴ�������ַ-BSPMECBASE*/
	#define BSP_AMBA_UART2_BASEADDR		0x900				/*UART2���ƼĴ�������ַ-BSPMECBASE*/	
	#define BSP_AMBA_AHB_BASEADDR		0xf00				/*AHB״̬�Ĵ�������ַ---BSPMECBASE*/
	#define BSP_AMBA_WDT_BASEADDR		(BSP_AMBA_TIMER_BASEADDR+0x50)		/*���Ź���ʱ���Ĵ�������ַ-BSPMECBASE��TIMER 5 in SOC2008��*/

	/*--------------------------���üĴ�����ַ���壬������LEON3-------------------------*/	
		
	/*��ʱ�����ƼĴ���*/
	#define BSP_GPT_REG			(BSP_AMBA_TIMER_BASEADDR+0x10)			/*GPT�Ĵ�����ַ-BSPMECBASE*/		
	#define BSP_RTCT_REG		(BSP_AMBA_TIMER_BASEADDR+0x20)			/*RTCT�Ĵ�����ַ-BSPMECBASE*/		

	#define BSP_TIMER_SR		(BSP_AMBA_TIMER_BASEADDR+0x00)			/*��ʱ����Ƶ���Ĵ�����ַ-BSPMECBASE*/				

	#define BSP_GPT_CR			BSP_GPT_REG													/*GPT�������Ĵ���,Ϊ����TSC695��ʾ��ʽͳһ*/			

	/*�жϿ��ƼĴ���*/
	#define BSP_INTR_MKR		(BSP_AMBA_INTR_BASEADDR+0x40)				/*�ж����μĴ���-BSPMECBASE*/				
	#define BSP_INTR_CLR		(BSP_AMBA_INTR_BASEADDR+0x0C)				/*�ж�����Ĵ���-BSPMECBASE*/			
	#define BSP_INTR_TGR		(BSP_AMBA_INTR_BASEADDR+0x08)				/*�ж�ǿ�ƴ����Ĵ���-BSPMECBASE*/			
	#define BSP_INTR_PEND		(BSP_AMBA_INTR_BASEADDR+0x04)				/*�жϹ���Ĵ���-BSPMECBASE*/
		
	/*����CACHEˢ��ʹ��/��ֹ--ENABLE:ʹ��;DISABLE:��ֹ*/
	#define	CACHE_D_REFRESH			ENABLE			
	
	/*ָ��CACHEˢ��ʹ��/��ֹ--ENABLE:ʹ��;DISABLE:��ֹ*/
	#define	CACHE_I_REFRESH			ENABLE	
	
	/*----------------------�Զ�����CPU�Ĵ���ʵ������ֵ----------------------*/
	
	/*CACHE���ƼĴ���*/		
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
	
	/*����Ĵ���*/	                            	
	#define BSPFSR_INIT	(	(NVM << 27)|	\
	 						(OFM << 26)|	\
	 						(UFM << 25)|	\
	 						(DZM << 24)|	\
	 						(NXM << 23))

#endif	/* __BSP_SOC_2008_H__ */
