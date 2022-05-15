#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Inilisasi variable awal
volatile int f_wdt = 0;
int counter = 0;

//Interrupt Watch Dog timer 
ISR(WDT_vect)
{
  if (f_wdt == 0)  // Jika f_wdt = 0 maka :
    f_wdt = 1;     // f_wdt = 1
}
int main(void)
{
  DDRB |= (1 << 7); // PortB.7 akan dijadikan output
  DDRA = 0xFF;      // Inilisasi PortA sebagai output
  MCUSR &= ~(1 << WDRF);// Clear reset flag pada port A
  /* Jika kita ingin mengubah WDE atau prescaller, maka kita perlu untuk
 set WDCE (Ini mengiziinkan update pada 4 putaran clock).
 */
  WDTCSR |= (1 << WDCE) | (1 << WDE);
  WDTCSR = _BV(WDP0) | _BV(WDP1) | _BV(WDP2); // Set prescaller baru 2 Second
  WDTCSR |= _BV(WDIE); //Enable WDE interrupt
  sei(); // Aktivasi global interrupt
  while (true)
  {
    if (f_wdt == 1) // Jika f_wdt == 1 maka :
    {
      PORTB ^= (1 << 7); // Keadaan Port B akan dibalikkan
      f_wdt = 0;          // f_wdt dijadikan 0
    }
    else
    {
      _delay_ms(300);     // Delay diberikan sebesar 300 ms
      PORTA = counter++;  // Pada porta akan ditampilkan sesuai nilai counter
    }
  }
}
