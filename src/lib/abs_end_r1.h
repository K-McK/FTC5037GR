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

void abs_end_r1(int delay, int lift_speed)
{
	if(g_mission_number == 1)g_to_turn_dist = g_dist_backwards;
	dl_step = dl_step+1;
	dl_robot_action_state = dl_wait;
	dl_speed = delay;
	wait1Msec(delay);
	servo[abdd] = g_abdd_down;
	abs_drive(FORWARD, E_ANGLE, g_to_turn_dist, 50, true, GYRO);
	if((abs(HTANGreadAccumulatedAngle(angle_sensor))/18)<15)
	{
		motor[left_motor] = 0;
		motor[right_motor] = 0;
		PlayTone(300,200);
		return;
	}

	dl_step = dl_step+1;
	dl_robot_action_state = dl_wait;
	dl_speed = 200;
	wait1Msec(200);
	//LSsetActive(LEGOLS);
	servo[light_sensor] = LIGHT_SERVO_DOWN;
	abs_turn(COUNTERCLOCKWISE, POINT, TURN, 75, 60);

	dl_step = dl_step+1;
	dl_robot_action_state = dl_wait;
	dl_speed = 200;
	wait1Msec(200);
	abs_drive(FORWARD, E_LIGHT, 110, 50, true, GYRO);
	motor[block_lift_motor] = lift_speed;
	motor[block_lift_motor2] = lift_speed;
	abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 60);
	motor[block_lift_motor] = 0;
	motor[block_lift_motor2] = 0;
	if(g_auto_grabber_selection_ramp_options == SUB_SELECTION_RAMP_STOP) abs_drive(FORWARD, E_ANGLE, 80, 50, true, GYRO);
	else abs_drive(FORWARD, E_ANGLE, 130, 50, true, GYRO);
}

#endif /* !ABS_S1_END_R1_H */
