#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     GYRO_MUX,       sensorI2CCustom)
#pragma config(Sensor, S3,     SENSOR_MUX,     sensorI2CCustom)
#pragma config(Sensor, S4,     ANGLE_SENSOR,   sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     right_motor,   tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     left_motor,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     flag_motor,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     lifter_motor,  tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
*
*  @file auto.c
*
*  @brief The automatic program for the robot.
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

/*Includes*/

//-----------------------
// sensor/mux/joystick includes
//-----------------------

#include "joystickdriver.c"
#include "lib/xander/hitechnic-sensormux.h"
#include "lib/xander/hitechnic-irseeker-v2.h"
#include "lib/xander/hitechnic-gyro.h"
#include "lib/xander/hitechnic-angle.h"
#include "lib/xander/hitechnic-accelerometer.h"

//-----------------------
// custom functions includes
//-----------------------

#include "lib/global_varaibles.h"
#include "lib/abs_selection_program.h"
#include "lib/abs_screen.h"
#include "lib/abs_gyro_cal.h"
#include "lib/math_utils.h"
#include "lib/abs_sensors.h"
#include "abs_move_utils.h"
#include "lib/abs_turn.h"
#include "abs_gyro_drive.h"
#include "lib/abs_drive.h"
#include "lib/abs_initialize.h"

//========================================
// Main program
//========================================

task main()
{
	initialize();
	switch(mission_number)
	{
	case 0:
		abs_turn(CLOCKWISE, POINT, TURN, 180, 60);
		wait10Msec(300);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 90, 60);
		wait10Msec(300);
		abs_turn(CLOCKWISE, POINT, TURN, 45, 60);
		wait10Msec(300);
		abs_turn(COUNTERCLOCKWISE, POINT, TURN, 0, 60);
		break;
	case 1:

		break;

	case 2:

		break;

	case 3:

		break;

	case 4:

		break;
	}
}
