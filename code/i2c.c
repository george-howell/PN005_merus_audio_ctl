/* i2c.c
*
* i2c functions using standard linux i2c driver module
*
* Created By: G. Howell
* Created On: 08/07/2020
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <linux/i2c-dev.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include "i2c.h"

// i2c linux device handle
int g_i2cFile;

// open the i2c device
void i2cOpen(uint8_t bus)
{	
	// create char array argument
	char buf[32];
	snprintf(buf, 32, "/dev/i2c-%d", bus);

	// open i2c bus
	g_i2cFile = open(buf, O_RDWR);

	// error check if i2c bus is open
 	if (g_i2cFile < 0) {
 		fprintf(stderr, "ERROR: failed to open i2c bus %d\n", bus);
		exit(EXIT_FAILURE);
	}
}

// close the i2c device
void i2cClose()
{
	close(g_i2cFile);
}

// i2c init
void i2cInit(uint8_t devAddr)
{
	// sets the device address
	if (ioctl(g_i2cFile, I2C_SLAVE, devAddr) < 0) {
		fprintf(stderr,"ERROR: failed to set the i2c address 0x%02x\n", devAddr);
		exit(EXIT_FAILURE);
	}
}

// i2c write data
void i2cWrite (uint8_t* wrData, uint32_t noBytes) 
{

	// writes to the command address
	if (write(g_i2cFile, wrData, noBytes) != noBytes) {
		fprintf(stderr,"ERROR: i2c write failed\n");
		exit(EXIT_FAILURE);
	}
}

// i2c read data
uint8_t* i2cRead (uint32_t noBytes) 
{
	// allocate output data buffer
	uint8_t* outData = (uint8_t*) malloc(sizeof(uint8_t) * noBytes);
	if (!outData) {
		fprintf(stderr,"ERROR: Failed to allocate output data buffer\n");
		exit(EXIT_FAILURE);
	}

    // read bytes of data from i2c bus
    if (read(g_i2cFile, outData, noBytes) != noBytes) {
    	fprintf(stderr,"ERROR: Failed to read i2c data\n");
        exit(EXIT_FAILURE);
    }

	return outData;
}

// i2c enable register and read 1 byte
uint8_t i2cEnRdByte(uint8_t regAddr)
{
	// enable reg
	uint8_t wrData[1] = {regAddr};
	i2cWrite(wrData, 1);

	// read reg
	uint8_t* rdData = i2cRead(1);

	return *rdData;
}

// i2c enable register and write 1 byte
void i2cEnWrByte(uint8_t regAddr, uint8_t wrByte)
{
	// enable reg and write byte
	uint8_t wrData[2] = {regAddr, wrByte};
	i2cWrite(wrData, 2);

}

