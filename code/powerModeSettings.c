/* powerModeSettings.c
*
* API's handles for the power mode settings registers
*
* Created By: G. Howell
* Created On: 23/07/2020
*
*/

#include <stdio.h>
#include <stdint.h>
#include "ma1270p.h"
#include "i2c.h"
#include "powerModeSettings.h"

/*
	API's
*/

/*
* @fn				- PMode_ReadAll
* 
* @brief			- reads all the power mode registers
*
* @param[in]		- n/a
*
* @return			- n/a
*
*/
void PMode_ReadAll(void)
{
	printf("Power Mode Settings:\n");

	// read Power Mode Control
	uint8_t rdData = i2cEnRdByte(PMC);

	// manual or auto mode
	if ((rdData >> PM_MAN_PM) & 1)
	{
		printf("   Man Pm: Man\n");
	} else
	{
		printf("   Man Pm: Auto\n");
	}

	// manual power mode
	printf("   Man Pm Mode: %d\n", (rdData >> PM_MAN) & PM_MAN_BITS);

	// read Threshold for Power Mode change PM1=>PM2
	rdData = i2cEnRdByte(PM_1_2);
	printf("   Thres PM1->PM2: %d\n", rdData);

	// read Threshold for Power Mode change PM2=>PM1
	rdData = i2cEnRdByte(PM_2_1);
	printf("   Thres PM2->PM1: %d\n", rdData);

	// read Threshold for Power Mode change PM2=>PM3
	rdData = i2cEnRdByte(PM_2_3);
	printf("   Thres PM2->PM3: %d\n", rdData);

	// read Threshold for Power Mode change PM3=>PM2
	rdData = i2cEnRdByte(PM_3_2);
	printf("   Thres PM3->PM2: %d\n", rdData);

	// read Select Power Mode Profile setting
	rdData = i2cEnRdByte(PM_PROF);
	printf("   Power Mode Profile: %d\n", (rdData & PM_PROF_BITS));

	// read Power Mode Profile configuration
	rdData = i2cEnRdByte(PM_PROF_CONFIG);
	
	uint8_t pmBits = ((rdData>>PM_PROF_CFG_1) & PM_PROF_CFG_BITS);
	printf("   PM1 Scheme: ");
	pmProfDisp(pmBits);

	pmBits = ((rdData>>PM_PROF_CFG_2) & PM_PROF_CFG_BITS);
	printf("   PM2 Scheme: ");
	pmProfDisp(pmBits);

	pmBits = ((rdData>>PM_PROF_CFG_3) & PM_PROF_CFG_BITS);
	printf("   PM3 Scheme: ");
	pmProfDisp(pmBits);

}

/*
	GENERAL FUNCTIONS
*/

void pmProfDisp(uint8_t pmBits)
{
	if (pmBits==0)
	{
		printf("A\n");
	} else if (pmBits==1)
	{
		printf("B\n");
	} else if (pmBits==2)
	{
		printf("C\n");
	} else
	{
		printf("D\n");
	}
}



