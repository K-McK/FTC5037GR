/**
*
*  @file abs_swing_turn_to.h
*
*  @brief The hedder file that alows you to do a swing turn
*
*  @param degree Tells the robot how much to turn
*
*  @param dir Tells the robot what way to turn
*
*  @param speed Tells the robot how fast to turn
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_SWING_TURN_TO_H
#define ABS_SWING_TURN_TO_H

#include "xzander/hitechnic-gyro.h"
#include "abs_turn_utils.h"
#include "lib/abs_gyro_read.h"
/** macros */


//=======================================
// swing turn
//=======================================
void abs_point_turn(int degree,e_direction dir,int speed)
{
	int i = 0;
	float rotSpeed = 0;
	float heading = 0;

if(dir == COUNTERCLOCKWISE)
	{
		motor[right_motor] = speed;
		motor[left_motor] = 0;
	}
	else
	{
		motor[right_motor] = 0;
		motor[left_motor] = speed;
	}

	while(i < 5)
	{
		if (abs(heading) > degree) i++;

		heading = abs_gyro_read(HTGYRO);

		//heading += rotSpeed * 0.02;

		nxtDisplayCenteredBigTextLine(3, "%2.0f", heading);
	}
	motor[right_motor] = 0;
	motor[left_motor] = 0;
}

//#define product(X, Y) ((X) * (Y))
//#define sum(X, Y) ((X) + (Y))
//#define min(X, Y) ((X) < (Y) ? (X) : (Y))
//#define max(X, Y) ((X) > (Y) ? (X) : (Y))

#endif /* !ABS_SWING_TURN_TO_H */
