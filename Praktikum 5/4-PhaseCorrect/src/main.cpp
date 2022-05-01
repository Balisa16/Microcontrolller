// Tugas No.1 : PWM Phase Correct
// TOP = OCRA;

#include <avr/io.h>

int main()
{
  DDRD = _BV(PD5);                    // activate PWM output
  TCCR0B = _BV(CS00);                 // prescaller 1
  TCCR0A |= _BV(COM0B1);              // Phasa correct mode & non inverting
  TCCR0A |= _BV(WGM00);
  TCCR0B |= _BV(WGM02);              // Phasa correct mode 8 bit
  OCR0A = 50;
  OCR0B = 15;
  while (true)
  {
  }
}