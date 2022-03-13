/*
  RGB Configuration
  Merah   (255, 0, 0)   ==> (HIGH, LOW, LOW)
  Kuning  (255, 255, 0) ==> (HIGH, HIGH, LOW)
  Hijau   (0, 255, 0)   ==> (LOW, HIGH, LOW)
*/

#include <avr/io.h>
#include <util/delay.h>

/*
Nama    : Sander Antonius Balisa
Kelas   : 2 D4 EB
NRP     : 2120600053
*/

int main()
{
  // PD2, PD3, dan PD4 akan digunakan sebagai output Car Traffic LED
  DDRD |= (1<<2)|(1<<3)|(1<<4)|(1<<5);

  // PB0 dan PB1 akan digunakan sebagai output Car Traffic LED
  DDRB |= (1<<0)|(1<<1);
  
  // Reset semua LED ==> Keadaan OFF
  PORTD &= ~(1<<2);
  PORTD &= ~(1<<3);
  PORTD &= ~(1<<4);
  PORTD &= ~(1<<5);
  PORTB &= ~(1<<0);
  PORTB &= ~(1<<1);

  while (true)
  {
    // Pada keadaan default , Lampu Hijau pada Car Traffic LED akan selalu menyala
    // Sedangkan pada Pedestrian Traffic LED memiliki kondisi default mati.
    PORTD |= (1<<4);      // LED Hijau Mobil menyala
    if(PINC &(1<<0))
    {
      PORTD &= ~(1<<4);   // LED Hijau Mobil mati
      PORTD |= (1<<3);    // LED Kuning Mobil mati
      PORTD |= (1<<5);
      _delay_ms(1000);    // Delay selama 1 detik
      
      PORTD &= ~(1<<3);   // LED Kuning Mobil mati
      PORTD &= ~(1<<5);
      PORTD |= (1<<2);    // LED Merah Mobil menyala
      _delay_ms(3000);    // Delay selama 3 detik

      PORTB |= (1<<1);     // Lampu Hijau Pejalan Kaki menyala
      _delay_ms(3000);    // Delay selama 3 detik

      PORTB &= ~(1<<1);   // Lampu Hijau Pejalan Kaki mati
      PORTB |= (1<<0);    // Lampu Merah Pejalan Kaki menyala
      _delay_ms(3000);    // Delay selama 3 detik

      PORTD &= ~(1<<2);   // Lampu Merah Mobil mati
      PORTB &= ~(1<<0);   // Lampu Merah Pejalan Kaki mati 
      PORTD |= (1<<3);    // Lampu Kuning Mobil menyala
      PORTD |= (1<<5);
      _delay_ms(2000);    // Delay selama 2 detik

      PORTD &= ~(1<<3);   // Lampu Kuning Mobil mati
      PORTD &= ~(1<<5);

      //Kembali ke keadaan default
    }
  }
}