
#include <reg51.h>

// Function prototype for delay
void delay();

void main()
{
    while(1)          // Infinite loop
    {
        P0 = 0xFF;     // Set Port 0 HIGH
        delay();      // Generate HIGH time

        P0 = 0x00;     // Set Port 0 LOW
        delay();      // Generate LOW time
    }
}

// Timer 0 delay function
void delay()
{
    TMOD = 0x01;       // Timer 0, Mode 1 (16-bit timer)

    TL0 = 0x01;        // Load lower byte of Timer 0
    TH0 = 0xFF;        // Load higher byte of Timer 0

    TR0 = 1;           // Start Timer 0

    while(TF0 == 0);   // Wait until timer overflows

    TR0 = 0;           // Stop Timer 0
    TF0 = 0;           // Clear Timer 0 overflow flag
}
