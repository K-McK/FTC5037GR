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

#include "abs_log.h"

/** macros */

//=======================================
// turn
//=======================================
void abs_turn(e_direction dir, e_turn_method turn_method, e_turn_stopping_method e_stop, int degree, int speed)
{
	//data log baced on turn direction
	if(dir == COUNTERCLOCKWISE)
		abs_log(__FILE__ ,"enter CC",speed,degree,g_rel_heading,g_const_heading);
	else
		abs_log(__FILE__ ,"enter C",speed,degree,g_rel_heading,g_const_heading);

	g_rel_heading = 0;
	g_rel_heading2 = 0;
	int target = 0;

	//turn to a direction instead of turning an amount

	if(e_stop == TURN_TO)
	{
		//turn baced on the angle of
		if(dir == COUNTERCLOCKWISE)
		{
			if(degree<g_recont_heading) target = -(g_recont_heading-degree);
			else target = -(360-(degree-g_recont_heading));
		}
		else
			//turn to a amount
		{
			if(degree<g_recont_heading) target = 360-(g_recont_heading-degree);
			else target = degree-g_recont_heading;
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
			while(abs(g_rel_heading) < abs(degree))/*i < 5)*/
			{
				nxtDisplayCenteredBigTextLine(5, "%d", g_recont_heading);

				if(dir == COUNTERCLOCKWISE)
				{
					motor[right_motor] = adjusted_turn_speed(speed, abs(degree), abs(g_rel_heading));
					motor[left_motor] = 0;
				}
				else
				{
					motor[right_motor] = 0;
					motor[left_motor] = adjusted_turn_speed(speed, abs(degree), abs(g_rel_heading));
				}
			}
		}

		//-------------------------
		// point turn
		//-------------------------
		else
		{
			while(abs(g_rel_heading) < abs(degree))/*i < 5)*/
			{
				nxtDisplayCenteredBigTextLine(5, "%d", g_recont_heading);

				if(dir == COUNTERCLOCKWISE)
				{
					motor[right_motor] = adjusted_turn_speed(speed, abs(degree), abs(g_rel_heading));
					motor[left_motor] = -adjusted_turn_speed(speed, abs(degree), abs(g_rel_heading));
				}
				else
				{
					motor[right_motor] = -adjusted_turn_speed(speed, abs(degree), abs(g_rel_heading));
					motor[left_motor] = adjusted_turn_speed(speed, abs(degree), abs(g_rel_heading));
				}
			}
		}
	}
	//-------------------------
	// turn condition
	//-------------------------
		motor[right_motor] = 0;
		motor[left_motor] = 0;

	abs_log(__FILE__ ,"exit",speed,degree,g_rel_heading,g_const_heading);
}

#endif /* !ABS_TURN_H */
