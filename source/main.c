#include "main.h"

unsigned int MainTime = 0;	//主函数运行定时器
uchar B_MainLoop = 0;	//主函数开关
// uchar SEG8_flag = 0;

uchar hour = 0;	//时钟小时
uchar min = 0;	//时钟分钟

uchar counter = 0;	

extern unsigned char SEG_state;	//晶码管开关状态
// extern unsigned char blink_flag;
extern unsigned char ALARM_flag;	//警报灯状态
extern unsigned char display2[4];	//显示
extern unsigned char sys_time[2];	//DS1302读出来的时间


void port_init(void)
{
	PORTA = 0x00;   
	PORTB = 0x00;
	PORTC = 0b00000001;
	PORTD = 0b10111111;

	DDRA = 0b11111111;
	DDRB = 0b11111111;
    DDRC = 0b11111110;    
	DDRD = 0b11100001;    
}

void timer0_init(void)
{
	TCCR0 = 0x00; //stop
	TCNT0 = 0x83; //set count
	OCR0  = 0x7D;  //set compare
	TCCR0 = 0x02; //start timer
}

void init_devices(void)
{
	 //stop errant interrupts until set up
	 CLI(); //disable all interrupts
	 port_init();
	 timer0_init();
	 ds1302_init();  //初始化时钟
	//  ReadData();  //读设定的时间数据
     ds1302_read_time();//读取DS1302的时间
	//  Check_SetClock();   //将DS1302读取到的时钟赋值给显示
	min = sys_time[1];
	hour = sys_time[0];

	 MCUCR = 0x00;
	 GICR  = 0x00;
	 TIMSK = 0x01; //timer interrupt sources
	 SEI(); //re-enable interrupts
	 
	//  Rbeep = 3;
   	//  BuzzerTime = 100;
 //all peripherals are now initialized
}

#pragma interrupt_handler timer0_ovf_isr:iv_TIM0_OVF
void timer0_ovf_isr(void)
{
    TCNT0 = 0x83; //reload counter value
    if(++MainTime % 25 == 0)  //3.125ms
	{
		
		B_MainLoop = 1;
	}
	if (MainTime >= 200)
	{
		MainTime = 0;
		SEG_state = 1;
		if (ALARM_flag)
		{
			ALARM_flag = 0;
		}
		else
		{
			ALARM_flag = 1;
		}
	}
}

void main(void)
{
    init_devices();
    TurnOff_AllLED();
	Hex_To_Bcd();
    while (1)
    {
        if (B_MainLoop)
        {
            B_MainLoop = 0;
            Key_scan();
            //display_time(hour,min);
			display();
        }
    }
}