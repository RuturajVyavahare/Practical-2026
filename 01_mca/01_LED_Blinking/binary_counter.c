
#include <reg51.h>

void delay(unsigned int t);

void main(void)
{
    unsigned char count;

    while(1)
    {
        for(count = 0; count <= 9; count++)
        {
            P2 = count;
            delay(1000);
        }
    }
}

void delay(unsigned int t)
{
    unsigned int i, j;

    for(i = 0; i < t; i++)
    {
        for(j = 0; j < 1275; j++)
        {
        }
    }
}
