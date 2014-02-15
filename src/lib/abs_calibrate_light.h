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

task abs_calibrate_light()
{
	LSsetActive(LEGOLS);
	servo[light_sensor] = LIGHT_SERVO_DOWN;
	//Tells the robot how bright the white line should be based on how black black is
	g_calibrated_light_threshold_val = g_light_sensor + g_light_delta_value;
	servo[light_sensor] = LIGHT_SERVO_UP;
}

#endif /* !TEMPLATE_H */
