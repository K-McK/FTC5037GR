/**
 *
 *  @file abs_screen.h
 *
 *  @brief adds a way to put things on the screen
 *
 *  @param None n/a
 *
 *  @return Returns nothing
 *
 *  @copyright Copyright 2013, Got Robot? FTC Team 5037
 *
 */

#ifndef ABS_SCREEN_H
#define ABS_SCREEN_H
//========================================
// Screen State
//========================================

task screen ()
{
	while(true)
	{
		nxtDisplayBigTextLine(7, "              ");
		switch(screen_state)
		{
		case s_clear:
			nxtDisplayBigTextLine(1, "              ");
			nxtDisplayBigTextLine(3, "              ");
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_mission:
			nxtDisplayBigTextLine(1, "Misson ","2%d", mission_number);
			//nxtDisplayBigTextLine(3, "%2d", mission_number);
			nxtDisplayBigTextLine(3, MissionNames1[mission_number]);
			nxtDisplayBigTextLine(5, MissionNames2[mission_number]);
			break;
		case s_delay:
		if(auto_selection_point == SELECTION_START_DELAY) nxtDisplayBigTextLine(1, "Start   ");
		else nxtDisplayBigTextLine(1, "Mission ");
			nxtDisplayBigTextLine(3, "Delay");
			nxtDisplayBigTextLine(5, "%2d", delay);
			break;
		case s_cal_time:
			nxtDisplayBigTextLine(1, "CalTime");
			nxtDisplayBigTextLine(3, "%2d", gyroCalTime);
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_gyro_cal:
			nxtDisplayTextLine(1, "Calibrating");
			nxtDisplayBigTextLine(3, "%2d", (gyroCalTime*1000)-(nPgmTime-starttime));
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_ready:
			nxtDisplayBigTextLine(1, "Program");
			nxtDisplayBigTextLine(3, "Ready");
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_delay_wait:
			nxtDisplayBigTextLine(1, "Delay");
			nxtDisplayBigTextLine(3, "%2d", (start_delay*1000)-(nPgmTime-starttime));
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_gyro_show:
			nxtDisplayBigTextLine(1, "GyroValue");
			nxtDisplayBigTextLine(3, "%2d", constHeading);
			nxtDisplayBigTextLine(5, "%2d", relHeading);
			break;
		case s_IR_show:
			nxtDisplayBigTextLine(1, "IR Value");
			nxtDisplayBigTextLine(3, "%2d", HTANGreadAccumulatedAngle(angle_sensor));
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_ac_show:
			nxtDisplayBigTextLine(1, "ac Value");
			nxtDisplayBigTextLine(3, "%2d  %2d", accelermoeter_sensor, misc);
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_error:
			nxtDisplayBigTextLine(1, "ERROR");
			nxtDisplayBigTextLine(3, error_list1[error]);
			nxtDisplayBigTextLine(5, error_list2[error]);
			break;
		case s_smoke_test:
			nxtDisplayBigTextLine(1, "%2d", smoke_test_num);
			nxtDisplayBigTextLine(3, smoke_test1[smoke_test_num]);
			nxtDisplayBigTextLine(5, smoke_test2[smoke_test_num]);
			break;
		case s_smoke_run1:
			nxtDisplayBigTextLine(1, smoke_test1[smoke_test_num]);
			nxtDisplayBigTextLine(3, "%2d", test_value);
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case S_smoke_run2:
			nxtDisplayBigTextLine(1, smoke_test1[smoke_test_num]);
			nxtDisplayBigTextLine(3, "%2d", sensor_value);
			nxtDisplayBigTextLine(5, sensor_list[sensor_num]);
			break;
		case s_screen_call:
			nxtDisplayBigTextLine(1, smoke_test1[smoke_test_num]);
			nxtDisplayBigTextLine(3, "%2d", test_value);
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_misc_show:
			nxtDisplayBigTextLine(1, "misc Value");
			nxtDisplayBigTextLine(3, "%2d", misc);
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_starting_point:
			nxtDisplayBigTextLine(1, "startPnt");
			nxtDisplayBigTextLine(3, StartingNames1[start_point]);
			nxtDisplayBigTextLine(5, StartingNames2[start_point]);
			break;
			case s_ending_point:
			nxtDisplayBigTextLine(1, "endPoint");
			nxtDisplayBigTextLine(3, EndingNames1[end_point]);
			nxtDisplayBigTextLine(5, EndingNames2[end_point]);
			break;
		}
	}
}
