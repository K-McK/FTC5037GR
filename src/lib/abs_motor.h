/**
*
*  @file abs_motor.h
*
*  @brief  Allows the robot to move attachments in auto.c
*
*  @param move_type lets the robot know what attchment to move
*
*  @param power tells the robot how much power it should use on the attachment
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
