#include <reg51.h>

unsigned char seg_code[] = {
    0xC0, 0xF9, 0xA4, 0xB0, 0x99,
    0x92, 0x82, 0xF8, 0x80, 0x90
};

void delay()
{
    int i;
    for(i = 0; i < 1000; i++);
}

void main()
{
    int num, i;

    while(1)
    {
        for(num = 0; num < 100; num++)
        {
            for(i = 0; i < 100; i++)
            {
                P1 = seg_code[num % 10];
                P2 = 0x02;
                delay();

                P1 = seg_code[num / 10];
                P2 = 0x01;
                delay();
            }
        }
    }
}
