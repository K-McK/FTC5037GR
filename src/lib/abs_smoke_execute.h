//=====================================================================================
//
//  ***    ***   *****      ****    ***   ****    ***   *****     ***
// *   *  *   *    *        *   *  *   *  *   *  *   *    *      *   *
// *      *   *    *        *   *  *   *  *   *  *   *    *          *
// *  **  *   *    *        ****   *   *  ****   *   *    *         *
// *   *  *   *    *        * *    *   *  *   *  *   *    *        *
// *   *  *   *    *        *  *   *   *  *   *  *   *    *
//  ***    ***     *        *   *   ***   ****    ***     *        *
//
//=====================================================================================
//
// FTC TEAM 5037
// Elgin Technlogy Center, Illinois
// Ring It Up (2012-2013)
// User Inferface Tasks
//
// These tasks (Display, Buttons) run in both Autonomous and Tele-Op modes.  They give the
// drive team access to multiple configuration and diagnostic screen displays.
//

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
				sensor_value = HTANGreadAccumulatedAngle(HTANG);
				break;
			case st_accelerometer:
				sensor_value = accelermoeter_sensor;
				break;
			}
			break;
		case 4:
			if(nNxtButtonPressed == kLeftButton)
			{
				motor[sky_hook] = ROBOT_LIFT_DOWN;
				test_value = ROBOT_LIFT_DOWN;
			}
			else if(nNxtButtonPressed == kRightButton)
			{
				motor[sky_hook] = ROBOT_LIFT_UP;
				test_value = ROBOT_LIFT_UP;
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
			servo[grabber_right] = test_value;
			servo[grabber_left] =  255-test_value;
			break;
		}
	}
	PlaySoundFile("! Click.rso");
}

#endif /* !ABS_SMOKE_EXECUTE_H */
