/* chMointor.c
*
* API's for the channel monitor registers
*
* Created By: G. Howell
* Created On: 23/07/2020
*
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "i2c.h"
#include "ma1270p.h"
#include "chMonitor.h"

/*
	API's
*/

/*
* @fn				- Mon_Ch0
* 
* @brief			- reads all the monitor registers for channel 0, Monitor 
* 					  register channel 0. Main, Frequency and Power Mode and 
* 					  Modulation Index.
*
* @param[in]		-
*
* @return			-
* 
* @todo				- check if all assumed statements are correct
*
*/
void Mon_Ch0(void)
{
	// initialise monitor data structure
	monData_s* monData = (monData_s*) malloc(sizeof(monData_s));

	/* 
		Frequency and Power Mode 
	*/

	// enable reg
	uint8_t wrData[2];
	wrData[0] = MON_REG_FP_CH0;
	i2cWrite(wrData, 1);

	// read reg
	uint8_t* rdData = i2cRead(1);
	monData->freqPowM = *rdData;

	/* 
		Main 
	*/

	// enable reg
	wrData[0] = MON_REG_CH0;
	i2cWrite(wrData, 1);

	// read reg
	rdData = i2cRead(1);
	monData->main = *rdData;

	/* 
		Modulation Index
	*/

	// enable reg
	wrData[0] = MON_REG_MOD_CH0;
	i2cWrite(wrData, 1);

	// read reg
	rdData = i2cRead(1);
	monData->mod = *rdData;

	printf("Monitor Register Channel 0: \n");
	dispMonData(monData);
}

/*
* @fn				- Mon_Ch1
* 
* @brief			- reads all the monitor registers for channel 1, Monitor 
* 					  register channel 1. Main, Frequency and Power Mode and 
* 					  Modulation Index.
*
* @param[in]		-
*
* @return			-
*
*/
void Mon_Ch1(void)
{
	// initialise monitor data structure
	monData_s* monData = (monData_s*) malloc(sizeof(monData_s));

	/* 
		Frequency and Power Mode 
	*/

	// enable reg
	uint8_t wrData[2];
	wrData[0] = MON_REG_FP_CH1;
	i2cWrite(wrData, 1);

	// read reg
	uint8_t* rdData = i2cRead(1);
	monData->freqPowM = *rdData;

	/* 
		Main 
	*/

	// enable reg
	wrData[0] = MON_REG_CH1;
	i2cWrite(wrData, 1);

	// read reg
	rdData = i2cRead(1);
	monData->main = *rdData;

	/* 
		Modulation Index
	*/

	// enable reg
	wrData[0] = MON_REG_MOD_CH1;
	i2cWrite(wrData, 1);

	// read reg
	rdData = i2cRead(1);
	monData->mod = *rdData;

	printf("Monitor Register Channel 0: \n");
	dispMonData(monData);
}

/*
* @fn				- Mon_MSEL
* 
* @brief			- reads all the monitor register Monitor MSEL register, 
* 					  to check what output configution the device is in
*
* @param[in]		-
*
* @return			-
*
*/

void Mon_MSEL(void)
{
	// enable msel_mon reg
	uint8_t wrData[2];
	wrData[0] = MON_OUT_CONFIG;
	i2cWrite(wrData, 1);

	// read reg
	uint8_t* rdData = i2cRead(1);

	// get relevant bits
	*rdData &= MON_MSEL_BITS;

	// determine config
	printf("Monitor MSEL Register:\n");
	if (*rdData == MON_BTL)
	{
		printf("   BTL\n");

	} else if (*rdData == MON_SE)
	{
		printf("   SE\n");

	} else if (*rdData == MON_BTL_SE)
	{
		printf("   BTL/SE\n");

	} else if (*rdData == MON_PBTL)
	{
		printf("   PBTL\n");

	} else
	{
		printf("   No connection\n");
	}
}

/*
	GENERAL FUNCTIONS
*/

// display the channel monitor data
void dispMonData(monData_s *monData)
{
	/* 
		Frequency and Power Mode 
	*/

	printf("   Freq Mode: 0x%.2x\n", (monData->freqPowM & MON_FREQ_M_BITS));
	printf("   Power Mode: 0x%.2x\n", (monData->freqPowM & MON_POW_M_BITS));

	/* 
		Main 
	*/

	if ((monData->main >> MON_OCP_MON) & 1)
	{
		printf("   OCP: event occured\n");
	} else
	{
		printf("   OCP: no event occured\n");
	}
	if ((monData->main >> MON_FLY_1) & 1)
	{
		printf("   Cfly1: error\n");
	} else
	{
		printf("   Cfly1: okay\n");
	}
	if ((monData->main >> MON_FLY_2) & 1)
	{
		printf("   Cfly2: error\n");
	} else
	{
		printf("   Cfly2: okay\n");
	}
	if ((monData->main >> MON_PVDD_OK) & 1)
	{
		printf("   PVDD: error\n");
	} else
	{
		printf("   PVDD: okay\n");
	}
	if ((monData->main >> MON_VDD_OK) & 1)
	{
		printf("   VDD: error\n");
	} else
	{
		printf("   VDD: okay\n");
	}
	if ((monData->main >> MON_MUTE) & 1)
	{
		printf("   Mute: muted\n");
	} else
	{
		printf("   Mute: unmuted\n");
	}

	/* 
		Modulation Index
	*/

	printf("   Mod Index: 0x%.2x\n", monData->mod);
}
