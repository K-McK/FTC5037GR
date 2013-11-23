/**
*
*  @file abs_motor.h
*
*  @brief  Enter a description of what this function does
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/
#ifndef ABS_MOTOR_H
#define ABS_MOTOR_H

void abs_motor(e_motor_move move_type, int power)
{
	if(move_type == FLAG)
	{
		motor[jolly_roger] = power;
	}
	else if(move_type == LIFT)
	{
		motor[sky_hook] = power;
	}
}
#endif /* !ABS_MOTOR_H */
