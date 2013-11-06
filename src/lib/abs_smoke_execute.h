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
	switch(smoke_test_num)
	{
	case 1:
		while(nNxtButtonPressed != kEnterButton)
		{
			PlayTone(20,20);
			wait1Msec(200);
		}
		PlaySoundFile("! Click.rso");
		break;
	}
}

#endif /* !ABS_SMOKE_EXECUTE_H */
