/**
*
*  @file abs_smoke_execute.h
*
*  @brief executes commands sent in smoke test
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_SMOKE_EXECUTE_H
#define ABS_SMOKE_EXECUTE_H

#include "abs_get_angle_sensor_val.h"

void abs_smoke_execute(int test_num)
{
	while(nNxtButtonPressed!=kEnterButton)
	{
		switch(test_num)
		{
		case 1:
			if(nNxtButtonPressed==kLeftButton)
			{
				motor[block_lift_motor] = g_block_speed_down;
				motor[block_lift_motor2] = g_block_speed_down;
			}
			break;
		}
	}
}

#endif /* !ABS_SMOKE_EXECUTE_H */
