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
#include "abs_end_ramp.h"
#include "abs_log.h"
#include "abs_get_angle_sensor_val.h"

void abs_s2_mission_execute()
{
	switch(g_mission_number)
	{
	case 0:	//test option only used for tests, currently angle sensor
		g_screen_state = S_ANGLE_SHOW;
		abs_drive(FORWARD, E_ANGLE, /*distance in cm*/600, 50, true, g_drive_type);
		break;

	case 1:	//IR mission
		dist_record=true;		 //set to record the following movement for end movement distance
		abs_drive(BACKWARD, E_IR_DETECT, BACKWARD_IR_THRESHOLD, 40, true, g_drive_type);
		if(abs_get_angle_sensor_val(RELATIVE_BPU) < 38)		//if robot did not drive minimal distance drive to first crate
		{
			dist_record = true;
			abs_drive(BACKWARD, E_ANGLE, 40 - abs_get_angle_sensor_val(RELATIVE_BPU), 40, true, g_drive_type);
		}
		wait1Msec(500);
		if(g_mission_number==1)		//if IR is used compensate line up
		{
			abs_drive(FORWARD, E_ANGLE, 6, 50, true, g_drive_type);
		}
		wait1Msec(500);
		break;

	case 2:	//deliver to crate 4 mission
		dist_record=true;
		abs_drive(BACKWARD, E_ANGLE, /*distance in cm*/40, 50, true, g_drive_type);
		break;

	case 3:	//deliver to crate 3 mission
		dist_record=true;
		abs_drive(BACKWARD, E_ANGLE, /*distance in cm*/65, 50, true, g_drive_type);
		break;

	case 4:	//deliver to crate 2 mission
		dist_record=true;
		abs_drive(BACKWARD, E_ANGLE, /*distance in cm*/115, 50, true, g_drive_type);
		break;

	case 5:	//deliver to crate 1 mission
		dist_record=true;
		abs_drive(BACKWARD, E_ANGLE, /*distance in cm*/140, 50, true, g_drive_type);
		wait1Msec(2000);
		break;

	case 6: //will be defence mission 1
		abs_turn(CLOCKWISE, POINT, TURN, 75, 60);
		wait1Msec(200);
		abs_drive(FORWARD, E_ANGLE, 190, 50, true, g_drive_type);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 75, 60);
		abs_drive(FORWARD, E_ANGLE, 80, 50, true, g_drive_type);
		break;

	case 7: //will be defence mission 2
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 98, 60);
		wait1Msec(200);
		abs_drive(FORWARD, E_ANGLE, 87, 50, true, g_drive_type);
		motor[block_lift_motor] = 40;
		motor[block_lift_motor2] = 40;
		abs_turn(CLOCKWISE, POINT, TURN, 103, 60);
		motor[block_lift_motor] = 0;
		motor[block_lift_motor2] = 0;
		abs_drive(FORWARD, E_ANGLE, 80, 50, true, g_drive_type);
		break;
	}
	abs_log(__FILE__,"abdd up",2,g_abdd_up,0,0);	//open and log abdd
	servo[abdd] = g_abdd_up;
	StartTask (abs_calibrate_light);	//calibrate the light sensor to find the white line
	wait1Msec(2000);
	servo[abdd] = g_abdd_down;	//return and log the abdd
	abs_log(__FILE__,"abdd down",2,g_abdd_down,0,0);

	wait1Msec(g_end_delay * DELAY_MULTIPLICATION_FACTOR); //wait for end delay, number option tab 4
}

#endif /* !ABS_S2_MISSION_EXECUTE_H */
