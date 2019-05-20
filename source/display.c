#include "main.h"


unsigned char display2[4];	//显示存储
unsigned char i;	//循环用
unsigned char blink_flag = 0;	//闪烁标记
unsigned char SEG_state = 1;	//SEG开关状态
extern unsigned char ALARM_flag;	//警报灯闪烁
extern unsigned char AP_Flag;	//AM,PM灯标记
// unsigned char D_Kcount = 0;

const unsigned char COM_P[]={W_COM1,W_COM2,W_COM3,W_COM4};

//延时函数
void DelayXms(unsigned int x)
{
	unsigned int i,j;
	for(i=x;i>0;i--)
	{
		for(j=153;j>0;j--);
	}
}

//关闭所有数码管
void TurnOff_AllLED(void)
{
	P_SEG &= SMG_Off;
    P_COM1 |= (1<<W_COM1);
	P_COM2 |= (1<<W_COM2);
	P_COM3 |= (1<<W_COM3);
	P_COM4 |= (1<<W_COM4);
}

//显示时间，控制数码管和AM、PM灯状态
void display(void)
{
	if (blink_flag == 1)	//是否闪烁
	{
		if (SEG_state)	//在闪烁时，数码管状态
		{
			for (i = 0; i < 4; i++)
			{
				P_COM &= ~(1<<COM_P[i]);
				P_SEG |= display2[i];
				DelayXms(5);
				P_SEG &= SMG_Off;
				P_COM |= (1<<COM_P[i]);
			}
		}
		else
		{
			TurnOff_AllLED();
		}
	}
	else	//不闪烁，正常显示
	{
		for (i = 0; i < 4; i++)
		{
			P_COM &= ~(1<<COM_P[i]);
			P_SEG |= display2[i];
			P_SEG8 |= (1<<W_SEG8);
			DelayXms(5);
			P_SEG &= SMG_Off;
			P_COM |= (1<<COM_P[i]);
		}
	}
	if (AP_Flag)	//AM和PM灯的切换
	{
		P_LED_PM |= (1 << W_LED_PM);
		P_LED_AM &= ~(1 << W_LED_AM);
	}
	else
	{
		P_LED_AM |= (1 << W_LED_AM);
		P_LED_PM &= ~(1 << W_LED_PM);
	}
}