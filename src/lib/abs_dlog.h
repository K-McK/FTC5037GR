/**
*
*  @file abs_dlog.h
*
*  @brief A function that handles the data log
*
*  @param N/A
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_DLOG_H
#define ABS_DLOG_H

void log_parameter(const char * key, int value)
{
	if(key != NULL)
	{
		StringFormat(sString, "\t");
		StringFormat(sString, key);
		WriteText(LogFileHandle, LogIoResult, sString);
		StringFormat(sString, ": %d",value);
		WriteText(LogFileHandle, LogIoResult, sString);
	}
}

void abs_dlog(const char * input1,const char * input2, const char * input3_str = NULL, int input3 = 0, const char * input4_str = NULL, int input4 = 0, const char * input5_str = NULL, int input5 = 0, const char * input6_str = NULL, int input6 = 0)
{
	StringFormat(sString, "");
	strcat(sString,CRLF);
	WriteText(LogFileHandle, LogIoResult, sString);

	StringFormat(sString, "%09.3f\t",(((float)nPgmTime)/1000));
	WriteText(LogFileHandle, LogIoResult, sString);

	if(!strcmp(input1,""))StringFormat(sString, input1);
	else StringFormat(sString, "");
	WriteText(LogFileHandle, LogIoResult, input1);


	StringFormat(sString, "\t");
	WriteText(LogFileHandle, LogIoResult, sString);
	//StartTask(TaskID, nTaskPriority);

	StringFormat(sString, "\t");
	StringFormat(sString, input2);
	WriteText(LogFileHandle, LogIoResult, sString);

	log_parameter(input3_str, input3);
	log_parameter(input4_str, input4);
	log_parameter(input5_str, input5);
	log_parameter(input6_str, input6);

	StringFormat(sString, "rel-g %4d\t", g_rel_heading_use);
	WriteText(LogFileHandle, LogIoResult, sString);

	StringFormat(sString, "cnst-g %4d\t", g_const_heading_use);
	WriteText(LogFileHandle, LogIoResult, sString);
}
#endif /* !ABS_LOG_H */
