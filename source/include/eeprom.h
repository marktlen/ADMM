#ifndef		__EEPROM__H
#define		__EEPROM__H

/* AVR EEPROM access functions */
#if !defined(_AVR)
#error "This file should only be used with ICCV7 for AVR"
#endif

/* IMPORTANT: The WRITE function waits until it is done before returning
 * and it disables interrupt!! Therefore they are not suitable for interrupt
 * intensive environment. For that, please use the rteeprom.c under 
 * c:\iccv7avr\examples.avr\ as examples.
 */

/* These defines are passed by the IDE as appropriate */
#if defined(_EE_EXTIO)
#define EEPROMread		EEPROMread_extIO
#define EEPROMwrite		EEPROMwrite_extIO
#define EEPROMReadBytes		EEPROMReadBytes_extIO
#define EEPROMWriteBytes	EEPROMWriteBytes_extIO

#elif defined(ATtiny13) || defined(ATtiny2313) || defined(ATtiny26) || defined(AT90S2313) || defined(AT90S2323) || defined(AT90S2333) || defined(AT90S2343) || defined(AT90S4414) || defined(AT90S4433) || defined(AT90S4434)

#define EEPROMread		EEPROMread_256
#define EEPROMwrite		EEPROMwrite_256
#define EEPROMReadBytes		EEPROMReadBytes_256
#define EEPROMWriteBytes	EEPROMWriteBytes_256
#endif

#define _256EEPROMread	EEPROMread_256
#define _256EEPROMwrite	EEPROMwrite_256

int EEPROMwrite( int location, unsigned char);
unsigned char EEPROMread( int);

void EEPROMReadBytes(int addr, void *ptr, int size);
void EEPROMWriteBytes(int addr, void *ptr, int size);

#define EEPROM_READ(addr, dst)		EEPROMReadBytes(addr, &dst, sizeof (dst))
#define EEPROM_WRITE(addr, src)		EEPROMWriteBytes(addr, &src, sizeof (src))

#endif
