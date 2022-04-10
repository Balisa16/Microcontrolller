//Frek 4 kHZ, 8 bit-Counter 0, Prescaller 8 
//Counter = 250
//TCNT0 = 255 - counter = 5

//Mode Normal

#include <avr/io.h>
void TimerInit()
{
  TCNT0 = 5; // Menginilisasi nilai TCNT awal = 5 --> 255 - counter = 5 
  TCCR0B |= (1<<CS01); //Memilih prescaller 8 ==> CS02|CS01|CS00 = 010
}

int main()
{
  DDRB |= _BV(PB5); // Mengaktifkan Output yang akan digunakan
  TimerInit(); //Menjalankan fungsi TimerInit()
  while(true) //Memasuki looping 
  {
    if (TIFR0 &(1<<TOV0)) //Memeriksa apakah nilai register TOV telah mencapai keadaan maks
    {
      TCNT0 = 5; // Mengembalikan nilai register TCNT0 pada nilai 5; 
      TIFR0 |= (1<<TOV0); // Mereset TOV0 dengan memberikan logic 1
      PORTB ^= (1<<PB5); //Membalikkan keadaan pada Port B5
    }
  }
}
