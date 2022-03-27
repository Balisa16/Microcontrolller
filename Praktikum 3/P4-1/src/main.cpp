#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
  PORTD &= ~(1<<4);
  _delay_ms(1000);
  PORTD |= (1<<4);
}

int main(void)
{
  DDRD = 0xD0;
  DDRB = 0x3F;
  PORTD |= _BV(PD2);
  EIMSK |= (1<<INT0);
  EICRA |= (1<<ISC01) | (1<<ISC00);
  sei();
  while ((true))
  {
    PORTB = 0x3F;
    PORTD |= (1<<PD7) | (1<<PD6);
    for (int i = 0; i <= 7; i++)
    {
      if(i >= 6)
      {
        if (i==6)
          PORTB |= (1<<5);
        PORTD = ~(1<<i);
      }
      else
        PORTB = ~(1<<i);
      _delay_ms(500);
    }
  }
}