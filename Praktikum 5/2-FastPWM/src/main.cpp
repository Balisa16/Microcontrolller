// Percobaan 2-PWM Fast 8 bit on timer 0
// TOP = 0XFF;
#include <avr/io.h>
int main(void)
{
  DDRD = _BV(PD5);                                // activate PWM output
  TCCR0B = _BV(CS00);                             // prescaller 1 dan fastPWM
  TCCR0A = _BV(WGM00) | _BV(WGM01) | _BV(COM0A1); // non inverting
  OCR0A = 200;
  while (true)
  {
  }
}