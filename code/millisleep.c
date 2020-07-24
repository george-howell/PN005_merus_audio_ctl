/* millisleep.c
*
* millisecond sleep function
*
* Created By: G. Howell
* Created On: 20/07/2020
*
*/

#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "millisleep.h"

// millisecond sleep function
void sleepMillisec(uint32_t tSec, uint32_t tMillisec)
{
	struct timespec tim, tim2;
	tim.tv_sec = tSec;
	tim.tv_nsec = tMillisec * 1000000;

	if(nanosleep(&tim , &tim2) < 0)
   	{
    	fprintf(stderr, "ERROR: millisecond sleep system call failed\n");
   	}
}
