#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

// global
extern unsigned long milliseconds;

class Timer {
    public:
        // call this before anything else
        void Init(void);

        unsigned long Get(void);        
        void Reset(void);
};