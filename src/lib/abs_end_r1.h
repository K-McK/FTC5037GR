/**
*
*  @file abs_end_r1.h
*
*  @brief stop point function to end on ramp 1
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_END_R1_H
#define ABS_END_R1_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_log.h"
#include "abs_get_angle_sensor_val.h"
#include "abs_control_light_sensor.h"
#include "abs_mission_to_turn_amount.h"
#include "abs_lift_block_lifter.h"

void abs_end_r1(int delay, int lift_speed)
{
	abs_log(__FILE__,"Function Enter",delay,lift_speed,0,0);
	//if(g_mission_number == 1)g_to_turn_dist = g_dist_backwards;
	if(g_start_point == 1 || g_start_point == 2) g_to_turn_dist = g_dist_backwards;
	dl_step = dl_step+1;
	dl_robot_action_state = dl_wait;
	dl_speed = delay;
	wait1Msec(delay);
	servo[abdd] = g_abdd_down;
	abs_drive(FORWARD, E_ANGLE, g_to_turn_dist, 50, true, GYRO);
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
	abs_control_light_sensor(ACTIVE);
	servo[light_sensor] = LIGHT_SERVO_DOWN;
	abs_turn(COUNTERCLOCKWISE, POINT, TURN_TO, abs_mission_to_turn_amount(g_start_point, g_end_point), 60);

	dl_step = dl_step+1;
	dl_robot_action_state = dl_wait;
	dl_speed = 200;
	wait1Msec(200);
	abs_drive(FORWARD, E_LIGHT, 110, 30, true, GYRO);
	StartTask(abs_lift_block_lifter);
	abs_turn(COUNTERCLOCKWISE, POINT, TURN_TO, 180, 60);

        /** before entering the ramp, pause for requested time */
	wait1Msec(g_ramp_delay * DELAY_MULTIPLICATION_FACTOR);

	if(g_auto_grabber_selection_ramp_options == SUB_SELECTION_RAMP_STOP) abs_drive(FORWARD, E_ANGLE, 80, 50, true, GYRO);
	else abs_drive(FORWARD, E_ANGLE, 130, 50, true, GYRO);
}

#endif /* !ABS_S1_END_R1_H */
