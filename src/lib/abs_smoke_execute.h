/**
*
*  @file abs_smoke_execute
*
*  @brief exucutes cammands sent in smoke test
*
*  @param no paramiters
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_SMOKE_EXECUTE
#define ABS_SMOKE_EXECUTE

void abs_smoke_execute ()
{
	screen_state = s_smoke_run1;
	while(nNxtButtonPressed != kEnterButton)
	{
		switch(smoke_test_num)
		{
			//---------------------------------
			// Jolly Roger
			//---------------------------------
		case 1:
			if(nNxtButtonPressed == kLeftButton)
			{
				motor[jolly_roger] = FLAG_SPEED_DOWN;
				test_value = FLAG_SPEED_DOWN;
			}
			else if(nNxtButtonPressed == kRightButton)
			{
				motor[jolly_roger] = FLAG_SPEED_UP;
				test_value = FLAG_SPEED_UP;
			}
			else
			{
				test_value = 0;
				motor[jolly_roger] = 0;
			}
			break;
			//---------------------------------
			// Drive
			//---------------------------------
		case 2:
			if(nNxtButtonPressed == kLeftButton)
			{
				motor[right_motor] = 60;
				motor[left_motor] = 60;
				test_value = 60;
			}
			else if(nNxtButtonPressed == kRightButton)
			{
				motor[right_motor] = -60;
				motor[left_motor] = -60;
				test_value = -60;
			}
			else
			{
				test_value = 0;
				motor[right_motor] = 0;
				motor[left_motor] = 0;
			}
			break;
			//---------------------------------
			// sensors
			//---------------------------------
		case 3:
			screen_state = S_smoke_run2;
			if(nNxtButtonPressed == kLeftButton)
			{
				if(test_value > 1) test_value--;
				while(nNxtButtonPressed == kLeftButton) {}
			}
			if(nNxtButtonPressed == kRightButton)
			{
				if(test_value < sensor_max) test_value++;
				while(nNxtButtonPressed == kRightButton) {}
			}
			sensor_num = test_value;
			switch(sensor_num)
			{
			case st_gyro:
				sensor_value = relHeading;
				break;
			case st_IR:
				sensor_value = IR_Bearing;
				break;
			case st_tilt:
				sensor_value = HTANGreadAccumulatedAngle(angle_sensor);
				break;
			case st_accelerometer:
				sensor_value = accelermoeter_sensor;
				break;
			}
			break;
			//---------------------------------
			// Block lift
			//---------------------------------
		case 4:
			if(nNxtButtonPressed == kLeftButton)
			{
				motor[block_lift_motor] = ROBOT_LIFT_DOWN;
				test_value = ROBOT_LIFT_DOWN;
			}
			else if(nNxtButtonPressed == kRightButton)
			{
				motor[block_lift_motor] = ROBOT_LIFT_UP;
				test_value = ROBOT_LIFT_UP;
			}
			else
			{
				motor[block_lift_motor] = 0;
				test_value = 0;
			}
			break;
			//---------------------------------
			// grabbers
			//---------------------------------
		case 5:
			if(nNxtButtonPressed == kLeftButton)
			{
				if(test_value>1) test_value--;
				while(nNxtButtonPressed == kLeftButton){}
			}
			if(nNxtButtonPressed == kRightButton)
			{
				if(test_value<3) test_value++;
				while(nNxtButtonPressed == kRightButton){}
			}
			switch(test_value)
			{
			case 1:
			servo[grabber_left] = GRABBER_LEFT_OPEN;
			servo[grabber_right] = GRABBER_RIGHT_OPEN;
				break;
			case 2:
			servo[grabber_left] = GRABBER_LEFT_MID;
			servo[grabber_right] = GRABBER_RIGHT_MID;
				break;
			case 3:
			servo[grabber_left] = GRABBER_LEFT_CLOSE;
			servo[grabber_right] = GRABBER_RIGHT_CLOSE;
				break;
			}
		break;
		//---------------------------------
		// sky hook
		//---------------------------------
	case 6:
		if(nNxtButtonPressed == kLeftButton)
		{
			motor[sky_hook] = ROBOT_LIFT_UP;
			test_value = ROBOT_LIFT_UP;
		}
		else if(nNxtButtonPressed == kRightButton)
		{
			motor[sky_hook] = ROBOT_LIFT_DOWN;
			test_value = ROBOT_LIFT_DOWN;
		}
		else
		{
			motor[sky_hook] = 0;
			test_value = 0;
		}
		break;
		//---------------------------------
		// roger slide
		//---------------------------------
	case 7:
		if(nNxtButtonPressed == kLeftButton)
		{
			servo[roger_slide] = 255;
			test_value = 255;
		}
		else if(nNxtButtonPressed == kRightButton)
		{
			servo[roger_slide] = 0;
			test_value = 0;
		}
		else
		{
			servo[roger_slide] = 127;
			test_value = 127;
		}
		break;
	}
}
PlaySoundFile("! Click.rso");
}

#endif /* !ABS_SMOKE_EXECUTE_H */
