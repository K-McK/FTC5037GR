string sFileName = "test2.txt";

TFileIOResult nIoResult;
TFileHandle hFileHandle;
int nFileSize = 100;
float  fParmToReadFloat = (float) 3.55;  // should only see this value if no file exists

task main()
{
	CloseAllHandles(nIoResult);																// make sure everything is closed
	wait1Msec(500);
	OpenRead(hFileHandle, nIoResult, sFileName , nFileSize);  // open the existing file
	ReadFloat(hFileHandle, nIoResult, fParmToReadFloat);			// read a single float value from it
	Close(hFileHandle, nIoResult);														// and close the file

	while(nNxtButtonPressed!=3)   // continue in editor until enter button is pressed
	{if (nNxtButtonPressed==1)
		{
			while(nNxtButtonPressed==1){};  // right arrow increases value
			fParmToReadFloat+=1;
		}
		if (nNxtButtonPressed==2)
		{
			while(nNxtButtonPressed==2){};  // left arrow decreases value
			fParmToReadFloat-=1;
		}
		nxtDisplayCenteredBigTextLine(6, "%3.1f", fParmToReadFloat); // update the display
	}

	Delete(sFileName, nIoResult);							// delete pre-existing file (if any)
	nxtDisplayBigTextLine(0, "Deleted");
	wait1Msec(2000);
	nFileSize = 100;
	OpenWrite(  hFileHandle, nIoResult, sFileName, nFileSize); // create new file
	nxtDisplayBigTextLine(2, "Opened");
	wait1Msec(2000);
	WriteFloat( hFileHandle, nIoResult, fParmToReadFloat);  // write our value
	nxtDisplayBigTextLine(4, "Written");
	wait1Msec(2000);
	Close(hFileHandle, nIoResult);				// and close the file
	nxtDisplayBigTextLine(6, "Closed");
	wait1Msec(2000);
}
