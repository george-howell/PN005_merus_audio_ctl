/* chMointor.h
*
* API's for the channel monitor registers
*
* Created By: G. Howell
* Created On: 24/07/2020
*
*/

#ifndef INC_CHMONITOR_H__
#define INC_CHMONITOR_H__

/* structure definitions */
typedef struct _monData {
		uint8_t freqPowM;
		uint8_t main;
		uint8_t mod;
	} monData_s;

/*
	API's
*/
void Mon_Ch0(void);
void Mon_Ch1(void);
void Mon_MSEL(void);

/*
	GENERAL FUNCTIONS
*/
void dispMonData(monData_s*);

#endif