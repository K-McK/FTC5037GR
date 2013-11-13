/**
*
*  @file abs_joystick_drive.h
*
*  @brief The header file that handles the joystick motor control
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_JOYSTICK_GUNNER_H
#define ABS_JOYSTICK_GUNNER_H

/** macros */
//=======================================
// joystick drive
//=======================================
void abs_joystick_gunner()
{
	if(abs(joystick.joy2_y1) > 10) 	motor[block_grabber_left] = joystick.joy2_y1*100/127;
	else motor[block_grabber_left] = 0;

	if(abs(joystick.joy2_y2) > 10) motor[block_grabber_right] = joystick.joy2_y2*100/127;
	else motor[block_grabber_right] = 0;

	if(joy2Btn(4))
	{
		motor(flag_motor)=75;
	}

	else if(joy2Btn(2))
	{
		motor(flag_motor)=-75;
	}

	else motor(flag_motor)=0;

if(joystick.joy1_TopHat == 0)
motor(lifter_motor)=LIFT_SPEED_UP;
if(joystick.joy1_TopHat == 4)
motor(lifter_motor)=LIFT_SPEED_DOWN;

}

#endif /* !ABS_JOYSTICK_DRIVE_H */
