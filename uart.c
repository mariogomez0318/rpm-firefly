#include <xc.h>
#include "uart.h"
#include "pps.h"

#define FCY 4000000UL
#define BAUD 9600UL
#define U1BRG_VALUE ((FCY/(16UL*BAUD))-1UL)
#include <libpic30.h>

void UART1_Init(void)
{
    U1MODE = 0;
    U1BRG  = U1BRG_VALUE;

    U1STA = 0;
    U1MODEbits.UARTEN = 1;
    __delay_us(10);
    U1STAbits.UTXEN = 1;
}

void UART1_Putc(char c)
{
    while(U1STAbits.UTXBF);
    U1TXREG = c;
}

void UART1_Puts(const char *s)
{
    while(*s)
        UART1_Putc(*s++);
}
