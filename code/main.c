#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ma1270p.h"
#include "parse.h"
#include "usage.h"
#include "error.h"
#include "i2c.h"

int main(int argc, char** argv)
{
 	parData_s* parseData = (parData_s*) malloc(sizeof(parData_s));

	// parse input arguments
	parseData = parseArgs(argc, argv);

	printf("devAddr: 0x%x; bus: %d\n",  parseData->devAddr, parseData->bus);

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
	}

	// close i2c device
	i2cClose();

	return (EXIT_SUCCESS);
}
