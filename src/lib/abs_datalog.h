/**
*
*  @file abs_datalog.h
*
*  @brief A function that handels the data log
*
*  @param N/A
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_DATALOG_H
#define ABS_DATALOG_H

#include "abs_get_angle_sensor_val.h"

/** macros */

//=======================================
// data log
//=======================================
task abs_datalog()
{
	//const string LogFileName = "DATALOG.txt";
	//TFileIOResult LogIoResult;
	//TFileHandle LogFileHandle;
	//long LogFileSize = 36000;
	//string sString;
	//string CRLF = (char)13+(char)10;

	//Delete(LogFileName, LogIoResult);
	//OpenWrite(LogFileHandle, LogIoResult, LogFileName, LogFileSize);

	if(selection_type == SELECTION_TYPE_CUSTOM) StringFormat(sString, "Custom");
	else if(selection_type == SELECTION_TYPE_NUMBER) StringFormat(sString, "Number");
	else if(selection_type == SELECTION_TYPE_QUICK) StringFormat(sString, "Quick");
	else StringFormat(sString, "Error");
	WriteText(LogFileHandle, LogIoResult, sString);

	StringFormat(sString, "");
	strcat(sString,CRLF);
	WriteText(LogFileHandle, LogIoResult, sString);

	for(int i=1;i<6;i++)//dl_cur_dist
	{
		StringFormat(sString, "%2d\t", g_input_array[i]);
		WriteText(LogFileHandle, LogIoResult, sString);
	}
	StringFormat(sString, "");
	strcat(sString,CRLF);
	WriteText(LogFileHandle, LogIoResult, sString);

	StringFormat(sString, "%2d\t", g_start_point);
	WriteText(LogFileHandle, LogIoResult, sString);

	StringFormat(sString, "%2d\t", g_start_delay);
	WriteText(LogFileHandle, LogIoResult, sString);

	StringFormat(sString, "%2d\t", g_mission_number);
	WriteText(LogFileHandle, LogIoResult, sString);

	StringFormat(sString, "%2d\t", g_end_delay);
	WriteText(LogFileHandle, LogIoResult, sString);

	StringFormat(sString, "%2d\t", g_end_point);
	WriteText(LogFileHandle, LogIoResult, sString);

	if(g_auto_grabber_selections == SUB_SELECTION_RAMP_STOP) StringFormat(sString, "N\t");
	else if(g_auto_grabber_selections == SUB_SELECTION_RAMP_CONTINUED) StringFormat(sString, "Y\t");
	WriteText(LogFileHandle, LogIoResult, sString);

	StringFormat(sString, "");
	strcat(sString,CRLF);
	WriteText(LogFileHandle, LogIoResult, sString);

	while(!LogData){EndTimeSlice();}
	/*while(false)//LogData
	{
		if(dl_change_event == true)
		{
			switch(dl_ce_detail)
			{
			case dl_ce_program_start: StringFormat(sString, "program start\t"); break;
			case dl_ce_start_delay: StringFormat(sString, "start delay %4d\t",g_input_array[STARTING_DELAY]); break;
			case dl_ce_end_delay: StringFormat(sString, "end delay %4d\t",g_input_array[END_DELAY]); break;
			case dl_ce_score_start: StringFormat(sString, "score %4d\t",g_mission_number); break;
			case dl_ce_end_point: StringFormat(sString, "end point %4d\t",g_end_point); break;
			case dl_ce_drive_end:
				if (dl_move_break == DL_LIGHT_BREAK) StringFormat(sString,"Move: light break\t");
				else StringFormat(sString," Move: angle break\t");
				WriteText(LogFileHandle, LogIoResult, sString);

				StringFormat(sString,"speed %4d\t",dl_speed);
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString,"dist %4d\t",dl_dist);
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString,"cur-angle raw %4d\t", abs_get_angle_sensor_val(RELATIVE_ASU));
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString,"cur-angle btu %4d\t", abs_get_angle_sensor_val(RELATIVE_BPU));
				break;
			case dl_ce_drive_start:
				StringFormat(sString,"Move start\t");
				WriteText(LogFileHandle, LogIoResult, sString);

				StringFormat(sString,"speed %4d\t",dl_speed);
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString,"dist %4d\t",dl_dist);
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString,"cur-angle raw %4d\t", abs_get_angle_sensor_val(RELATIVE_ASU));
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString,"cur-angle btu %4d\t", abs_get_angle_sensor_val(RELATIVE_BPU));
				break;
			case dl_ce_angle_reset:
				StringFormat(sString,"Angle reset\t");
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString,"(raw value) %4d\t",abs_get_angle_sensor_val(RELATIVE_ASU));
				break;
			case dl_ce_turn_start:
				StringFormat(sString,"Turn start\t");
				WriteText(LogFileHandle, LogIoResult, sString);

				StringFormat(sString,"speed %4d\t",dl_speed);
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString,"dist %4d\t",dl_dist);
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString,"rel-gyro %4d\t",g_rel_heading);
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString,"const-gyro %4d\t",g_const_heading);
				break;
			case dl_ce_turn_end:
				StringFormat(sString,"Turn end\t");
				WriteText(LogFileHandle, LogIoResult, sString);

				StringFormat(sString,"speed %4d\t",dl_speed);
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString,"dist %4d\t",dl_dist);
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString,"rel-gyro %4d\t",g_rel_heading);
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString,"const-gyro %4d\t",g_const_heading);
				break;
			}
			WriteText(LogFileHandle, LogIoResult, sString);
			StringFormat(sString, g_datalog_change_event_names[dl_ce_detail]);	//extra detail
			WriteText(LogFileHandle, LogIoResult, sString);

			StringFormat(sString, "");
			strcat(sString,CRLF);
			WriteText(LogFileHandle, LogIoResult, sString);
			dl_change_event = false;
		}
		else if(nPgmTime%50==0 && dl_change_event == false)
		{
			StringFormat(sString, "%4d\t", dl_step);

			WriteText(LogFileHandle, LogIoResult, sString);
			StringFormat(sString, "%4d\t", nPgmTime);
			WriteText(LogFileHandle, LogIoResult, sString);

			switch(dl_robot_action_state)
			{
			case dl_robot_stop:
				StringFormat(sString, "Stop\t");								//robot state name
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "None\t");									//extra detail
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "0\t");											//speed
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "0\t");											//distance
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", g_rel_heading);		//relitive heading for gyro
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", g_const_heading);	//constant heading for gyro
				WriteText(LogFileHandle, LogIoResult, sString);
				break;

			case dl_gyro_move:
				if(dl_dist_method == DL_IR) StringFormat(sString, "gyro_move_IR\t");		//robot state name
				else if(dl_dist_method == DL_ANGLE) StringFormat(sString, "g_move_angle\t");
				else if(dl_dist_method == DL_LIGHT) StringFormat(sString, "g_move_light\t");
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, g_datalog_details_names[dl_robot_action_detail]);	//extra detail
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "\t");																						//added the tab (\t)
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", dl_speed);					//speed
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", dl_dist);		    	//distance
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", g_rel_heading);		//relitive heading for gyro
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", g_const_heading);	//constant heading for gyro
				WriteText(LogFileHandle, LogIoResult, sString);
				if(dl_dist_method == DL_LIGHT)StringFormat(sString, "%4d\t", g_light_sensor);
				else StringFormat(sString, "%4d\t", dl_cur_dist);	//current distance value for end triger, could be angle/IR
					WriteText(LogFileHandle, LogIoResult, sString);
				if(dl_dist_method == DL_ANGLE || dl_dist_method == DL_LIGHT)
				{
					StringFormat(sString, "%4d\t", abs_get_angle_sensor_val(RELATIVE_BPU));	//current distance value interpreted for end triger, could be angle/IR
					WriteText(LogFileHandle, LogIoResult, sString);
				}
				break;

			case dl_gyro_turn:
				StringFormat(sString, "gyro_turn\t");								  	//robot state name
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, g_datalog_details_names[dl_robot_action_detail]);	//extra detail
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "\t");																						//added the tab (\t)
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", dl_speed);					//speed
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", dl_dist);		    	//distance
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", g_rel_heading);		//relitive heading for gyro
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", g_const_heading);	//constant heading for gyro
				WriteText(LogFileHandle, LogIoResult, sString);
				break;

			case dl_run_abdd:
				StringFormat(sString, "abdd\t");								  	//robot state name
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, g_datalog_details_names[dl_robot_action_detail]);	//extra detail
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "\t");																						//added the tab (\t)
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", dl_speed);					//speed
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", dl_dist);		    	//distance
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", g_rel_heading);		//relitive heading for gyro
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", g_const_heading);	//constant heading for gyro
				WriteText(LogFileHandle, LogIoResult, sString);
				break;

			case dl_wait:
				StringFormat(sString, "wait\t");								  	//robot state name
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, g_datalog_details_names[0]);	//extra detail
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "\t");																						//added the tab (\t)
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", dl_speed);					//speed
				WriteText(LogFileHandle, LogIoResult, sString);
				//StringFormat(sString, "%4d\t", dl_dist);		    	//distance
				//WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", g_rel_heading);		//relitive heading for gyro
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "%4d\t", g_const_heading);	//constant heading for gyro
				WriteText(LogFileHandle, LogIoResult, sString);
				break;
			}
			StringFormat(sString, "");
			strcat(sString,CRLF);
			WriteText(LogFileHandle, LogIoResult, sString);
			//wait1Msec(50);									// sample frequency
		}
	}*/
	//Close(LogFileHandle, LogIoResult);		// close the file once we are told to stop
	wait10Msec(20);
}

#endif /* !ABS_DATALOG_H */
