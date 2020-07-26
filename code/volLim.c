/* volLim.c
*
* API's for the volume and limiter registers
*
* Created By: G. Howell
* Created On: 23/07/2020
*
*/

#include <stdio.h>
#include <stdint.h>
#include "i2c.h"
#include "ma1270p.h"
#include "volLim.h"

/*
	API's
*/

/*
* @fn				- VL_ReadAll
* 
* @brief			- reads all the volume and limiter registers
*
* @param[in]		-
*
* @return			-
* 
*
*/
void VL_ReadAll(void)
{
	printf("Volume and Limiter Settings:\n");

	// read audio_proc_attack, audio_proc_release and audio_proc_enable
	uint8_t rdData = i2cEnRdByte(VOL_LIM_AR);

	// get audio_proc_attack
	uint8_t regBits = (rdData>>VOL_ATT_SHIFT) & VOL_ATT_BIT;
	printf("   Lim Attack: ");
	if (regBits==0)
	{
		printf("slow\n");
	} else if (regBits==1)
	{
		printf("normal\n");
	} else
	{
		printf("fast\n");
	}

	// get audio_proc_release
	regBits = (rdData>>VOL_REL_SHIFT) & VOL_REL_BIT;
	printf("   Lim Release: ");
	if (regBits==0)
	{
		printf("slow\n");
	} else if (regBits==1)
	{
		printf("normal\n");
	} else
	{
		printf("fast\n");
	}

	// get audio_proc_enable
	regBits = (rdData>>VOL_BPASS_SHIFT) & 1;
	printf("   Audio Proc Bypass: ");
	if (regBits)
	{
		printf("in use\n");
	} else
	{
		printf("bypassed\n");
	}

	// read audio_proc_mute and audio_proc_limiter
	rdData = i2cEnRdByte(VOL_MUTE_LIM_BY);

	// get audio_proc_mute
	printf("   Audio Mute: ");
	if ((rdData>>VOL_MUTE_SHIFT) & 1)
	{
		printf("muted\n");
	} else
	{
		printf("unmuted\n");
	}

	// get audio_proc_limiter
	printf("   Lim Bypass: ");
	if ((rdData>>VOL_BYLIM_SHIFT) & 1)
	{
		printf("disabled\n");
	} else
	{
		printf("enabled\n");
	}

	// read vol_db_master
	rdData = i2cEnRdByte(VOL_DB_MST);
	printf("   Master Int dB Vol: 0x%x\n", rdData);

	// read vol_lsb_master
	rdData = i2cEnRdByte(VOL_LSB_MST);
	printf("   Master Frac dB Vol: 0x%x\n", (rdData & VOL_LSB_BITS));

	// read vol_db_ch0
	rdData = i2cEnRdByte(VOL_DB_CH0);
	printf("   Ch0L Int dB Vol: 0x%x\n", rdData);

	// read vol_db_ch1
	rdData = i2cEnRdByte(VOL_DB_CH1);
	printf("   Ch0R Int dB Vol: 0x%x\n", rdData);

	// read vol_db_ch2
	rdData = i2cEnRdByte(VOL_DB_CH2);
	printf("   Ch1L Int dB Vol: 0x%x\n", rdData);

	// read vol_db_ch3
	rdData = i2cEnRdByte(VOL_DB_CH3);
	printf("   Ch1R Int dB Vol: 0x%x\n", rdData);

	// read vol_lsb_ch0, vol_lsb_ch1, vol_lsb_ch2 and vol_lsb_ch3
	rdData = i2cEnRdByte(VOL_LSB_CH0_3);

	// get vol_lsb_ch0
	regBits = (rdData>>VOL_LSB_CH0_SHIFT) & VOL_LSB_BITS;
	printf("   Ch0L Fract dB Vol: 0x%x\n", regBits);

	// get vol_lsb_ch1
	regBits = (rdData>>VOL_LSB_CH1_SHIFT) & VOL_LSB_BITS;
	printf("   Ch0R Fract dB Vol: 0x%x\n", regBits);

	// get vol_lsb_ch2
	regBits = (rdData>>VOL_LSB_CH2_SHIFT) & VOL_LSB_BITS;
	printf("   Ch1L Fract dB Vol: 0x%x\n", regBits);

	// get vol_lsb_ch3
	regBits = (rdData>>VOL_LSB_CH3_SHIFT) & VOL_LSB_BITS;
	printf("   Ch1R Fract dB Vol: 0x%x\n", regBits);

	// read thr_db_ch0
	rdData = i2cEnRdByte(VOL_TH_DB_CH0);
	printf("   Ch0L Int dBFS Lim: 0x%x\n", rdData);

	// read thr_db_ch1
	rdData = i2cEnRdByte(VOL_TH_DB_CH1);
	printf("   Ch0R Int dBFS Lim: 0x%x\n", rdData);

	// read thr_db_ch2
	rdData = i2cEnRdByte(VOL_TH_DB_CH2);
	printf("   Ch1L Int dBFS Lim: 0x%x\n", rdData);

	// read thr_db_ch3
	rdData = i2cEnRdByte(VOL_TH_DB_CH3);
	printf("   Ch1R Int dBFS Lim: 0x%x\n", rdData);

	// read vol_lsb_ch0, thr_lsb_ch1, thr_lsb_ch2 and thr_lsb_ch3
	rdData = i2cEnRdByte(TH_LSB_CH0);

	// get thr_lsb_ch1
	regBits = (rdData>>VOL_LSB_CH0_SHIFT) & VOL_LSB_BITS;
	printf("   Ch0L Fract dBFS Lim: 0x%x\n", regBits);

	// get vol_lsb_ch1
	regBits = (rdData>>VOL_LSB_CH1_SHIFT) & VOL_LSB_BITS;
	printf("   Ch0R Fract dBFS Lim: 0x%x\n", regBits);

	// get vol_lsb_ch2
	regBits = (rdData>>VOL_LSB_CH2_SHIFT) & VOL_LSB_BITS;
	printf("   Ch1L Fract dBFS Lim: 0x%x\n", regBits);

	// get vol_lsb_ch3
	regBits = (rdData>>VOL_LSB_CH3_SHIFT) & VOL_LSB_BITS;
	printf("   Ch1R Fract dBFS Lim: 0x%x\n", regBits);

	// read audio_proc_limiter_mon and audio_proc_clip_mon
	rdData = i2cEnRdByte(AUDP_LC_MON);

	// get audio_proc_limiter_mon
	printf("   Lim Active: ");
	if ((rdData>>4) & 1)
	{
		printf("Ch0L ");
	}
	if ((rdData>>5) & 1)
	{
		printf("Ch0R ");
	}
	if ((rdData>>6) & 1)
	{
		printf("Ch1L ");
	}
	if ((rdData>>7) & 1)
	{
		printf("Ch1R ");
	}
	if (((rdData>>4) & 0xf) == 0)
	{
		printf("no channels");
	}
	printf("\n");

	printf("   Clip Active: ");
	// get audio_proc_clip_mon
	if ((rdData>>0) & 1)
	{
		printf("Ch0L ");
	}
	if ((rdData>>1) & 1)
	{
		printf("Ch0R ");
	}
	if ((rdData>>2) & 1)
	{
		printf("Ch1L ");
	}
	if ((rdData>>3) & 1)
	{
		printf("Ch1R ");
	}
	if (((rdData>>4) & 0xf) == 0)
	{
		printf("no channels");
	}
	printf("\n");
}
