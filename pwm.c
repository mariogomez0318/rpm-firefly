#include <xc.h>
#include "pwm.h"

void PWM_OC1_Init(void)
{
    T2CONbits.TON = 0;     
    T2CONbits.TCKPS = 0;  
    TMR2 = 0;      
    PR2 = 0xFFFF; 
    T2CONbits.TON = 1;    

    OC1R = 0;
    OC1RS = 1000;

    OC1CON1bits.OCTSEL = 0b000; 
    OC1CON2bits.SYNCSEL = 0x1F; 
    OC1CON2bits.OCTRIG  = 0;
    OC1CON1bits.OCM = 0b110;    
}
