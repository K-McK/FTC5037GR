#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     GYRO_MUX,       sensorI2CCustom)
#pragma config(Sensor, S3,     SENSOR_MUX,     sensorI2CCustom)
#pragma config(Sensor, S4,     angle_sensor,   sensorI2CCustom)
#pragma config(Motor,  motorA,          test_motor,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     block_lift_motor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     sky_hook,      tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     jolly_roger,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     block_lift_motor2, tmotorTetrix, openLoop)
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
 *  @file tele_op.c
 *
 *  @brief The tele_op program for the robot
 *
 *  @param None n/a
 *
 *  @return Returns nothing
 *
 *  @copyright Copyright 2013, Got Robot? FTC Team 5037
 *
 */

//-----------------------
// sensor/mux/joystick includes
//-----------------------

#include "JoystickDriver.c"
#include "lib/xander/hitechnic-sensormux.h"
#include "drivers/hitechnic-accelerometer.h"
#include "lib/xander/hitechnic-irseeker-v2.h"
#include "lib/xander/hitechnic-gyro.h"
#include "lib/xander/hitechnic-angle.h"

//-----------------------
// custom functions includes
//-----------------------

#include "lib/global_varaibles.h"
#include "lib/abs_screen.h"
#include "lib/abs_teleop_utils.h"
#include "lib/abs_joystick_drive.h"
#include "lib/abs_joystick_gunner.h"
#include "lib/abs_auto_datalog_write.h"
#include "lib/abs_teleop_datalog_write.h"
#include "lib/abs_datalog.h"
#include "lib/abs_tele_op_initialize.h"
//========================================
// Main program
//========================================

task main ()
{
	abs_tele_op_initialize();
	StartTask(abs_joystick_gunner);
	while(g_program_done==false)
	{
		abs_joystick_drive(LINEAR);
	}
}
