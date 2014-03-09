/**
*
*  @file abs_gyro2_cal.h
*
*  @brief
*
*  @param None n/a
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_GYRO2_CAL_H
#define ABS_GYRO2_CAL_H

task abs_gyro2_cal()
{
	g_gyro2_drift = abs_gyro_wrapper(GYRO2);
	g_gyro2_cal_done = true;
}
#endif
