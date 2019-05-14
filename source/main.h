#ifndef _MAIN_H_
#define _MAIN_H_
#include <iom16v.h>
#include <macros.h>
#include <eeprom.h>
#include "key.h"
#include "display.h"

#define uchar unsigned char
#define uint unsigned int

void port_init(void);
void timer0_init(void);
void init_devices(void);
void timer0_ovf_isr(void);

#endif