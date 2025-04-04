#include "device_driver.h"

static void Sys_Init(void)
{
	Clock_Init();
	LED_Init();
	Key_Poll_Init();
	Uart_Init(115200);
}

void Main(void)
{
	volatile int i;

	Sys_Init();
	Uart_Printf("ADC Test\n");

	Adc_Cds_Init();

	for(;;)
	{
		Adc_Start();
		while(!Adc_Get_Status());
		Uart1_Printf("0x%.4X\n", Adc_Get_Data());
		for(i=0; i<0x400000; i++);
	}
}


//cds 0x000 ~ 0xfff 2^12 4개로 나눠서 밝기에 따른 조절