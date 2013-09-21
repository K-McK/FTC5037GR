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
//============================================================
// User Interface State Machine definitions
//============================================================
#define S_GYRO 1
#define S_SONAR 2
#define S_MOTORS 3
#define S_IR1 4
#define S_GYRO2 5
#define S_LIFTER 6
#define S_MISSION 7
#define S_DELAY 8
#define S_CALTIME 9
#define S_LIGHT 10
#define S_SERVOS 11
#define S_ENCODERS 12
#define S_JOY1 13
#define S_JOY2 14
#define S_TELEOP 15
#define S_JOY_BUTTONS 16
#define S_BIG_NUMS 17
#define S_ARDD 18
#define S_SIDE 19
#define S_IR2 20

bool done = true;

//====================================================================
// These functions duplicate the ones in joystick.c but to avoid
// conflict in multiple tasks the UI uses this local copy
//====================================================================
short My_joy1Btn(int btn)
{   return ((joystick.joy1_Buttons & (1 << (btn - 1))) != 0);  }
short My_joy2Btn(int btn)
{   return ((joystick.joy2_Buttons & (1 << (btn - 1))) != 0);  }

//====================================================
// Display task
//====================================================
task display()
{
	while(true)
	{
		if (CurrentScreen!=RequestedScreen)		// a different screen has been requested
		{eraseDisplay();											// so clear the old data
			CurrentScreen=RequestedScreen;			// and setup the new screen
		}
		switch (CurrentScreen)								// go draw the desired screen data values
		{
		case S_MOTORS:
			nxtDisplayBigTextLine(0," MOTORS");
			nxtDisplayBigTextLine(2, "%4d%4d", motor[LF_motor], motor[RF_motor]);
			nxtDisplayBigTextLine(4, "%4d%4d", motor[LR_motor], motor[RR_motor]);
			nxtDisplayStringAt(0,8, " LIFT->");
			nxtDisplayBigStringAt(48,15, "%4d", motor[lifterMotor]);
			break;

		case S_ENCODERS:
			nxtDisplayBigTextLine(0,"ENCODERS");
			nxtDisplayBigTextLine(2, "%4d%4d", nMotorEncoder[LF_motor], nMotorEncoder[RF_motor]);
			nxtDisplayBigTextLine(4, "%4d%4d", nMotorEncoder[LR_motor], nMotorEncoder[RR_motor]);
			nxtDisplayStringAt(0,8, " LIFT->");
			nxtDisplayBigStringAt(48,15, "%4d", nMotorEncoder[lifterMotor]);
			break;

		case S_LIGHT:
			nxtDisplayBigStringAt(0,63,"LIGHT");
			nxtDisplayTextLine(2, "   LIGHT SENSOR");
			nxtDisplayBigTextLine(3, "   %3d", light_normalised);
			nxtDisplayTextLine(5, " LIGHT THRESHOLD");
			nxtDisplayBigTextLine(6, "   %3d", light_threshold);
			StatusDisplay(61,63,ir_mux_status);
			break;

		case S_TELEOP:
			nxtDisplayBigStringAt(0,63,"TELE-OP");
			nxtDisplayTextLine(2, " DRIVE SPEED");
			nxtDisplayBigTextLine(3, "   %3.0f", drive_speed);
			nxtDisplayTextLine(5, " DRIVE ANGLE");
			nxtDisplayBigTextLine(6, "   %3.0f", drive_angle);
			break;

		case S_GYRO:
			nxtDisplayBigStringAt(0,63,"GYRO");
			nxtDisplayBigTextLine(2, "    %3.2f", drift);
			nxtDisplayStringAt(0,40, "DRIFT");
			nxtDisplayBigTextLine(4, "    %3.2f", rawgyro);
			nxtDisplayStringAt(0,24, "RAW");
			nxtDisplayBigTextLine(6, "    %4d", gyro_noise);
			nxtDisplayStringAt(0,8, "NOISE");
			StatusDisplay(61,63,gyro_mux_status);
			break;

		case S_GYRO2:
			nxtDisplayBigStringAt(0,63,"GYRO2");
			nxtDisplayTextLine(2, " DRIFT   DDRIFT");
			nxtDisplayBigTextLine(3, "%3.0f %3.0f", drift,Driver_Cal);
			nxtDisplayTextLine(5, " RELHEAD CONHEAD");
			nxtDisplayBigTextLine(6, "%3.0f%4.0f", relHeading, constHeading);
			StatusDisplay(61,63,gyro_mux_status);
			break;

		case S_LIFTER:
			nxtDisplayBigTextLine(0," LIFTER");
			nxtDisplayTextLine(2, "SPEED");
			nxtDisplayBigStringAt(50,47, "%4d", lifter_speed);
			nxtDisplayTextLine(4, "STATE");
			nxtDisplayBigStringAt(50, 31,"%4d", lifter_state);
			nxtDisplayBigStringAt(26,15, "%6d", nMotorEncoder[lifterMotor]);
			nxtDisplayStringAt(0,16, "ENCODER");
			break;

		case S_SONAR:
			nxtDisplayBigStringAt(0,63,"SONAR");
			nxtDisplayTextLine(3, "  SIDE    REAR  ");
			nxtDisplayBigTextLine(4, "%3d %3d", sonarLive,sonarLive2);
			nxtDisplayBigTextLine(6, "%3d %3d", sonarRaw,sonarRaw2);
			StatusDisplay(61,63,ir_mux_status);
			break;

		case S_IR1:
			nxtDisplayBigStringAt(0,63,"IR");
			nxtDisplayBigTextLine(2, "%3d %3d", acS[0], acS[1]);
			nxtDisplayBigTextLine(4, "%3d %3d", acS[2], acS[3]);
			nxtDisplayBigTextLine(6, "%3d %3.0f", acS[4], IR_Bearing);
			StatusDisplay(61,63,ir_mux_status);
			break;

		case S_SERVOS:
			nxtDisplayBigStringAt(0,63," SERVOS");
			nxtDisplayTextLine(2, " LEFT    RIGHT");
			nxtDisplayBigTextLine(3, "%3d,%3d", servo[left_servo],servo[right_servo]);
			nxtDisplayTextLine(5, "  ARM  SHOULDER");
			nxtDisplayBigTextLine(6, "%3d,%3d", servo[wrist], servo[shoulder]);
			break;

		case S_JOY1:
			nxtDisplayBigStringAt(0,63,"JOY1");
			nxtDisplayBigTextLine(2, "%4d%4d", joystick.joy1_x1,joystick.joy1_x2);
			nxtDisplayBigTextLine(4, "%4d%4d", joystick.joy1_y1,joystick.joy1_y2);
			nxtDisplayBigTextLine(6, "%2d%6d", joystick.joy1_TopHat, joystick.joy1_Buttons);
			StatusDisplay(61,63,Joy1Enabled);
			break;

		case S_JOY2:
			nxtDisplayBigStringAt(0,63,"JOY2");
			nxtDisplayBigTextLine(2, "%4d%4d", joystick.joy2_x1,joystick.joy2_x2);
			nxtDisplayBigTextLine(4, "%4d%4d", joystick.joy2_y1,joystick.joy2_y2);
			nxtDisplayBigTextLine(6, "%2d%6d", joystick.joy2_TopHat, joystick.joy2_Buttons);
			StatusDisplay(61,63,Joy2Enabled);
			break;

		case S_JOY_BUTTONS:
			nxtDisplayBigStringAt(0,63,"BUTTONS");
			nxtDisplayStringAt(0,48, "12,12  %1d  %1d", My_joy1Btn(1),My_joy1Btn(2));
			nxtDisplayStringAt(0,40, "34,34  %1d  %1d", My_joy1Btn(3),My_joy1Btn(4));
			nxtDisplayStringAt(0,32, "56,56  %1d  %1d", My_joy1Btn(5),My_joy1Btn(6));
			nxtDisplayStringAt(0,24, "78,78  %1d  %1d", My_joy1Btn(7),My_joy1Btn(8));
			nxtDisplayStringAt(0,16, "9,10   %1d  %1d", My_joy1Btn(9),My_joy1Btn(10));
			nxtDisplayStringAt(0,8, "11,12  %1d  %1d", My_joy1Btn(11),My_joy1Btn(12));
			nxtDisplayStringAt(75,48, "%1d  %1d", My_joy2Btn(1),My_joy2Btn(2));
			nxtDisplayStringAt(75,40, "%1d  %1d", My_joy2Btn(3),My_joy2Btn(4));
			nxtDisplayStringAt(75,32, "%1d  %1d", My_joy2Btn(5),My_joy2Btn(6));
			nxtDisplayStringAt(75,24, "%1d  %1d", My_joy2Btn(7),My_joy2Btn(8));
			nxtDisplayStringAt(75,16, "%1d  %1d", My_joy2Btn(9),My_joy2Btn(10));
			nxtDisplayStringAt(75,8, "%1d  %1d", My_joy2Btn(11),My_joy2Btn(12));
			break;

		case S_BIG_NUMS:
			nxtDisplayBigTextLine(0,"HEADING");
			Big_Number(0,3,(long)constHeading,0,4);
			break;

		case S_MISSION:
			nxtDisplayBigStringAt(0,63,"MISS =");
			nxtDisplayBigStringAt(61,63, "%3d", MissionNumber);
			nxtDisplayBigTextLine(2, MissionNames1[MissionNumber]);
			nxtDisplayBigTextLine(4, MissionNames2[MissionNumber]);
			nxtDisplayBigTextLine(6, MissionNames3[MissionNumber]);
			break;

		case S_DELAY:
			nxtDisplayBigTextLine(0,"  DELAY");
			nxtDisplayBigTextLine(4, "   %3d", Start_Delay);
			break;

		case S_CALTIME:
			nxtDisplayBigTextLine(0,"CAL TIME");
			nxtDisplayBigTextLine(4, "  %3d", gyroCalTime);
			break;

		case S_ARDD:
			nxtDisplayBigTextLine(0,"ARDD");
			if(wristPosition) nxtDisplayBigTextLine(4, "OPEN");
			else nxtDisplayBigTextLine(4, "CLOSED");
			break;

		case S_SIDE:
			nxtDisplayBigTextLine(0,"SIDE");
			switch(fieldRed)
			{
			case STOP:
				nxtDisplayBigTextLine(4, "STOP");
				break;
			case RED:
				nxtDisplayBigTextLine(4, "redSide");
				break;
			case BLUE:
				nxtDisplayBigTextLine(4, "blueSide");
				break;
			}
			break;

			case S_IR2:
			nxtDisplayBigStringAt(0,63,"IR2");
			nxtDisplayBigTextLine(2, "%3d %3d", acS2[0], acS2[1]);
			nxtDisplayBigTextLine(4, "%3d %3d", acS2[2], acS2[3]);
			nxtDisplayBigTextLine(6, "%3d %3.0f", acS2[4], IR_Bearing2);
			StatusDisplay(61,63,ir_mux_status);
			break;

		default:
			nxtDisplayBigTextLine(0,"UNKNOWN");
		}
		wait1Msec(75);
	}
}


//====================================================
// NXT Button Handler Task
//====================================================
task buttons()
{
	while(true)
	{
		do
		{
			button = nNxtButtonPressed;				// read state of NXT buttons
		}
		while (button==kNoButton);					// loop until we get a button press
			switch(CurrentScreen)								// then handle that button pressed based on the active screen
		{
		case S_GYRO:
			if (button==kEnterButton) RequestedScreen = S_GYRO2;		// next screen
				break;

		case S_GYRO2:
			if (button==kEnterButton) RequestedScreen = S_LIFTER;		// next screen
				break;

		case S_LIFTER:
			if (button==kEnterButton) RequestedScreen = S_MOTORS;		// next screen
				break;

		case S_MOTORS:
			if (button==kEnterButton) RequestedScreen = S_ENCODERS;		// next screen
				break;

		case S_ENCODERS:
			if (button==kEnterButton) RequestedScreen = S_SONAR;		// next screen
				break;

		case S_SONAR:
			if (button==kEnterButton) RequestedScreen = S_IR1;				// next screen
				break;

		case S_IR1:
			if (button==kEnterButton) RequestedScreen = S_TELEOP;		// next screen
				break;

		case S_TELEOP:
			if (button==kEnterButton) RequestedScreen = S_SERVOS;		// next screen
				break;

		case S_SERVOS:
			if (button==kEnterButton) RequestedScreen = S_JOY1;		// next screen
				break;

		case S_JOY1:
			if (button==kEnterButton) RequestedScreen = S_JOY2;		// next screen
				break;

		case S_JOY2:
			if (button==kEnterButton) RequestedScreen = S_JOY_BUTTONS;		// next screen
				break;

		case S_JOY_BUTTONS:
			if (button==kEnterButton) RequestedScreen = S_LIGHT;		// next screen
				break;

		case S_LIGHT:
			if (button==kEnterButton) RequestedScreen = S_BIG_NUMS;	// next screen
				break;

		case S_BIG_NUMS:
			if (button==kEnterButton) RequestedScreen = S_MISSION;	// next screen
				break;

		case S_MISSION:
			if (button==kEnterButton) RequestedScreen = S_DELAY;		// next screen
				if (button==kLeftButton) {if (MissionNumber>1) MissionNumber-=1;}
			if (button==kRightButton) {if (MissionNumber<MAXMISSIONS) MissionNumber+=1;}
			break;

		case S_DELAY:
			if (button==kEnterButton) RequestedScreen = S_CALTIME;	// next screen
				if (button==kLeftButton) {Start_Delay-=1; if (Start_Delay<0) Start_Delay=0;}
			if (button==kRightButton) {Start_Delay+=1; if (Start_Delay>30) Start_Delay=30;}
			break;

		case S_CALTIME:
			if (button==kEnterButton)
			{
				if (gyroCalTime>0) calibrate = 1;						// if a time has been configured then initiate the calibration
					RequestedScreen = S_SIDE;										// next screen
			}
			if (button==kLeftButton) {gyroCalTime-=1; if (gyroCalTime<0) gyroCalTime=0;}
			if (button==kRightButton) {gyroCalTime+=1; if (gyroCalTime>30) gyroCalTime=30;}
			break;

		case S_ARDD:
			if (button==kEnterButton)
			{
				RequestedScreen = S_IR2;	// next screen/ here
				done = true;
			}

			servo[shoulder] = SHOULDER_DOWN;
			if (button==kLeftButton)
			{
				servo[wrist] = WRIST_CLOSED;
				wristPosition = false;
			}
			if (button==kRightButton)
			{
				wristPosition = true;
				servo[wrist] = WRIST_OPEN;
			}
			break;
			case S_IR2:
			if (button==kEnterButton)
			{
				RequestedScreen = S_GYRO;	// next screen/ here
				done = true;
			}
			break;
		case S_SIDE:
			if(button==kEnterButton) RequestedScreen = S_ARDD;
			if (button==kLeftButton)
			{
				fieldRed--;
				if(fieldRed<0) fieldRed = 0;
			}
			if (button==kRightButton)
			{
				fieldRed++;
				if(fieldRed>2) fieldRed = 2;
			}
			{
				wristPosition = true;
				servo[wrist] = WRIST_OPEN;
			}
			break;
		}
		while(nNxtButtonPressed!=kNoButton){};		// wait for the pressed key to be released
	}
}
