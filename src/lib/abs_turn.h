/**
*
*  @file abs_point_turn_to.h
*
*  @brief The hedder file that alows you to do a point turn
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
#ifndef ABS_TURN_H
#define ABS_TURN_H

/** macros */

//=======================================
// point turn
//=======================================
void abs_turn(e_direction dir, e_turn_method turn_method, e_turn_stopping_method e_stop, int degree, int speed)
{
	int i = 0;
	relHeading = 0;
	int	heading = 0;
	//-------------------------
	//Turn To
	//-------------------------
	if(e_stop == TURN_TO)
	{
		//-------------------------
		// swing turn
		//-------------------------
		if(turn_method == SWING)
		{
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
		}

		//-------------------------
		// point turn
		//-------------------------
		else if(turn_method == POINT)
		{
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
		}
		else if(e_stop == TURN_TO)
		{
			//-------------------------
			// swing turn
			//-------------------------
			if(turn_method == SWING)
			{
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
			}

			//-------------------------
			// point turn
			//-------------------------
			else if(turn_method == POINT)
			{
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
			}
		}


		//-------------------------
		// turn condition
		//-------------------------
		if(e_stop == TURN_TO)
		{
			heading = constHeading;
		}
		else
		{
			heading = relHeading;
		}
		while(i < 5)
		{

			if (abs(heading) > degree) i++;
			nxtDisplayCenteredBigTextLine(1, "%d", degree);
		}
		motor[right_motor] = 0;
		motor[left_motor] = 0;
	}
}

#endif /* !ABS_TURN_H */
