#include <xc.h>
#include "adc.h"

void ADC_Init(void)
{
    AD1CON1bits.ADON = 0;

    AD1PCFGbits.PCFG0 = 0;
    AD1CHSbits.CH0SA = 0;

    AD1CON2bits.VCFG = 0;

    AD1CON1bits.FORM = 0;
    AD1CON1bits.SSRC = 7;
    AD1CON1bits.ASAM = 1;

    AD1CON3bits.ADCS = 2;
    AD1CON3bits.SAMC = 2;

    AD1CON1bits.ADON = 1;
}

uint16_t ADC_Read(void)
{
    while(!AD1CON1bits.DONE);
    AD1CON1bits.DONE = 0;
    return ADC1BUF0;
}
