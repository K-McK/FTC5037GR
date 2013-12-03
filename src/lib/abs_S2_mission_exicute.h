/*
*
*  @file abs_S2_mission_exicute.h
*
*  @brief runs the missions from the starting point S2
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_S2_MISSION_EXICUTE_H
#define ABS_S2_MISSION_EXICUTE_H

/** macros */
//=========================
// the missions for S2
//=========================
void abs_S2_mission_exicute()
{
	switch(mission_number)
	{
	case 1:
		break;

	case 2:
		abs_turn(CLOCKWISE, SWING, TURN_TO, 45, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/30, 50, true);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 100, 60);
		abs_drive(BACKWARD, E_ANGLE, /*distance in cm*/100, 50, true);
		servo[abdd] = ABDD_UP;
		wait1Msec(2000);
		servo[abdd] = ABDD_DOWN;
		if(end_point == 3)to_turn_dist = 145;
		else to_turn_dist = crate4_to_turn_dist;
		break;

	case 3:
		abs_turn(CLOCKWISE, SWING, TURN_TO, 45, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/30, 50, true);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 100, 60);
		abs_drive(BACKWARD, E_ANGLE, /*distance in cm*/75, 50, true);
		servo[abdd] = ABDD_UP;
		wait1Msec(2000);
		servo[abdd] = ABDD_DOWN;
		if(end_point == 3)to_turn_dist = 120;
		else to_turn_dist = crate3_to_turn_dist;
		break;

	case 4:
		abs_turn(CLOCKWISE, SWING, TURN_TO, 45, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/30, 50, true);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 100, 60);
		abs_drive(BACKWARD, E_ANGLE, /*distance in cm*/25, 50, true);
		servo[abdd] = ABDD_UP;
		wait1Msec(2000);
		servo[abdd] = ABDD_DOWN;
		if(end_point == 3)to_turn_dist = 70;
		else to_turn_dist = crate2_to_turn_dist;
		break;

	case 5:
		abs_turn(CLOCKWISE, SWING, TURN_TO, 45, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/30, 50, true);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 100, 60);
		servo[abdd] = ABDD_UP;
		wait1Msec(2000);
		servo[abdd] = ABDD_DOWN;
		if(end_point == 3) to_turn_dist = 45;
		else if(end_point == 2) to_turn_dist = crate1_to_turn_dist+5;
		break;

	case 6:
		abs_turn(CLOCKWISE, SWING, TURN_TO, 45, 60);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/30, 50, true);
		abs_turn(CLOCKWISE, POINT, TURN_TO, 100, 60);
		abs_drive(BACKWARD, E_ANGLE, to_turn_dist, 50, true);
		abs_turn(CLOCKWISE, POINT, TURN, 90, 60);
		abs_drive(FORWARD, E_ANGLE, 180, 50, true);
		break;

	case 7:
		break;
	}
	wait1Msec(end_delay*1000);
	switch(end_point)
	{
	case 1:
		wait1Msec(2000);
		servo[abdd] = ABDD_DOWN;
		motor[right_motor] = 0;
		motor[left_motor] = 0;
		motor[sky_hook] = 0;
		motor[block_lift_motor] = 0;
		motor[block_lift_motor2] = 0;
		break;
	case 2:
		wait1Msec(2000);
		servo[abdd] = ABDD_DOWN;
		abs_drive(FORWARD, E_ANGLE, to_turn_dist, 50, true);
		wait1Msec(200);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 75, 60);
		wait1Msec(200);
		abs_drive(FORWARD, E_ANGLE, 85, 50, true);
		motor[block_lift_motor] = 40;
		motor[block_lift_motor2] = 40;
		if(auto_grabber_selections == SUB_SELECTION_GRABBERS_IN) abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 60);
		else if(auto_grabber_selections == SUB_SELECTION_GRABBERS_OUT)abs_turn(CLOCKWISE, POINT, TURN, 90, 60);
		motor[block_lift_motor] = 0;
		motor[block_lift_motor2] = 0;
		if(auto_grabber_selections == SUB_SELECTION_GRABBERS_IN) abs_drive(FORWARD, E_ANGLE, 80, 50, true);
		else if(auto_grabber_selections == SUB_SELECTION_GRABBERS_OUT)abs_drive(BACKWARD, E_ANGLE, 80, 50, true);
		break;
	case 3:
		wait1Msec(2000);
		servo[abdd] = ABDD_DOWN;
		abs_drive(BACKWARD, E_ANGLE, to_turn_dist, 50, true);
		wait1Msec(200);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 60);
		wait1Msec(200);
		abs_drive(FORWARD, E_ANGLE, 90, 50, true);
		motor[block_lift_motor] = 40;
		motor[block_lift_motor2] = 40;
		if(auto_grabber_selections == SUB_SELECTION_GRABBERS_IN) abs_turn(CLOCKWISE, POINT, TURN, 90, 60);
		else if(auto_grabber_selections == SUB_SELECTION_GRABBERS_OUT)abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 60);
		motor[block_lift_motor] = 0;
		motor[block_lift_motor2] = 0;
		if(auto_grabber_selections == SUB_SELECTION_GRABBERS_IN) abs_drive(FORWARD, E_ANGLE, 80, 50, true);
		else if(auto_grabber_selections == SUB_SELECTION_GRABBERS_OUT)abs_drive(BACKWARD, E_ANGLE, 80, 50, true);
		break;
	}
}

#endif /* !ABS_S2_MISSION_EXICUTE_H */
