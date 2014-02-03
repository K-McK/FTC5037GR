/**
*
*  @file abs_teleop_datalog.h
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
#ifndef ABS_TELEOP_DATALOG_H
#define ABS_TELEOP_DATALOG_H

/** macros */

//=======================================
// data log
//=======================================
task abs_teleop_datalog()
{
	const string TeleFileName = "TELELOG.txt";
	TFileIOResult TeleIoResult;
	TFileHandle TeleFileHandle;
	long TeleFileSize = 12000;
	string sString;
	string CRLF = (char)13+(char)10;

	Delete(TeleFileName, TeleIoResult);
	OpenWrite(TeleFileHandle, TeleIoResult, TeleFileName, TeleFileSize);

	int k = 0;
	while(nPgmTime<60000)
	{
		//------------------------------
		// check for button press
		//------------------------------

		if(joy1Btn(k) && dl_joy1_btns[k]==false)
		{
			dl_joy1_btns[k]=true;
			dl_btn_change = true;
		}
		if(joy2Btn(k) && dl_joy2_btns[k]==false)
		{
			dl_joy2_btns[k]=true;
			dl_btn_change = true;
		}

		//------------------------------
		// check for button release
		//------------------------------

		if((joy1Btn(k)==false) && dl_joy1_btns[k]==true)
		{
			dl_joy1_btns[k]=false;
			dl_btn_change = true;
		}
		if((joy2Btn(k)==false) && dl_joy2_btns[k]==true)
		{
			dl_joy2_btns[k]=false;
			dl_btn_change = true;
		}
		k++;
		if(k>12)k=0;

		//==============================================

		if(dl_btn_change == true)
		{
			dl_btn_change = false;
			PlayTone(400,20);

			StringFormat(sString, "%4d~\t",nPgmTime);
			WriteText(TeleFileHandle, TeleIoResult, sString);

			for(int i=1;i<12;i++)
			{
				if(dl_joy1_btns[i]==true)StringFormat(sString, "-%2d-T\t",i);
				else StringFormat(sString, " %2d F\t",i);
				WriteText(TeleFileHandle, TeleIoResult, sString);
			}

			StringFormat(sString, "");
			strcat(sString,CRLF);
			WriteText(TeleFileHandle, TeleIoResult, sString);
		}
	}
	//while(nPgmTime<14999)
	//{
	//	if(dl_btn_change==true)
	//	{
	//		StringFormat(sString, "%4d",nPgmTime);
	//		WriteText(TeleFileHandle, TeleIoResult, sString);

	//		StringFormat(sString, "");
	//		strcat(sString,CRLF);
	//		WriteText(TeleFileHandle, TeleIoResult, sString);

	//		for(int i=0;i>12;i++)
	//		{
	//			StringFormat(sString, "%4d\t",dl_joy1_btns[i]);
	//		WriteText(TeleFileHandle, TeleIoResult, sString);
	//		}

	//		StringFormat(sString, "");
	//		strcat(sString,CRLF);
	//		WriteText(TeleFileHandle, TeleIoResult, sString);

	//		for(int i=0;i>12;i++)
	//		{
	//			StringFormat(sString, "%4d\t",dl_joy2_btns[i]);
	//		WriteText(TeleFileHandle, TeleIoResult, sString);
	//		}

	//		StringFormat(sString, "");
	//		strcat(sString,CRLF);
	//		WriteText(TeleFileHandle, TeleIoResult, sString);
	//	}
	//}
	//Close(TeleFileHandle, TeleIoResult);		// close the file once we are told to stop
	//PlayTone(200,20);
	//wait10Msec(20);

	Close(TeleFileHandle, TeleIoResult);		// close the file once we are told to stop
	PlayTone(200,20);
	wait10Msec(20);
}

#endif /* !ABS_TELEOP_DATALOG_H */
