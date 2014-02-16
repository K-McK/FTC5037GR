/**
 *
 *  @file abs_s2_mission_execute.h
 *
 *  @brief runs the missions from the starting point S2
 *
 *  @param None n/a
 *
 *  @return returns nothing
 *
 *  @copyright Copyright 2013, Got Robot? FTC Team 5037
 *
 */

#ifndef ABS_S2_MISSION_EXECUTE_H
#define ABS_S2_MISSION_EXECUTE_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_stop_robot.h"
#include "abs_end_r1.h"
#include "abs_end_r2.h"
#include "abs_log.h"
#include "abs_get_angle_sensor_val.h"

void abs_s2_mission_execute()
{
	switch(g_mission_number)
	{
	case 0:
		g_screen_state = S_ANGLE_SHOW;
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/600, 50, true, GYRO);
		break;

	case 1:
		abs_drive(BACKWARD, E_IR_DETECT, 3, 40, true, GYRO);
		PlayTone(200,20);
		//if(g_IR_angle_dist_complete == true) g_end_point = 12;
	if(g_end_point == 2)
		{
			if(abs_get_angle_sensor_val(RELATIVE_BPU) < 62) g_to_turn_dist = g_forward_crate4_to_turn_dist;
			else if(abs_get_angle_sensor_val(RELATIVE_BPU) < 100) g_to_turn_dist = g_forward_crate3_to_turn_dist;
			else if(abs_get_angle_sensor_val(RELATIVE_BPU) < 137) g_to_turn_dist = g_forward_crate2_to_turn_dist;
			else if(abs_get_angle_sensor_val(RELATIVE_BPU) < 162) g_to_turn_dist = g_forward_crate1_to_turn_dist;
		}
		else if(g_end_point == 3)
		{
			if(abs_get_angle_sensor_val(RELATIVE_BPU) < 62) g_to_turn_dist = g_backwards_crate4_to_turn_dist;
			else if(abs_get_angle_sensor_val(RELATIVE_BPU) < 100) g_to_turn_dist = g_backwards_crate3_to_turn_dist;
			else if(abs_get_angle_sensor_val(RELATIVE_BPU) < 137) g_to_turn_dist = g_backwards_crate2_to_turn_dist;
			else if(abs_get_angle_sensor_val(RELATIVE_BPU) < 162) g_to_turn_dist = g_backwards_crate1_to_turn_dist;
		}
		dl_step = dl_step+1;
		dl_robot_action_state = dl_wait;
		dl_speed = 1000;
		wait1Msec(1000);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/6, 50, true, GYRO);
		dl_step = dl_step+1;
		dl_robot_action_state = dl_wait;
		dl_speed = 500;
		wait1Msec(500);
		break;

	case 2:
		if(g_end_point == 3)g_to_turn_dist = g_backwards_crate4_to_turn_dist;
		else g_to_turn_dist = g_forward_crate4_to_turn_dist;
		abs_drive(BACKWARD, E_ANGLE, /*distance in cm*/40, 50, true, GYRO);
		break;

	case 3:
		if(g_end_point == 3)g_to_turn_dist = g_backwards_crate3_to_turn_dist;
		else g_to_turn_dist = g_forward_crate3_to_turn_dist;
		abs_drive(BACKWARD, E_ANGLE, /*distance in cm*/65, 50, true, GYRO);
		break;

	case 4:
		if(g_end_point == 3)g_to_turn_dist = g_backwards_crate2_to_turn_dist;
		else g_to_turn_dist = g_forward_crate2_to_turn_dist;
		abs_drive(BACKWARD, E_ANGLE, /*distance in cm*/115, 50, true, GYRO);
		break;

	case 5:
		if(g_end_point == 3)g_to_turn_dist = g_backwards_crate1_to_turn_dist;
		else g_to_turn_dist = g_forward_crate1_to_turn_dist;
		abs_drive(BACKWARD, E_ANGLE, /*distance in cm*/140, 50, true, GYRO);
		dl_step = dl_step+1;
		dl_robot_action_state = dl_wait;
		dl_speed = 2000;
		wait1Msec(2000);
		break;

	case 6:
		abs_turn(CLOCKWISE, POINT, TURN, 75, 60);
		dl_step = dl_step+1;
		dl_robot_action_state = dl_wait;
		dl_speed = 200;
		wait1Msec(200);
		abs_drive(FORWARD, E_ANGLE, 190, 50, true, GYRO);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 75, 60);
		abs_drive(FORWARD, E_ANGLE, 80, 50, true, GYRO);
		break;

	case 7:
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 98, 60);
		dl_step = dl_step+1;
		dl_robot_action_state = dl_wait;
		dl_speed = 200;
		wait1Msec(200);
		abs_drive(FORWARD, E_ANGLE, 87, 50, true, GYRO);
		motor[block_lift_motor] = 40;
		motor[block_lift_motor2] = 40;
		abs_turn(CLOCKWISE, POINT, TURN, 103, 60);
		motor[block_lift_motor] = 0;
		motor[block_lift_motor2] = 0;
		abs_drive(FORWARD, E_ANGLE, 80, 50, true, GYRO);
		break;
	}
	dl_step++;
	dl_robot_action_state = dl_run_abdd;
	dl_robot_action_detail = dl_abdd_open;
	dl_speed = servoChangeRate[abdd];
	dl_dist = g_abdd_up;
	abs_log(__FILE__,"abdd up",2,g_abdd_up,0,0);
	servo[abdd] = g_abdd_up;
	wait1Msec(2000);
	servo[abdd] = g_abdd_down;
	abs_log(__FILE__,"abdd down",2,g_abdd_down,0,0);

	dl_change_event = true;
	dl_ce_detail = dl_ce_end_delay;

	dl_speed = g_end_delay*1000;
	wait1Msec(g_end_delay*1000);

	dl_step++;
	dl_robot_action_detail = dl_abdd_close;
	dl_dist = g_abdd_down;

	dl_change_event = true;
	dl_ce_detail = dl_ce_end_point;

	wait1Msec(100);

	switch(g_end_point)
	{
	case 1:
		wait1Msec(2000);
		dl_step = dl_step+1;
		dl_robot_action_state = dl_wait;
		dl_speed = 2000;
		servo[abdd] = g_abdd_down;
		abs_stop_robot();
		break;
	case 2:
		abs_end_r1(2000,40);
		break;
	case 3:
		abs_end_r2(2000,40);
		break;
	}
}

#endif /* !ABS_S2_MISSION_EXECUTE_H */
