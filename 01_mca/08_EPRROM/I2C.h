#ifndef I2C_H
	#define I2C_H
	
	#define I2Cwrite	0x00			//LSB bit 0 (write)
	#define I2Cread		0x01			//LSB bit 1 (read)

	void I2CInit(void);
	void I2CStart(void);
	void I2CStop(void);
	void I2Csend(unsigned char);
	unsigned char I2Cget(void);

#endif
