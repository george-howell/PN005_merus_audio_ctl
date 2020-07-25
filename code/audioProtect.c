/* audioProtect.c
*
* API's handles for the audio protection registers
*
* Created By: G. Howell
* Created On: 23/07/2020
*
*/

#include <stdio.h>
#include <stdint.h>
#include "ma1270p.h"
#include "i2c.h"
#include "audioProtect.h"

/*
* @fn				- AP_ReadAll
* 
* @brief			- reads all the audio proctection settings
*
* @param[in]		- n/a
*
* @return			- n/a
*
*/
void AP_ReadAll(void)
{

	printf("Audio Protection Settings:\n");

	// read Soft-clipping and over- current protection latching
	uint8_t rdData = i2cEnRdByte(SCLIP_OCPROC);
	if ((rdData>>PM_CLIP) & 1)
	{
		printf("   Soft Clip: enabled\n");
	} else
	{
		printf("   Soft Clip: disabled\n");
	}
	if ((rdData>>PM_OCP) & 1)
	{
		printf("   OCP: enabled\n");
	} else
	{
		printf("   OCP: disabled\n");
	}

	// read Audio in mode
	rdData = i2cEnRdByte(AUD_IN_MODE);

	if ((rdData>>AP_AI_MODE) & AP_AI_MODE_BITS)
	{
		printf("   Audio In Mode: 26dB gain\n");
	} else
	{
		printf("   Audio In Mode: 20dB gain\n");
	}

	// read Audio in mode overwrite
	rdData = i2cEnRdByte(AUD_IN_MODE_OW);

	if (rdData>>AP_AI_MODE_OVER)
	{
		printf("   Audio In Mode Overwrite: enabled\n");
	} else
	{
		printf("   Audio In Mode Overwrite: disabled\n");
	}

	// read DC protection
	rdData = i2cEnRdByte(DC_PROT);

	if (rdData>>AP_DC_PROC)
	{
		printf("   DC Protection: enabled\n");
	} else
	{
		printf("   DC Protection: disabled\n");
	}

}

/*
* @fn				- AP_ClrOCP
* 
* @brief			- clears the OCP latch
*
* @param[in]		- n/a
*
* @return			- n/a
*
*/
void AP_ClrOCP(void)
{
	// read value
	uint8_t rdData = i2cEnRdByte(OCP_LATCH_CLR);

	// write enable bit
	rdData |= (1 << AP_OCP_CLR);
	i2cEnWrByte(OCP_LATCH_CLR, rdData);

	// read value
	rdData = i2cEnRdByte(OCP_LATCH_CLR);

	// clear enable bit
	rdData &= ~(1 << AP_OCP_CLR);
	i2cEnWrByte(OCP_LATCH_CLR, rdData);

	printf("cleared OCP latch register\n");

}















