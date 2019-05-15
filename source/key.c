#include "key.h"

extern unsigned char B_set_time = 0;
extern unsigned char blink_flag;
extern unsigned char display2[4];
unsigned char B_i;
extern uchar hour;
extern uchar min;
unsigned char B_flag[5];
unsigned char B_state[5];

unsigned char get_key(unsigned char key_input)
{
    static unsigned char key_time = 0;
    unsigned char key_press, key_return = 0;
    key_press = key_input;
    switch (B_state[B_i])
    {
    case key_state_0:
        if (!key_press)
        {
            B_state[B_i] = key_state_1;
        }
        break;
    case key_state_1:
        if (!key_press)
        {
            B_state[B_i] = key_state_2;
            key_time = 0;
        }
        else
        {
            B_state[B_i] = key_state_0;
        }
        break;
    case key_state_2:
        if(key_press)
        {
            B_state[B_i] = key_state_0;
            key_return = 1;
        }
        else if (++key_time >= hold_time)
        {
            B_state[B_i] = key_state_3;
            key_time = 0;
            key_return = 2;
        }
        break;
    case key_state_3:
        if (key_press)
        {
            B_state[B_i] = key_state_0;
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
    B_i = 0;
    B_flag[B_i]=get_key(key_clock);
    if (get_key(key_clock) == 1)
    {
        P_LED_AM |= (1<<W_LED_AM);
    }
    
    B_i++;
    B_flag[B_i]=get_key(key_set);
    hour=B_flag[B_i];
    B_i++;
    B_flag[B_i]=get_key(key_pre);
    min=B_flag[B_i]*10;
    B_i++;
    B_flag[B_i]=get_key(key_ok);
    min=B_flag[B_i];
    B_i++;
    // if (get_key(key_set) == 1)
    // {
    //     P_LED_AM |= (1<<W_LED_AM);
    //     B_set_time = 0;
    // }
    // if (get_key(key_clock) == 1)
    // {
    //     P_LED_AM |= (1<<W_LED_AM);
    // }
    // if (get_key(key_clock) == 2 && B_set_time == 0)
    // {
    //     P_LED_PM |= (1<<W_LED_PM);
    //     B_set_time = 1;
    // }
    // if (B_set_time)
    // {
    //     P_LED_AM |= (1<<W_LED_AM);
    //     blink_flag = 1;
    // }
    
}