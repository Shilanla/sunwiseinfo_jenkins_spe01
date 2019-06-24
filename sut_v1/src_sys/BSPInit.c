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
	/* �洢�� */
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_MEMORY_BASEADDR);
	cpu_mec[0x0/4]=0x16fa4277;		//���ô洢�����ƼĴ���1
	cpu_mec[0x4/4]=0x00081065;		//���ô洢�����ƼĴ���2
	cpu_mec[0x8/4]=0x08000200;		//���ô洢�����ƼĴ���3

	/* ʱ�� */
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_TIMER_BASEADDR);
	cpu_mec[0x00/4] = 0x0000002c;	//����Ԥ��Ƶ������
	cpu_mec[0x04/4] = 0x0000002c;	//����Ԥ��Ƶ���ؼ���ֵ
	
	cpu_mec[0x10/4] = 0xffffffff;	//���ö�ʱ��1�ļ���ֵ
	cpu_mec[0x14/4] = 0xffffffff;	//���ö�ʱ��1�����ؼ���ֵ
	cpu_mec[0x18/4] = 0x00000007;	//���ö�ʱ��1�Ŀ�����
	
	cpu_mec[0x30/4] = 0xffffffff;	//���ö�ʱ��3�ļ���ֵ
	cpu_mec[0x34/4] = 0xffffffff;	//���ö�ʱ��3�����ؼ���ֵ
	cpu_mec[0x38/4] = 0x00000000;	//���ö�ʱ��3�Ŀ�����

	cpu_mec[0x40/4] = 0xffffffff;	//���ö�ʱ��4�ļ���ֵ
	cpu_mec[0x44/4] = 0xffffffff;	//���ö�ʱ��4�����ؼ���ֵ
	cpu_mec[0x48/4] = 0x00000000;	//���ö�ʱ��4�Ŀ�����
	
	/* ��ֹ�ڲ����Ź� */
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_WDT_BASEADDR);
	cpu_mec[0x8/4] = 0;										

	/* ���� */
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_UART1_BASEADDR);
	cpu_mec[0x0C/4]=0x00000091;		//���ô���1�ķ�Ƶ�Ĵ���
	cpu_mec[0x08/4]=0x00000003;		//���ô���1�Ŀ��ƼĴ���
	
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_UART2_BASEADDR);
	cpu_mec[0x0C/4]=0x00000091;		//���ô���2�ķ�Ƶ�Ĵ���
	cpu_mec[0x08/4]=0x00000003;		//���ô���2�Ŀ��ƼĴ���

	/* GPIO */
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_GPIO_BASEADDR);
	cpu_mec[0x04/4]=0x00000000;		//����GPIO�˿����ݼĴ���	
	cpu_mec[0x08/4]=0x00000000;		//����GPIO�˿ڷ���
	cpu_mec[0x0C/4]=0x000000f0;		//�����ж����Σ�GPI�Ƿ�����жϣ��Ĵ���		  
	cpu_mec[0x10/4]=0x000000f0;		//�����жϼ��ԼĴ���		
	cpu_mec[0x14/4]=0x00000000;		//�����жϴ����Ĵ���
	
	/* AHB����״̬�Ĵ�����ʼ�� */
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_AHB_BASEADDR);	
	cpu_mec[0x0/4] = 0;											//AHB����״̬�Ĵ�������
	return;
}

void Interrupt_Initializes(unsigned int flgInt)
{
	volatile unsigned int *cpu_mec;

	ExtIntHandle[0] = (unsigned int)AppIntHandle1;
	ExtIntHandle[1] = (unsigned int)AppIntHandle2;
	ExtIntHandle[2] = (unsigned int)AppIntHandle3;
	ExtIntHandle[3] = (unsigned int)AppIntHandle4;

	/* �ж� */
	cpu_mec=(volatile unsigned int *)(BSPMECBASE+BSP_AMBA_INTR_BASEADDR);
	cpu_mec[0x8/4] = 0;						//�ж�ǿ�ƴ����Ĵ�������		
	cpu_mec[0x40/4] = (flgInt << 4);		//�����ж����μĴ���

	return;
}

/*����ǰGPT*/
unsigned int SYS_GetGPTTime(void)
{
	volatile unsigned int *mec = (volatile unsigned int *)BSPMECBASE;

	return mec[BSP_GPT_CR/4]; 	/*����ǰGPT*/
}

/* ��ʱ����, dtm ��ʱʱ��, ������΢�� */
void SYS_Delay(unsigned int dtm)
{
	volatile unsigned int tmold;
	volatile unsigned int tmnew;
	volatile unsigned int tmdiff;
	volatile unsigned int *mec = (volatile unsigned int *)BSPMECBASE;

	tmold  = mec[BSP_GPT_CR/4]; 	/*����ǰGPT*/

	tmdiff = 0;
	while ( tmdiff < dtm)
	{
		tmnew  = mec[BSP_GPT_CR/4]; 	/*����ǰGPT*/

		if ( tmnew <=tmold )  /* GPTΪ������ */
		{
			tmdiff = tmold -tmnew;
		}
		else   /* �������ֵ����32λ����� */
		{
			tmdiff = 0xffffffff - tmnew + tmold +1;  /* 0xffffffff��32λ�����������ֵ */
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
