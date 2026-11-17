
#include <reg51.h>

// Simple delay function
void delay()
{
    unsigned int i, j;

    for(i = 0; i < 1000; i++)
    {
        for(j = 0; j < 100; j++);
    }
}

void main()
{
    // Hex codes for Common Anode 7-Segment Display (0-9)
    unsigned char seg_code[] =
    {
        0xC0, 0xF9, 0xA4, 0xB0, 0x99,
        0x92, 0x82, 0xF8, 0x80, 0x90
    };

    unsigned int cnt;

    while(1)
    {
        // Loop from 0 to 9
        for(cnt = 0; cnt <= 9; cnt++)
        {
            P1 = seg_code[cnt];  // Send digit code to Port 1
            P2 = 0x02;           // Enable only the unit display
            delay();             // Wait before next number
        }
    }
}
