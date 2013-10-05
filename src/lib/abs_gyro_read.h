/**
*
*  @file abs_gyro_read.h
*
*  @brief A hedder file that allows you to read the input comming from the gyro
*
*  Copyright 2013, Got Robot! FTC Team 5037
*
*	@param gyro Gyro raw sensor value
*
*/
#ifndef ABS_GYRO_READ_H
#define ABS_GYRO_READ_H



void abs_gyro_read (int GYRO, turn_context* tcontext)
{
	long currtime;
	float rawgyro = 0;
	currtime=nPgmTime;
	rawgyro = HTGYROreadRot(GYRO);
	tcontext->heading += (rawgyro - drift) * (float)(currtime - tcontext->time)/1000;
	//relHeading += (rawgyro - drift) * (float)(currtime - tcontext->time)/1000;
	tcontext->time = currtime;
}

#endif /* !ABS_GYRO_READ_H */
