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
#ifndef ABS_LIFT_BLOCK_LIFTER_H
#define ABS_LIFT_BLOCK_LIFTER_H

#include "global_variables.h"

task abs_lift_block_lifter()
{
	//abs_log(__FILE__,"Enter",0,0,0,0);
	motor[block_lift_motor] = g_end_ramp_lift_speed;
	motor[block_lift_motor2] = g_end_ramp_lift_speed;
	wait1Msec(750);
	motor[block_lift_motor] = 0;
	motor[block_lift_motor2] = 0;
	//abs_log(__FILE__,"Exit",0,0,0,0);
}

#endif /* !TEMPLATE_H */
