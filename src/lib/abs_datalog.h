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
const string LogFileName = "DATALOG.txt";
TFileIOResult LogIoResult;
TFileHandle LogFileHandle;
int LogFileSize= 12000;
string sString;
string CRLF = (char)13+(char)10;

	WriteText(LogFileHandle, LogIoResult, sString);
	//StringFormat(sString, "%7d", bearingAC2);

	Delete(LogFileName, LogIoResult);
	OpenWrite(  LogFileHandle, LogIoResult, LogFileName, LogFileSize);
	while(!LogData){EndTimeSlice();}
	while(LogData)
	{
		//StringFormat(sString, "%4d", step);							//	autonomous program step number
		//WriteText(IRFileHandle, IRIoResult, sString);
		//StringFormat(sString, "%7d", IR_Bearing);					//our calculated bearing IR one
		//WriteText(IRFileHandle, IRIoResult, sString);
		//StringFormat(sString, "%7d", bearingAC);		//			IR calculated bearing IR one
		//WriteText(IRFileHandle, IRIoResult, sString);
		////StringFormat(sString, "%7d", IR_Bearing2);		//		our calculated bearing IR two
		//WriteText(IRFileHandle, IRIoResult, sString);
		//StringFormat(sString, "%7d", bearingAC);				//	IR calculated bearing IR two
		//WriteText(IRFileHandle, IRIoResult, sString);
		//StringFormat(sString, "%7d", sonarLive);				//	Side mounted sonar
		//WriteText(IRFileHandle, IRIoResult, sString);
		//StringFormat(sString, "%7d", sonarLive2);				//	Front mounted sonar
		//WriteText(IRFileHandle, IRIoResult, sString);
		//StringFormat(sString, "%7d", light_normalised);				//	Front mounted sonar
		//strcat(sString,CRLF);
		//WriteText(IRFileHandle, IRIoResult, sString);
		wait1Msec(50);									// sample frequency
	}
	Close(LogFileHandle, LogIoResult);		// close the file once we are told to stop
	wait10Msec(20);
}

#endif /* !ABS_DATALOG_H */
