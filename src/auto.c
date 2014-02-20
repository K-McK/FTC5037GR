#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     GYRO_MUX,       sensorI2CCustom)
#pragma config(Sensor, S3,     SENSOR_MUX,     sensorI2CCustom)
#pragma config(Sensor, S4,     angle_sensor,   sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     jolly_roger,   tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     block_lift_motor2, tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     block_lift_motor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     sky_hook,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     right_motor,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     left_motor,    tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    grabber_right,        tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    grabber_left,         tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    roger_slide,          tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_4,    light_sensor,         tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    ground_arm,           tServoStandard)
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
#include "lib/xander/lego-light.h"
#include "lib/xander/hitechnic-irseeker-v2.h"
#include "lib/xander/hitechnic-gyro.h"
#include "lib/xander/hitechnic-angle.h"
#include "lib/xander/hitechnic-accelerometer.h"

#include "lib/global_variables.h"
#include "lib/abs_initialize.h"
#include "lib/abs_s1_mission_execute.h"
#include "lib/abs_s2_mission_execute.h"
#include "lib/abs_s3_mission_execute.h"
#include "lib/abs_s4_mission_execute.h"
#include "lib/abs_dlog.h"
#include "lib/abs_stay_on_ramp.h"

//========================================
// Main program
//========================================
task main()
{
	Delete(LogFileName, LogIoResult);
	OpenWrite(LogFileHandle, LogIoResult, LogFileName, LogFileSize);

	abs_dlog(__FILE__ ,"Program start"," Start time:", nPgmTime);

	abs_initialize();

	g_rel_heading = 0;
	switch(g_start_point)
	{
	case 1:
		abs_s1_mission_execute();
		break;
	case 2:
		abs_s2_mission_execute();
		break;
	case 3:
		abs_s3_mission_execute();
		break;
	case 4:
		abs_s4_mission_execute();
		break;
	}

	abs_dlog(__FILE__ ,"end auto", "End time:", nPgmTime);
	Close(LogFileHandle, LogIoResult);
	LogData=false;

	if(g_stay_on_ramp)
	abs_stay_on_ramp();
}
