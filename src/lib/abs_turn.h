/**
*
*  @file abs_turn.h
*
*  @brief The header file that alows you to do a point turn
*
*  @param degree Tells the robot how much to turn
*
*  @param dir Tells the robot what way to turn
*
*  @param speed Tells the robot how fast to turn
*
*  @return Returns nothing
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
	int target = 0;

	if(e_stop == TURN_TO)
	{
		if(dir == COUNTERCLOCKWISE)
		{
			if(degree<recont_heading) target = -(recont_heading-degree);
			else target = -(360-(degree-recont_heading));
		}
		else
		{
			if(degree<recont_heading) target = 360-(recont_heading-degree);
			else target = degree-recont_heading;
		}
		abs_turn(dir, turn_method, TURN, target, speed);
		PlaySoundFile("! Click.rso");
	}
	else
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
		else
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

	if(e_stop == TURN)
	{
		while(i < 5)
		{
			if (abs(relHeading) > abs(degree)) i++;
			nxtDisplayCenteredBigTextLine(5, "%d", recont_heading);
		}
		motor[right_motor] = 0;
		motor[left_motor] = 0;
	}
}

#endif /* !ABS_TURN_H */
