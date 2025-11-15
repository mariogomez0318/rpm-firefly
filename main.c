#include <xc.h>
#include <stdint.h>
#include <stdio.h>


#include "pps.h"
#include "uart.h"
#include "pwm.h"
#include "adc.h"
#include "interrupts.h"
#include "tmp36.h"

#define FCY 4000000UL
#include <libpic30.h>

#pragma config FWDTEN = OFF
#pragma config JTAGEN = OFF
#pragma config POSCMOD = NONE
#pragma config FNOSC = FRC
#pragma config IESO   = OFF
#pragma config OSCIOFNC = OFF

int main(void)
{
    CLKDIVbits.RCDIV = 0;

    PPS_Init();
    UART1_Init();
    PWM_OC1_Init();
    ADC_Init();
    INT1_Init();
    Timer1_Init();

    uint16_t adc_value;
    uint16_t duty;
    char buffer[32];

    while(1)
    {
        adc_value = ADC_Read();

        duty = (adc_value * 2000UL) / 1023UL;
        if(duty >= 999) duty = 999;
        OC1R = duty;

        float temp = TMP36_GetTemperature(adc_value);

        sprintf(buffer, "T:%.2fC RPM:%u\r\n", temp, rpm);
        UART1_Puts(buffer);

        __delay_ms(100);
    }
    return 0;
}
