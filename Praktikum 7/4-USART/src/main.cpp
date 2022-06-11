// added untuk linker this option -Wl,-u,vfprintf -lprintf_flt
#include <stdio.h>
#include "usart.c"
#include "usart.h"
#include <util/delay.h>
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
