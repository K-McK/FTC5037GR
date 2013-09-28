/**
*
*  Filename:  math_utils.h
*
*  Description:  a collection of math operations
*
*  Copyright 2013, Got Robot! FTC Team 5037
*
*/
#ifndef ABS_POINT_TURN_TO_H
#define ABS_POINT_TURN_TO_H

#include "xzander/hitechnic-gyro.h"
#include "abs_turn_utils.h"
/** macros */


//=======================================
// point turn
//=======================================
void abs_point_turn_to(int degree,e_direction dir,int speed)
{
	int i = 0;
	float rotSpeed = 0;
	float heading = 0;

if(dir == COUNTERCLOCKWISE)
	{
		motor[right_motor] = speed;
		motor[left_motor] = -speed;
	}
	else
	{
		motor[right_motor] = -speed;
		motor[left_motor] = speed;
	}

	while(i < 5)
	{
		if (abs(heading) > degree) i++;

		rotSpeed = HTGYROreadRot(HTGYRO);

		heading += rotSpeed * 0.02;

		nxtDisplayCenteredBigTextLine(3, "%2.0f", heading);
	}
	motor[right_motor] = 0;
	motor[left_motor] = 0;
}

//#define product(X, Y) ((X) * (Y))
//#define sum(X, Y) ((X) + (Y))
//#define min(X, Y) ((X) < (Y) ? (X) : (Y))
//#define max(X, Y) ((X) > (Y) ? (X) : (Y))

#endif /* !MATH_UTILS_H */