
#include <reg51.h>

// Function prototype for delay
void delay();

void main()
{
    while(1)              // Infinite loop
    {
        int i, j;

        // Increase value from 0 to 255
        for(i = 0; i <= 255; i++)
        {
            P1 = i;       // Send increasing value to Port 1
            delay();      // Small delay
        }

        // Decrease value from 255 to 0
        for(j = 255; j >= 0; j--)
        {
            P1 = j;       // Send decreasing value to Port 1
            delay();      // Small delay
        }
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
