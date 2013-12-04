#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     GYRO_MUX,       sensorI2CCustom)
#pragma config(Sensor, S3,     SENSOR_MUX,     sensorI2CCustom)
#pragma config(Sensor, S4,     angle_sensor,   sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     block_lift_motor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     sky_hook,      tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     jolly_roger,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     block_lift_motor2, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     right_motor,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     left_motor,    tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    grabber_right,        tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    grabber_left,         tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    roger_slide,          tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_4,    light_sensor,         tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    abdd,                 tServoStandard)
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
//#include "lib/abs_selection_call.h"
#include "lib/abs_screen.h"
#include "lib/abs_gyro_cal.h"
#include "lib/math_utils.h"
#include "lib/abs_sensors.h"
#include "abs_move_utils.h"
#include "lib/abs_turn.h"
#include "abs_gyro_drive.h"
#include "lib/abs_drive.h"
#include "lib/abs_initialize.h"
#include "lib/abs_motor.h"
#include "lib/abs_S1_mission_exicute.h"
#include "lib/abs_S2_mission_exicute.h"
#include "lib/abs_S3_mission_exicute.h"
#include "lib/abs_S4_mission_exicute.h"

//========================================
// Main program
//========================================

task main()
{
	initialize();
	g_rel_heading = 0;
	switch(g_start_point)
	{
	case 1:
		abs_S1_mission_exicute();
		break;
	case 2:
		abs_S2_mission_exicute();
		break;
	case 3:
		abs_S3_mission_exicute();
		break;
	case 4:
		abs_S4_mission_exicute();
		break;
	}
}
