/**
*
*  @file abs_smoke_execute
*
*  @brief exucutes cammands sent in smoke test
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
		case 1:
			break;
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
			else test_value = 0;
			break;
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
				sensor_value = HTANGreadAccumulatedAngle(ANGLE_SENSOR);
				break;
			case st_accelerometer:
				sensor_value = accelermoeter_sensor;
				break;
			}
			break;
		case 4:
			if(nNxtButtonPressed == kLeftButton)
			{
				motor[lifter_motor] = LIFT_SPEED_DOWN;
				test_value = LIFT_SPEED_DOWN;
			}
			else if(nNxtButtonPressed == kRightButton)
			{
				motor[lifter_motor] = LIFT_SPEED_UP;
				test_value = LIFT_SPEED_UP;
			}
			else test_value = 0;
			break;
		case 5:
			if(nNxtButtonPressed == kLeftButton)
			{
				while(nNxtButtonPressed == kLeftButton) {}
				if(test_value > 0) test_value -= 5;
			}
			else if(nNxtButtonPressed == kRightButton)
			{
				while(nNxtButtonPressed == kRightButton) {}
				if(test_value < 255) test_value += 5;
			}
			servo[right_servo] = test_value;
			servo[left_servo] =  255-test_value;
			break;
		}
	}
	PlaySoundFile("! Click.rso");
}

#endif /* !ABS_SMOKE_EXECUTE_H */
