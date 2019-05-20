#include "main.h"

extern unsigned char display2[4];	//数码管显示
extern unsigned char min;
extern unsigned char hour;
unsigned char AP_Flag = 0;	//为0时亮AM灯,为1时亮PM灯

//字符集
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

//确保时间在12小时和59分钟以内，调整AM和PM灯，赋予需要显示的字符
void Hex_To_Bcd(void)
{
	if (min >= 60)
	{
		hour += min/60;
		min = 0;
	}
	if ((hour/12)%2)
	{
		AP_Flag = 0;
	}
	else
	{
		AP_Flag = 1;
	}
	
	
	if (hour > 12)
	{
		hour %= 13;
		display2[0] = SmgTab[SMG_Off];
	}
	if (hour/10 > 0)
	{
		display2[0] = SmgTab[hour/10];
	}
	else
	{
		display2[0] = SmgTab[SMG_Off];
	}
	display2[1] = SmgTab[hour%10];
	display2[2] = SmgTab[min/10];
	display2[3] = SmgTab[min%10];
}