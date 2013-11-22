/**
*
*  @file abs_joystick_drive.h
*
*  @brief The header file that handles the joystick motor control
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_JOYSTICK_DRIVE_H
#define ABS_JOYSTICK_DRIVE_H

/** macros */
//=======================================
// joystick drive
//=======================================
void abs_joystick_drive(e_joystick_method joy_type)
{
	//-----------------------------
	// drive motor controls
	//-----------------------------

	int speed1;
	int speed2;

	int j1 = abs(joystick.joy1_y1);
	int j2 = abs(joystick.joy1_y2);

	if(joy_type == LINEAR)
	{
		speed1 = j1*100/127;
		speed2 = j2*100/127;
	}
	else
	{
		speed1 = ((j1*j1) * 100/(128*128));
		speed2 = ((j2*j2) * 100/(128*128));
	}

	if(joy1Btn(7))
	{
		speed1 = speed1/5;
		speed2 = speed2/5;
	}
	else if(joy1Btn(5)){}
	else
	{
		speed1 = speed1/3;
		speed2 = speed2/3;
	}

	if(speed1<10) speed1 = 0;
	if(speed2<10) speed2 = 0;

	if(joystick.joy1_y1<0) speed1 = -speed1;
	if(joystick.joy1_y2<0) speed2 = -speed2;

	motor[right_motor] = speed2;
	motor[left_motor] = speed1;
}

#endif /* !ABS_JOYSTICK_DRIVE_H */
