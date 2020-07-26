/* parse.c
*
* parse input data
*
* Created By: G. Howell
* Created On: 23/07/2020
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "parse.h"
#include "usage.h"
#include "ma1270p.h"

parData_s* parseArgs(int argc, char ** argv)
{
	if (argc==1) 
	{
		usageErr();
	}

	parData_s* parData = (parData_s*) malloc(sizeof(parData_s));

	// sets default i2c device parameters
	parData->bus = 1;
	parData->devAddr = I2C_DEVADDR_1;

	int c;

	while ((c = getopt(argc, argv, "b:d:e:m:p:a:i:v:g:")) != -1)
	    switch (c)
	 	{
	 		case 'b':
	 			parData->bus  = atoi(optarg);
	 			break;

	 		case 'd':
	 			parData->devAddr = strtoll(optarg, NULL, 16);
	 			break;

	 		case 'g':
	 			if (!strcmp(optarg, "rdAll"))
	 			{
	 				parData->opt = c;
	 				parData->arg = optarg;

	 			} else 
	 			{
	 				printf("opt: %c; arg: %s\n",  c, optarg);
	 				usageArgErr(optarg);
	 			}
	 			break;

	 		case 'e':
	 			if (!strcmp(optarg, "acc") || !strcmp(optarg, "liv") || !strcmp(optarg, "clr"))
	 			{
	 				parData->opt = c;
	 				parData->arg = optarg;

	 			} else 
	 			{
	 				printf("opt: %c; arg: %s\n",  c, optarg);
	 				usageArgErr(optarg);
	 			}
	 			break;

	 		case 'm':
	 			if (!strcmp(optarg, "ch0") || !strcmp(optarg, "ch1") || !strcmp(optarg, "msel"))
	 			{
	 				parData->opt = c;
	 				parData->arg = optarg;

	 			} else 
	 			{
	 				printf("opt: %c; arg: %s\n",  c, optarg);
	 				usageArgErr(optarg);
	 			}
	 			break;

	 		case 'p':
	 			if (!strcmp(optarg, "rdAll"))
	 			{
	 				parData->opt = c;
	 				parData->arg = optarg;

	 			} else 
	 			{
	 				printf("opt: %c; arg: %s\n",  c, optarg);
	 				usageArgErr(optarg);
	 			}
	 			break;

	 		case 'a':
	 			if (!strcmp(optarg, "rdAll") || !strcmp(optarg, "clrOCP"))
	 			{
	 				parData->opt = c;
	 				parData->arg = optarg;

	 			} else 
	 			{
	 				printf("opt: %c; arg: %s\n",  c, optarg);
	 				usageArgErr(optarg);
	 			}
	 			break;

	 		case 'i':
	 			if (!strcmp(optarg, "rdAll"))
	 			{
	 				parData->opt = c;
	 				parData->arg = optarg;

	 			} else 
	 			{
	 				printf("opt: %c; arg: %s\n",  c, optarg);
	 				usageArgErr(optarg);
	 			}
	 			break;

	 		case 'v':
	 			if (!strcmp(optarg, "rdAll"))
	 			{
	 				parData->opt = c;
	 				parData->arg = optarg;

	 			} else 
	 			{
	 				printf("opt: %c; arg: %s\n",  c, optarg);
	 				usageArgErr(optarg);
	 			}
	 			break;

	 		default:
	 			usageErr();
	 	}

	 return parData;
}
