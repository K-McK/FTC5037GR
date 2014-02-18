/**
*
*  @file template.h (this should be the name of the function)
*
*  @brief  Enter a description of what this function does
*
*  @param
*
*  @return
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/
#ifndef ABS_CALIBRATE_LIGHT_H
#define ABS_CALIBRATE_LIGHT_H

#include "global_variables.h"
#include "abs_log.h"
#include "abs_control_light_sensor.h"
#include "math_utils.h"

task abs_calibrate_light()
{
	servo[light_sensor] = LIGHT_SERVO_DOWN;
	wait1Msec(1000);
	abs_control_light_sensor(ACTIVE);

	long calibration_start = nPgmTime;
        int i;
        int avg_light_reading = 0;
        int min_light_reading = DEFAULT_CALIBRATED_LIGHT_THRESHOLD;
        int max_light_reading = 0;

	for(i=0; nPgmTime < LIGHT_SENSOR_CALIBRATION_TIME + calibration_start; i++)
        {
          int light_reading = g_light_sensor;

          min_light_reading = min(min_light_reading, light_reading);
          max_light_reading = max(min_light_reading, light_reading);
          avg_light_reading = running_avg(avg_light_reading, i, light_reading);

	  wait1Msec(LIGHT_CALIBRATION_SAMPLE_RATE);
        }

        //avg_light_reading_int = (int)avg_light_reading;

	abs_log(__FILE__ ,"Captured Data",i,avg_light_reading,min_light_reading,max_light_reading);

	//Tells the robot how bright the white line should be based on how black black is
	if(avg_light_reading == 0)
	{
		g_calibrated_light_threshold_val = DEFAULT_CALIBRATED_LIGHT_THRESHOLD;
		abs_log(__FILE__ ,"Light calibration failed",g_calibrated_light_threshold_val,avg_light_reading,g_light_delta_value,0);
	}
	else
	{
		g_calibrated_light_threshold_val = avg_light_reading + g_light_delta_value;
		abs_log(__FILE__ ,"Light calibration worked",g_calibrated_light_threshold_val,avg_light_reading,g_light_delta_value,0);
	}

	abs_control_light_sensor(INACTIVE);
	wait1Msec(1000);
	servo[light_sensor] = LIGHT_SERVO_UP;
}

#endif /* !TEMPLATE_H */
