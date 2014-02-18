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
#ifndef ABS_DLOG_H
#define ABS_DLOG_H

/** macros */
void abs_dlog(const char * input1,const char * input2, const char * input3_str = NULL, int input3 = 0, const char * input4_str = NULL, int input4 = 0, const char * input5_str = NULL, int input5 = 0, const char * input6_str = NULL, int input6 = 0)
{
	StringFormat(sString, "%4d\t",nPgmTime);
	WriteText(LogFileHandle, LogIoResult, sString);

	if(!strcmp(input1,""))StringFormat(sString, input1);
	else StringFormat(sString, "");
	WriteText(LogFileHandle, LogIoResult, input1);

	StringFormat(sString, "\t");
	WriteText(LogFileHandle, LogIoResult, sString);

	if(input3_str == NULL)
	{
		return;
	}
	else
	{
		StringFormat(sString, "\t");
		StringFormat(sString, input3_str);
		WriteText(LogFileHandle, LogIoResult, sString);
		StringFormat(sString, "\t%d",input3);
		WriteText(LogFileHandle, LogIoResult, sString);

		if(input4_str == NULL)
		{
			return;
		}
		else
		{
			StringFormat(sString, "\t");
			StringFormat(sString, input4_str);
			WriteText(LogFileHandle, LogIoResult, sString);
			StringFormat(sString, "\t%d",input3);
			WriteText(LogFileHandle, LogIoResult, sString);
			if(input5_str == NULL)
			{
				return;
			}
			else
			{
				StringFormat(sString, "\t");
				StringFormat(sString, input4_str);
				WriteText(LogFileHandle, LogIoResult, sString);
				StringFormat(sString, "\t%d",input3);
				WriteText(LogFileHandle, LogIoResult, sString);
				if(input6_str == NULL)
				{
					return;
				}
				else
				{
					StringFormat(sString, "\t");
					StringFormat(sString, input6_str);
					WriteText(LogFileHandle, LogIoResult, sString);
					StringFormat(sString, "\t%d",input3);
					WriteText(LogFileHandle, LogIoResult, sString);
				}
			}
		}
	}


	StringFormat(sString, "rel-g %4d\t", g_rel_heading);
	WriteText(LogFileHandle, LogIoResult, sString);

	StringFormat(sString, "cnst-g %4d\t", g_const_heading);
	WriteText(LogFileHandle, LogIoResult, sString);
}
#endif /* !ABS_LOG_H */
