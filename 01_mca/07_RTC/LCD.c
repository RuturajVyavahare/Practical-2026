#include"lpc214x.h"
#include"LCD.h"

#define LCD_DATAMASK	0x000000FF
#define LCD_PORT 		0x000FF000
#define LCD_SHIFT		12
#define LCD_RS			1 << 20
#define LCD_EN 			1 << 21

void LCD_delay(unsigned int time)
{
 unsigned int i , j ;

	for(i = 0; i < time; i++)
	{
		for(j=0;j<500;j++);
	}
}

void SendInstruction(unsigned int command)
{
	 command &= LCD_DATAMASK; 	// mask the command
	 command = command << LCD_SHIFT;

	//set RS pin low
	 IOCLR1 = LCD_RS;		// RS low : Instruction
	 LCD_delay(10);
	//Set EN pin HIgh
	 IOSET1 = LCD_EN;		// EN High
	 LCD_delay(10);
	//Set Data on pins
	 IOCLR0 = LCD_PORT;
	 IOSET0 = command; 		// DATA
	 LCD_delay(10);
	//set EN pin Low
	 IOCLR1 = LCD_EN;		// EN Low
	 LCD_delay(10);
	 IOCLR1 = LCD_RS;		// RS Low
	 IOCLR1 = LCD_DATAMASK << LCD_SHIFT;
}

void SendData(unsigned int lcddata)
{
	 lcddata &= LCD_DATAMASK; 	// mask the command
	 lcddata = lcddata << LCD_SHIFT;

	//set RS pin low
	 IOSET1 = LCD_RS;		// RS HIGH : DATA
	 LCD_delay(10);
	//Set EN pin HIgh
	 IOSET1 = LCD_EN;		// EN High
	 LCD_delay(10);
	//Set Data on pins
	 IOCLR0 = LCD_PORT;
	 IOSET0 = lcddata; 		// DATA
	 LCD_delay(10);
	//set EN pin Low
	 IOCLR1 = LCD_EN;		// EN Low
	 LCD_delay(10);
	 IOCLR1 = LCD_RS;		// RS Low
	 IOCLR1 = LCD_DATAMASK << LCD_SHIFT;
}

void SetLineNumber(unsigned int linenum)
{
	if(linenum == 1)
	{
	  SendInstruction( SETDDRAMADDR | 0x00 );		// set ddram address as 0x00
	}
	else
	{
	  SendInstruction( SETDDRAMADDR | 0x40 );		// set ddram address as 0x40
	}

}

void SetAddress(unsigned char memory, unsigned int address )
{

	address &= 0x0000007F;

	if(memory == DDRAM)
	{
	  SendInstruction( SETDDRAMADDR | address );
	}
	else
	{
	  SendInstruction( SETCGRAMADDR | address );
	}

}

void BlinkDisplay(void)
{

	SendInstruction( DISPONOFFCTRL );
	LCD_delay(500);
	SendInstruction( DISPONOFFCTRL | DISPLAY_ON | CURSOR_ON | BLINKCHAR_ON );
	LCD_delay(500);

}

void ShiftDisplay(unsigned char direction, unsigned int clicks)
{
unsigned int i;

	if(direction == RIGHTSHIFT)
	{
	 for(i = 0; i < clicks ; i++)
	 {
	   SendInstruction( DISPCURSHIFT | SHIFTRIGHT );
	 }
	}
	else
	{
	for(i = 0; i < clicks ; i++)
	 {
	   SendInstruction( DISPCURSHIFT );
	 }

	}
}

void ClearDisplay(void)
{
	 SendInstruction(CLEARDISPLAY);
}


void InitLCD(void)
{
unsigned int temp;

	//initialise the pins for the lcd
	temp  = PINSEL2;		// set the pins function as GPIO.
	temp &= 0xFFFFFFF7;
	PINSEL2 = 0;

	IODIR1 = LCD_RS | LCD_EN;		//set the direction of the pins as output
	IODIR0 = 0x000FF000;

	//initialise the lcd : function set command : 8 bit interface : 5ms wait
	SendInstruction( FUNCTIONSET | FS_DATALENGTH );
	LCD_delay(5);

	//initialise the lcd : function set command : 8 bit interface : 100us wait
	SendInstruction( FUNCTIONSET | FS_DATALENGTH );
	LCD_delay(1);

	//initialise the lcd : function set command : 8 bit interface : set interface , line numbers and font size
	SendInstruction( FUNCTIONSET | FS_DATALENGTH | FS_LINES2 );  // set interface 8 bit, no of lines =2 and character font 5x7

	//display off
	SendInstruction(DISPONOFFCTRL);

	//clear display
	SendInstruction(CLEARDISPLAY);

	//entry mode set : increment / decrement
	SendInstruction(ENTRYMODESET | ENTRYMODESET_INC);	//set as increment of address

	//display on : set cursor and blinking
//	SendInstruction(DISPONOFFCTRL | DISPLAY_ON | CURSOR_ON | BLINKCHAR_ON);	// display on and cursor blinking on
	SendInstruction(DISPONOFFCTRL | DISPLAY_ON | CURSOR_ON );	// display on and cursor blinking on
}
/********************************************************************************************************************/


