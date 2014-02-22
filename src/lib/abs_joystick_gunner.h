/**
*
*  @file abs_joystick_gunner.h
*
*  @brief The header file that handles the joystick motor control
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_JOYSTICK_GUNNER_H
#define ABS_JOYSTICK_GUNNER_H

task abs_joystick_gunner()
{
	while(true)
	{
		//-----------------------------
		// flag motor control
		//-----------------------------
		g_misc = joystick.joy2_TopHat;
		switch(joystick.joy2_TopHat)
		{
		case -1:
			motor[jolly_roger]= 0;
			break;
		case 0:
			motor[jolly_roger] = g_flag_speed_down;
			break;
		case 2:
			motor[jolly_roger] = g_flag_speed_right;
			break;
		case 6:
			motor[jolly_roger] = g_flag_speed_left;
			break;
		case 4:
			motor[jolly_roger] = g_flag_speed_up;
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
		if((joy1Btn(9))&&(joy2Btn(9))&&(joy1Btn(10))&&(joy2Btn(10))) g_program_done = true;

		//-----------------------------
		// block lift
		//-----------------------------
		if(joystick.joy2_y1>10)
		{
			motor[block_lift_motor] = g_block_speed_up;
			motor[block_lift_motor2] = g_block_speed_up;
		}
		else if(joystick.joy2_y1<-10)
		{
			if(joy2Btn(11))
			{
				motor[block_lift_motor] = -100;
				motor[block_lift_motor2] = -100;
			}
			else
			{
				motor[block_lift_motor] = g_block_speed_down;
				motor[block_lift_motor2] = g_block_speed_down;
			}
		}

		else
		{
			motor[block_lift_motor] = 0;
			motor[block_lift_motor2] = 0;
		}

		//-----------------------------
		// block grabber
		//-----------------------------

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
	}
}

#endif /* !ABS_JOYSTICK_DRIVE_H */
