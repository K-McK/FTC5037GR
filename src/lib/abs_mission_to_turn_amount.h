/**
*
*  @file abs_mission_to_turn_amount.h
*
*  @brief  Enter a description of what this function does
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/
#ifndef ABS_MISSION_TO_TURN_AMOUNT
#define ABS_MISSION_TO_TURN_AMOUNT

int abs_mission_to_turn_amount(int starting_point, int ramp_position, bool good_gyro, e_turn_stopping_method turn_method)
{
	abs_dlog(__FILE__ ,"Turn amount calculator", "ramp position:", ramp_position, "good gyro?", good_gyro, "Turn method", turn_method);
	if(good_gyro)
	{
		switch (starting_point)
		{
		case 1:
		case 2:
			if(ramp_position == 2)
			{
				if(turn_method==TURN_TO)
				{
					return 275;
				}
				else
				{
					return 85;
				}
			}
			else
			{
				if(turn_method==TURN_TO)
				{
					return 265;
				}
				else
				{
					return 95;
				}
			}
		case 3:
			return 315;
		case 4:
			return 45;
		default:
			return 0;
		}
	}
	else
	{
		if(ramp_position == 2)
		{
			return 85;
		}
		else
		{
			return 95;
		}
	}
}
#endif /* !TEMPLATE_H */
