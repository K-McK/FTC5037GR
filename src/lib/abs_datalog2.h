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
#ifndef ABS_LOG_H
#define ABS_LOG_H

/** macros */
void log(string input1, string input2, string input3, string input4, string input5)
{
	if(input1!=NULL)StringFormat(sString, input1);
	else StringFormat(sString, "");
	WriteText(LogFileHandle, LogIoResult, sString);

	if(input2!=NULL)StringFormat(sString, input2);
	else StringFormat(sString, "");
	WriteText(LogFileHandle, LogIoResult, sString);

	if(input3!=NULL)StringFormat(sString, input3);
	else StringFormat(sString, "");
	WriteText(LogFileHandle, LogIoResult, sString);

	if(input4!=NULL)StringFormat(sString, input4);
	else StringFormat(sString, "");
	WriteText(LogFileHandle, LogIoResult, sString);

	if(input5!=NULL)StringFormat(sString, input5);
	else StringFormat(sString, "");
	WriteText(LogFileHandle, LogIoResult, sString);
}
#endif /* !ABS_LOG_H */
