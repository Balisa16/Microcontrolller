// added untuk linker this option -Wl,-u,vfprintf -lprintf_flt
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <avr/io.h>
#include <util/delay.h>
#include "usart.h"
#include "usart.c"
int main(void)
{
  float number = 123.45;
  usartInit();
  USARTBanner();
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
