// added untuk linker this option -Wl,-u,vfprintf -lprintf_flt
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#define FDEV_SETUP_STREAM ( put,
get,
rwflag )
#define UART_BAUD_RATE 9600
#define UART_BAUD_REGISTERS (((F_CPU / (UART_BAUD_RATE * 16UL))) - 1)
int uart_putchar(char c, FILE *stream);
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL,_FDEV_SETUP_WRITE);
// FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
void usartInit(void);
int main(void)
{
  float number = 123.45;
  usartInit();
  while (1)
  {
    fprintf(&mystdout, "**fprintf Test \n\r");
    // _delay_ms(500);
    // fprintf(&mystdout, "%f\n\r", number);
    // _delay_ms(500);
    printf("Hello World\n\r");
    _delay_ms(500);
    printf("%f\n\r", number);
    _delay_ms(500);
  }
  return 1;
}
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