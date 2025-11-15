#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>

extern volatile uint16_t pulse_count;
extern volatile uint16_t rpm;

void INT1_Init(void);
void Timer1_Init(void);

#endif
