/**
 *
 *  @file abs_stop_robot.h
 *
 *  @brief when called stops the robot from moving
 *
 *  @param None n/a
 *
 *  @return Returns nothing
 *
 *  @copyright Copyright 2013, Got Robot! FTC Team 5037
 */
#ifndef ABS_STOP_ROBOT_H
#define ABS_STOP_ROBOT_H

void abs_stop_robot()
{
	motor[left_motor] = 0;
	motor[right_motor] = 0;
	motor[block_lift_motor] = 0;
	motor[block_lift_motor2] = 0;
	motor[sky_hook] = 0;
	servo[roger_slide] = 127;
}

#endif /* !ABS_STOP_ROBOT_H */
