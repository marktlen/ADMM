#ifndef __AVRDEF_H
#define __AVRDEF_H	1

#if !defined(_AVR)
#error "This file should only be used with ICCV7 for AVR"
#endif

#ifndef BIT
#define BIT(x)	(1 << (x))
#endif

#if !defined(flash)
#define flash	__flash		/* IAR compatibility */
#endif

#ifndef C_task
#define C_task
#endif

#define _asm	asm			/* old style */

#define WDR() 	asm("wdr")
#define SEI()	asm("sei")
#define CLI()	asm("cli")
#define NOP()	asm("nop")
#define SLEEP() asm("sleep");
#define _WDR() 	asm("wdr")
#define _SEI()	asm("sei")
#define _CLI()	asm("cli")
#define _NOP()	asm("nop")
#define _SLEEP() asm("sleep");

// For MegaAVR and XMega and access flash memory in any address
// any RAMP? registers used are saved/restored
unsigned char FlashReadByte(unsigned char ramp, unsigned addr);
unsigned FlashReadWord(unsigned char ramp, unsigned addr);
unsigned long FlashReadLWord(unsigned char ramp, unsigned addr);
void FlashReadBytes(unsigned char ramp, unsigned addr, unsigned char *buf, int n);

// For XMega, access data memory in any address
// any RAMP? registers used are saved/restored
unsigned char EDataReadByte(unsigned char ramp, unsigned addr);
unsigned EDataReadWord(unsigned char ramp, unsigned addr);
unsigned long EDataReadLWord(unsigned char ramp, unsigned addr);
void EDataReadBytes(unsigned char ramp, unsigned addr, unsigned char *buf, int n);

void EDataWriteByte(unsigned char ramp, unsigned addr);
void EDataWriteWord(unsigned char ramp, unsigned addr);
void EDataWriteLWord(unsigned char ramp, unsigned addr);
void EDataWriteBytes(unsigned char ramp, unsigned addr, unsigned char *buf, int n);

/* Serial Port Macros
 * for 4 Mhz crystal!
 * 
 * USE THE AppBuilder for UART initialization!!!
 */
#define BAUD9600	25
#define BAUD19K		12

/* NOT ALL (new) AVRs define these. Use the AppBuilder!!
 */
#define UART_TRANSMIT_ON()	UCR |= 0x8
#define UART_TRANSMIT_OFF()	UCR &= ~0x8
#define UART_RECEIVE_ON()	UCR |= 0x10
#define UART_RECEIVE_OFF()	UCR &= ~0x10

#define COMPRESS_DISABLE		NOCC_START()
#define COMPRESS_REENABLE		NOCC_END()

#define NOCC_START()	asm(".nocc_start")
#define NOCC_END()	asm(".nocc_end")

void _StackCheck(void);
void _StackOverflowed(char);

#endif
