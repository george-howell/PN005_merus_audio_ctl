/* i2sFmt.c
*
* API's for the I2S Format configuration
*
* Created By: G. Howell
* Created On: 23/07/2020
*
*/

#include <stdio.h>
#include <stdint.h>
#include "ma1270p.h"
#include "i2c.h"
#include "i2sFmt.h"

/*
	API's
*/

/*
* @fn				- I2S_ReadAll
* 
* @brief			- reads all the i2s format configuration
*   				  registers
*
* @param[in]		- n/a
*
* @return			- n/a
*
*/
void I2S_ReadAll(void)
{
	printf("I2S Settings:\n");

	// read PCM word format
	uint8_t rdData = i2cEnRdByte(I2S_PCM_FMT);
	rdData &= I2S_PCM_BITS;
	
	printf("   PCM Word Fmt: ");
	if (rdData==0)
	{
		printf("i2s standard\n");
	} else if (rdData==1)
	{
		printf("left justified (default)\n");
	} else if (rdData==4)
	{
		printf("right justified 16 bits\n");
	} else if (rdData==5)
	{
		printf("right justified 18 bits\n");
	} 
	else if (rdData==6)
	{
		printf("right justified 20 bits\n");
	} 
	else if (rdData==7)
	{
		printf("right justified 24 bits\n");
	}

	// read other i2s registers
	rdData = i2cEnRdByte(I2S_CNF_1);

	// i2s_rightfirst
	printf("   Order of PCM Words: ");
	if ((rdData>>I2S_RFIRST) & 1) 
	{
		printf("right first\n");
	} else
	{
		printf("left first\n");
	}

	// i2s_framesize
	uint8_t fraSizeBits = (rdData>>I2S_FSIZE) & I2S_FSIZE_BITS;
	printf("   No. Bits Per Frame: ");
	if (fraSizeBits == 0)
	{
		printf("64\n");
	} else if (fraSizeBits == 1)
	{
		printf("48\n");
	} else if (fraSizeBits == 2)
	{
		printf("32\n");
	}

	// i2s_order
	printf("   Order of PCM Bits: ");
	if ((rdData>>I2S_ORDER) & 1) 
	{
		printf("LSB first\n");
	} else
	{
		printf("MSB first\n");
	}

	// i2s_ws_pol
	printf("   Word Pairing: ");
	if ((rdData>>I2S_WS_POL) & 1) 
	{
		printf("word select high\n");
	} else
	{
		printf("word select low\n");
	}

	// i2s_ws_pol
	printf("   Clocking Edge: ");
	if ((rdData>>I2S_SCK_POL) & 1) 
	{
		printf("falling edge\n");
	} else
	{
		printf("rising edge\n");
	}
}
