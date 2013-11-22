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
		//-----------------------------
		// robot lift
		//-----------------------------
		if(joystick.joy2_y2>10) motor[sky_hook]=ROBOT_LIFT_UP;
		else if(joystick.joy2_y2<-10)motor[sky_hook]=ROBOT_LIFT_DOWN;
		else motor[sky_hook] = 0;

		//-----------------------------
		// flag motor control
		//-----------------------------
		switch(joystick.joy2_TopHat)
		{
		case -1:
			motor[jolly_roger]= 0;
			break;
		case 1:
			motor[jolly_roger] = FLAG_SPEED_UP;
			break;
		case 4:
			motor[jolly_roger] = FLAG_SPEED_DOWN;
			break;
		}

		//-----------------------------
		// roger slide
		//-----------------------------
		if(joy1Btn(9)) servo[roger_slide] = 0;
		else if(joy1Btn(10)) servo[roger_slide] = 255;
		else servo[roger_slide] = 127;

		//-----------------------------
		// block lift
		//-----------------------------
		if(joystick.joy2_y1>10) motor[block_lift_motor] = BLOCK_SPEED_UP;
		else if(joystick.joy2_y1<-10) motor[block_lift_motor] = BLOCK_SPEED_DOWN;
		else motor[block_lift_motor] = 0;

		//-----------------------------
		// block grabber
		//-----------------------------
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
			servo[left_grabber] = GRABBER_LEFT_OPEN;
			servo[right_grabber] = GRABBER_RIGHT_OPEN;
			break;
		case GRABBER_MID:
			servo[left_grabber] = GRABBER_LEFT_MID;
			servo[right_grabber] = GRABBER_RIGHT_MID;
			break;
		case GRABBER_CLOSE:
			servo[left_grabber] = GRABBER_LEFT_CLOSE;
			servo[right_grabber] = GRABBER_RIGHT_CLOSE;
			break;
		case GRABBER_POS_LEFT_CLOSE:
			servo[left_grabber] = GRABBER_LEFT_CLOSE;
			break;
		case GRABBER_POS_LEFT_OPEN:
			servo[left_grabber] = GRABBER_LEFT_OPEN;
			break;
		case GRABBER_POS_RIGHT_CLOSE:
			servo[right_grabber] = GRABBER_RIGHT_CLOSE;
			break;
		case GRABBER_POS_RIGHT_OPEN:
			servo[right_grabber] = GRABBER_RIGHT_OPEN;
			break;
		}
	}
}

#endif /* !ABS_JOYSTICK_DRIVE_H */
