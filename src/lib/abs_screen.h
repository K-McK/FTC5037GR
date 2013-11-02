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
//========================================
// Screen State
//========================================

task screen ()
{
	while(true)
	{
		switch(screen_state)
		{
		case s_clear:
			nxtDisplayBigTextLine(1, "              ");
			nxtDisplayBigTextLine(3, "              ");
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_mission:
			nxtDisplayBigTextLine(1, "Missons");
			nxtDisplayBigTextLine(3, "%2d", mission_number);
			nxtDisplayBigTextLine(5, MissionNames1[mission_number]);
			break;
		case s_start_delay:
			nxtDisplayBigTextLine(1, "Delay");
			nxtDisplayBigTextLine(3, "%2d", start_delay);
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_cal_time:
			nxtDisplayBigTextLine(1, "CalTime");
			nxtDisplayBigTextLine(3, "%2d", gyroCalTime);
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_gyro_cal:
			nxtDisplayTextLine(1, "Calibrating");
			nxtDisplayBigTextLine(3, "%2d", (gyroCalTime*1000)-(nPgmTime-starttime));
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_ready:
			nxtDisplayBigTextLine(1, "Program");
			nxtDisplayBigTextLine(3, "Ready");
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_delay_wait:
			nxtDisplayBigTextLine(1, "Delay");
			nxtDisplayBigTextLine(3, "%2d", (start_delay*1000)-(nPgmTime-starttime));
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_gyro_show:
			nxtDisplayBigTextLine(1, "GyroValue");
			nxtDisplayBigTextLine(3, "%2d", constHeading);
			nxtDisplayBigTextLine(5, MissionNames1[0]);
			break;
		case s_error:
			nxtDisplayBigTextLine(1, "ERROR");
			nxtDisplayBigTextLine(3, error_list1[error]);
			nxtDisplayBigTextLine(5, error_list2[error]);
			break;
		case s_smoke_test:
			nxtDisplayBigTextLine(1, "%2d", smoke_test_num);
			nxtDisplayBigTextLine(3, smoke_test1[smoke_test_num]);
			nxtDisplayBigTextLine(5, smoke_test2[smoke_test_num]);
			break;
		case s_smoke_run:
			nxtDisplayBigTextLine(1, smoke_test1[0]);
			//nxtDisplayBigTextLine(3, error_list1[error]);
			//nxtDisplayBigTextLine(5, error_list2[error]);
			break;
		}
	}
}
