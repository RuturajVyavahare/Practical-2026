
#include <reg51.h>

// Function prototype for delay
void delay();

void main()
{
    while(1)              // Infinite loop
    {
        int i, j;

        // Gradually increase value from 0 to 255
        for(i = 0; i <= 255; i++)
        {
            P1 = i;       // Send increasing value to Port 1
            delay();      // Small delay
        }

        P1 = 0;           // Immediately reset output to 0
        delay();          // Small delay
    }
}

// Timer 0 delay function
void delay()
{
    TMOD = 0x01;          // Timer 0, Mode 1 (16-bit timer)

    TL0 = 0x1A;           // Load lower byte of Timer 0
    TH0 = 0xFF;           // Load higher byte of Timer 0

    TR0 = 1;              // Start Timer 0

    while(TF0 == 0);      // Wait for timer overflow

    TR0 = 0;              // Stop Timer 0
    TF0 = 0;              // Clear overflow flag
}
