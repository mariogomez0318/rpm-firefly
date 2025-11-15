#include <xc.h>
#include "interrupts.h"

#define PULSOS_POR_REV 4000

volatile uint16_t pulse_count = 0;
volatile uint16_t rpm = 0;

void INT1_Init()
{
    INTCON2bits.INT1EP = 1;
    IPC5bits.INT1IP = 6;
    IFS1bits.INT1IF = 0;
    IEC1bits.INT1IE = 1;
}

void __attribute__((interrupt, no_auto_psv)) _INT1Interrupt(void)
{
    pulse_count++;
    IFS1bits.INT1IF = 0;
}

void Timer1_Init(void)
{
    T1CON = 0;
    TMR1 = 0;

    PR1 = 1562;
    T1CONbits.TCKPS = 3;
    T1CONbits.TON = 1;

    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    IPC0bits.T1IP = 5;
}

void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
    uint16_t p = pulse_count;
    pulse_count = 0;

    rpm = (p * 600UL) / PULSOS_POR_REV;

    IFS0bits.T1IF = 0;
}
