/* usage.c
*
* parse input data
*
* Created By: G. Howell
* Created On: 18/07/2020
*
*/

#include "usage.h"
#include <stdio.h>
#include <stdlib.h>

/* usage option error */
void usageOptErr(void)
{
	fprintf(stderr, "Error: incorrect usage option\n");
	usage();
}

/* usage argument error */
void usageArgErr(char* arg)
{
	fprintf(stderr, "Error: incorrect usage argument %s\n", arg);
	usage();
}

/* usage  error */
void usageErr(void)
{
	fprintf(stderr, "Error: incorrect usage\n");
	usage();
}

/* usage statement */
void usage(void)
{
	printf("MA1270P_CTL\n");
	printf("Usage:\n");
	printf("  ma1270p_ctl -bdempa [opt]\n");
	printf("  * other than -b and -d, only one other option may be used\n");
	printf("  * if no -b or -d option selected, -b defaults to 1, -d defaults to 0x20\n");
	printf("\n");
	printf("  EXAMPLE: ma1270p_ctl -b 1 -d 0x20 -e acc\n");
	printf("\n");
	printf("Options:\n");
	printf("  -b: i2c bus (default=1)\n"); 
	printf("      [1,2,etc]\n");
	printf("  -d: device address (default=0x20)\n"); 
	printf("      [0x20,0x21,etc]\n");
	printf("  -g: general\n");
	printf("      [rdAll] - reads all parameters from all registers\n");
	printf("  -e: error monitor\n"); 
	printf("      [acc] - accumulated errors\n");
	printf("      [liv] - live errors\n");
	printf("      [clr] - clears accumulated errors\n");
	printf("  -m: channel config monitors\n"); 
	printf("      [ch0] - get channel 0 configuration\n");
	printf("      [ch1] - get channel 0 configuration\n");
	printf("      [msel] - get msel output configuration\n");
	printf("  -p: power mode config\n"); 
	printf("      [rdAll] - read all parameter values\n");
	printf("  -a: audio protection registers\n"); 
	printf("      [rdAll] - read all parameter values\n");
	printf("      [clrOCP] - clear the OCP latch\n");
	printf("  -i: i2s format\n"); 
	printf("      [rdAll] - read all parameter values\n");
	printf("  -v: volume control and limiter registers\n"); 
	printf("      [rdAll] - read all parameter values\n");
	printf("\n");

	exit(EXIT_FAILURE);
}
