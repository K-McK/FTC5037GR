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
	screen_state = s_smoke_run;
	while(nNxtButtonPressed != kEnterButton)
	{
		switch(smoke_test_num)
		{
		case 1:
			PlayTone(20,20);
			wait1Msec(200);
			PlaySoundFile("! Click.rso");
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
		}
	}
}

#endif /* !ABS_SMOKE_EXECUTE_H */
