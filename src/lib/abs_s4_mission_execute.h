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

void abs_s4_mission_execute()
{
	switch(g_mission_number)
	{
	case 1:
		break;

	case 2:
		abs_turn(CLOCKWISE, SWING, TURN_TO, 60, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/30, 50, true, GYRO);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 128, 60);
		if(g_end_point == 3) g_to_turn_dist = g_forward_crate1_to_turn_dist+5;
		else if(g_end_point == 2) g_to_turn_dist = 45;
		break;

	case 3:
		abs_turn(CLOCKWISE, SWING, TURN_TO, 60, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/29, 50, true, GYRO);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 135, 60);
		abs_drive(BACKWARD, E_ANGLE, /*distance in cm*/23, 50, true, GYRO);
		if(g_end_point == 3)g_to_turn_dist = g_forward_crate2_to_turn_dist;
		else g_to_turn_dist = 70;
		break;

	case 4:
		abs_turn(CLOCKWISE, SWING, TURN_TO, 60, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/29, 50, true, GYRO);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 135, 60);
		abs_drive(BACKWARD, E_ANGLE, /*distance in cm*/75, 50, true, GYRO);
		if(g_end_point == 3)g_to_turn_dist = g_forward_crate3_to_turn_dist;
		else g_to_turn_dist = 120;
		break;

	case 5:
		abs_turn(CLOCKWISE, SWING, TURN_TO, 60, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/29, 50, true, GYRO);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 135, 60);
		abs_drive(BACKWARD, E_ANGLE, /*distance in cm*/100, 50, true, GYRO);
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
	dl_step++;
	dl_robot_action_state = dl_run_abdd;
	dl_robot_action_detail = dl_abdd_open;
	dl_speed = servoChangeRate[abdd];
	dl_dist = g_abdd_up;
	servo[abdd] = g_abdd_up;
	wait1Msec(2000);
	servo[abdd] = g_abdd_down;

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
		servo[abdd] = g_abdd_up;
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

#endif /* !ABS_S4_MISSION_EXECUTE_H */
