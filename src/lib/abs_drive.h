/**
*
*  @file template.h (this should be the name of the function)
*
*  @brief  Enter a description of what this function does
*
*  @param
*
*  @return
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/
#ifndef ABS_DRIVE_H
#define ABS_DRIVE_H

#include "xzander/hitechnic-angle.h"
/** macros */
//=========================
//Drive
//=========================
void abs_drive(e_drive_direction dir, e_stopping_method dist_method, int dist, int speed)
{
	HTANGresetAccumulatedAngle(ANGLE_SENSOR);
	int i = 0;
	nMotorEncoder(right_motor)= 0;

	if(dir == FORWARD)  //Decides if you are driveing forwards or backwards
	{
		motor(right_motor)=speed;
		motor(left_motor)=speed;
	}
	else
	{
		motor(right_motor)=-speed;
		motor(left_motor)=-speed;
	}

	if(dist_method == E_TIME)   //time stopping method
	{
		wait1Msec(dist);
	}
	else if(dist_method == E_DEGREES)  //encoder stopping method
	{
		while(i<5)
		{
			if(abs(nMotorEncoder(right_motor)) > dist)
				i++;
		}
	}
	else
	{
		if(dir == FORWARD)
		{
			while(HTANGreadAccumulatedAngle(ANGLE_SENSOR) < distance_to_angle_derees(dist));
		}
		else
		{
			while(HTANGreadAccumulatedAngle(ANGLE_SENSOR) < distance_to_angle_derees(-dist));
		}
		motor(left_motor)=0;
		motor(right_motor)=0;
	}
}


	/** enumerations */

	/** structures */

	/** function prototypes */

	/** global constant variables */

#endif /* !ABS_DRIVE_H */
