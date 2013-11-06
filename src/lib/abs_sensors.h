//=====================================================================================
//
//  ***    ***   *****      ****    ***   ****    ***   *****     ***
// *   *  *   *    *        *   *  *   *  *   *  *   *    *      *   *
// *      *   *    *        *   *  *   *  *   *  *   *    *          *
// *  **  *   *    *        ****   *   *  ****   *   *    *         *
// *   *  *   *    *        * *    *   *  *   *  *   *    *        *
// *   *  *   *    *        *  *   *   *  *   *  *   *    *
//  ***    ***     *        *   *   ***   ****    ***     *        *
//
//=====================================================================================
//
// FTC TEAM 5037
// Elgin Technlogy Center, Illinois
// Block Party (2013-2014)
// User Inferface Tasks
//
//========================================
// Sensors not including gyro
//========================================

task abs_sensors_read ()
{
	prevtime = nPgmTime;

	while(true)
	{
		//-------------------------
		// HiTechnic IR Sensor
		//-------------------------
		bearingAC = HTIRS2readACDir(HTIRS2);				// Read the IR bearing from the sensor
		currDir = (float) bearingAC;

		HTIRS2readAllACStrength(HTIRS2, acS[0], acS[1], acS[2], acS[3], acS[4]);
		//-----------------------------------
		// code for the peaks of IR sensor
		//-----------------------------------
		if (bearingAC!=0)								// we have a valid IR signal
		{
			int maximum = -1;
			int peak = 0, offset=0;
			for (int i=0;i<5;i++)	// scan array to find the peak entry
			{	if (acS[i]>maximum)
				{
					peak = i;
					maximum = acS[i];
				}
			}
			offset=0;
			if ((peak < 4) && (peak>0) && (acS[peak] != 0))  // we are not working with extreme value
			{
				if (acS[peak-1]!=acS[peak+1]) // if the values either side of the peak are identical then peak is peak
				{
					if (acS[peak-1]>acS[peak+1])	// otherwise decide which side has higher signal
					{
						offset = -25*(1-(float)(acS[peak]-acS[peak-1])/		// calculate the bias away from the peak
						max(acS[peak], acS[peak-1]));
					}
					else
					{
						offset = 25*(1-(float)(acS[peak]-acS[peak+1])/
						max(acS[peak], acS[peak+1]));
					}
				}
			}
			IR_Bearing = (float)((peak-2)*50) + offset;		// direction is the total of the peak bias plus the adjacent bias
		}
		//-------------------------
		// HiTechnic Gyro
		//-------------------------

		currtime=nPgmTime;
		rawgyro = HTGYROreadRot(HTGYRO);
		constHeading += (rawgyro - drift) * (float)(currtime-prevtime)/1000;
		relHeading += (rawgyro - drift) * (float)(currtime-prevtime)/1000;
		prevtime = currtime;
	}
}
