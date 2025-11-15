#include <xc.h>
#include "pps.h"

void PPS_Init(void)
{
    __builtin_write_OSCCONL(OSCCON & ~0x40);
    RPOR1bits.RP3R = 18;
    RPINR18bits.U1RXR = 8;
    RPOR4bits.RP9R = 3;
    RPINR0bits.INT1R = 7;
    __builtin_write_OSCCONL(OSCCON | 0x40);
}
