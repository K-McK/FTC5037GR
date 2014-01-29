/**
*
*  @file abs_s1_mission_execute.h
*
*  @brief runs the missions from the starting point S1
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_S1_MISSION_EXECUTE_H
#define ABS_S1_MISSION_EXECUTE_H

void abs_s1_mission_execute()
{
	dl_robot_action_state = dl_change_event;
	dl_robot_action_detail = dl_ce_score_start;
	switch(g_mission_number)
	{
	case 0:
		g_screen_state = S_ANGLE_SHOW;
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/600, 50, true);
		break;

	case 1:
		g_screen_state = S_ANGLE_SHOW;
		abs_drive(FORWARD, E_IR_DETECT, 7, 40, true);
		if(HTANGreadAccumulatedAngle(angle_sensor)<(38*INT_ANGLE_SENSOR_CIRCUMFERENCE))
			abs_drive(FORWARD, E_IR_DETECT, 7, ((50*INT_ANGLE_SENSOR_CIRCUMFERENCE)-HTANGreadAccumulatedAngle(angle_sensor)), true);
		PlayTone(200,20);
		wait1Msec(1000);
		//if(g_IR_angle_dist_complete == true) g_end_point = 12;
		if(g_end_point == 2)
		{
			if(HTANGreadAccumulatedAngle(angle_sensor)<(62*INT_ANGLE_SENSOR_CIRCUMFERENCE)) g_to_turn_dist = g_forward_crate1_to_turn_dist;
			else if(HTANGreadAccumulatedAngle(angle_sensor)<(100*INT_ANGLE_SENSOR_CIRCUMFERENCE)) g_to_turn_dist = g_forward_crate2_to_turn_dist;
			else if(HTANGreadAccumulatedAngle(angle_sensor)<(137*INT_ANGLE_SENSOR_CIRCUMFERENCE)) g_to_turn_dist = g_forward_crate3_to_turn_dist;
			else if(HTANGreadAccumulatedAngle(angle_sensor)<(162*INT_ANGLE_SENSOR_CIRCUMFERENCE)) g_to_turn_dist = g_forward_crate4_to_turn_dist;
		}
		else if(g_end_point == 3)
		{
			if(HTANGreadAccumulatedAngle(angle_sensor)<(62*INT_ANGLE_SENSOR_CIRCUMFERENCE)) g_to_turn_dist = g_backwards_crate1_to_turn_dist;
			else if(HTANGreadAccumulatedAngle(angle_sensor)<(100*INT_ANGLE_SENSOR_CIRCUMFERENCE)) g_to_turn_dist = g_backwards_crate2_to_turn_dist;
			else if(HTANGreadAccumulatedAngle(angle_sensor)<(137*INT_ANGLE_SENSOR_CIRCUMFERENCE)) g_to_turn_dist = g_backwards_crate3_to_turn_dist;
			else if(HTANGreadAccumulatedAngle(angle_sensor)<(162*INT_ANGLE_SENSOR_CIRCUMFERENCE)) g_to_turn_dist = g_backwards_crate4_to_turn_dist;
		}
		wait1Msec(500);
		break;

	case 2:
		if(g_end_point == 3)g_to_turn_dist = g_backwards_crate4_to_turn_dist;
		else g_to_turn_dist = g_forward_crate4_to_turn_dist;
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/150, 50, true);
		wait1Msec(2000);
		break;

	case 3:
		if(g_end_point == 3)g_to_turn_dist = g_backwards_crate3_to_turn_dist;
		else g_to_turn_dist = g_forward_crate3_to_turn_dist;
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/125, 50, true);
		break;

	case 4:
		if(g_end_point == 3)g_to_turn_dist = g_backwards_crate2_to_turn_dist;
		else g_to_turn_dist = g_forward_crate2_to_turn_dist;
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/75, 50, true);
		break;

	case 5:
		if(g_end_point == 3)g_to_turn_dist = g_backwards_crate1_to_turn_dist;
		else g_to_turn_dist = g_forward_crate1_to_turn_dist;
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/50, 50, true);
		break;

	case 6:
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 75, 60);
		wait1Msec(200);
		abs_drive(FORWARD, E_ANGLE, 190, 50, true);
		abs_turn(CLOCKWISE, POINT, TURN, 75, 60);
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
			while((g_accelermoeter_sensor < dist+5) && (g_accelermoeter_sensor > dist-5) && ((ac_start_time - nPgmTime)<500))
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
	dl_step++;
	dl_robot_action_state = dl_run_abdd;
	dl_robot_action_detail = dl_abdd_open;
	dl_speed = servoChangeRate[abdd];
	dl_dist = g_abdd_up;
	servo[abdd] = g_abdd_up;
	wait1Msec(2000);
	dl_robot_action_detail = dl_abdd_close;
	dl_dist = g_abdd_down;
	servo[abdd] = g_abdd_down;

	dl_step++;
	dl_robot_action_state = dl_wait;
	dl_robot_action_detail = 0;
	dl_speed = g_end_delay*1000;
	wait1Msec(g_end_delay*1000);

	dl_robot_action_state = dl_change_event;
	dl_robot_action_detail = dl_ce_end_point;
	switch(g_end_point)
	{
	case 1:
		wait1Msec(2000);
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

#endif /* !ABS_S1_MISSION_EXICUTE_H */
