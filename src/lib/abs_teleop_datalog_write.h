/**
*
*  @file abs_datalog.h
*
*  @brief A function that handels the data log for tele op
*
*  @param N/A
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_TELEOP_DATALOG_WRITE_H
#define ABS_TELEOP_DATALOG_WRITE_H

/** macros */

//=======================================
// data log
//=======================================
void abs_teleop_datalog_write()
{
	dl_step++;
	StringFormat(sString, "%4d\t", nPgmTime);
	WriteText(LogFileHandle, LogIoResult, sString);
	StringFormat(sString, "%4d\t", dl_step);
	WriteText(LogFileHandle, LogIoResult, sString);

	StringFormat(sString, "");
	strcat(sString,CRLF);
	WriteText(LogFileHandle, LogIoResult, sString);

	//----------------------------------
	// controler 1
	//----------------------------------

	StringFormat(sString, "joy 1");
	WriteText(LogFileHandle, LogIoResult, sString);
	for(int i=0;i>12;i++)
	{
		StringFormat(sString, g_dl_joy1_brn_names[i]);
		WriteText(LogFileHandle, LogIoResult, sString);
		StringFormat(sString, " : ");
		WriteText(LogFileHandle, LogIoResult, sString);
		StringFormat(sString, "%4d\t", dl_joy2_btn_array[i]);
		WriteText(LogFileHandle, LogIoResult, sString);
	}

	StringFormat(sString, "D-pad %4d\t", dl_joy1_dpad);
	WriteText(LogFileHandle, LogIoResult, sString);

	StringFormat(sString, "j1 %4d\t", joystick.joy1_y1);
	WriteText(LogFileHandle, LogIoResult, sString);
	StringFormat(sString, "j2 %4d\t", joystick.joy1_y2);
	WriteText(LogFileHandle, LogIoResult, sString);

	StringFormat(sString, "");
	strcat(sString,CRLF);
	WriteText(LogFileHandle, LogIoResult, sString);

	//----------------------------------
	// controler 2
	//----------------------------------

	StringFormat(sString, "joy 2");
	WriteText(LogFileHandle, LogIoResult, sString);
	for(int i=0;i>12;i++)
	{
		StringFormat(sString, g_dl_joy2_brn_names[i]);
		WriteText(LogFileHandle, LogIoResult, sString);
		StringFormat(sString, " : ");
		WriteText(LogFileHandle, LogIoResult, sString);
		StringFormat(sString, "%4d\t", dl_joy2_btn_array[i]);



		WriteText(LogFileHandle, LogIoResult, sString);
	}

	StringFormat(sString, "D-pad %4d\t", dl_joy2_dpad);
	WriteText(LogFileHandle, LogIoResult, sString);

	StringFormat(sString, "j1 %4d\t", joystick.joy2_y1);
	WriteText(LogFileHandle, LogIoResult, sString);
	StringFormat(sString, "j2 %4d\t", joystick.joy2_y2);
	WriteText(LogFileHandle, LogIoResult, sString);

	dl_teleop_btn_press = false;
}

#endif /* !ABS_TELEOP_DATALOG_WRITE_H */
