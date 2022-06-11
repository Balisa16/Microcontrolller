
#ifndef USART_H_
#define USART_H_
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
#endif /* USART_H_ */