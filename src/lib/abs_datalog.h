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
	wait10Msec(20);
}

#endif /* !ABS_DATALOG_H */
