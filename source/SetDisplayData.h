#ifndef _SETDISPLAYDATA_H_
#define _SETDISPLAYDATA_H_


#define  LED_AM       PORTA //RC5
#define  LED_PM       PORTA //RC6

#define  Led_Data1    display2[0]   //数码管1
#define  Led_Data2    display2[1]   //数码管2
#define  Led_Data3    display2[2]   //数码管3
#define  Led_Data4    display2[3]   //数码管4

#define  ON_LED_MudFlash()    Led_Data2 |= (1<<7)
#define  OFF_LED_MudFlash()   Led_Data2 &= ~(1<<7)


void Hex_To_Bcd();
void cheakTime(void);
void SetDisplayData(void);

#endif