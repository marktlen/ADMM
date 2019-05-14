#include "key.h"

extern unsigned char B_set_time = 0;
extern unsigned char display2[4];

unsigned char get_key(unsigned char key_input)
{
    static unsigned char key_state = 0, key_time = 0;
    unsigned char key_press, key_return = 0;
    key_press = key_input;
    switch (key_state)
    {
    case key_state_0:
        if (!key_press)
        {
            key_state = key_state_1;
        }
        break;
    case key_state_1:
        if (!key_press)
        {
            key_state = key_state_2;
            key_time = 0;
        }
        else
        {
            key_state = key_state_0;
        }
        break;
    case key_state_2:
        if(key_press)
        {
            key_state = key_state_0;
            key_return = 1;
        }
        else if (++key_time >= hold_time)
        {
            key_state = key_state_3;
            key_time = 0;
            key_return = 2;
        }
        break;
    case key_state_3:
        if (key_press)
        {
            key_state = key_state_0;
        }
        else
        {
            // if (++key_time >= add_period)
            // {
            //     key_time = 0;
            //     key_return = 2;
            // }
            key_return = 2;
        }
        break;
    }
    return key_return;
}

void Key_scan(void)
{
    if (get_key(key_clock) == 1)
    {
        PORTA |= (1<<5);
    }
    if (get_key(key_clock) == 2 && B_set_time == 0)
    {
        PORTA |= (1<<6);
        B_set_time = 1;
    }
    if (B_set_time)
    {
        PORTA |= (1<<4);
        // if (get_key(key_set) == 1)
        // {
        //     //保存时间
        //     B_set_time = 0;
        //     return;
        // }
        // if (get_key(key_clock) == 1)
        // {
        //     display2[0]++;
        // }
        // if (get_key(key_clock) == 2)
        // {
        //     display2[1]++;
        // }
    }
    if (get_key(key_set) == 1)
    {
        B_set_time = 0;
        PORTA |= (1<<5);
        PORTA |= (1<<6);
    }
    
}