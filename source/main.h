#ifndef _MAIN_H_
#define _MAIN_H_
#include <iom16v.h>
#include <macros.h>
#include <eeprom.h>
#include "SetDisplayData.h"
#include "key.h"
#include "display.h"
#include "DS1302.h"
#include "EEPROM.h"

//这个省事的东西没怎么用啊
#define uchar unsigned char
#define uint unsigned int

//LED接入位置
#define P_LED_ALARM PORTA
#define P_LED_AM PORTA
#define P_LED_PM PORTA
#define W_LED_ALARM 4
#define W_LED_AM 5
#define W_LED_PM 6

#define P_BOOZ PORTA
#define W_BOOZ 1

//电机接入位置
#define P_motor PORTD
#define W_motor 0

void port_init(void); //IO初始化
void timer0_init(void); //timer0初始化
void init_devices(void);    //单片机环境初始化
void timer0_ovf_isr(void);  //timer0溢出中断

#endif