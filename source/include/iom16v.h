#ifndef __iom16v_h
#define __iom16v_h

/* ATmega16 header file for
 * ImageCraft ICCAVR compiler
 */

/* last changed 2004/12/19

   2008/07/03   checked for new chip M16A
                removed unused ADHSM defínition
 */

/* 2 wire serial interface */
#define TWBR	(*(volatile unsigned char *)0x20)
#define TWSR	(*(volatile unsigned char *)0x21)
#define  TWPS1    1
#define  TWPS0    0
#define TWCR	(*(volatile unsigned char *)0x56)
#define  TWINT    7
#define  TWEA     6
#define  TWSTA    5
#define  TWSTO    4
#define  TWWC     3
#define  TWEN     2
#define  TWIE     0
#define TWAR	(*(volatile unsigned char *)0x22)
#define  TWGCE    0
#define TWDR	(*(volatile unsigned char *)0x23)

/* ADC */
#define ADC 	(*(volatile unsigned int *)0x24)
#define ADCL	(*(volatile unsigned char *)0x24)
#define ADCH	(*(volatile unsigned char *)0x25)
#define ADCSR	(*(volatile unsigned char *)0x26)
#define ADCSRA	(*(volatile unsigned char *)0x26)
#define  ADEN     7
#define  ADSC     6
#define  ADATE    5
#define  ADFR     5    /*This definition was in old datasheet*/
#define  ADIF     4
#define  ADIE     3
#define  ADPS2    2
#define  ADPS1    1
#define  ADPS0    0
#define ADMUX	(*(volatile unsigned char *)0x27)
#define  REFS1    7
#define  REFS0    6
#define  ADLAR    5
#define  MUX4     4
#define  MUX3     3
#define  MUX2     2
#define  MUX1     1
#define  MUX0     0

/* Analog Comparator */
#define ACSR	(*(volatile unsigned char *)0x28)
#define  ACD      7
#define  ACBG     6
#define  ACO      5
#define  ACI      4
#define  ACIE     3
#define  ACIC     2
#define  ACIS1    1
#define  ACIS0    0

/* USART */
#define UBRRHI	(*(volatile unsigned char *)0x40)
#define UBRRH	(*(volatile unsigned char *)0x40)
#define  URSEL    7
#define UBRR	(*(volatile unsigned char *)0x29)
#define UBRRL	(*(volatile unsigned char *)0x29)
#define UCSRC	(*(volatile unsigned char *)0x40)
#define  URSEL    7
#define  UMSEL    6
#define  UPM1     5
#define  UPM0     4
#define  USBS     3
#define  UCSZ1    2
#define  UCSZ0    1
#define  UCPOL    0
#define UCSRB	(*(volatile unsigned char *)0x2A)
#define  RXCIE    7
#define  TXCIE    6
#define  UDRIE    5
#define  RXEN     4
#define  TXEN     3
#define  UCSZ2    2
#define  RXB8     1
#define  TXB8     0
#define UCSRA	(*(volatile unsigned char *)0x2B)
#define  RXC      7
#define  TXC      6
#define  UDRE     5
#define  FE       4
#define  DOR      3
#define  OVR      3    /*This definition differs from the databook*/
#define  PE       2
#define  U2X      1
#define  MPCM     0
#define UDR	(*(volatile unsigned char *)0x2C)

/* SPI */
#define SPCR	(*(volatile unsigned char *)0x2D)
#define  SPIE     7
#define  SPE      6
#define  DORD     5
#define  MSTR     4
#define  CPOL     3
#define  CPHA     2
#define  SPR1     1
#define  SPR0     0
#define SPSR	(*(volatile unsigned char *)0x2E)
#define  SPIF     7
#define  WCOL     6
#define  SPI2X    0
#define SPDR	(*(volatile unsigned char *)0x2F)

/* Port D */
#define PIND	(*(volatile unsigned char *)0x30)
#define DDRD	(*(volatile unsigned char *)0x31)
#define PORTD	(*(volatile unsigned char *)0x32)

/* Port C */
#define PINC	(*(volatile unsigned char *)0x33)
#define DDRC	(*(volatile unsigned char *)0x34)
#define PORTC	(*(volatile unsigned char *)0x35)

/* Port B */
#define PINB	(*(volatile unsigned char *)0x36)
#define DDRB	(*(volatile unsigned char *)0x37)
#define PORTB	(*(volatile unsigned char *)0x38)

/* Port A */
#define PINA	(*(volatile unsigned char *)0x39)
#define DDRA	(*(volatile unsigned char *)0x3A)
#define PORTA	(*(volatile unsigned char *)0x3B)

/* EEPROM */
#define EECR	(*(volatile unsigned char *)0x3C)
#define  EERIE    3
#define  EEMWE    2
#define  EEWE     1
#define  EERE     0
#define EEDR	(*(volatile unsigned char *)0x3D)
#define EEAR	(*(volatile unsigned int *)0x3E)
#define EEARL	(*(volatile unsigned char *)0x3E)
#define EEARH	(*(volatile unsigned char *)0x3F)

/* Watchdog Timer Control Register */
#define WDTCR	(*(volatile unsigned char *)0x41)
#define  WDTOE    4
#define  WDE      3
#define  WDP2     2
#define  WDP1     1
#define  WDP0     0

/* Timer/Counter 2 */
#define ASSR	(*(volatile unsigned char *)0x42)
#define  AS2      3
#define  TCN2UB   2
#define  OCR2UB   1
#define  TCR2UB   0
#define OCR2	(*(volatile unsigned char *)0x43)
#define TCNT2	(*(volatile unsigned char *)0x44)
#define TCCR2	(*(volatile unsigned char *)0x45)
#define  FOC2     7
#define  WGM20    6
#define  COM21    5
#define  COM20    4
#define  WGM21    3
#define  CS22     2
#define  CS21     1
#define  CS20     0

/* Timer/Counter 1 */
#define ICR1	(*(volatile unsigned int *)0x46)
#define ICR1L	(*(volatile unsigned char *)0x46)
#define ICR1H	(*(volatile unsigned char *)0x47)
#define OCR1B	(*(volatile unsigned int *)0x48)
#define OCR1BL	(*(volatile unsigned char *)0x48)
#define OCR1BH	(*(volatile unsigned char *)0x49)
#define OCR1A	(*(volatile unsigned int *)0x4A)
#define OCR1AL	(*(volatile unsigned char *)0x4A)
#define OCR1AH	(*(volatile unsigned char *)0x4B)
#define TCNT1	(*(volatile unsigned int *)0x4C)
#define TCNT1L	(*(volatile unsigned char *)0x4C)
#define TCNT1H	(*(volatile unsigned char *)0x4D)
#define TCCR1B	(*(volatile unsigned char *)0x4E)
#define  ICNC1    7
#define  ICES1    6
#define  WGM13    4
#define  WGM12    3
#define  CS12     2
#define  CS11     1
#define  CS10     0
#define TCCR1A	(*(volatile unsigned char *)0x4F)
#define  COM1A1   7
#define  COM1A0   6
#define  COM1B1   5
#define  COM1B0   4
#define  FOC1A    3
#define  FOC1B    2
#define  WGM11    1
#define  WGM10    0

/* Special Function I/O register */
#define SFIOR	(*(volatile unsigned char *)0x50)
#define  ADTS2    7
#define  ADTS1    6
#define  ADTS0    5
#define  ACME     3
#define  PUD      2
#define  PSR2     1
#define  PSR10    0

/* Oscillator Calibration */
#define OSCCAL	(*(volatile unsigned char *)0x51)
/* On-Chip Debug register */
#define OCDR	(*(volatile unsigned char *)0x51)

/* Timer/Counter 0 */
#define OCR0	(*(volatile unsigned char *)0x5C)
#define TCNT0	(*(volatile unsigned char *)0x52)
#define TCCR0	(*(volatile unsigned char *)0x53)
#define  FOC0     7
#define  WGM00    6
#define  COM01    5
#define  COM00    4
#define  WGM01    3
#define  CS02     2
#define  CS01     1
#define  CS00     0

/* MCU general */
#define MCUCSR	(*(volatile unsigned char *)0x54)
#define MCUSR	(*(volatile unsigned char *)0x54)
#define	 JTD      7
#define	 ISC2     6
#define	 JTRF     4
#define	 WDRF     3
#define  BORF     2
#define  EXTRF    1
#define  PORF     0
#define MCUCR	(*(volatile unsigned char *)0x55)
#define  SM2      7
#define  SE       6
#define  SM1      5
#define  SM0      4
#define  ISC11    3
#define  ISC10    2
#define  ISC01    1
#define  ISC00    0

/* SPM Conrol Register */
#define SPMCR	(*(volatile unsigned char *)0x57)
#define  SPMIE    7
#define  RWWSB    6
#define  RWWSRE   4
#define  BLBSET   3
#define  PGWRT    2
#define  PGERS    1
#define  SPMEN    0

/* Timer/Counter Interrupts */
#define TIFR	(*(volatile unsigned char *)0x58)
#define  OCF2     7
#define  TOV2     6
#define  ICF1     5
#define  OCF1A    4
#define  OCF1B    3
#define  TOV1     2
#define  OCF0     1
#define  TOV0     0
#define TIMSK	(*(volatile unsigned char *)0x59)
#define  OCIE2    7
#define  TOIE2    6
#define  TICIE1   5
#define  OCIE1A   4
#define  OCIE1B   3
#define  TOIE1    2
#define  OCIE0    1
#define  TOIE0    0

/* General Interrupts */
#define GIFR	(*(volatile unsigned char *)0x5A)
#define  INTF1    7
#define  INTF0    6
#define  INTF2    5
#define GICR	(*(volatile unsigned char *)0x5B)
#define  INT1     7
#define  INT0     6
#define  INT2     5
#define  IVSEL    1
#define  IVCE     0

/* Stack Pointer */
#define SP	(*(volatile unsigned int *)0x5D)
#define SPL	(*(volatile unsigned char *)0x5D)
#define SPH	(*(volatile unsigned char *)0x5E)

/* Status REGister */
#define SREG	(*(volatile unsigned char *)0x5F)


/* Port A bits */
#define  PORTA7   7
#define  PORTA6   6
#define  PORTA5   5
#define  PORTA4   4
#define  PORTA3   3
#define  PORTA2   2
#define  PORTA1   1
#define  PORTA0   0
#define  PA7      7
#define  PA6      6
#define  PA5      5
#define  PA4      4
#define  PA3      3
#define  PA2      2
#define  PA1      1
#define  PA0      0

#define  DDA7     7
#define  DDA6     6
#define  DDA5     5
#define  DDA4     4
#define  DDA3     3
#define  DDA2     2
#define  DDA1     1
#define  DDA0     0

#define  PINA7    7
#define  PINA6    6
#define  PINA5    5
#define  PINA4    4
#define  PINA3    3
#define  PINA2    2
#define  PINA1    1
#define  PINA0    0

/* Port B bits */
#define  PORTB7   7
#define  PORTB6   6
#define  PORTB5   5
#define  PORTB4   4
#define  PORTB3   3
#define  PORTB2   2
#define  PORTB1   1
#define  PORTB0   0
#define  PB7      7
#define  PB6      6
#define  PB5      5
#define  PB4      4
#define  PB3      3
#define  PB2      2
#define  PB1      1
#define  PB0      0

#define  DDB7     7
#define  DDB6     6
#define  DDB5     5
#define  DDB4     4
#define  DDB3     3
#define  DDB2     2
#define  DDB1     1
#define  DDB0     0

#define  PINB7    7
#define  PINB6    6
#define  PINB5    5
#define  PINB4    4
#define  PINB3    3
#define  PINB2    2
#define  PINB1    1
#define  PINB0    0

/* Port C bits */
#define  PORTC7   7
#define  PORTC6   6
#define  PORTC5   5
#define  PORTC4   4
#define  PORTC3   3
#define  PORTC2   2
#define  PORTC1   1
#define  PORTC0   0
#define  PC7      7
#define  PC6      6
#define  PC5      5
#define  PC4      4
#define  PC3      3
#define  PC2      2
#define  PC1      1
#define  PC0      0

#define  DDC7     7
#define  DDC6     6
#define  DDC5     5
#define  DDC4     4
#define  DDC3     3
#define  DDC2     2
#define  DDC1     1
#define  DDC0     0

#define  PINC7    7
#define  PINC6    6
#define  PINC5    5
#define  PINC4    4
#define  PINC3    3
#define  PINC2    2
#define  PINC1    1
#define  PINC0    0

/* Port D bits */
#define  PORTD7   7
#define  PORTD6   6
#define  PORTD5   5
#define  PORTD4   4
#define  PORTD3   3
#define  PORTD2   2
#define  PORTD1   1
#define  PORTD0   0
#define  PD7      7
#define  PD6      6
#define  PD5      5
#define  PD4      4
#define  PD3      3
#define  PD2      2
#define  PD1      1
#define  PD0      0

#define  DDD7     7
#define  DDD6     6
#define  DDD5     5
#define  DDD4     4
#define  DDD3     3
#define  DDD2     2
#define  DDD1     1
#define  DDD0     0

#define  PIND7    7
#define  PIND6    6
#define  PIND5    5
#define  PIND4    4
#define  PIND3    3
#define  PIND2    2
#define  PIND1    1
#define  PIND0    0


/* Lock and Fuse Bits with LPM/SPM instructions */

/* lock bits */
#define  BLB12    5
#define  BLB11    4
#define  BLB02    3
#define  BLB01    2
#define  LB2      1
#define  LB1      0

/* fuses low bits */
#define  BODLEVEL 7
#define  BODEN    6
#define  SUT1     5
#define  SUT0     4
#define  CKSEL3   3
#define  CKSEL2   2
#define  CKSEL1   1
#define  CKSEL0   0

/* fuses high bits */
#define  OCDEN    7
#define  JTAGEN   6
#define  SPIEN    5
#define  CKOPT    4
#define  EESAVE   3
#define  BOOTSZ1  2
#define  BOOTSZ0  1
#define  BOOTRST  0


/* Interrupt Vector Numbers */

#define iv_RESET        1
#define iv_INT0         2
#define iv_EXT_INT0     2
#define iv_INT1         3
#define iv_EXT_INT1     3
#define iv_TIMER2_COMPA 4
#define iv_TIMER2_COMP  4
#define iv_TIM2_COMP    4
#define iv_TIMER2_OVF   5
#define iv_TIM2_OVF     5
#define iv_TIMER1_CAPT  6
#define iv_TIM1_CAPT    6
#define iv_TIMER1_COMPA 7
#define iv_TIM1_COMPA   7
#define iv_TIMER1_COMPB 8
#define iv_TIM1_COMPB   8
#define iv_TIMER1_OVF   9
#define iv_TIM1_OVF     9
#define iv_TIMER0_OVF   10
#define iv_TIM0_OVF     10
#define iv_SPI_STC      11
#define iv_USART_RX     12
#define iv_USART_RXC    12
#define iv_USART0_RX    12
#define iv_USART0_RXC   12
#define iv_USART_DRE    13
#define iv_USART_UDRE   13
#define iv_USART0_DRE   13
#define iv_USART0_UDRE  13
#define iv_USART_TX     14
#define iv_USART_TXC    14
#define iv_USART0_TX    14
#define iv_USART0_TXC   14
#define iv_ADC          15
#define iv_EE_RDY       16
#define iv_EE_READY     16
#define iv_ANA_COMP     17
#define iv_ANALOG_COMP  17
#define iv_TWI          18
#define iv_TWSI         18
#define iv_INT2         19
#define iv_EXT_INT2     19
#define iv_TIMER0_COMPA 20
#define iv_TIMER0_COMP  20
#define iv_TIM0_COMP    20
#define iv_SPM_RDY      21
#define iv_SPM_READY    21

/* */

#endif
