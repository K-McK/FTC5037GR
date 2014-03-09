/**
*
*  @file abs_gyro1_cal.h
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

#ifndef ABS_GYRO1_CAL_H
#define ABS_GYRO1_CAL_H

task abs_gyro1_cal()
{
	g_gyro1_drift = abs_gyro_wrapper(GYRO1);
	g_gyro1_cal_done = true;
}
#endif
