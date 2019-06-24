#include "bsp.h"

unsigned int ExtIntHandle[4];
extern void AppIntHandle1(void);
extern void AppIntHandle2(void);
extern void AppIntHandle3(void);
extern void AppIntHandle4(void);
extern void AppInit(void);
extern void AppLoopTask(void);

volatile int gg;

void BSP_Init_CPU(void)
{
	volatile unsigned int *cpu_mec;
	/* 存储器 */
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_MEMORY_BASEADDR);
	cpu_mec[0x0/4]=0x16fa4277;		//设置存储器控制寄存器1
	cpu_mec[0x4/4]=0x00081065;		//设置存储器控制寄存器2
	cpu_mec[0x8/4]=0x08000200;		//设置存储器控制寄存器3

	/* 时钟 */
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_TIMER_BASEADDR);
	cpu_mec[0x00/4] = 0x0000002c;	//设置预分频计数器
	cpu_mec[0x04/4] = 0x0000002c;	//设置预分频重载计数值
	
	cpu_mec[0x10/4] = 0xffffffff;	//设置定时器1的计数值
	cpu_mec[0x14/4] = 0xffffffff;	//设置定时器1的重载计数值
	cpu_mec[0x18/4] = 0x00000007;	//设置定时器1的控制字
	
	cpu_mec[0x30/4] = 0xffffffff;	//设置定时器3的计数值
	cpu_mec[0x34/4] = 0xffffffff;	//设置定时器3的重载计数值
	cpu_mec[0x38/4] = 0x00000000;	//设置定时器3的控制字

	cpu_mec[0x40/4] = 0xffffffff;	//设置定时器4的计数值
	cpu_mec[0x44/4] = 0xffffffff;	//设置定时器4的重载计数值
	cpu_mec[0x48/4] = 0x00000000;	//设置定时器4的控制字
	
	/* 禁止内部看门狗 */
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_WDT_BASEADDR);
	cpu_mec[0x8/4] = 0;										

	/* 串口 */
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_UART1_BASEADDR);
	cpu_mec[0x0C/4]=0x00000091;		//设置串口1的分频寄存器
	cpu_mec[0x08/4]=0x00000003;		//设置串口1的控制寄存器
	
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_UART2_BASEADDR);
	cpu_mec[0x0C/4]=0x00000091;		//设置串口2的分频寄存器
	cpu_mec[0x08/4]=0x00000003;		//设置串口2的控制寄存器

	/* GPIO */
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_GPIO_BASEADDR);
	cpu_mec[0x04/4]=0x00000000;		//设置GPIO端口数据寄存器	
	cpu_mec[0x08/4]=0x00000000;		//设置GPIO端口方向
	cpu_mec[0x0C/4]=0x000000f0;		//设置中断屏蔽（GPI是否产生中断）寄存器		  
	cpu_mec[0x10/4]=0x000000f0;		//设置中断极性寄存器		
	cpu_mec[0x14/4]=0x00000000;		//设置中断触发寄存器
	
	/* AHB总线状态寄存器初始化 */
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_AHB_BASEADDR);	
	cpu_mec[0x0/4] = 0;											//AHB总线状态寄存器清零
	return;
}

void Interrupt_Initializes(unsigned int flgInt)
{
	volatile unsigned int *cpu_mec;

	ExtIntHandle[0] = (unsigned int)AppIntHandle1;
	ExtIntHandle[1] = (unsigned int)AppIntHandle2;
	ExtIntHandle[2] = (unsigned int)AppIntHandle3;
	ExtIntHandle[3] = (unsigned int)AppIntHandle4;

	/* 中断 */
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_INTR_BASEADDR);
	cpu_mec[0x8/4] = 0;						//中断强制触发寄存器清零		
	cpu_mec[0x40/4] = (flgInt << 4);		//设置中断屏蔽寄存器

	return;
}

/*读当前GPT*/
unsigned int SYS_GetGPTTime(void)
{
	volatile unsigned int *mec = (volatile unsigned int *)BSPMECBASE;

	return mec[BSP_GPT_CR/4]; 	/*读当前GPT*/
}

/* 延时函数, dtm 延时时间, 当量是微秒 */
void SYS_Delay(unsigned int dtm)
{
	volatile unsigned int tmold;
	volatile unsigned int tmnew;
	volatile unsigned int tmdiff;
	volatile unsigned int *mec = (volatile unsigned int *)BSPMECBASE;

	tmold  = mec[BSP_GPT_CR/4]; 	/*读当前GPT*/

	tmdiff = 0;
	while ( tmdiff < dtm)
	{
		tmnew  = mec[BSP_GPT_CR/4]; 	/*读当前GPT*/

		if ( tmnew <=tmold )  /* GPT为减计数 */
		{
			tmdiff = tmold -tmnew;
		}
		else   /* 处理计数值大于32位的情况 */
		{
			tmdiff = 0xffffffff - tmnew + tmold +1;  /* 0xffffffff是32位处理器的最大值 */
		}
	}

	return;
}

void SysMain(void)
{
	BSP_Init_CPU();

	AppInit();

	while(1) 
	{
		AppLoopTask();
  	}
}
