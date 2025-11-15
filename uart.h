#ifndef UART_H
#define UART_H

#include <stdint.h>

void UART1_Init(void);
void UART1_Putc(char c);
void UART1_Puts(const char *s);

#endif
