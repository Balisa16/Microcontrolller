#include <stdio.h>
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Sensor.hpp"
#include "Welcome.h"
#include <Servo.h>

#include <Arduino.h>

long durasi, timing_pintu = 0;
int jarak, i = 0;
bool Welc = false;

#define EchoPin 4

void initPWM(void);
void TimerInit(void);

Servo servo1;

ISR(TIMER0_COMPA_vect)
{
  if(i < Welcome_size && Welc == true )
  {
    i++;
    OCR3A = ~pgm_read_byte(&Welcome[i]);
  }
  else if(i >= Welcome_size)
  {
    i = 0;
    Welc = false;
  }
}

int main()
{
  DDRH |= _BV(PH3);  // D5 menjadi output Trigger
  DDRB |= _BV(PB4);   // LED indikator
  TimerInit();
  initPWM();
  sei();
  servo1.attach(11);
  servo1.write(120);
  jarak = 120;
  Serial.begin(115200);
  while(true)
  {    
    PORTH &= ~(1<<PH3);
    _delay_us(2);
    PORTH |= (1<<PH3);
    _delay_us(10);
    PORTH &= ~(1<<PH3);
    durasi = Sander.P_Masuk(EchoPin, 0x1, 100000);
    jarak = durasi* 0.034 / 2;
    Serial.print(jarak);
    Serial.print(" ");
    Serial.print(timing_pintu);
    Serial.print(" ");
    Serial.println(i);
    if(jarak <= 80)
    {
      timing_pintu = 40;
      servo1.write(0);
      Welc = true;
      PORTB |= _BV(PB4);
      _delay_ms(40);
    }
    else if(timing_pintu != 0)
    {
      timing_pintu--;
    }
    else
    {
      Welc = false;
      servo1.write(120);
      PORTB &= ~_BV(PB4);
      i = 0;
    }
    _delay_ms(100);
  }
}

void initPWM()
{
  DDRE = _BV(PE3);
  TCCR3B = _BV(CS30)|_BV(WGM32);
  TCCR3A = _BV(WGM30)|_BV(COM3A1);
  OCR3A = 200;
}

void TimerInit(void)
{
  TCCR0A |= _BV(WGM01);
  TCCR0B |= _BV(CS01);
  OCR0A = 250;
  TIMSK0 |= (1 << OCIE0A);
  sei();
}