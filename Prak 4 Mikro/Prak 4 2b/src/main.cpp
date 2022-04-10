//Frek 16 kHZ, 16 bit-Counter 1, Prescaller 1 
//Counter = 500
//TCNT1 = 65535- counter = 65035

// Mode Normal dengan Interrupt

#include <avr/io.h>
#include <avr/interrupt.h>

void TimerInit(void)
{
  DDRB |= (1<<PB5); // Mengaktifkan Output yang akan digunakan
  TIMSK1 |= (1 << TOIE1); // enable overflow interrupt
  TCCR1B |= (1 << CS10); //Memilih prescaller 1 ==> CS12|CS11|CS10 = 001
  TCNT1 = 65035; // Menginilisasi nilai TCNT awal = 65035 --> TCNT1 = 65535- counter = 65035
  sei(); //Mengaktifkan global interrupt enable
}

ISR (TIMER1_OVF_vect)
{
  PORTB ^= (1 << PB5); //Membalikkan keadaan pada Port B5
  TCNT1 = 65035; // Mengembalikan nilai register TCNT1 pada nilai 65035; 
}

int main(void) {
  TimerInit(); //Menjalankan fungsi TimerInit()
  while (true) {
    // Tidak dilakukan apa apa. Namun dilakukan looping secara terus menerus.
  }
}