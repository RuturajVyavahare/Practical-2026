
//Commands for 16x2 character LCD

#define CLEARDISPLAY 		0x01			// clear display command mask
#define RETURNHOME 			0X02			// return home command mask
#define ENTRYMODESET 		0X04			// entry mode set command mask
#define DISPONOFFCTRL 		0X08			// display on off control mask
#define DISPCURSHIFT 		0X10			// display cursor shift command mask
#define FUNCTIONSET			0X20			// function set command mask
#define SETCGRAMADDR 		0x40			// set cgram address mask
#define SETDDRAMADDR		0X80			// set ddram address mask

#define ENTRYMODESET_INC 	0X02			// entry mode increment mask
#define ENTRYMODESET_DEC 	0X04			// entry mode decrement mask
#define ENTRYMODESET_SHIFT 	0X01			// entry mode shift mask
#define DISPLAY_ON			0x04			// display control entire display onoff mask
#define CURSOR_ON			0x02			// display control curson onoff mask
#define BLINKCHAR_ON		0x01			// display control character blink mask
#define SHIFTCURSOR			0x08			// cursor shift mask
#define SHIFTRIGHT			0x04			// cursor shift direction mask

#define FS_DATALENGTH		0x10			// function set data length for 8 bit
#define FS_LINES2			0x08			// function set line number for 2 line display
#define FS_FONT				0x04			// function set font info mask for 5x10 dots

#define DDRAM			1
#define CGRAM			0
#define RIGHTSHIFT		1
#define LEFTSHIFT		0


void SendInstruction(unsigned int);
void SendData(unsigned int);
void InitLCD(void);
void SetLineNumber(unsigned int);
void SetAddress(unsigned char, unsigned int );
void BlinkDisplay(void);
void ShiftDisplay(unsigned char, unsigned int);
void RollDisplay(void);
void ClearDisplay(void);

