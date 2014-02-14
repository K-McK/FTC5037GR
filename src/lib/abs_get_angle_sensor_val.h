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
#ifndef ABS_GET_ANGLE_SENSOR_VAL_H
#define ABS_GET_ANGLE_SENSOR_VAL_H

long abs_get_angle_sensor_val(e_angle_val_type angle_val)
{
	if(angle_val == RELATIVE)
	{
		return abs(HTANGreadAccumulatedAngle(angle_sensor) - g_angle_sensor_val);
	}
	else if(angle_val == RAW)
	{
		return abs(HTANGreadAccumulatedAngle(angle_sensor);
	}
	else
	{
		return abs(HTANGreadAccumulatedAngle(angle_sensor) - g_angle_sensor_val)/INT_ANGLE_SENSOR_CIRCUMFERENCE;
}
}

#endif /* !ABS_GET_ANGLE_SENSOR_VAL_H */
