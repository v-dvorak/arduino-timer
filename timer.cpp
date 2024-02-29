#include "timer.h"

// global
unsigned long milliseconds = 0;

void Timer::Init(void) {
    TCCR0A = (1 << WGM01);
    TCCR0B = ((1 << CS01) | (1 << CS00));
    TIMSK0 = (1 << OCIE0A);
    OCR0A = ((F_CPU / 64) / 1000 - 1);
}

unsigned long Timer::Get(void) {
    unsigned long current_ms;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        current_ms = milliseconds;
    }
    return current_ms;
}

void Timer::Reset(void) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        milliseconds = 0;
    }
}

// ISR
ISR(TIMER0_COMPA_vect) {
    ++milliseconds;
}
