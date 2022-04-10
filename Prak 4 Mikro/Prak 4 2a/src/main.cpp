//Frek 16 kHZ, 16 bit-Counter 1, Prescaller 1 
//Counter = 500
//TCNT1 = 65535- counter = 65035

//Mode Normal

#include <avr/io.h>
void TimerInit()
{
  TCNT1 = 65035; // Menginilisasi nilai TCNT awal = 65535- counter = 65035
  TCCR1B |= (1<<CS10); //Memilih prescaller 1 ==> CS12|CS11|CS10 = 001
}
int main()
{
  DDRB |= _BV(PB5); // Mengaktifkan Output yang akan digunakan
  TimerInit(); //Menjalankan fungsi TimerInit()
  while(true) //Memasuki looping 
  {
    if (TIFR1 &(1<<TOV1)) //Memeriksa apakah nilai register TOV1 telah mencapai keadaan maks
    {
      TCNT1 = 65035; // Mengembalikan nilai register TCNT1 pada nilai 65035; 
      TIFR1 |= (1<<TOV1); // Mereset TOV1 dengan memberikan logic 1
      PORTB ^= (1<<PB5); //Membalikkan keadaan pada Port B5
    }
  }
}
