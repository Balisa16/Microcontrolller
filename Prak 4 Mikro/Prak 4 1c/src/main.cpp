#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/sleep.h>

void TimerInit();

ISR(TIMER2_COMPA_vect)
{
  PORTB ^= (1 << PB5);
}

int main(void)
{
  DDRB |=_BV(DDB5);
  DDRB |=_BV(DDB3);
  TimerInit();
  sei();
  while (1) 
  {
    sleep_mode(); // sleep
  }
}
void TimerInit() 
{
  TCCR2A |= (1<<COM2A0);
  TCCR2A |= _BV(WGM21);
  TCCR2B |= _BV(CS22);
  OCR2A = -200 ; // delayms
  TIMSK2 |= (1 << OCIE2A);
}