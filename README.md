# Timer

Simple library for timing in milliseconds, works with Atmega328P, Arduino UNO, may work for other AVRs. Uses `TIMER0` and interrupts, can be easily modified to run on any timer, for that see documentation linked below. Timer can run without an overflow for almost 50 days.

## Features

### Init

```cpp
void Init(void);
```

Initialisation function, must be called before anything else.

### Get

```cpp
unsigned long Get(void);
```

Read current time.

### Reset

```cpp
void Reset(void);
```

Resets milliseconds counter back to zero.

## Example usage

```cpp
#include "timer.h"
#define DELAY 200 // in ms

Timer timer;
unsigned long lastReading;

int main(void)
{
    // setup timer
    timer.Init();
    unsigned long lastReading = 0;
    unsigned long currentTime = 0;
    // enable interrupts
	sei();

	// main loop
	while (1)
	{
        // get time at the start of a loop
        currentTime = timer.Get();

        // if enough time has passed
        if (currentTime - lastReading > DELAY) {
            /* 
            do something (e.g. blink LED)
            */
           // reset timing
           lastReading = currentTime;
        }
    }
}

```

## Sources

- [Atmega328P Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)
