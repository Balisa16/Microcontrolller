#include <avr/io.h>
#include <stdio.h>
#include "usart.h"
int uart_putchar(char c, FILE *stream)
{
    if (c == '\n')
        uart_putchar('\r', stream);
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
    return 0;
}
void usartInit(void)
{
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
    UCSR0C |= (0 << USBS0) | (1 << UCSZ00) | (1 << UCSZ01);
    UBRR0L = UART_BAUD_REGISTERS;
    stdout = &mystdout;
}
volatile unsigned char USARTGetChar(void)
{
    // Wait for data to be received
    while (!(UCSR0A & (1 << RXC0)))
        ;
    return UDR0;
}
void USARTPutChar(unsigned char data)
{
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    UDR0 = data;
}
void USARTPutStr(char *s)
{
    char i = 0;
    char c;
    while ((c = *(s + (i++))) != 0)
        USARTPutChar(c);
}
void USARTBanner(void)
{
    USARTPutStr("\n\r");
    USARTPutStr("**************************\n\r");
    USARTPutStr("***** test usart ******\n\r");
    USARTPutStr("**************************\n\r");
}