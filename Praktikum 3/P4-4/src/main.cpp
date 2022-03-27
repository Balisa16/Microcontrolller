#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
  PORTD &= ~(1<<4);
  _delay_ms(5000);
  PORTD |= (1<<4);
}

ISR(INT1_vect)
{
  PORTD |= (1<<4);
  _delay_ms(5000);
  PORTD &= ~(1<<4);
}

int main(void)
{
  DDRD = 0xD0;
  DDRB = 0x3F; 
  PORTD |= _BV(PD2);
  PORTD |= _BV(PD3);
  EIMSK |= (1<<INT0) | (1<<INT1);
  EICRA |= _BV(ISC01);
  EICRA |= _BV(ISC11);
  sei();
  while (true)
  {
    PORTB = 0x3F;
    PORTD |= (1<<PD7) | (1<<PD6);
    for (int i = 0; i <= 7; i++)
    {
      if(i >= 6)
      {
        if (i==6)
          PORTB = 0X3F;
        PORTD = ~(1<<i);
      }
      else
        PORTB = ~(1<<i);
      _delay_ms(500);
    }
  }
}