#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Inilisasi variable awal
volatile int f_wdt = 0;
int counter = 0;

//Interrupt Watch Dog timer 
ISR(WDT_vect)
{
  PORTA = counter++;  // Pada porta akan ditampilkan sesuai nilai counter
}
int main(void)
{
  DDRB |= (1 << 7); // PortB.7 akan dijadikan output
  DDRA = 0xFF;      // Inilisasi PortA sebagai output
  MCUSR &= ~(1 << WDRF);// Clear reset flag pada port A
  WDTCSR |= (1 << WDCE) | (1 << WDE);
  WDTCSR = _BV(WDP0) | _BV(WDP1) | _BV(WDP2); // Set prescaller baru 2 Second
  WDTCSR |= _BV(WDIE); //Enable WDE interrupt
  sei(); // Aktivasi global interrupt
  while (true)
  {
  }
}
