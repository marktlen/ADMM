#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "main.h"

//4个COM
#define  P_COM1    PORTC 	//RB1  //RB3       //12     //数码管1(自左向右
#define  P_COM2    PORTC  //RA3  //RB1       //9       //数码管2
#define  P_COM3    PORTC	//RA2  //RC6       //8      //数码管3
#define  P_COM4    PORTC  	//RB5  //RA3       //6 //数码管4
#define P_COM PORTC

//COM接入针脚位置
#define W_COM1 4
#define W_COM2 5
#define W_COM3 6
#define W_COM4 7

#define  Led_Data1    display2[0]   //数码管1
#define  Led_Data2    display2[1]   //数码管2
#define  Led_Data3    display2[2]   //数码管3
#define  Led_Data4    display2[3]   //数码管4
//8个SEG
#define  P_SEG1   PORTB	//RA0 	//RC3    //11
#define  P_SEG2   PORTB	//RA1	 //RC5    //7
#define  P_SEG3   PORTB	//RB3 	//RE3    //4
#define  P_SEG4   PORTB		// RB6	 //RA1    //2
#define  P_SEG5   PORTB	//RB7	//RA2    //1
#define  P_SEG6   PORTB	//RE3	 //RC4    //10
#define  P_SEG7   PORTB	//RB4	 //RA4    //5
#define  P_SEG8   PORTB		// RB2 	//RA0    //3    
#define P_SEG   PORTB
#define W_SEG8 7    //时钟:灯位置

#define		SIGA		(unsigned char)0x01
#define		SIGB		(unsigned char)0x02
#define		SIGC		(unsigned char)0x04
#define		SIGD		(unsigned char)0x08
#define		SIGE		(unsigned char)0x10
#define		SIGF		(unsigned char)0x20
#define		SIGG		(unsigned char)0x40
#define		SIGM		(unsigned char)0x80


#define		SMG_0			SIGA|SIGB|SIGC|SIGD|SIGE|SIGF         	
#define		SMG_1			SIGB|SIGC                             	
#define		SMG_2			SIGA|SIGB|SIGD|SIGE|SIGG              	
#define		SMG_3			SIGA|SIGB|SIGC|SIGD|SIGG 
#define		SMG_4			SIGB|SIGC|SIGF|SIGG                   	
#define		SMG_5			SIGA|SIGC|SIGD|SIGF|SIGG              	
#define		SMG_6			SIGA|SIGC|SIGD|SIGE|SIGF|SIGG         	
#define		SMG_7			SIGA|SIGB|SIGC                        	
#define		SMG_8			SIGA|SIGB|SIGC|SIGD|SIGE|SIGF|SIGG    	
#define		SMG_9			SIGA|SIGB|SIGC|SIGD|SIGF|SIGG         	
#define		SMG_A			SIGA|SIGB|SIGC|SIGE|SIGF|SIGG         	
#define		SMG_B			SIGC|SIGD|SIGE|SIGF|SIGG              	
#define		SMG_C			SIGA|SIGD|SIGE|SIGF                   	
#define		SMG_D			SIGB|SIGC|SIGD|SIGE|SIGG              	
#define		SMG_E			SIGA|SIGD|SIGE|SIGF|SIGG              	
#define		SMG_F			SIGA|SIGE|SIGF|SIGG
#define		SMG_H			SIGB|SIGC|SIGG|SIGE|SIGF
#define		SMG_Off			(unsigned char)0


void TurnOff_AllLED(void);
void display(void);
void DelayXms(unsigned int x);

#endif