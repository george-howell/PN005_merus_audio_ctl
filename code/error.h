/* error.h
*
* API's handles for the error register functions
*
* Created By: G. Howell
* Created On: 23/07/2020
*
*/

#ifndef INC_ERROR_H_
#define INC_ERROR_H_

/*
	API's
*/
void Err_AccumRd(void);
void Err_LiveRd(void);
void Err_ClearAcc(void);

/*
	GENERAL FUNCTIONS
*/
void errDisplay(uint8_t);

#endif
