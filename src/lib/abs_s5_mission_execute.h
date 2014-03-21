/**
*
*  @file abs_s5_mission_execute.h
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

#ifndef ABS_S5_MISSION_EXECUTE_H
#define ABS_S5_MISSION_EXECUTE_H

#include "abs_drive.h"
#include "abs_turn.h"
#include "abs_stop_robot.h"
#include "abs_end_ramp.h"
#include "abs_dlog.h"
#include "abs_get_angle_sensor_val.h"
#include "abs_stay_on_ramp.h"

void abs_s5_mission_execute()
{
	switch(g_mission_number)
	{
	case 0:
		break;

	case 1: //go to other side of the field and block an apponet
		abs_drive(FORWARD, E_ANGLE, 240, 40, true, g_drive_type);
		abs_turn(CLOCKWISE, POINT, TURN, 90, 40);
		abs_drive(FORWARD, E_ANGLE, 100, 40, true, g_drive_type);
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	case 5:
		break;

	case 6:
		break;

	case 7:
		break;
	}
	abs_dlog(__FILE__,"abdd up", "instance", 2, "g_abdd_up", g_abdd_up);	//open and log abdd
	servo[abdd] = g_abdd_up;
	#if USE_TASK_PRIORITY == 1
	StartTask(abs_calibrate_light, MEDIUM_PRIORITY_TASK);		//start the screen function, this handels all screen interactions
#else
	StartTask(abs_calibrate_light);		//start the screen function, this handels all screen interactions
#endif
	wait1Msec(2000);
	servoChangeRate[abdd] = abdd_down_speed;
	servo[abdd] = g_abdd_down;	//return and log the abdd
	abs_dlog(__FILE__,"abdd down", "instance", 2, "g_abdd_down", g_abdd_down);

	wait1Msec(g_end_delay * DELAY_MULTIPLICATION_FACTOR); //wait for end delay, number option tab 4

	//abs_dlog(__FILE__,"start of end", "g_end_point", g_end_point);
}

#endif /* !ABS_S5_MISSION_EXICUTE_H */
