#include "display.h"


unsigned char display2[4];
unsigned char i;
unsigned char blink_flag = 0;
unsigned char SEG_state = 1;

const unsigned char SmgTab[]={
	SMG_0,
	SMG_1,
	SMG_2,
	SMG_3,
	SMG_4,
	SMG_5,
	SMG_6,
	SMG_7,
	SMG_8,
	SMG_9,
	SMG_A,
	SMG_B,
	SMG_C,
	SMG_D,
	SMG_E,
	SMG_F,
	SMG_Off
};

const unsigned char COM_P[]={W_COM1,W_COM2,W_COM3,W_COM4};

void DelayXms(unsigned int x)
{
	unsigned int i,j;
	for(i=x;i>0;i--)
	{
		for(j=153;j>0;j--);
	}
}

void TurnOff_AllLED(void)
{
	// P_SEG &= SMG_Off;
    P_COM1 |= (1<<W_COM1);
	P_COM2 |= (1<<W_COM2);
	P_COM3 |= (1<<W_COM3);
	P_COM4 |= (1<<W_COM4);
}

void display_time(unsigned char hour,unsigned char min)  //显示时间
{

    display2[0] = SmgTab[hour/10];  //左一，小时大于10时显示
    display2[1] = SmgTab[hour%10];
    display2[2] = SmgTab[min/10];
    display2[3] = SmgTab[min%10];
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
	}
	else	//不闪烁，正常显示
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
	
}