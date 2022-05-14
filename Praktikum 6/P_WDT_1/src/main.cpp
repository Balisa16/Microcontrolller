#include <avr/io.h>
#include <util/delay.h>
#include <avr/wdt.h>

int cnt = 0;          // Inilisasi nilai counter awal = 0;
int vdly = 1;         // Inilisasi pengali delay awal = 1;
void Delay(int vdly); // Deklarasi fungsi Delay

int main(void)
{
  DDRA = 0xFF;        // Inilisasi port output yang akan digunakan
  wdt_enable(WDTO_1S);// Memilih waktu timeout yang dicapai adalah 1 S
  while (1)           // Looping berulang
  {
    PORTA = cnt++;    // Menampilkan keluaran pada PORT A sesuai counter A
    Delay(vdly++);    // Memanggil fungsi Delay dengan nilai vdly yang selalu meningkat
    wdt_reset();      // Delay direset
  }
}

void Delay(int vdly)
{
  while (vdly--)    // Jika vdly-- = true maka akan dilakukan delay berulang
  {
    _delay_ms(100); // Delay 100 ms
  }
}
