//Frek 16 kHZ, 16 bit-Counter 1, Prescaller 1 
//Counter = 500
//OCR1A = 500

// Mode CTC

#include <avr/io.h>

void TimerInit()
{
  DDRB |= _BV(PB5); // Mengaktifkan Output yang akan digunakan
  TCCR1B |= (1<<CS10); //Memilih prescaller 1 ==> CS12|CS11|CS10 = 001
  TCCR1B |= (1<<WGM12); //Memilih mode CTC ==> WGM12|WG11|WGM10 = 100
  OCR1A = 500; // Menginilisasi nilai OCR1A awal = 500
}

int main()
{
  TimerInit(); // Menjalankan / memanggil fungsi TimerInit()
  while(true)
  {
    if (TIFR1 &(1<<OCF1A)) //Memeriksa apakah nilai OCF1A pada register TIFR1 telah mencapai keadaan maks (SET)
    {
      PORTB ^= (1<<PB5); //Membalikkan keadaan pada Port B5
      TIFR1 |= (1<<OCF1A); // Mereset OCF1A dengan memberikan logic 1
    }
  }
}