#include "key.h"

// extern unsigned char B_set_time = 0;
extern unsigned char blink_flag;    //是否闪烁
extern unsigned char SEG_state; //SEG开关状态
extern unsigned char display2[4];
unsigned char B_i;
extern uchar hour;
extern uchar min;
unsigned char B_flag[5];
unsigned char B_state[5];

unsigned char get_key(unsigned char key_input)
{
    static unsigned char key_state[2] = {0,0} ,key_time[2] = {0,0};
    unsigned char key_press, key_return = 0;
    key_press = key_input;
    if (key_input == key_clock)
    {
        B_i = 1;
    }
    else
    {
        B_i = 0;
    }
    
    switch (key_state[B_i])
    {
    case key_state_0:
        if (key_press == 0)
        {
            key_state[B_i] = key_state_1;
        }
        break;
    case key_state_1:
        if (key_press == 0)
        {
            key_state[B_i] = key_state_2;
            key_time[B_i] = 0;
        }
        else
        {
            key_state[B_i] = key_state_0;
        }
        break;
    case key_state_2:
        if(key_press != 0)
        {
            key_state[B_i] = key_state_0;
            key_return = 1;
        }
        else if (++key_time[B_i] >= hold_time)
        {
            key_state[B_i] = key_state_3;
            key_time[B_i] = 0;
            key_return = 2;
        }
        break;
    case key_state_3:
        if (key_press != 0)
        {
            key_state[B_i] = key_state_0;
        }
        else
        {
            key_return = 2;
        }
        break;
    }
    return key_return;
}

void Key_scan(void)
{
    B_flag[1]=get_key(key_clock);
    if (B_flag[1] == 1)
    {
        P_LED_AM |= (1 << W_LED_AM);
    }
    if (B_flag[1] == 2)
    {
        P_LED_ALARM |= (1<< W_LED_ALARM);
        blink_flag = 1;
    }
    B_flag[0]=get_key(key_set);
    if (B_flag[0] == 1)
    {
        P_LED_PM |= (1 << W_LED_PM);
    }
    
    
}