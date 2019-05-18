#include "main.h"

//用于保存定时时间
void Memory_Write(unsigned int Addr,unsigned char Value)
{	
	EEARH = 0x00;
	while(EECR & (1 << EEWE));
	EEARL = Addr;
	EEDR = Value;
	EECR |= (1 << EEMWE);
	EECR |= (1 << EEWE);
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