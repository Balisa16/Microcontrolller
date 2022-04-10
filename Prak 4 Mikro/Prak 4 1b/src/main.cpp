//Frek 4 kHZ, 8 bit-Counter 2, Prescaller 8 
//Counter = 250
//TCNT0 = 255 - counter = 5

// Mode Normal dengan Interrupt

#include <avr/io.h>
#include <avr/interrupt.h>

void TimerInit(void)
{
  DDRB |= (1<<PB5); // Mengaktifkan Output yang akan digunakan
  TIMSK0 |= (1 << TOIE0); // enable overflow interrupt
  TCCR0B |= (1 << CS01); //Memilih prescaller 8 ==> CS02|CS01|CS00 = 010
  TCNT0 = 5; // Menginilisasi nilai TCNT awal = 5 --> 255 - counter = 5 
  sei(); //Mengaktifkan global interrupt enable
}

ISR (TIMER0_OVF_vect)
{
  PORTB ^= (1 << PB5); //Membalikkan keadaan pada Port B5
  TCNT0 = 5; // Mengembalikan nilai register TCNT0 pada nilai 5; 
}

int main(void) {
  TimerInit(); //Menjalankan fungsi TimerInit()
  while (true) {
    // Tidak dilakukan apa apa. Namun dilakukan looping secara terus menerus.
  }
}