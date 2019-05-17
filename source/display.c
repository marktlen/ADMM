#include "display.h"


unsigned char display2[4];
unsigned char i;
unsigned char blink_flag = 0;
unsigned char SEG_state = 1;
unsigned char D_Kcount;

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
	P_SEG &= SMG_Off;
    P_COM1 |= (1<<W_COM1);
	P_COM2 |= (1<<W_COM2);
	P_COM3 |= (1<<W_COM3);
	P_COM4 |= (1<<W_COM4);
}

void display()  //显示时间
{

    P_COM1 |= (1<<4);
	P_COM2 |= (1<<5);
	P_COM3 |= (1<<6);
	P_COM4 |= (1<<7);
	P_SEG =0X00;
	switch(D_Kcount)	
	{
		case 1:
			
			if(Led_Data1 & 0x01)	{P_SEG1 |= 1<<0;}
			if(Led_Data1 & 0x02)	{P_SEG2 |= 1<<1;}
			if(Led_Data1 & 0x04)	{P_SEG3 |= 1<<2;}
			if(Led_Data1 & 0x08)	{P_SEG4 |= 1<<3;}
			if(Led_Data1 & 0x10)	{P_SEG5 |= 1<<4;}
			if(Led_Data1 & 0x20)	{P_SEG6 |= 1<<5;}
			if(Led_Data1 & 0x40)	{P_SEG7 |= 1<<6;}
			//if(Led_Data1 & 0x80)	{P_SEG8 = 1<<7;}
			P_COM1 &= ~(1<<4);
			break;
		case 2:
			
			
			if(Led_Data2 & 0x01)	{P_SEG1 |= 1<<0;}
			if(Led_Data2 & 0x02)	{P_SEG2 |= 1<<1;}
			if(Led_Data2 & 0x04)	{P_SEG3 |= 1<<2;}
			if(Led_Data2 & 0x08)	{P_SEG4 |= 1<<3;}
			if(Led_Data2 & 0x10)	{P_SEG5 |= 1<<4;}
			if(Led_Data2 & 0x20)	{P_SEG6 |= 1<<5;}
			if(Led_Data2 & 0x40)	{P_SEG7 |= 1<<6;}
			if(Led_Data2 & 0x80)	{P_SEG8 |= 1<<7;}
			P_COM2 &= ~(1<<5);																		 
			break;
		case 3:
			
			
			if(Led_Data3 & 0x01)	{P_SEG1 |= 1<<0;}
			if(Led_Data3 & 0x02)	{P_SEG2 |= 1<<1;}
			if(Led_Data3 & 0x04)	{P_SEG3 |= 1<<2;}
			if(Led_Data3 & 0x08)	{P_SEG4 |= 1<<3;}
			if(Led_Data3 & 0x10)	{P_SEG5 |= 1<<4;}
			if(Led_Data3 & 0x20)	{P_SEG6 |= 1<<5;}
			if(Led_Data3 & 0x40)	{P_SEG7 |= 1<<6;}
			//if(Led_Data1 & 0x80)	{P_SEG8 = 1<<7;}
			P_COM3 &= ~(1<<6);																 
			break;
		case 4:

			if(Led_Data4 & 0x01)	{P_SEG1 |= 1<<0;}
			if(Led_Data4 & 0x02)	{P_SEG2 |= 1<<1;}
			if(Led_Data4 & 0x04)	{P_SEG3 |= 1<<2;}
			if(Led_Data4 & 0x08)	{P_SEG4 |= 1<<3;}
			if(Led_Data4 & 0x10)	{P_SEG5 |= 1<<4;}
			if(Led_Data4 & 0x20)	{P_SEG6 |= 1<<5;}
			if(Led_Data4 & 0x40)	{P_SEG7 |= 1<<6;}
			//if(Led_Data1 & 0x80)	{P_SEG8 = 1<<7;}
			P_COM4 &= ~(1<<7);																	 
			break;
		default: break;
	}
	if(++D_Kcount > 4) D_Kcount = 1;
}