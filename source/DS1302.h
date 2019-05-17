#ifndef _DS1302_H_
#define _DS1302_H_


void ds1302_write_byte(unsigned char addr, unsigned char d);
unsigned char ds1302_read_byte(unsigned char addr);//śÁŇť×Ö˝Ú
void ds1302_write_time(unsigned char hour, unsigned char min);
unsigned char* ds1302_read_time(void);
void ds1302_init(void);
#endif