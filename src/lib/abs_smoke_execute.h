/**
*
*  @file abs_smoke_execute.h
*
*  @brief executes commands sent in smoke test
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_SMOKE_EXECUTE_H
#define ABS_SMOKE_EXECUTE_H

#include "abs_get_angle_sensor_val.h"

void abs_smoke_execute ()
{
	g_screen_state = S_SMOKE_RUN1;
	while(nNxtButtonPressed != kEnterButton)
	{
		switch(g_smoke_test_num)
		{
			//---------------------------------
			// Jolly Roger
			//---------------------------------
		case 1:
			if(nNxtButtonPressed == kLeftButton)
			{
				motor[jolly_roger] = g_flag_speed_down;
				g_test_value = g_flag_speed_down;
			}
			else if(nNxtButtonPressed == kRightButton)
			{
				motor[jolly_roger] = g_flag_speed_up;
				g_test_value = g_flag_speed_up;
			}
			else
			{
				g_test_value = 0;
				motor[jolly_roger] = 0;
			}
			break;
			//---------------------------------
			// Drive
			//---------------------------------
		case 2:
			if(nNxtButtonPressed == kLeftButton)
			{
				motor[right_motor] = 60;
				motor[left_motor] = 60;
				g_test_value = 60;
			}
			else if(nNxtButtonPressed == kRightButton)
			{
				motor[right_motor] = -60;
				motor[left_motor] = -60;
				g_test_value = -60;
			}
			else
			{
				g_test_value = 0;
				motor[right_motor] = 0;
				motor[left_motor] = 0;
			}
			break;
			//---------------------------------
			// sensors
			//---------------------------------
		case 3:
			g_screen_state = S_SMOKE_RUN2;
			if(nNxtButtonPressed == kLeftButton)
			{
				if(g_test_value > 1) g_test_value--;
				while(nNxtButtonPressed == kLeftButton) {}
			}
			if(nNxtButtonPressed == kRightButton)
			{
				if(g_test_value < g_sensor_max) g_test_value++;
				while(nNxtButtonPressed == kRightButton) {}
			}
			g_sensor_num = g_test_value;
			switch(g_sensor_num)
			{
			case ST_GYRO:
				g_sensor_value = g_rel_heading;
				break;
			case ST_IR:
				g_sensor_value = g_bearing_ac1;
				g_sensor_value2 = g_bearing_ac2;
				break;
			case ST_TILT:
				g_sensor_value = abs_get_angle_sensor_val(RELATIVE);
				break;
			case ST_ACCELEROMETER:
				g_sensor_value = g_accelermoeter_sensor;
				break;
			}
			break;
			//---------------------------------
			// Block lift
			//---------------------------------
		case 4:
			if(nNxtButtonPressed == kLeftButton)
			{
				motor[block_lift_motor] = g_robot_lift_down;
				motor[block_lift_motor2] = g_robot_lift_down;
				g_test_value = g_robot_lift_down;
			}
			else if(nNxtButtonPressed == kRightButton)
			{
				motor[block_lift_motor] = g_robot_lift_up;
				motor[block_lift_motor2] = g_robot_lift_up;
				g_test_value = g_robot_lift_up;
			}
			else
			{
				motor[block_lift_motor] = 0;
				motor[block_lift_motor2] = 0;
				g_test_value = 0;
			}
			break;
			//---------------------------------
			// grabbers
			//---------------------------------
		case 5:
			if(nNxtButtonPressed == kLeftButton)
			{
				if(g_test_value>1) g_test_value--;
				while(nNxtButtonPressed == kLeftButton){}
			}
			if(nNxtButtonPressed == kRightButton)
			{
				if(g_test_value<3) g_test_value++;
				while(nNxtButtonPressed == kRightButton){}
			}
			switch(g_test_value)
			{
			case 1:
			servo[grabber_left] = GRABBER_LEFT_OPEN;
			servo[grabber_right] = GRABBER_RIGHT_OPEN;
				break;
			case 2:
			servo[grabber_left] = GRABBER_LEFT_MID;
			servo[grabber_right] = GRABBER_RIGHT_MID;
				break;
			case 3:
			servo[grabber_left] = GRABBER_LEFT_CLOSE;
			servo[grabber_right] = GRABBER_RIGHT_CLOSE;
				break;
			}
		break;
		//---------------------------------
		// sky hook
		//---------------------------------
	case 6:
		if(nNxtButtonPressed == kLeftButton)
		{
			motor[sky_hook] = g_robot_lift_up;
			g_test_value = g_robot_lift_up;
		}
		else if(nNxtButtonPressed == kRightButton)
		{
			motor[sky_hook] = g_robot_lift_down;
			g_test_value = g_robot_lift_down;
		}
		else
		{
			motor[sky_hook] = 0;
			g_test_value = 0;
		}
		break;
		//---------------------------------
		// roger slide
		//---------------------------------
	case 7:
		if(nNxtButtonPressed == kLeftButton)
		{
			servo[roger_slide] = 255;
			g_test_value = 255;
		}
		else if(nNxtButtonPressed == kRightButton)
		{
			servo[roger_slide] = 0;
			g_test_value = 0;
		}
		else
		{
			servo[roger_slide] = 127;
			g_test_value = 127;
		}
		break;
		//---------------------------------
		// ground arm
		//---------------------------------
	case 8:
		if(nNxtButtonPressed == kLeftButton)
		{
			servo[ground_arm] = g_ground_arm_down;
			g_test_value = g_ground_arm_down;
		}
		else if(nNxtButtonPressed == kRightButton)
		{
			servo[ground_arm] = g_ground_arm_up;
			g_test_value = g_ground_arm_up;
		}
		break;
		//---------------------------------
		// light sensor
		//---------------------------------

	case 9:
		if(nNxtButtonPressed == kLeftButton)
		{
			servo[ground_arm] = g_ground_arm_down;
			g_test_value = g_ground_arm_down;
		}
		else if(nNxtButtonPressed == kRightButton)
		{
			servo[ground_arm] = g_ground_arm_up;
			g_test_value = g_ground_arm_up;
		}
		break;
	}
}
PlaySoundFile("! Click.rso");
}

#endif /* !ABS_SMOKE_EXECUTE_H */
