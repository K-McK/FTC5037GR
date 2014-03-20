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
	string buff = "";
	if(key != NULL)
	{
		StringFormat(buff, "\t ");
		StringFormat(buff, key);
		WriteText(LogFileHandle, LogIoResult, buff);
		StringFormat(buff, ": %d",value);
		WriteText(LogFileHandle, LogIoResult, buff);
	}
}


void abs_dlog(const char * input1,const char * input2, const char * input3_str = NULL, int input3 = 0, const char * input4_str = NULL, int input4 = 0, const char * input5_str = NULL, int input5 = 0, const char * input6_str = NULL, int input6 = 0)
{
	string buff = "";
	StringFormat(buff, "");
	strcat(buff,CRLF);
	WriteText(LogFileHandle, LogIoResult, buff);

	StringFormat(buff, "%09.3f\t",(((float)nPgmTime)/1000));
	WriteText(LogFileHandle, LogIoResult, buff);

	if(!strcmp(input1,""))StringFormat(buff, input1);
	else StringFormat(buff, "");
	WriteText(LogFileHandle, LogIoResult, input1);


	//StringFormat(buff, "\t");
	//WriteText(LogFileHandle, LogIoResult, buff);
	//StartTask(TaskID, nTaskPriority);

	StringFormat(buff, "\t");
	StringFormat(buff, input2);
	WriteText(LogFileHandle, LogIoResult, buff);

	log_parameter(input3_str, input3);
	log_parameter(input4_str, input4);
	log_parameter(input5_str, input5);
	log_parameter(input6_str, input6);

	StringFormat(buff, "rel-g %4d\t", g_rel_heading_use);
	WriteText(LogFileHandle, LogIoResult, buff);

	StringFormat(buff, "cnst-g %4d\t", g_const_heading);
	WriteText(LogFileHandle, LogIoResult, buff);
}
#endif /* !ABS_LOG_H */
