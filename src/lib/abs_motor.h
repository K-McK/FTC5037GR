/**
*
*  @file abs_motor.h
*
*  @brief  Allows the robot to move attachments in auto.c
*
*  @param move_type lets the robot know what attchment to move
*
*  @param power tells the robot how much power it should use on the attachment
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/
#ifndef ABS_MOTOR_H
#define ABS_MOTOR_H



void abs_motor(e_motor_move move_type)
{
	//-----------------------------
	// flag motor control
	//-----------------------------

	//switch(joystick.joy2_TopHat)
	//{
	//case -1:
	//	motor[jolly_roger]= 0;
	//	break;
	//case 0:
	//	motor[jolly_roger] = FLAG_SPEED_UP;
	//	break;
	//case 2:
	//	motor[jolly_roger] = FLAG_SPEED_RIGHT;
	//	break;
	//case 6:
	//	motor[jolly_roger] = FLAG_SPEED_LEFT;
	//	break;
	//case 4:
	//	motor[jolly_roger] = FLAG_SPEED_DOWN;
	//	break;
	//}

	//-----------------------------
	// roger slide
	//-----------------------------
	if(move_type == ROGGER_SLIDE) servo[roger_slide] = 0;

	//-----------------------------
	// block lift
	//-----------------------------
	//if(move_type == LIFT)
	//{
	//	motor[block_lift_motor] = BLOCK_SPEED_UP;
	//	wait10Msec(50);
	//	motor[block_lift_motor] = BLOCK_SPEED_DOWN;
	//}

	//-----------------------------
	// block grabber
	//-----------------------------
	//int grabber_position;

	//if(move_type == GRABBER) grabber_position = GRABBER_CLOSE;

	//switch(grabber_position)
	//{
	//case GRABBER_CLOSE:
	//	servo[grabber_left] = GRABBER_LEFT_CLOSE;
	//	servo[grabber_right] = GRABBER_RIGHT_CLOSE;
	//	break;
	//}

	//-----------------------------
	// ABDD
	//-----------------------------
	if(move_type == ABDD)
	{
		servo[abdd] = ABDD_UP;
		wait10Msec(70);
		servo[abdd] = ABDD_DOWN;
	}
}

#endif /* !ABS_MOTOR_H */
