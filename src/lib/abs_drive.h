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

/** macros */
//=========================
//Drive
//=========================
void abs_drive(e_drive_direction dir, e_distance_method dist_method, int dist, int speed)
{
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
	else   //encoder stopping method
	{
		while(i<5)
		{
			if(abs(nMotorEncoder(right_motor)) > dist)
				i++;
		}
	}
	motor(left_motor)=0;
	motor(right_motor)=0;
}

/** enumerations */

/** structures */

/** function prototypes */

/** global constant variables */

#endif /* !ABS_DRIVE_H */
