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

task abs_screen ()
{
	while(true)
	{
		nxtDisplayBigTextLine(7, "              ");
		switch(g_screen_state)
		{
		case S_CLEAR:
			nxtDisplayBigTextLine(1, "              ");
			nxtDisplayBigTextLine(3, "              ");
			nxtDisplayBigTextLine(5, g_mission_names1[0]);
			break;
		case S_MISSION:
			nxtDisplayBigTextLine(1, "Misson ","2%d", g_mission_number);
			nxtDisplayBigTextLine(3, g_mission_names1[g_mission_number]);
			nxtDisplayBigTextLine(5, g_mission_names2[g_mission_number]);
			break;
		case S_DELAY:
			if(g_auto_selection_point == SELECTION_START_DELAY) nxtDisplayBigTextLine(1, "Start   ");
			else nxtDisplayBigTextLine(1, "Mission ");
			nxtDisplayBigTextLine(3, "Delay");
			nxtDisplayBigTextLine(5, "%2d", g_delay);
			break;
		case S_CAL_TIME:
			nxtDisplayBigTextLine(1, "CalTime");
			nxtDisplayBigTextLine(3, "%2d", g_gyro_cal_time);
			nxtDisplayBigTextLine(5, g_mission_names1[0]);
			break;
		case S_GYRO_CAL:
			nxtDisplayTextLine(1, "Calibrating");
			nxtDisplayBigTextLine(3, "%2d", (g_gyro_cal_time*1000)-(nPgmTime-g_start_time));
			nxtDisplayBigTextLine(5, g_mission_names1[0]);
			break;
		case S_READY:
			nxtDisplayBigTextLine(1, "Program");
			nxtDisplayBigTextLine(3, "Ready");
			if(g_auto_grabber_selection_ramp_options == SUB_SELECTION_RAMP_STOP) nxtDisplayBigTextLine(5, "%1d%1d%1d%1d%1d N", g_start_point, g_start_delay, g_mission_number, g_end_delay, g_end_point);
			else nxtDisplayBigTextLine(5, "%1d%1d%1d%1d%1d Y", g_start_point, g_start_delay, g_mission_number, g_end_delay, g_end_point);
			break;
		case S_DELAY_WAIT:
			nxtDisplayBigTextLine(1, "Delay");
			nxtDisplayBigTextLine(3, "%2d", (g_start_delay*1000)-(nPgmTime-g_start_time));
			nxtDisplayBigTextLine(5, g_mission_names1[0]);
			break;
		case S_GYRO_SHOW:
			nxtDisplayBigTextLine(1, "GyroValue");
			nxtDisplayBigTextLine(3, "%2d", g_const_heading);
			nxtDisplayBigTextLine(5, "%2d", g_rel_heading);
			break;
		case S_IR_SHOW:
			nxtDisplayBigTextLine(1, "IR Value");
			nxtDisplayBigTextLine(3, "%2d  %2d", g_bearing_ac1, g_bearing_ac2);
			nxtDisplayBigTextLine(5, g_mission_names1[0]);
			break;
		case S_AC_SHOW:
			nxtDisplayBigTextLine(1, "ac Value");
			nxtDisplayBigTextLine(3, "%2d  %2d", g_accelermoeter_sensor, g_misc);
			nxtDisplayBigTextLine(5, g_mission_names1[0]);
			break;
		case S_ERROR:
			nxtDisplayBigTextLine(1, "ERROR");
			nxtDisplayBigTextLine(3, g_error_list1[g_error]);
			nxtDisplayBigTextLine(5, g_error_list2[g_error]);
			break;
		case S_SMOKE_TEST:
			nxtDisplayBigTextLine(1, "%2d", g_smoke_test_num);
			nxtDisplayBigTextLine(3, g_smoke_test1[g_smoke_test_num]);
			nxtDisplayBigTextLine(5, g_smoke_test2[g_smoke_test_num]);
			break;
		case S_SMOKE_RUN1:
			nxtDisplayBigTextLine(1, g_smoke_test1[g_smoke_test_num]);
			nxtDisplayBigTextLine(3, "%2d", g_test_value);
			nxtDisplayBigTextLine(5, g_mission_names1[0]);
			break;
		case S_SMOKE_RUN2:
			nxtDisplayBigTextLine(1, g_smoke_test1[g_smoke_test_num]);
			nxtDisplayBigTextLine(3, "%2d  %2d", g_sensor_value, g_sensor_value2);
			nxtDisplayBigTextLine(5, g_sensor_list[g_sensor_num]);
			break;
		case S_SCREEN_CALL:
			nxtDisplayBigTextLine(1, g_smoke_test1[g_smoke_test_num]);
			nxtDisplayBigTextLine(3, "%2d", g_test_value);
			nxtDisplayBigTextLine(5, g_mission_names1[0]);
			break;
		case S_MISC_SHOW:
			nxtDisplayBigTextLine(1, "misc Value");
			nxtDisplayBigTextLine(3, "%2d", g_misc);
			nxtDisplayBigTextLine(5, g_mission_names1[0]);
		case S_ANGLE_SHOW:
			nxtDisplayBigTextLine(1, "angle Value");
			nxtDisplayBigTextLine(3, "%2d", HTANGreadAccumulatedAngle(angle_sensor));
			nxtDisplayBigTextLine(5, g_mission_names1[0]);
			break;
		case S_STARTING_POINT:
			nxtDisplayBigTextLine(1, "startPnt");
			nxtDisplayBigTextLine(3, g_starting_names1[g_start_point]);
			nxtDisplayBigTextLine(5, g_starting_names2[g_start_point]);
			break;
		case S_ENDING_POINT:
			nxtDisplayBigTextLine(1, "endPoint");
			nxtDisplayBigTextLine(3, g_ending_names1[g_end_point]);
			nxtDisplayBigTextLine(5, g_ending_names2[g_end_point]);
			break;
		case S_SELECTION_SUB_GRABBERS:
			nxtDisplayBigTextLine(1, "Grabbers");
			nxtDisplayBigTextLine(3, "inOrOut?");
			if(g_auto_grabber_selections == SUB_SELECTION_GRABBERS_IN) nxtDisplayBigTextLine(5, g_basic_word_list [1]);
			else if(g_auto_grabber_selections == SUB_SELECTION_GRABBERS_OUT) nxtDisplayBigTextLine(5, g_basic_word_list [2]);
			break;
		case S_SELECTION_SUB_RAMP:
			nxtDisplayBigTextLine(1, "Ramp    ");
			nxtDisplayBigTextLine(3, "continu?");
			if(g_auto_grabber_selection_ramp_options == SUB_SELECTION_RAMP_CONTINUED) nxtDisplayBigTextLine(5, g_basic_word_list [3]);
			else if(g_auto_grabber_selection_ramp_options == SUB_SELECTION_RAMP_STOP) nxtDisplayBigTextLine(5, g_basic_word_list [4]);
			break;
		case S_TIME_SHOW:
			nxtDisplayBigTextLine(1, "T1    T2");
			nxtDisplayBigTextLine(3, "%2d", g_debug_time_1);
			nxtDisplayBigTextLine(5, "%2d", g_debug_time_2);
			break;
		case S_MISSION_SHOW:
			nxtDisplayBigTextLine(1, "numbers");
			nxtDisplayBigTextLine(3, " %1d%1d%1d%1d%1d", g_intput_array[1],g_intput_array[2],g_intput_array[3],g_intput_array[4],g_intput_array[5]);
			nxtDisplayTextLine(5, "%1d-%1d-%1d-%1d-%1d", g_start_point, g_start_delay, g_mission_number, g_end_delay, g_end_point);
			break;
		case S_SELECTION_TYPE:
			nxtDisplayBigTextLine(1, "Selecton");
			nxtDisplayBigTextLine(3, "Type:   ");
			if(selection_type == SELECTION_TYPE_CUSTOM) nxtDisplayBigTextLine(5, "custom  ");
			else if(selection_type == SELECTION_TYPE_NUMBER) nxtDisplayBigTextLine(5, "number  ");
			else if(selection_type == SELECTION_TYPE_QUICK) nxtDisplayBigTextLine(5, "quick    ");
			break;
		case S_NUMBER_SELECTION:
			nxtDisplayBigTextLine(1, "Mission");
			nxtDisplayBigTextLine(3, " %1d%1d%1d%1d%1d", g_intput_array[1],g_intput_array[2],g_intput_array[3],g_intput_array[4],g_intput_array[5]);
			switch(g_graph_selection_tab)
			{
			case 1: nxtDisplayBigTextLine(5, " ^      "); break;
			case 2: nxtDisplayBigTextLine(5, "  ^     "); break;
			case 3: nxtDisplayBigTextLine(5, "   ^    "); break;
			case 4: nxtDisplayBigTextLine(5, "    ^   "); break;
			case 5: nxtDisplayBigTextLine(5, "     ^  "); break;
			}
			break;
		case S_QUICK_SELECTION:
			nxtDisplayBigTextLine(1, "Mission");
			nxtDisplayBigTextLine(3, g_quick_names1[g_quick_mission]);
			nxtDisplayBigTextLine(5, g_quick_names2[g_quick_mission]);
			break;
		}
	}
}

#endif
