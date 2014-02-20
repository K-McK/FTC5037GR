/**
*
*  @file abs_control_light_sensor.h
*
*  @brief  Enter a description of what this function does
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/
#ifndef ABS_CONTROL_LIGHT_SENSOR_H
#define ABS_CONTROL_LIGHT_SENSOR_H

void abs_control_light_sensor(e_light_sensor_status status)
{
	if(status == ACTIVE)
	{
		LSsetActive(LEGOLS);
		//LSsetActive(LEGOLS);
	}
	else
	{
		LSsetInactive(LEGOLS);
		//LSsetInactive(LEGOLS);
	}
}

#endif /* !TEMPLATE_H */
