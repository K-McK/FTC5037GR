/**
*
*  Filename:  abs_gyro_read.h
*
*  Description:  A hedder file that allows you to read the input comming from the gyro
*
*  Copyright 2013, Got Robot! FTC Team 5037
*
*	@param gyro Gyro raw sensor value
*
*/
#ifndef ABS_GYRO_READ_H
#define ABS_GYRO_READ_H


/** macros */
float abs_gyro_read (int GYRO)
{
	long currtime,prevtime;
	float rawgyro = 0;
	float constHeading=0;
	currtime=nPgmTime;
	rawgyro = HTGYROreadRot(GYRO);
	constHeading += (rawgyro - drift) * (float)(currtime-prevtime)/1000;
	//relHeading += (rawgyro - drift) * (float)(currtime-prevtime)/1000;
	prevtime = currtime;
	return constHeading;
}

#endif /* !ABS_GYRO_READ_H */
