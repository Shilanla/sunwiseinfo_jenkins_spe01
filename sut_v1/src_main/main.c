#include "sys.h"
#include "io.h"
#include "controller.h"

void AppIntHandle1(void)
{
	QuerySensorData();

	controller_step();

	SendCmdData();

	/* ң�ؽ���ִ�� */
	if (*ADDR_TC_CTRL == 0x1)
	{
		*ADDR_TC_CTRL = 0;
		ParseTcData(ADDR_TC_DATA);
	}

	/* ң�������� */
	PakTmData(ADDR_TM_DATA);
	*ADDR_TM_CTRL = 0x1;

	return;
}

void AppIntHandle2(void)
{
	return;
}

void AppIntHandle3(void)
{
	return;
}

void AppIntHandle4(void)
{
	return;
}

void AppLoopTask(void)
{
	return;
}

void AppInit(void)
{
	InitIO();
	controller_initialize();
	Interrupt_Initializes(0x1);

	return;
}

