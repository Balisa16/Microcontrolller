//Frek 4 kHZ, 8 bit-Counter 0, Prescaller 8 
//Counter = 250
//OCR2A = 250

// Mode CTC

#include <avr/io.h>

void TimerInit()
{
  DDRB |= _BV(PB5); // Mengaktifkan Output yang akan digunakan
  TCCR0B |= (1<<CS01); //Memilih prescaller 8 ==> CS02|CS01|CS00 = 010
  TCCR0A |= (1<<WGM01); //Memilih mode CTC ==> WGM02|WGM01|WGM00 = 010
  OCR0A = 250; // Menginilisasi nilai OCR2A awal = 250
}

int main()
{
  TimerInit(); // Menjalankan / memanggil fungsi TimerInit()
  while(true)
  {
    if (TIFR0 &(1<<OCF0A)) //Memeriksa apakah nilai OCF0A pada register TIFR0 telah mencapai keadaan maks (SET)
    {
      PORTB ^= (1<<PB5); //Membalikkan keadaan pada Port B5
      TIFR0 |= (1<<OCF0A); // Mereset OCF0A dengan memberikan logic 1
    }
  }
}