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
task abs_joystick_gunner()
{
	while(true)
	{
		if(joy1Btn())
		{
			motor[]=-100;
		}
		else if(joy1Btn())
		{
			motor[]=100;
		}
		else motor[] = 0;

		//if(joy1Btn(9)) servo[roger_slide] = -60;
		//else if(joy1Btn(10)) servo[roger_slide] = 60;
		//else servo[roger_slide] = 0;

		if(joy2Btn())
		{
			motor()=-60;
		}
		else motor()=0;

		if(joy1Btn()) servo[] = 0;
		else if(joy1Btn()) servo[] = 255;
		else servo[roger_slide] = 127;

		if(abs(joystick.joy2_y2)>10) motor[] = joystick.joy2_y2*100/127;
		else motor[] = 0;

		int grabber_position;

		if(joy2Btn(1) || joy1Btn(1)) grabber_position = GRABBER_OPEN;
		if(joy2Btn(2) || joy1Btn(2)) grabber_position = GRABBER_MID;
		if(joy2Btn(3) || joy1Btn(3)) grabber_position = GRABBER_CLOSE;

		if(joy2Btn(5)) grabber_position = GRABBER_POS_LEFT_OPEN;
		else if(joy2Btn(7)) grabber_position = GRABBER_POS_LEFT_CLOSE;
		if(joy2Btn(6)) grabber_position = GRABBER_POS_RIGHT_OPEN;
		else if(joy2Btn(8)) grabber_position = GRABBER_POS_RIGHT_CLOSE;

		switch(grabber_position)
		{
		case GRABBER_OPEN:
			servo[grabber_left] = GRABBER_LEFT_OPEN;
			servo[grabber_right] = GRABBER_RIGHT_OPEN;
			break;
		case GRABBER_MID:
			servo[grabber_left] = GRABBER_LEFT_MID;
			servo[grabber_right] = GRABBER_RIGHT_MID;
			break;
		case GRABBER_CLOSE:
			servo[grabber_left] = GRABBER_LEFT_CLOSE;
			servo[grabber_right] = GRABBER_RIGHT_CLOSE;
			break;
		case GRABBER_POS_LEFT_CLOSE:
			servo[grabber_left] = GRABBER_LEFT_CLOSE;
			break;
		case GRABBER_POS_LEFT_OPEN:
			servo[grabber_left] = GRABBER_LEFT_OPEN;
			break;
		case GRABBER_POS_RIGHT_CLOSE:
			servo[grabber_right] = GRABBER_RIGHT_CLOSE;
			break;
		case GRABBER_POS_RIGHT_OPEN:
			servo[grabber_right] = GRABBER_RIGHT_OPEN;
			break;
		}

	}
}

#endif /* !ABS_JOYSTICK_DRIVE_H */
