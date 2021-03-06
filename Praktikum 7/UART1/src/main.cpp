#include <avr/io.h>
#include <stdlib.h>
#include <avr/delay.h>
//----------- Global variable here ----
#define BAUDRATE 9600
#define VBAUDRATE (F_CPU / ((unsigned long)BAUDRATE * 16) - 1)
#define BAUDH VBAUDRATE / 256
#define BAUDL VBAUDRATE % 256
// Global function here
void USARTInit(void);
volatile unsigned char USARTGetChar(void);
void USARTPutChar(unsigned char data);
void USARTPutStr(char *s);
void USARTBanner(void);

int main(void)
{
  // unsigned char tanda;
  USARTInit();
  USARTBanner();
  while (1)
  {
    USARTPutChar('U');
    _delay_ms(100);
  }
}
void USARTInit(void)
{
  // setup baudrate
  UBRR0H = BAUDH;
  UBRR0L = BAUDL;
  // Enable Receiver and Transmitter
  UCSR0B = (1 << RXEN0) | (1   << TXEN0);
  // Set frame format: 8data, 1stop bit
  UCSR0C = (0 << USBS0) | (3 << UCSZ00);
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