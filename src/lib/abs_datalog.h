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

/** macros */

//=======================================
// data log
//=======================================
task abs_datalog()
{

	if(g_auto_program == true) Delete(LogFileName, LogIoResult);
	OpenWrite(LogFileHandle, LogIoResult, LogFileName, LogFileSize);

	if(g_auto_program == true)
	{
		StringFormat(sString, "===== Auto =====");
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
	}
	else
	{
		StringFormat(sString, "===== Tele Op =====");
		WriteText(LogFileHandle, LogIoResult, sString);
		StringFormat(sString, "");
		strcat(sString,CRLF);
		WriteText(LogFileHandle, LogIoResult, sString);
	}

	while(!LogData){EndTimeSlice();}

	while(LogData)
	{
		if(g_auto_program == true)
		{
			if(dl_robot_action_state == dl_change_event) abs_auto_datalog_write();
			else if(nPgmTime % 50 == 0) abs_auto_datalog_write();
		}
		else if(dl_teleop_btn_press) abs_teleop_datalog_write();

		StringFormat(sString, "");
		strcat(sString,CRLF);
		WriteText(LogFileHandle, LogIoResult, sString);
	}
	Close(LogFileHandle, LogIoResult);		// close the file once we are told to stop
	wait10Msec(20);
}

#endif /* !ABS_DATALOG_H */
