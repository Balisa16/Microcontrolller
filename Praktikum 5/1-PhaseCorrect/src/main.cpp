// Percobaan 1-PWM Phase Correct 8 bit on timer 0
// TOP = 0XFF;
#include <avr/io.h>
int main(void)
{
  DDRD = _BV(PD6);                    // activate PWM output
  TCCR0B = _BV(CS00);                 // prescaller 1
  TCCR0A = _BV(WGM00) | _BV(COM0A1);  // Phasa correct mode & non inverting 
  OCR0A = 15;
  while (true)
  {
  }
}