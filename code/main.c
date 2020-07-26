#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ma1270p.h"
#include "parse.h"
#include "usage.h"
#include "error.h"
#include "i2c.h"
#include "chMonitor.h"
#include "powerModeSettings.h"
#include "audioProtect.h"
#include "i2sFmt.h"
#include "volLim.h"

int main(int argc, char** argv)
{
 	parData_s* parseData = (parData_s*) malloc(sizeof(parData_s));

	// parse input arguments
	parseData = parseArgs(argc, argv);

	printf("Setup:\n   devAddr: 0x%x; bus: %d\n",  parseData->devAddr, parseData->bus);

	// open i2c device
 	i2cOpen(parseData->bus);

 	// initialise i2c with dev address
 	i2cInit(parseData->devAddr);

	// start function
	if (parseData->opt=='e')
	{
		if (!strcmp(parseData->arg, "acc"))
		{
			Err_AccumRd();
		} else if (!strcmp(parseData->arg, "liv"))
		{
			Err_LiveRd();
		} else if (!strcmp(parseData->arg, "clr"))
		{
			Err_ClearAcc();
		}
	} else if (parseData->opt=='m')
	{
		if (!strcmp(parseData->arg, "ch0"))
		{
			Mon_Ch0();
		} else if (!strcmp(parseData->arg, "ch1"))
		{
			Mon_Ch1();
		} else if (!strcmp(parseData->arg, "msel"))
		{
			Mon_MSEL();
		}
	} else if (parseData->opt=='p')
	{
		if (!strcmp(parseData->arg, "rdAll"))
		{
			PMode_ReadAll();
		}
	} else if (parseData->opt=='a')
	{
		if (!strcmp(parseData->arg, "rdAll"))
		{
			AP_ReadAll();
		} else if (!strcmp(parseData->arg, "clrOCP"))
		{
			AP_ClrOCP();
		}
	} else if (parseData->opt=='i')
	{
		if (!strcmp(parseData->arg, "rdAll"))
		{
			I2S_ReadAll();
		}
	} else if (parseData->opt=='v')
	{
		if (!strcmp(parseData->arg, "rdAll"))
		{
			VL_ReadAll();
		}
	} else if (parseData->opt=='g')
	{
		if (!strcmp(parseData->arg, "rdAll"))
		{
			Err_AccumRd();
			Mon_Ch0();
			Mon_Ch1();
			Mon_MSEL();
			PMode_ReadAll();
			AP_ReadAll();
			I2S_ReadAll();
			VL_ReadAll();
		}
	}

	// close i2c device
	i2cClose();

	return (EXIT_SUCCESS);
}
