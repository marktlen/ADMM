#include "main.h"

extern unsigned char bookTime[2];   //预约时间

//用于保存定时时间
void Memory_Write(unsigned int Addr,unsigned char Value)
{	
	EEARH = 0x00;	//高位地址置零
	while(EECR & (1 << EEWE));	//等待EEWE=0
	EEARL = Addr;
	EEDR = Value;
	EECR |= (1 << EEMWE);	//EEPROM主写使能
	EECR |= (1 << EEWE);	//EEPROM写使能
}

/***********************************************
函数名称：Memory_Read
函数功能：读数据/程序寄存器
入口参数：Addr - 读取地址
出口参数：返回读取地址相应数值
备注：
************************************************/
unsigned char Memory_Read(unsigned int Addr)
{
	unsigned char value;

	while(EECR & (1 << EEWE));
	EEARH = 0x00;
	EEARL = Addr ++;
	EECR |= (1 << EERE);
	value = EEDR;

	return value;
}

void ReadData(void)
{
	bookTime[0] = Memory_Read(add_book_hour);
	bookTime[1] = Memory_Read(add_book_min);
}