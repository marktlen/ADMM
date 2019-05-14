#ifndef _KEY_H_
#define _KEY_H_

#include "main.h"


//按钮接入针脚
#define key_cheak (PINC&(1<<0)) 
#define key_clock (PIND&(1<<1))
#define key_set (PIND&(1<<2))
#define key_pre (PIND&(1<<3))
#define key_ok (PIND&(1<<4))

//按键状态
#define key_state_0 0   //抬起
#define key_state_1 1   //确认态
#define key_state_2 2   //按下态
#define key_state_3 3   //长按态

//时间设置
#define hold_time 200 //长按时间
#define add_period 50 //按住时间每多少秒进行一次加时

extern unsigned char B_set_time;

unsigned char read_key(unsigned char key_input);  //指定获取按键状态

void Key_scan(void);    //扫描按键

#endif