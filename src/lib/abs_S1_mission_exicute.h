/*
*
*  @file abs_S1_mission_exicute.h
*
*  @brief runs the missions from the starting point S1
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_S1_MISSION_EXICUTE_H
#define ABS_S1_MISSION_EXICUTE_H

/** macros */
//=========================
// the missions for S1
//=========================
void abs_S1_mission_exicute()
{
	switch(mission_number)
	{
	case 0:
		abs_turn(CLOCKWISE, POINT, TURN, 180, 60);
		wait10Msec(300);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 60);
		wait10Msec(300);
		abs_turn(CLOCKWISE, POINT, TURN, 45, 60);
		wait10Msec(300);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 0, 60);
		break;

	case 1:
		abs_drive(FORWARD, E_IR_DETECT, 0, 40, true);
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/15, 50, true);
		wait1Msec(500);
		servo[abdd] = ABDD_UP;
		wait1Msec(2000);
		servo[abdd] = ABDD_DOWN;
		break;

	case 2:
		if(end_point == 3)to_turn_dist = 145;
		else to_turn_dist = crate4_to_turn_dist;
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/150, 50, true);
		wait1Msec(2000);
		servo[abdd] = ABDD_UP;
		wait1Msec(2000);
		servo[abdd] = ABDD_DOWN;
		break;

	case 3:
		if(end_point == 3)to_turn_dist = 120;
		else to_turn_dist = crate3_to_turn_dist;
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/125, 50, true);
		servo[abdd] = ABDD_UP;
		wait1Msec(2000);
		servo[abdd] = ABDD_DOWN;
		break;

	case 4:
		if(end_point == 3)to_turn_dist = 70;
		else to_turn_dist = crate2_to_turn_dist;
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/75, 50, true);
		servo[abdd] = ABDD_UP;
		wait1Msec(2000);
		servo[abdd] = ABDD_DOWN;
		break;

	case 5:
		if(end_point == 3)to_turn_dist = 45;
		else to_turn_dist = crate1_to_turn_dist;
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/50, 50, true);
		servo[abdd] = ABDD_UP;
		wait1Msec(2000);
		servo[abdd] = ABDD_DOWN;
		break;

	case 6:
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 98, 60);
		wait1Msec(200);
		abs_drive(FORWARD, E_ANGLE, 87, 50, true);
		motor[block_lift_motor] = 40;
		motor[block_lift_motor2] = 40;
		abs_turn(CLOCKWISE, POINT, TURN, 103, 60);
		motor[block_lift_motor] = 0;
		motor[block_lift_motor2] = 0;
		abs_drive(FORWARD, E_ANGLE, 80, 50, true);
		break;

	case 7:
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 98, 60);
		wait1Msec(200);
		abs_drive(FORWARD, E_ANGLE, 87, 50, true);
		motor[block_lift_motor] = 40;
		motor[block_lift_motor2] = 40;
		abs_turn(CLOCKWISE, POINT, TURN, 103, 60);
		motor[block_lift_motor] = 0;
		motor[block_lift_motor2] = 0;
		abs_drive(FORWARD, E_ANGLE, 80, 50, true);
		break;

	case 140:
		int dist = 30;
		bool done = false;
		while(done == false)
		{
			int ac_start_time = nPgmTime;
			int i = 0;
			while((accelermoeter_sensor < dist+5) && (accelermoeter_sensor > dist-5) && ((ac_start_time - nPgmTime)<500))
			{
				i++;
				PlayTone(20,20);
				wait1Msec(1);
			}
			if(i > 490) done = true;
			PlayTone(20,20);
		}
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
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 60);
		motor[block_lift_motor] = 0;
		motor[block_lift_motor2] = 0;
		abs_drive(FORWARD, E_ANGLE, 80, 50, true);
		break;
	case 3:
		wait1Msec(2000);
		servo[abdd] = ABDD_DOWN;
		abs_drive(BACKWARD, E_ANGLE, to_turn_dist, 50, true);
		wait1Msec(200);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 98, 60);
		wait1Msec(200);
		abs_drive(FORWARD, E_ANGLE, 87, 50, true);
		motor[block_lift_motor] = 40;
		motor[block_lift_motor2] = 40;
		abs_turn(CLOCKWISE, POINT, TURN, 103, 60);
		motor[block_lift_motor] = 0;
		motor[block_lift_motor2] = 0;
		abs_drive(FORWARD, E_ANGLE, 80, 50, true);
		break;
	}
}

#endif /* !ABS_S1_MISSION_EXICUTE_H */
