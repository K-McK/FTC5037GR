/**
*
*  @file abs_get_gyro_sensor_val.h
*
*  @brief  Enter a description of what this function does
*
*  @param
*
*  @return
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/
#ifndef ABS_GET_GYRO_SENSOR_VAL_H
#define ABS_GET_GYRO_SENSOR_VAL_H

int abs_get_gyro_sensor_val(e_gyro_val_type gyro_val)
{
	if(gyro_val == RAW)
	{
		return HTGYROreadRot(HTGYRO);
	}
	else
	{
		return (HTGYROreadRot(HTGYRO) - g_original_gyro_val);
	}
}

#endif /* !ABS_GET_GYRO_SENSOR_VAL_H */
