#include "LPC214x.h"


#define I2C_ENABLE 	1 << 6		   //I2C Enable bit
#define I2C_START	1 << 5		   //Start Bit
#define I2C_STOP 	1 << 4		   //Stop Bit
#define I2C_SI		1 << 3		   //I2C interrupt flag
#define I2C_AACK  	1 << 2		   //assert ACK flag

void I2CInit(void)
{
	PINSEL0 &= 0xFFFFFF0F;							//set the pins for i2c functions
	PINSEL0 |= 0x00000050;							//P0.2 -> SCL0		P0.3 -> SDA0
	
	I2C0CONCLR  = I2C_ENABLE | I2C_START | I2C_STOP | I2C_SI | I2C_AACK;	//clear all the bits in CONTROL register
	
	//set I2C clock to work at 100Khz 
	I2C0SCLH = 0x4B ;							//set the high time of i2c clock; (15mhz / 100khz / 2)
	I2C0SCLL = 0x4B ;							//set the low time of i2c clock;
	
	I2C0CONSET = I2C_ENABLE ;					//enable the I2C Interface
}										


void I2CStart(void)								  //Function to initiate a start condition on the I2C bus
{
	unsigned int status;	
	status = status;
	I2C0CONCLR = (I2C_START | I2C_STOP | I2C_SI | I2C_AACK); 	// clear all the bits in CONCLR register	
	I2C0CONSET = (I2C_ENABLE );					 		  		//Enable the I2C interface 
	I2C0CONSET = (I2C_START);					  				//set the STA bit 
	while(!((status=I2C0CONSET)& I2C_SI));						//wait till interrupt flag becomes set
}


void I2CStop(void)
{
	unsigned int status;	
	status = status;					 
	I2C0CONCLR = I2C_START | I2C_SI | I2C_AACK;				//clear all bits 
	I2C0CONSET = I2C_STOP;										//set STOP bit
}


void I2Csend(unsigned char data)
{	   
	unsigned int status;	
	status = status;
	I2C0DAT = data;
	I2C0CONCLR = I2C_START | I2C_STOP ;						// clear start bit for next operation 
	I2C0CONCLR = I2C_SI;									// clear interrupt flag
	while(!((status=I2C0CONSET)& I2C_SI));				   	//wait till interrupt flag becomes set
}


unsigned char I2Cget(void)
{
	unsigned char data;
	unsigned int status;	
	status = status;
	
	I2C0CONCLR = I2C_START | I2C_STOP;		
	I2C0CONCLR = I2C_SI;									// clear interrupt flag				
	I2C0CONSET = I2C_AACK;								   	// send ack to continue further data transfer
	while(!((status=I2C0CONSET)& I2C_SI));					//wait till interrupt flag becomes set
	data = I2C0DAT;
	return data;
}

