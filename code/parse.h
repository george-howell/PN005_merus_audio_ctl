/* parse.h
*
* parse input data
*
* Created By: G. Howell
* Created On: 23/07/2020
*
*/

#ifndef INC_PARSE_H_
#define INC_PARSE_H_

typedef struct _arg {
		int bus;
		int devAddr;
		char opt;
		char* arg;
	} parData_s;

parData_s* parseArgs(int, char**);

#endif
