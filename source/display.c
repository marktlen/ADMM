#include "display.h"


unsigned char display2[4];

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
	SMG_N
};

void TurnOff_AllLED(void)
{
    PORTC |= 0x0f;
}

void TurnOn_AllLED(void)
{
    PORTC |= 0xf0;
}

void display_time(unsigned char hour,unsigned char min)  //显示时间
{

    display2[0] = SmgTab[hour/10];  //左一，小时大于10时显示
    display2[1] = SmgTab[hour%10];
    display2[2] = SmgTab[min/10];
    display2[3] = SmgTab[min%10];
}