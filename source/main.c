#include "main.h"

uchar MainTime = 0;	//主函数运行定时器
uchar B_MainLoop = 0;	//主函数开关

uchar hour = 0;	//时钟小时
uchar min = 0;	//时钟分钟

uchar counter = 0;	

extern unsigned char SEG_state;	//晶码管开关状态
extern unsigned char blink_flag;

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
	//  ds1302_init();  //初始化时钟
	//  ReadData();  //读设定的时间数据
    //  ds1302_read_time();//读取DS1302的时间
	//  Check_SetClock();   //将DS1302读取到的时钟赋值给显示

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
    if(++MainTime >= 25)  //3.125ms
	{
		MainTime = 0;
		B_MainLoop = 1;
	}
}

void main(void)
{
    init_devices();
    TurnOff_AllLED();
    while (1)
    {
        if (B_MainLoop)
        {
            B_MainLoop = 0;
            Key_scan();
            display_time(hour,min);
        }
    }
}