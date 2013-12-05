/**
 *
 *  @file abs_s3_mission_execute.h
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
#ifndef ABS_S3_MISSION_EXECUTE_H
#define ABS_S3_MISSION_EXECUTE_H

void abs_s3_mission_execute()
{
	switch(g_mission_number)
	{
	case 1:
		break;

	case 2:
		abs_turn(COUNTERCLOCKWISE, SWING, TURN_TO, 315, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/30, 50, true);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 40, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/100, 50, true);
		servo[abdd] = g_abdd_up;
		wait1Msec(2000);
		servo[abdd] = g_abdd_down;
		if(g_end_point == 3)g_to_turn_dist = 145;
		else g_to_turn_dist = g_forward_crate4_to_turn_dist;
		break;

	case 3:
		abs_turn(COUNTERCLOCKWISE, SWING, TURN_TO, 315, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/30, 50, true);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 40, 35);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/75, 50, true);
		servo[abdd] = g_abdd_up;
		wait1Msec(2000);
		servo[abdd] = g_abdd_down;
		if(g_end_point == 3)g_to_turn_dist = 120;
		else g_to_turn_dist = g_forward_crate3_to_turn_dist;
		break;

	case 4:
		abs_turn(COUNTERCLOCKWISE, SWING, TURN_TO, 315, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/33, 50, true);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 39, 50);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/25, 50, true);
		servo[abdd] = g_abdd_up;
		wait1Msec(2000);
		servo[abdd] = g_abdd_down;
		if(g_end_point == 3)g_to_turn_dist = 70;
		else g_to_turn_dist = g_forward_crate2_to_turn_dist;
		break;

	case 5:
		abs_turn(COUNTERCLOCKWISE, SWING, TURN_TO, 315, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/30, 50, true);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 35, 60);
		servo[abdd] = g_abdd_up;
		wait1Msec(2000);
		servo[abdd] = g_abdd_down;
		if(g_end_point == 3) g_to_turn_dist = 45;
		else if(g_end_point == 2) g_to_turn_dist = g_forward_crate1_to_turn_dist+5;
		break;

	case 6:
		abs_turn(COUNTERCLOCKWISE, SWING, TURN_TO, 315, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/30, 50, true);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 35, 60);
		abs_drive(BACKWARD, E_ANGLE, g_to_turn_dist, 50, true);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 60);
		abs_drive(FORWARD, E_ANGLE, 180, 50, true);
		break;

	case 7:
		break;
	}
	wait1Msec(g_end_delay*1000);
	switch(g_end_point)
	{
	case 1:
		wait1Msec(2000);
		servo[abdd] = g_abdd_down;
		motor[right_motor] = 0;
		motor[left_motor] = 0;
		motor[sky_hook] = 0;
		motor[block_lift_motor] = 0;
		motor[block_lift_motor2] = 0;
		break;
	case 2:
		wait1Msec(2000);
		servo[abdd] = g_abdd_down;
		abs_drive(FORWARD, E_ANGLE, g_to_turn_dist, 50, true);
		wait1Msec(200);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 75, 60);
		wait1Msec(200);
		abs_drive(FORWARD, E_ANGLE, 85, 50, true);
		motor[block_lift_motor] = 40;
		motor[block_lift_motor2] = 40;
		if(g_auto_grabber_selections == SUB_SELECTION_GRABBERS_IN) abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 60);
		else if(g_auto_grabber_selections == SUB_SELECTION_GRABBERS_OUT)abs_turn(CLOCKWISE, POINT, TURN, 90, 60);
		motor[block_lift_motor] = 0;
		motor[block_lift_motor2] = 0;
		if(g_auto_grabber_selection_ramp_options == SUB_SELECTION_RAMP_STOP)
		{
			if(g_auto_grabber_selections == SUB_SELECTION_GRABBERS_IN) abs_drive(FORWARD, E_ANGLE, 80, 50, true);
			else if(g_auto_grabber_selections == SUB_SELECTION_GRABBERS_OUT) abs_drive(BACKWARD, E_ANGLE, 80, 50, true);
		}
		else abs_drive(FORWARD, E_ANGLE, 135, 50, true);
		break;
	case 3:
		wait1Msec(2000);
		servo[abdd] = g_abdd_down;
		abs_drive(BACKWARD, E_ANGLE, g_to_turn_dist, 50, true);
		wait1Msec(200);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 60);
		wait1Msec(200);
		abs_drive(FORWARD, E_ANGLE, 90, 50, true);
		motor[block_lift_motor] = 40;
		motor[block_lift_motor2] = 40;
		if(g_auto_grabber_selections == SUB_SELECTION_GRABBERS_IN) abs_turn(CLOCKWISE, POINT, TURN, 90, 60);
		else if(g_auto_grabber_selections == SUB_SELECTION_GRABBERS_OUT)abs_turn(COUNTERCLOCKWISE, POINT, TURN, 85, 60);
		motor[block_lift_motor] = 0;
		motor[block_lift_motor2] = 0;
		if(g_auto_grabber_selection_ramp_options == SUB_SELECTION_RAMP_STOP)
		{
			if(g_auto_grabber_selections == SUB_SELECTION_GRABBERS_IN) abs_drive(FORWARD, E_ANGLE, 80, 50, true);
			else if(g_auto_grabber_selections == SUB_SELECTION_GRABBERS_OUT)abs_drive(BACKWARD, E_ANGLE, 80, 50, true);
		}
		else abs_drive(FORWARD, E_ANGLE, 135, 50, true);
		break;
	}
}

#endif /* !ABS_S3_MISSION_EXECUTE_H */
