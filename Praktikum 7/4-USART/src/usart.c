#include "usart.h"
#include <avr/io.h>
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