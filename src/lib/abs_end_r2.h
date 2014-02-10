/**
*
*  @file abs_end_r2.h
*
*  @brief stop point function to end on ramp 2
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_END_R2_H
#define ABS_END_R2_H

#include "abs_drive.h"
#include "abs_turn.h"

void abs_end_r2(int delay, int lift_speed)
{
	wait1Msec(delay);
	servo[abdd] = g_abdd_down;
	abs_drive(BACKWARD, E_ANGLE, g_dist_backwards, 50, true, GYRO);
	wait1Msec(200);
	abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 60);
	wait1Msec(200);
	abs_drive(FORWARD, E_LIGHT, 87, 50, true, GYRO);
	wait1Msec(500);
	motor[block_lift_motor] = lift_speed;
	motor[block_lift_motor2] = lift_speed;
	abs_turn(CLOCKWISE, POINT, TURN, 84, 50);
	motor[block_lift_motor] = 0;
	motor[block_lift_motor2] = 0;
	if(g_auto_grabber_selection_ramp_options == SUB_SELECTION_RAMP_STOP) abs_drive(FORWARD, E_ANGLE, 80, 50, true, GYRO);
	else abs_drive(FORWARD, E_ANGLE, 130, 50, true, GYRO);
}

#endif /* !ABS_S1_END_R2_H */
