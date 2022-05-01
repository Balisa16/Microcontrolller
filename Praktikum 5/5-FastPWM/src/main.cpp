// Tugas No.2 : PWM Fast Non Inverting
// TOP = OCRA;
#include <avr/io.h>
int main(void)
{
  DDRD |= _BV(PD5) | _BV(PD6);                                // activate PWM output
  TCCR0B = _BV(CS00);                             // prescaller 1 dan fastPWM
  TCCR0A |= _BV(WGM00) | _BV(WGM01) | _BV(COM0B1);// non inverting
  TCCR0B |= _BV(WGM02);
  OCR0A = 150;
  OCR0B = 30;
  while (true)
  {
  }
} 