/**
*
*  @file abs_disable_gyro.h
*
*  @brief
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_DISABLE_GYRO_H
#define ABS_DISABLE_GYRO_H

#include "global_variables.h"

#define HIGH_GYRO_VAL 9999

void abs_disable_gyro(e_gyro_names disable_gyro)
{
	if(disable_gyro == GYRO1)
	{
		g_gyro1_cal_done = true;
		g_gyro1_drift = HIGH_GYRO_VAL;
		g_gyro_noise1 = HIGH_GYRO_VAL;
	}
	else
	{
		g_gyro2_cal_done = true;
		g_gyro2_drift = HIGH_GYRO_VAL;
		g_gyro_noise2 = HIGH_GYRO_VAL;
	}
}
#endif /* !ABS_INITIALIZE_H */
