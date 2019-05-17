#include "main.h"

// extern unsigned char B_set_time = 0;
extern unsigned char blink_flag;    //是否闪烁
extern unsigned char SEG_state; //SEG开关状态
extern unsigned char display2[4];   //晶码管当前显示内容
unsigned char B_i;  //按钮序号
extern unsigned char hour;  //时钟小时
extern unsigned char min;   //时钟分钟
unsigned char ALARM_flag = 0;    //警报灯状态
unsigned char key_time[5] = {0,0,0,0,0}; //保持时间
unsigned char B_flag[5];    //按钮触发标记
unsigned char B_state[5] = {0,0,0,0,0};   //按钮功能标记

//传入所需要检测的针脚，进行当前按钮状态的检测
unsigned char get_key(unsigned char key_input)
{
    //存储两个按钮的状态机内状态和时间
    static unsigned char key_state[5] = {0,0,0,0,0} ,key_time[5] = {0,0,0,0,0}; 
    unsigned char key_press, key_return = 0;  //输入针脚当前信号，定义状态返回值  
    key_press = key_input;

    //对按下按钮进行序号标记
    if (key_input == key_clock)
    {
        B_i = 1;
    }
    else if(key_input == key_set)
    {
        B_i = 0;
    }
    else if (key_input == key_pre)
    {
        B_i = 2;
    }
    else if (key_input == key_ok)
    {
        B_i = 3;
    }
    else
    {
        B_i = 4;
    }
    //判断状态,状态机
    switch (key_state[B_i])
    {
    case key_state_0:   //按钮没有被触发
        if (key_press == 0) //按钮被触发
        {
            key_state[B_i] = key_state_1;   //按钮对应标记为确认态
        }
        break;
    case key_state_1:   //按钮确认态
        if (key_press == 0) //按钮是否被触发
        {
            key_state[B_i] = key_state_2;   //按钮依旧被触发进入点击状态
            key_time[B_i] = 0;  //下一状态可能会用到，所以进行计时器置零的操作
        }
        else
        {
            //没有保存触发，判定为抖动，返回未触发态
            key_state[B_i] = key_state_0;
        }
        break;
    case key_state_2:   //按钮点击态
        if(key_press != 0)  //是否没有被按下
        {
            key_state[B_i] = key_state_0;   //没有再被按下，返回无触发态
            key_return = 1; //判定为点击按钮，标记为按钮进行了一次点击
        }
        //还在被按着，开始进行按下计时，当达到设定长按时间进行处理
        else if (++key_time[B_i] >= hold_time)
        {
            key_state[B_i] = key_state_3;   //标记为长按态
            key_time[B_i] = 0;  //计时器清零
            key_return = 2; //判定按钮进行一次长按，并标记状态
        }
        break;
    case key_state_3:   //按钮长按太
        if (key_press != 0) //是否没有被按下
        {
            key_state[B_i] = key_state_0;   //按钮抬起，返回无触发态
        }
        else
        {
            key_return = 2; //依然在进行长按，标记长按状态
            if (++key_time[B_i] >= 100)		// 按键时间计数
            {
                key_time[B_i] = 0;			// 按下时间>0.3s，清按键计数器
                key_return = 3;		// 输出"3"
            }
        }
        break;
    }
    return key_return;  //返回标记状态
}

//按钮状态轮询
void Key_scan(void)
{
    B_flag[1]=get_key(key_clock);   //访问clock按钮，获得状态
    B_flag[0]=get_key(key_set); //访问set按钮
    B_flag[2]=get_key(key_pre); //访问pre按钮
    B_flag[3]=get_key(key_cheak);
    B_flag[4]=get_key(key_ok);

    if (B_state[1] == 1)
    {
        if (B_flag[1] == 1) //点击clock
        {
            P_LED_AM &= ~(1 << W_LED_AM);     
            Hex_To_Bcd(hour,++min);
        }
        if (B_flag[1] == 3) //长按clock
        {
            P_LED_ALARM &= ~(1<< W_LED_ALARM);
            min += 10;
            Hex_To_Bcd(hour,min);
        }
        if (B_flag[0] == 1) //点击set
        {
            P_LED_PM &= ~(1 << W_LED_PM);
            B_state[1] = 0; //设置系统时间关闭
            blink_flag = 0;
        }
    }
    else if (B_state[0] == 1)
    {
        /* code */
    }
    else if (B_state[2] == 1)   //提前吃药，等等行程开关撞到
    {
        P_motor &= ~(1<<W_motor);   //打开电机
        if (B_flag[3] == 1) //行程开关
        {
            B_state[3] = 1;
            B_state[2] = 0;
            P_motor |= (1<<W_motor);   //关闭电机
        }
    }
    else if (B_state[3] == 1)   //等等ok键
    {
        if (ALARM_flag)
        {
            P_LED_ALARM |= (1<< W_LED_ALARM);
        }
        else
        {
            P_LED_ALARM &= ~(1<< W_LED_ALARM);
        }
        if (B_flag[4] == 1) //点击OK键
        {
            B_state[3] = 0;
            P_LED_ALARM &= ~(1<< W_LED_ALARM);
        }
    }
    else
    {
        if (B_flag[1] == 1) //点击clock
        {
           
        }
        if (B_flag[1] == 2) //长按clock
        {
            P_LED_ALARM |= (1<< W_LED_ALARM);
            blink_flag = 1; //晶码管开启闪烁
            B_state[1] = 1; //设置系统时间开启
        }
        if (B_flag[0] == 1) //点击set
        {
           
        }
        if (B_flag[2] == 1) //点击pre
        {
            P_LED_PM |= (1 << W_LED_PM);
            B_state[2] = 1;    //进入提前吃药模式
        }
    }   
}