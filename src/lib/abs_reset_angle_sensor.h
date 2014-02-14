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
#ifndef ABS_RESET_ANGLE_SENSOR_H
#define ABS_RESET_ANGLE_SENSOR_H

long abs_reset_angle_sensor_val()
{
	g_angle_sensor_val = HTANGreadAccumulatedAngle(angle_sensor);
}

#endif /* !ABS_RESET_ANGLE_SENSOR_H */
