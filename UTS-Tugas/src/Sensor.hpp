#pragma once
#ifndef HCSR04_h
#define HCSR04_h

#include "wiring_private.h"
#include "pins_arduino.h"

struct SensorUltrasonik{
    unsigned long P_Masuk(uint8_t pin, uint8_t state, unsigned long timeout)
    {
        uint8_t bit = digitalPinToBitMask(pin);
        uint8_t port = digitalPinToPort(pin);
        uint8_t stateMask = (state ? bit : 0);
        unsigned long maxloops = microsecondsToClockCycles(timeout)/16;
        unsigned long width = countPulseASM(portInputRegister(port), bit, stateMask, maxloops);
        if (width)
            return clockCyclesToMicroseconds(width * 16 + 16);
        else
            return 0;
    }
};

static SensorUltrasonik Sander;

#endif