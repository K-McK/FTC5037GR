/**
*
*  @file abs_end_ramp.h
*
*  @brief stop point function to end on either ramp
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_END_RAMP_H
#define ABS_END_RAMP_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_log.h"
#include "abs_get_angle_sensor_val.h"
#include "abs_control_light_sensor.h"
#include "abs_mission_to_turn_amount.h"
#include "abs_lift_block_lifter.h"

void abs_end_ramp(int delay, int lift_speed)
{
	abs_log(__FILE__,"Function Enter",delay,lift_speed,0,0);

	if(g_end_point != 2 && g_end_point !=3)
	{
		abs_log(__FILE__,"Function called for incorrect ramp",0,0,0,0);
		return;
	}

	if(g_start_point == 1 || g_start_point == 2) g_to_turn_dist = g_dist_backwards;
	dl_step = dl_step+1;
	dl_robot_action_state = dl_wait;
	dl_speed = delay;
	wait1Msec(delay);
	servo[abdd] = g_abdd_down;

	if(g_end_point == 2)
	{
		abs_dlog(__FILE__ ,"drive to ramp 1");
		abs_drive(FORWARD, E_ANGLE, g_to_turn_dist, 50, true, GYRO);
	}
	else
	{
		abs_dlog(__FILE__ ,"drive to ramp 2");
		abs_drive(BACKWARD, E_ANGLE, g_to_turn_dist, 50, true, GYRO);
	}

	if(abs_get_angle_sensor_val(RELATIVE_BPU) < 5)//15)
	{
		abs_log(__FILE__,"dist fail",abs_get_angle_sensor_val(RELATIVE_BPU),0,0,0);
		motor[left_motor] = 0;
		motor[right_motor] = 0;
		PlayTone(300,200);
		return;
	}

	dl_step = dl_step+1;
	dl_robot_action_state = dl_wait;
	dl_speed = 200;
	wait1Msec(200);
#if EOPD_ACTIVE == 0
	abs_control_light_sensor(ACTIVE);
#endif
	servo[optical_servo] = OPTICAL_SERVO_DOWN;

	if(g_good_gyro && g_em_first_turn_type == CONSTANT_TURN)
	{
		abs_dlog(__FILE__ ,"first turn: good gyro");
		abs_turn(COUNTERCLOCKWISE, POINT, TURN_TO, abs_mission_to_turn_amount(g_start_point, g_end_point, g_good_gyro), 40);//was 60
	}
	else
	{
		abs_dlog(__FILE__ ,"first turn: bad gyro");
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, abs_mission_to_turn_amount(g_start_point, g_end_point, false/*g_good_gyro*/), 40);//was 60
	}

	wait1Msec(g_input_array[CORNOR_DELAY]*DELAY_MULTIPLICATION_FACTOR);
	dl_step = dl_step+1;
	dl_robot_action_state = dl_wait;
	dl_speed = 200;
	wait1Msec(200);
	abs_drive(FORWARD, E_OPTICAL, 110, 30, true, GYRO);
	if(abs_get_angle_sensor_val(RELATIVE_BPU) < 20)
	{
		abs_drive(FORWARD, E_ANGLE, 110 - abs_get_angle_sensor_val(RELATIVE_BPU), 30, true, GYRO);
	}
	abs_control_light_sensor(INACTIVE);
	dl_step = dl_step+1;
	dl_robot_action_state = dl_wait;
	dl_speed = 500;
	wait1Msec(500);
	StartTask(abs_lift_block_lifter);

	if(g_good_gyro && g_em_first_turn_type == CONSTANT_TURN)
	{
		if(g_end_point == 2)
		{
			abs_dlog(__FILE__ ,"second turn: good gyro");
			abs_turn(COUNTERCLOCKWISE, POINT, TURN_TO, 180, 40);//was 60
		}
		else
		{
			abs_dlog(__FILE__ ,"second turn: bad gyro");
			abs_turn(CLOCKWISE, POINT, TURN_TO, 0, 40);//was 50
		}
	}
	else
	{
		if(g_end_point == 2)
		{
			abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 60);
		}
		else
		{
			abs_turn(CLOCKWISE, POINT, TURN, 90, 50);
		}
	}
	/** before entering the ramp, pause for the requested time */
	wait1Msec(g_input_array[RAMP_DELAY] * DELAY_MULTIPLICATION_FACTOR);

	if(g_auto_selection_ramp_continue_options == SUB_SELECTION_RAMP_STOP) abs_drive(FORWARD, E_ANGLE, 80, 50, true, GYRO);
	else abs_drive(FORWARD, E_ANGLE, 130, 50, true, GYRO);

	//if the lift task is still running at this point then stop it
	StopTask(abs_lift_block_lifter);
}

#endif /* !ABS_S1_END_RAMP_H */
