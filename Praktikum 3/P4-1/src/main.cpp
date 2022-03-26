#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/*
Nama      : Sander Antonius Balisa
NRP       : 2120600053
Kelas     : 2 D4 EB 
*/

ISR(INT0_vect)
{
  PORTD &= ~(1<<4);
  _delay_ms(1000);
  PORTD |= (1<<4);
}

int main(void)
{
  // Inilisasi PORT Output
  DDRD = 0xD0;          // ==>1101 0000 = D0
  DDRB = 0x3F;          // ==>0011 1111 = 3F

  PORTD |= _BV(PD2);    // Pin INT0 PD2 Pull-Up
  EIMSK |= (1<<INT0);   // Enable interrupt
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