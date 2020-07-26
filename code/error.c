/* error.c
*
* API's handles for the error register functions
*
* Created By: G. Howell
* Created On: 23/07/2020
*
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "error.h"
#include "i2c.h"
#include "ma1270p.h"
#include "millisleep.h"

/*
	API's
*/

/*
* @fn				- Err_AccumRd
* 
* @brief			- reads the accumulated error register
*
* @param[in]		- n/a
*
* @return			-
*
*/
void Err_AccumRd(void) 
{	
	// read ERR_ACC reg
	uint8_t rdData = i2cEnRdByte(ERR_ACC);

	printf("\nError Accumulated Register:\n");
	errDisplay(rdData);
}

/*
* @fn				- Err_ClearAcc
* 
* @brief			- clears the accumulated error register
*
* @param[in]		- n/a
*
* @return			-
*
*/
void Err_ClearAcc(void) 
{
	// read ERR_ACC reg
	uint8_t rdData = i2cEnRdByte(ERR_H_CLR);

	// write enable bit
	rdData |= (1 << ERR_H_CLR_BIT);
	i2cEnWrByte(ERR_H_CLR, rdData);

	// read value in ERR_H_CLR
	rdData = i2cEnRdByte(ERR_H_CLR);

	// write disable bit
	rdData &= ~(1 << ERR_H_CLR_BIT);
	i2cEnWrByte(ERR_H_CLR, rdData);

	printf("cleared accumulated error register\n");
}

/*
* @fn				- Err_LiveRd
* 
* @brief			- reads the live error register every ~10ms
*
* @param[in]		- n/a
*
* @return			-
*
*/
void Err_LiveRd(void) 
{	

	printf("\nError Live Register:\n");

	// enable ERR_H_CLR reg
	uint8_t data[1];
	data[0] = ERR_LIVE;
	i2cWrite(data, 1);
	uint8_t* rdData;

	while(1)
	{
		// read i2c data
		rdData = i2cRead(1);

		if (!*rdData)
		{
			errDisplay(*rdData);
		}

		// sleep for 100ms
		sleepMillisec(0,10);
	}
}

/*
	GENERAL FUNCTIONS
*/

// display results
void errDisplay(uint8_t data)
{
	// if statement to determine specific error	
	if ((data >> 0) & 1)
	{
		printf("   err: flying capacitor over-voltage error\n");
	}

	if ((data >> 1) & 1) 
	{
		printf("   err: over-current protection\n");
	}

	if ((data >> 2) & 1) 
	{
		printf("   err: pll error\n");
	}

	if ((data >> 3) & 1) 
	{
		printf("   err: PVDD under-voltage protection\n");
	}

	if ((data >> 4) & 1) 
	{
		printf("   err: over-temperature warning\n");
	}

	if ((data >> 5) & 1) 
	{
		printf("   err: over-temperature error\n");
	}

	if ((data >> 6) & 1) 
	{
		printf("   err: pin-to-pin low impedance protection\n");
	} 

	if ((data >> 7) & 1) 
	{
		printf("   err: DC protection\n");
	}
}
