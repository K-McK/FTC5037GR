/**
 *
 *  @file abs_s4_mission_execute.h
 *
 *  @brief runs the missions from the starting point S3
 *
 *  @param None n/a
 *
 *  @return returns nothing
 *
 *  @copyright Copyright 2013, Got Robot? FTC Team 5037
 *
 */

#ifndef ABS_S4_MISSION_EXECUTE_H
#define ABS_S4_MISSION_EXECUTE_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_stop_robot.h"
#include "abs_end_ramp.h"
#include "abs_dlog.h"

void abs_s4_mission_execute()
{
	switch(g_mission_number)
	{
	case 1:
		break;

	case 2:
		abs_drive(FORWARD, E_ANGLE, 5, 30, true, GYRO);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 45, 40);
		abs_drive(FORWARD, E_ANGLE, 37, 60, true, GYRO);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 136, 30);
		abs_drive(FORWARD, E_ANGLE, 5, 30, true, GYRO);

		if(g_end_point == 3) g_to_turn_dist = g_forward_crate1_to_turn_dist;
		else if(g_end_point == 2) g_to_turn_dist = 45;
		break;

	case 3:
		abs_drive(FORWARD, E_ANGLE, 5, 30, true, GYRO);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 45, 40);
		abs_drive(FORWARD, E_ANGLE, 37, 60, true, GYRO);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 136, 30);
		abs_drive(BACKWARD, E_ANGLE, 7, 50, true, GYRO);
		if(g_end_point == 3)g_to_turn_dist = g_forward_crate2_to_turn_dist;
		else g_to_turn_dist = 70;
		break;

	case 4:
		abs_drive(FORWARD, E_ANGLE, 5, 30, true, GYRO);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 45, 40);
		abs_drive(FORWARD, E_ANGLE, 37, 60, true, GYRO);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 136, 30);
		abs_drive(BACKWARD, E_ANGLE, 55, 50, true, GYRO);
		if(g_end_point == 3)g_to_turn_dist = g_forward_crate3_to_turn_dist;
		else g_to_turn_dist = 120;
		break;

	case 5:
		abs_drive(FORWARD, E_ANGLE, 5, 30, true, GYRO);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 45, 40);
		abs_drive(FORWARD, E_ANGLE, 37, 60, true, GYRO);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 136, 30);
		abs_drive(BACKWARD, E_ANGLE, 82, 50, true, GYRO);
		if(g_end_point == 3)g_to_turn_dist = g_forward_crate4_to_turn_dist;
		else g_to_turn_dist = 145;
		break;

	case 6:
		abs_turn(CLOCKWISE, SWING, TURN_TO, 60, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/30, 50, true, GYRO);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 120, 60);
		abs_drive(FORWARD, E_ANGLE, g_to_turn_dist, 50, true, GYRO);
		abs_turn(CLOCKWISE, POINT, TURN, 90, 60);
		abs_drive(FORWARD, E_ANGLE, 180, 50, true, GYRO);
		break;

	case 7:
		break;
	}
	if(g_mission_number != 0)
	{
		abs_dlog(__FILE__,"abdd up");
		servo[abdd] = g_abdd_up;
		StartTask (abs_calibrate_optical);
		wait1Msec(2000);
		servoChangeRate[abdd] = 10;
		servo[abdd] = g_abdd_down;
		abs_dlog(__FILE__,"abdd down");
	}

	wait1Msec(g_end_delay * DELAY_MULTIPLICATION_FACTOR);
	wait1Msec(100);
}

#endif /* !ABS_S4_MISSION_EXECUTE_H */
