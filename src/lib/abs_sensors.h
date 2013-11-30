/**
*
*  @file abs_sensors.h
*
*  @brief A hedder file that handles the sensors
*
*  @param no paramiters
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
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
			//nxtDisplayBigTextLine(3, "%2d", IR_Bearing);
		}
		//-------------------------
		// HiTechnic IR Sensor 2
		//-------------------------
		bearingAC2 = HTIRS2readACDir(HTIRS2_2);				// Read the IR bearing from the sensor
		currDir2 = (float) bearingAC2;

		HTIRS2readAllACStrength(HTIRS2_2, acS2[0], acS2[1], acS2[2], acS2[3], acS2[4]);
		//-----------------------------------
		// code for the peaks of IR sensor 2
		//-----------------------------------
		if (bearingAC2!=0)								// we have a valid IR signal
		{
			int maximum = -1;
			int peak = 0, offset=0;
			for (int i=0;i<5;i++)	// scan array to find the peak entry
			{	if (acS2[i]>maximum)
				{
					peak = i;
					maximum = acS2[i];
				}
			}
			offset=0;
			if ((peak < 4) && (peak>0) && (acS2[peak] != 0))  // we are not working with extreme value
			{
				if (acS2[peak-1]!=acS2[peak+1]) // if the values either side of the peak are identical then peak is peak
				{
					if (acS2[peak-1]>acS2[peak+1])	// otherwise decide which side has higher signal
					{
						offset = -25*(1-(float)(acS2[peak]-acS2[peak-1])/		// calculate the bias away from the peak
						max(acS2[peak], acS2[peak-1]));
					}
					else
					{
						offset = 25*(1-(float)(acS2[peak]-acS2[peak+1])/
						max(acS2[peak], acS2[peak+1]));
					}
				}
			}
			IR_Bearing2 = (float)((peak-2)*50) + offset;		// direction is the total of the peak bias plus the adjacent bias
			//nxtDisplayBigTextLine(3, "%2d", IR_Bearing);
		}
		//-------------------------
		// HiTechnic Gyro
		//-------------------------

		currtime=nPgmTime;
		rawgyro = HTGYROreadRot(HTGYRO);
		constHeading += (rawgyro - drift) * (float)(currtime-prevtime)/1000;
		relHeading += (rawgyro - drift) * (float)(currtime-prevtime)/1000;
		prevtime = currtime;

		recont_heading = constHeading % 360;
		if(recont_heading<0) recont_heading += 360;

		//-------------------------
		// HiTechnic accelermoeter
		//-------------------------

		HTACreadAllAxes(HTAC, _x_axis, _y_axis, _z_axis);
		accelermoeter_sensor = _x_axis;

		if(sensor_reference_drive == true)
		{
			accelermoeter_reads++;
			accelermoeter_array[accelermoeter_reads%50]=accelermoeter_sensor;
			for(int i=0;i<30;i++)
			{
				accelermoeter_total_value = accelermoeter_array[i];
			}
			accelermoeter_average = accelermoeter_total_value/50;
		}
		else
		{
			accelermoeter_reads = 0;
			accelermoeter_total_value = 0;
			accelermoeter_average = 0;
			memset(accelermoeter_array,0,30);
		}
		//-------------------------
		// HiTechnic angle sensor
		//-------------------------
		//if(reset_angle == true) HTANGresetAccumulatedAngle(HTANG);
		//else angle_sensor = HTANGreadAccumulatedAngle(HTANG);
	}
}
