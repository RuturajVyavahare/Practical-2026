#include <reg51.h>

unsigned char seg_code[] = {
    0xC0, 0xF9, 0xA4, 0xB0, 0x99,
    0x92, 0x82, 0xF8, 0x80, 0x90
};

void delay()
{
    int i, j;
    for(i = 0; i < 100; i++)
        for(j = 0; j < 100; j++);
}

void main()
{
    int i;

    while(1)
    {
        for(i = 0; i < 10; i++)
        {
            P1 = seg_code[i];
            P2 = 0x02;
            delay();
        }
    }
}
