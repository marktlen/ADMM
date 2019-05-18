#ifndef _EEPROM_H_
#define _EEPROM_H_

//预约时间在EEPROM内的存储位置
#define add_book_hour   0x00
#define add_book_min    0x10

void Memory_Write(unsigned int Addr,unsigned char Value);
unsigned char Memory_Read(unsigned int Addr);
void ReadData(void);

#endif