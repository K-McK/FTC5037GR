/**
*
*  @file abs_point_turn_to.h
*
*  @brief The hedder file that alows you to do a point turn
*
*  Copyright 2013, Got Robot! FTC Team 5037
*
*/
#ifndef ABS_POINT_TURN_TO_H
#define ABS_POINT_TURN_TO_H

#include "xzander/hitechnic-gyro.h"
#include "abs_turn_utils.h"
#include "abs_gyro_read.h"
#include "abs_get_mem.h"
/** macros */


//=======================================
// point turn
//=======================================
void abs_point_turn_to(int degree,e_direction dir,int speed)
{
	int i = 0;
	float rotSpeed = 0;
	float heading = 0;
	turn_context* tcontext = 	(turn_context*)abs_get_mem(sizeof(turn_context));
	tcontext->time = 0;
	tcontext->heading = 0;
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
//gyro pre turn start
	while(i < 5)
	{
		if (abs(heading) > degree) i++;
		abs_gyro_read(HTGYRO,tcontext); //gyro read

		//heading += rotSpeed * 0.02;

		nxtDisplayCenteredBigTextLine(3, "%2.0f", tcontext->heading);
	}
	motor[right_motor] = 0;
	motor[left_motor] = 0;
}

//#define product(X, Y) ((X) * (Y))
//#define sum(X, Y) ((X) + (Y))
//#define min(X, Y) ((X) < (Y) ? (X) : (Y))
//#define max(X, Y) ((X) > (Y) ? (X) : (Y))

#endif /* !ABS_POINT_TURN_TO_H */
