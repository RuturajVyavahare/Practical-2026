#include "I2C.h"						  

#define EEPROM_Addr 0xA0		  		//device address

void EEPROM_write(unsigned int add, unsigned char *data, unsigned char len)
{
	unsigned char i;
	I2CStart();							//Assert START
	I2Csend(EEPROM_Addr | I2Cwrite);	//Device address with LSB bit 0
	I2Csend(add >> 8);		   			//Address higher byte
	I2Csend(add & 0xFF);				//Address lower byte
	for(i=0;i<len;i++)
		I2Csend(*data++); 				//write the array to EEPROM
	I2CStop();
}

void EEPROM_read(unsigned int add, unsigned char *data, unsigned char len)
{
	unsigned char i;
	I2CStart();							 //Assert START
	I2Csend(EEPROM_Addr | I2Cwrite);	 //Device address with LSB bit 0 (Dummy Write)
	I2Csend(add >> 8);	   				//Address higher byte
	I2Csend(add & 0xFF);	 			//Address lower byte
	I2CStart();							//Assert Restart
	I2Csend(EEPROM_Addr | I2Cread);		//Device address with LSB bit 1
	for(i=0;i<len;i++)
		*data++ = I2Cget(); 			//Read EEPROM
	I2CStop();	
}
