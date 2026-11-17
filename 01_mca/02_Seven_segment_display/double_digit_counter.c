
#include <reg51.h>

// Define control pins for multiplexing
#define seg_tens 0x01   // Tens place ON
#define seg_unit 0x02   // Unit place ON

// Short delay for multiplexing
void delay()
{
    unsigned int i;

    for(i = 0; i < 1000; i++);
}

void main()
{
    // Hex codes for Common Anode 7-Segment Display (0-9)
    unsigned char seg_code[] =
    {
        0xC0, 0xF9, 0xA4, 0xB0, 0x99,
        0x92, 0x82, 0xF8, 0x80, 0x90
    };

    unsigned int cnt, num, temp, i;

    while(1)
    {
        // Main counter loop from 0 to 99
        for(cnt = 0; cnt <= 99; cnt++)
        {
            // Multiplexing loop
            for(i = 0; i < 100; i++)
            {
                num = cnt;

                // Display Unit Digit
                temp = num % 10;
                P1 = seg_code[temp];
                P2 = seg_unit;
                delay();

                // Display Tens Digit
                temp = num / 10;
                P1 = seg_code[temp];
                P2 = seg_tens;
                delay();
            }
        }
    }
}
