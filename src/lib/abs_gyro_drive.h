/**
*
*  @file abs_gyro_drive_to.h
*
*  @brief handles the speed control for the motors based on the gyro
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_GYRO_DRIVE_H
#define ABS_GYRO_DRIVE_H

/** macros */


//=======================================
// gyro drive
//======================================='
void abs_gyro_drive(int speed,e_drive_direction dir)
{
	int error = drive_heading - relHeading;

	if(dir == FORWARD)
	{
		motor[left_motor] = speed - error;
		motor[right_motor] = speed + error;
	}
	else
	{
		motor[left_motor] = speed + error;
		motor[right_motor] = speed - error;
	}
}
#endif /* !ABS_GYRO_DRIVE_H */
