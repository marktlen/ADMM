#include "main.h"

unsigned char sys_time[2];  //读出来的时间

/*复位脚*/
#define RST_CLR	 PORTD&=~(1<<7)             //RB7 = 0/*电平置低*/
#define RST_SET	 PORTD|=(1<<7)/*电平置高*/
#define RST_IN	 DDRD&=~(1<<7)/*方向输入*/
#define RST_OUT	 DDRD|=(1<<7)/*方向输出*/

/*双向数据*/
#define IO_CLR	PORTD&=~(1<<5)                //RB6 = 0/*电平置低*/
#define IO_SET	PORTD|=(1<<5)/*电平置高*/
#define IO_R	(PIND&(1<<5))  /*电平读取*/
#define IO_IN	DDRD&=~(1<<5) /*方向输入*/
#define IO_OUT	DDRD|=(1<<5)/*方向输出*/

/*时钟信号*/
#define SCK_CLR	PORTD&=~(1<<6)               //RB5 = 0/*时钟信号*/
#define SCK_SET	PORTD|=(1<<6)/*电平置高*/
#define SCK_IN	DDRD&=~(1<<6)/*方向输入*/
#define SCK_OUT	DDRD|=(1<<6)/*方向输出*/


#define ds1302_sec_add			0x80		//秒数据 写入地址
#define ds1302_min_add			0x82		//分数据 写入地址
#define ds1302_hr_add			0x84		//时数据 地址
#define ds1302_control_add		0x8e		//控制寄存器数据 写入地址

/*向DS1302写入一字节数据*/
void ds1302_write_byte(unsigned char addr, unsigned char d) 
{

	unsigned char i;
	RST_SET;					/*启动DS1302总线*/
	/*写入目标地址：addr*/
	IO_OUT;
	addr = addr & 0xFE;/*最低位置零*///最低位为0时表示写入数据
	for (i = 0; i < 8; i ++){		 //先写低位
		if (addr & 0x01){
			IO_SET;
		}
		else{
			IO_CLR;
		}
		SCK_SET;
		SCK_CLR;
		addr = addr >> 1;
	}
	/*写入数据：d*///先写低位
	IO_OUT;
	for (i = 0; i < 8; i ++) {
		if (d & 0x01) {
			IO_SET;
		}
		else {
			IO_CLR;
		}
		SCK_SET;
		SCK_CLR;
		d = d >> 1;
	}
	RST_CLR;					/*停止DS1302总线*/
}


/*从DS1302读出一字节数据*/
unsigned char ds1302_read_byte(unsigned char addr) 
{

	unsigned char i;
	unsigned char temp;
	RST_SET;					/*启动DS1302总线*/

	/*写入目标地址：addr*/
	IO_OUT;
	addr = addr | 0x01;/*最低位置高*///最低位为1时表示读出数据
	for (i = 0; i < 8; i ++) {
		if (addr & 0x01) {
			IO_SET;
			}
		else {
			IO_CLR;
			}
		SCK_SET;
		SCK_CLR;
		addr = addr >> 1;
		}
	
	/*输出数据：temp*/
	IO_IN;
	for (i = 0; i < 8; i ++) {
		temp = temp >> 1;
		if (IO_R) {
			temp |= 0x80;
			}
		else {
			temp &= 0x7F;
			}
		SCK_SET;
		SCK_CLR;
		}
	
	RST_CLR;					/*停止DS1302总线*/
	return temp;
}




/*向DS302写入时钟数据*/
void ds1302_write_time(unsigned char hour, unsigned char min)
{
	unsigned char mudA,mudB;
	//转换成BCD码再写入，如写入12，其实是要写入0001 0010
	mudA = hour/10;
	mudB = hour%10;
	//hour = mudA*16 + mudB;
	hour = (mudA<<4)|mudB;
	mudA = min/10;
	mudB = min%10;
	//min = mudA*16 + mudB;
	min = (mudA<<4)|mudB;
	
	ds1302_write_byte(ds1302_control_add,0x00);			//关闭写保护 
    //ds1302_write_byte(ds1302_sec_add,0x80);				//暂停
	//ds1302_write_byte(ds1302_sec_add,Sys_buf[2]);		//秒 
	ds1302_write_byte(ds1302_min_add,min);		//分
	ds1302_write_byte(ds1302_hr_add,hour);		//时 
	ds1302_write_byte(ds1302_control_add,0x80);         //打开写保护
	
	
	/*ds1302_write_byte(ds1302_sec_add,0x80);				//暂停 
	//ds1302_write_byte(ds1302_charger_add,0xa9);			//涓流充电 
	ds1302_write_byte(ds1302_year_add,time_buf[1]);		//年 
	ds1302_write_byte(ds1302_month_add,time_buf[2]);	//月 
	ds1302_write_byte(ds1302_date_add,time_buf[3]);		//日 
	ds1302_write_byte(ds1302_day_add,time_buf[7]);		//周 
	ds1302_write_byte(ds1302_hr_add,time_buf[4]);		//时 
	ds1302_write_byte(ds1302_min_add,time_buf[5]);		//分
	ds1302_write_byte(ds1302_sec_add,time_buf[6]);		//秒
	ds1302_write_byte(ds1302_day_add,time_buf[7]);		//周 
	ds1302_write_byte(ds1302_control_add,0x80);			//打开写保护 */
}

/*从DS302读出时钟数据*/
unsigned char* ds1302_read_time(void)  
{ 
    unsigned char i,tmpA,tmpB;

	//time_buf[1]=ds1302_read_byte(ds1302_sec_add);		//秒 
	
	sys_time[1]=ds1302_read_byte(ds1302_min_add);		//分
	sys_time[0]=ds1302_read_byte(ds1302_hr_add);		//时 
	//读出来的数码是BCD码，需要转换，如读出0001 0011，其实是13
	for(i=0;i<2;i++)
	{
		tmpA = sys_time[i]/16;
		tmpB = sys_time[i]%16;
		sys_time[i] = tmpA*10 + tmpB;
	}
	/*time_buf[1]=ds1302_read_byte(ds1302_year_add);		//年 
	time_buf[2]=ds1302_read_byte(ds1302_month_add);		//月 
	time_buf[3]=ds1302_read_byte(ds1302_date_add);		//日 
	//time_buf[4]=ds1302_read_byte(ds1302_hr_add);		//时 
	//time_buf[5]=ds1302_read_byte(ds1302_min_add);		//分 
	time_buf[6]=(ds1302_read_byte(ds1302_sec_add))&0x7F;//秒 
	time_buf[7]=ds1302_read_byte(ds1302_day_add);		//周 */
	return sys_time;
}

/*DS302初始化函数*/
void ds1302_init(void) 
{
	RST_CLR;			/*RST脚置低*/
	SCK_CLR;			/*SCK脚置低*/
	RST_OUT;			/*RST脚设置为输出*/
	SCK_OUT;			/*SCK脚设置为输出*/
}