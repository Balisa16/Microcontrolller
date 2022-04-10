//Frek 4 kHZ, 8 bit-Counter 0, Prescaller 8 
//Counter = 250
//OCR0A = 250

// Mode CTC dengan interrupt

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void TimerInit() 
{
  DDRB |=_BV(DDB5); // Mengaktifkan Output yang akan digunakan
  TCCR0A |= _BV(WGM01); //Memilih mode CTC ==> WGM02|WGM01|WGM00 = 010
  TCCR0B |= _BV(CS01); //Memilih prescaller 8 ==> CS02|CS01|CS00 = 010
  OCR0A = 250; //Menetapkan batasan atas OCR0A adalah 250
  TIMSK0 |= (1 << OCIE0A); // enable Timer/Counter0 Output Compare Match A Interrupt
  sei(); //Mengaktifkan global interrupt enable
}

ISR(TIMER0_COMPA_vect)
{
  PORTB ^= (1 << PB5); //Membalikkan keadaan pada Port B5
}

int main(void)
{
  TimerInit(); //Menjalankan fungsi TimerInit()
  while (true) 
  {
    // Tidak dilakukan apa apa. Namun dilakukan looping secara terus menerus.
  }
}























// TCCR2A |= (1<<COM2B1); 