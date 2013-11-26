/**
*
*  @file abs_joystick_gunner.h
*
*  @brief The header file that handles the joystick motor control
*
*  @param no paramiters
*
*  @return Returns nothing
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
		// flag motor control
		//-----------------------------
		misc = joystick.joy2_TopHat;
		switch(joystick.joy2_TopHat)
		{
		case -1:
			motor[jolly_roger]= 0;
			break;
		case 0:
			motor[jolly_roger] = FLAG_SPEED_UP;
			break;
		case 2:
			motor[jolly_roger] = FLAG_SPEED_RIGHT;
			break;
		case 6:
			motor[jolly_roger] = FLAG_SPEED_LEFT;
			break;
		case 4:
			motor[jolly_roger] = FLAG_SPEED_DOWN;
			break;
		}

		//-----------------------------
		// roger slide
		//-----------------------------
		if(joystick.joy2_y2>10) servo[roger_slide] = 255;
		else if(joystick.joy2_y2<-10) servo[roger_slide] = 0;
		else servo[roger_slide] = 127;

		//-----------------------------
		// robot kill switch
		//-----------------------------
		if((joy1Btn(9))&&(joy2Btn(9))&&(joy1Btn(10))&&(joy2Btn(10))) program_done = true;

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

		if(joy2Btn(1)) //grabber_position = GRABBER_OPEN;
		{
			servo[grabber_left] = GRABBER_LEFT_OPEN;
			servo[grabber_right] = GRABBER_RIGHT_OPEN;
		}
		if(joy2Btn(2)) //grabber_position = GRABBER_MID;
		{
			servo[grabber_left] = GRABBER_LEFT_MID;
			servo[grabber_right] = GRABBER_RIGHT_MID;
		}
		if(joy2Btn(3)) //grabber_position = GRABBER_CLOSE;
		{
			servo[grabber_left] = GRABBER_LEFT_CLOSE;
			servo[grabber_right] = GRABBER_RIGHT_CLOSE;
		}

		if(joy2Btn(5)) servo[grabber_left] = GRABBER_LEFT_OPEN;
		else if(joy2Btn(7)) servo[grabber_left] = GRABBER_LEFT_CLOSE;
		if(joy2Btn(6)) servo[grabber_right] = GRABBER_RIGHT_OPEN;
		else if(joy2Btn(8)) servo[grabber_right] = GRABBER_RIGHT_CLOSE;

		//switch(grabber_position)
		//{
		//case GRABBER_OPEN:
		//	servo[grabber_left] = GRABBER_LEFT_OPEN;
		//	servo[grabber_right] = GRABBER_RIGHT_OPEN;
		//	break;
		//case GRABBER_MID:
		//	servo[grabber_left] = GRABBER_LEFT_MID;
		//	servo[grabber_right] = GRABBER_RIGHT_MID;
		//	break;
		//case GRABBER_CLOSE:
		//	servo[grabber_left] = GRABBER_LEFT_CLOSE;
		//	servo[grabber_right] = GRABBER_RIGHT_CLOSE;
		//	break;
		//case GRABBER_POS_LEFT_CLOSE:
		//	servo[grabber_left] = GRABBER_LEFT_CLOSE;
		//	break;
		//case GRABBER_POS_LEFT_OPEN:
		//	servo[grabber_left] = GRABBER_LEFT_OPEN;
		//	break;
		//case GRABBER_POS_RIGHT_CLOSE:
		//	servo[grabber_right] = GRABBER_RIGHT_CLOSE;
		//	break;
		//case GRABBER_POS_RIGHT_OPEN:
		//	servo[grabber_right] = GRABBER_RIGHT_OPEN;
		//	break;
		//}
	}
}

#endif /* !ABS_JOYSTICK_DRIVE_H */
