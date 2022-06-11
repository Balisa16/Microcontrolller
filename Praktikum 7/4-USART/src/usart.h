#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <avr/io.h>
#ifndef USART_H_
#define USART_H_
#define UART_BAUD_RATE 9600
#define UART_BAUD_REGISTERS (((F_CPU / (UART_BAUD_RATE * 16UL))) - 1)
int uart_putchar(char c, FILE *stream);
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
void usartInit(void);
#endif /* USART_H_ */