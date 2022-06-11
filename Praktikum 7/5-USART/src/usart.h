#ifndef USART_H_
#define USART_H_
#define UART_BAUD_RATE 9600
#define UART_BAUD_REGISTERS (((F_CPU / (UART_BAUD_RATE * 16UL))) - 1)
int uart_putchar(char c, FILE *stream);
// static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL,_FDEV_SETUP_WRITE);
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
void usartInit(void);
volatile unsigned char USARTGetChar(void);
void USARTPutChar(unsigned char data);
void USARTPutStr(char *s);
void USARTBanner(void);
#endif /* USART_H_ *