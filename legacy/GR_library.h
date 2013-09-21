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
// Library functions
//
//=================================================
// Miscellaneous general purpose max and min macros
//=================================================
#define max(a, b)               (((a) > (b))? (a): (b))
#define min(a, b)               (((a) < (b))? (a): (b))

//================================================================================================
// calculate individual motor speeds based on the motor angle versus the requested drive angle
//================================================================================================
void SetDrive (float drive_angle, float drive_speed, int robot_orientation=constHeading) //bool RobotRelative=true)
{
	float LF_speed, RF_speed, LR_speed, RR_speed, gyro_angle;
	gyro_angle=constHeading;																						// assume we'll be using field relative mode
	//if(RobotRelative==true) gyro_angle = 0;															// otherwise configure robot relative drive
	LF_speed = cosDegrees(LF_angle-drive_angle+gyro_angle)*drive_speed; // individual motor speeds are calculated
	RF_speed = cosDegrees(RF_angle-drive_angle+gyro_angle)*drive_speed; // relative to the mounted angle of that
	LR_speed = cosDegrees(LR_angle-drive_angle+gyro_angle)*drive_speed; // motor, but adjusted for the current
	RR_speed = cosDegrees(RR_angle-drive_angle+gyro_angle)*drive_speed; // orientation of the robot per the GYRO

	//====================================================================
	// Now handle request for rotation, either standalone or while driving
	//====================================================================
	int rotation_factor=0;																	// assume no rotation is requested
	int speed_limit=drive_speed;												// this is used to determine maximum allowable speed if there is also rotation


// taken from tele-op
	int rotation_error = constHeading-robot_orientation;
	int rotator = 0;
	if (rotation_error < -3) rotator = -10;
	if (rotation_error > 3) rotator = 10;
	rotation_factor=rotator;								// calculate desired versus actual to get a rotation factor
	if (drive_speed+abs(rotation_factor)>100)						// then rotation will take us beyond 100% power
		{
			speed_limit-=abs(rotation_factor);								// so we adjust the speed limit down to allow for rotation (if any)
		}

// previous code before April 2
	//rotation_factor=(constHeading-robot_orientation)*ROTATION_GAIN;
	//speed_limit-=abs(rotation_factor);								// adjuist spped limit down to allow for rotation (if any)

	//=================================================================================
	// now prorate the power levels so the highest equals the requested power level
	//=================================================================================
	float highest = max(max(abs(LF_speed),abs(RF_speed)),max(abs(LR_speed),abs(RR_speed)));
	float adjust_factor=1;
	if (highest!=0) adjust_factor=speed_limit/highest;

	LF_speed*=adjust_factor;
	RF_speed*=adjust_factor;
	LR_speed*=adjust_factor;
	RR_speed*=adjust_factor;

	LF_speed+=rotation_factor;		// add in the rotation factor to each drive motor
	RF_speed+=rotation_factor;
	LR_speed+=rotation_factor;
	RR_speed+=rotation_factor;
	//=======================================================================
	// finally operate the actual drive motors at the calculated power levels
	//=======================================================================
	motor[LF_motor]=(int)LF_speed;
	motor[RF_motor]=(int)RF_speed;
	motor[LR_motor]=(int)LR_speed;
	motor[RR_motor]=(int)RR_speed;
}


void moveLightServo (bool upOrDown)
{
	if(upOrDown) //if up
	{
		servo[lightServo] = 140;
	}
	else 				//if down
	{
		servo[lightServo] = 30;
	}
}

//============================================================================
// Helper function - stop the robot by shutting down power to all drive wheels
//============================================================================
void StopRobot()
{
	motor[LF_motor]=0;     // shutdown all drive motors
	motor[RF_motor]=0;
	motor[LR_motor]=0;
	motor[RR_motor]=0;
}

//============================================================================
// Helper function - reset the encoders on all four drive wheels
//============================================================================
void ResetDriveEncoders()
{
	nMotorEncoder[LF_motor] = 0;
	wait1Msec(5);
	nMotorEncoder[RF_motor] = 0;
	wait1Msec(5);
	nMotorEncoder[LR_motor] = 0;
	wait1Msec(5);
	nMotorEncoder[RR_motor] = 0;
	wait1Msec(5);
}

//=======================================================================================
// Helper function - display OK or BAD in specified screen position given a BOOLEAN value
//=======================================================================================
void StatusDisplay(int x, int y, bool StatusValue)
{
	string ScreenText = " OK";							// assume we'll be displaying OK (leading space)
	if (StatusValue) ScreenText = "BAD";		// otherwise we set the string to BAD
		nxtDisplayBigStringAt(x,y, ScreenText);	// and go display it in the requested position
}

//======================================================================================
// display numbers right justified with optional decimal point
//======================================================================================
#define RHS 81
void Big_Number (int x, int y, long value, int dp, int fieldwidth)
{
	int dig, myx, digits=0;
	myx=x+fieldwidth*20;
	bool neg=false;
	char fname[] = "My_0.ric";													// configure filename for RIC file output
	long limit = pow(10,fieldwidth+1)-1;								// max display capability
	if (value<0 | dp!=0) limit/=10;											// one digit less if negative or decimal places
		if (value>limit) value = limit;											// enforce limit
		if (value<0 && abs(value) >limit) value = -limit;		// and also low end if negative
		if (value<0) {value= -value;                        // if negative then work with absolute value
		neg=true;                           							// and say that we need to put up a negative sign
	}
	do
	{
		if ((dp!=0) & (digits==dp)) {nxtDisplayRICFile(myx+13,y, "My_DecDot.ric");   // time to put out the decimal point
			myx-=7;               														// and adjust display position accordingly
		}
		dig=value%10;                                      // figure out what the next digit is to be
		value=value/10;                                    // then adjust the number down by a factor of 10
		if (dig==0)
		{ if ((digits<=dp) | (value!=0)) nxtDisplayRICFile(myx,y, "My_0.ric");		// display a zero only if digit is not a leading zero
			else {if (neg) {nxtDisplayRICFile(myx+10,y, "My_-.ric");          			// display a negative sign if the number is all displayed already
					neg=false;                      																		// only display the sign once
				}
				else nxtEraseRect(myx,y,19+myx,40+y);    // if number is all displayed then use leading spaces to get rid of any old digits
			}
		}
		else
		{fname[3]='0'+dig;									// setup filename for the current digit
			nxtDisplayRICFile(myx,y, fname);	// display the current digit;
		}
		digits+=1;													// another digit done
		myx-=20;														// adjust cursor position for next digit
	} while (digits<=fieldwidth);					// continue until all requested digits are displayed
}
