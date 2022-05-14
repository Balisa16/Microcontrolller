#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile int f_wdt = 0;

// Interrupt Watch Dog Timer
ISR(WDT_vect)
{
  if (f_wdt == 0) // Jika f_wdt = 0 maka :
    f_wdt = 1;    // f_wdt = 1
}

void enterSleep(void) //Fungsi Sleep
{
  set_sleep_mode(SLEEP_MODE_PWR_SAVE); // Mode Sleep diset
  sleep_enable(); // Sleep diaktifkan
  sleep_mode(); // Memasuki Sleep mode
  sleep_disable(); // Sleep dinonaktifkan
  power_all_enable(); // Semua power diaktifkan
}

int main(void)
{
  DDRB |= (1 << 7); // Inilisasi output pada PORTB pin 7
  MCUSR &= ~(1 << WDRF);  // Clear the reset flag.
  WDTCSR |= (1 << WDCE) | (1 << WDE); // In order to change WDE or the prescaler, we need to set WDCE (This will allow updates for 4 clock cycles).
  WDTCSR = 1 << WDP3; // set new watchdog timeout prescaler value WDTCSR = 1<<WDP0 | 1<<WDP3;  8.0 seconds
  WDTCSR |= _BV(WDIE); // Enable the WD interrupt (note no reset).
  sei();  // Global Interrupt Enable
  while (1)
  {
    if (f_wdt == 1) // Jika f_wdt = 1 maka :
    {
      PORTB ^= (1 << 7);  // PORTB akan dinegasikan outputnya (Dibalikkan)
      f_wdt = 0;          // Nilai f_wdt akan dijadikan 0
      enterSleep();       // Memasuki mode sleep // Memanggil fungsi enterSleep
    }
  }
}