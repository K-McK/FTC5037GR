/**
*
*  Filename:  math_utils.h
*
*  Description:  a collection of math operations
*
*  Copyright 2013, Got Robot! FTC Team 5037
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

#endif /* !MATH_UTILS_H */
