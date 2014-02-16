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

task abs_calibrate_light()
{
	servo[light_sensor] = LIGHT_SERVO_DOWN;
	abs_control_light_sensor(ACTIVE);
	wait1Msec(1000);
	//Tells the robot how bright the white line should be based on how black black is
	if(g_light_sensor == 0)
	{
		g_calibrated_light_threshold_val = DEFAULT_CALIBRATED_LIGHT_THRESHOLD;
		abs_log(__FILE__ ,"Light calibration failed",g_calibrated_light_threshold_val,g_light_sensor,g_light_delta_value,0);
	}
	else
	{
		if(g_light_sensor <= 30)
		{
			g_calibrated_light_threshold_val = 32
		}
		else
		{
			g_calibrated_light_threshold_val = g_light_sensor + g_light_delta_value;
		}
		abs_log(__FILE__ ,"Light calibration worked",g_calibrated_light_threshold_val,g_light_sensor,g_light_delta_value,0);
	}
	wait1Msec(1000);
	abs_control_light_sensor(INACTIVE);
	servo[light_sensor] = LIGHT_SERVO_UP;
}

#endif /* !TEMPLATE_H */
