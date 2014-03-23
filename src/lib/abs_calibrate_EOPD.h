/**
*
*  @file abs_calibrate_EOPD.h
*
*  @brief  Calibrates the EOPD sensor
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/
#ifndef ABS_CALIBRATE_EOPD_H
#define ABS_CALIBRATE_EOPD_H

#include "global_variables.h"
#include "abs_dlog.h"
#include "math_utils.h"

task abs_calibrate_EOPD()
{
	servo[EOPD_sensor] = EOPD_SERVO_DOWN;
	wait1Msec(1000);

	long calibration_start = nPgmTime;
        int i;
        int avg_EOPD_reading = 0;
        int min_EOPD_reading = DEFAULT_CALIBRATED_EOPD_THRESHOLD;
        int max_EOPD_reading = 0;

	for(i=0; nPgmTime < EOPD_SENSOR_CALIBRATION_TIME + calibration_start; i++)
        {
          int EOPD_reading = g_EOPD_sensor;

          min_EOPD_reading = min(min_EOPD_reading, EOPD_reading);
          max_EOPD_reading = max(min_EOPD_reading, EOPD_reading);
          avg_EOPD_reading = running_avg(avg_EOPD_reading, i, EOPD_reading);

	  wait1Msec(EOPD_CALIBRATION_SAMPLE_RATE);
        }

	abs_dlog(__FILE__ , "Captured Data", "count", i, "avg EOPD reading", avg_EOPD_reading, "min EOPD reading", min_EOPD_reading, "max EOPD reading", max_EOPD_reading);

	//Tells the robot how bright the white line should be based on how black black is
	if(avg_EOPD_reading == 0)
	{
		g_calibrated_EOPD_threshold_val = DEFAULT_CALIBRATED_EOPD_THRESHOLD;
		abs_dlog(__FILE__ , "EOPD calibration failed", "g_calibrated_EOPD_threshold_val", g_calibrated_EOPD_threshold_val, "avg_EOPD_reading", avg_EOPD_reading, "g_EOPD_delta_value", g_EOPD_delta_value);
	}
	else
	{
		g_calibrated_EOPD_threshold_val = avg_EOPD_reading + g_EOPD_delta_value;

		abs_dlog(__FILE__ , "EOPD calibration worked", "g_calibrated_EOPD_threshold_val", g_calibrated_EOPD_threshold_val, "avg_EOPD_reading", avg_EOPD_reading, "g_EOPD_delta_value", g_EOPD_delta_value);
	}

	wait1Msec(1000);
	servo[EOPD_sensor] = EOPD_SERVO_UP;
}

#endif /* !TEMPLATE_H */
