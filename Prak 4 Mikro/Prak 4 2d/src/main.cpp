//Frek 16 kHZ, 16 bit-Counter 1, Prescaller 1 
//Counter = 500
//OCR1A = 500

// Mode CTC dengan interrupt

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void TimerInit() 
{
  DDRB |=_BV(DDB5); // Mengaktifkan Output yang akan digunakan
  TCCR1B |= _BV(WGM12); //Memilih mode CTC ==> WGM12|WGM11|WGM10 = 100
  TCCR1B |= _BV(CS10); //Memilih prescaller 1 ==> CS12|CS11|CS10 = 001
  OCR1A = 500; //Menetapkan batasan atas OCR1A adalah 500
  TIMSK1 |= (1 << OCIE1A); // enable Timer/Counter1 Output Compare Match A Interrupt
  sei(); //Mengaktifkan global interrupt enable
}

ISR(TIMER1_COMPA_vect)
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