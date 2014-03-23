/**
*
*  @file abs_initialize.h
*
*  @brief A header file that handles the initialization when we start the game
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_INITIALIZE_H
#define ABS_INITIALIZE_H

#include "abs_gyro_wrapper.h"
#include "abs_sensors.h"
#include "abs_datalog.h"
#include "abs_dlog.h"
#include "abs_reset_angle_sensor.h"
#include "abs_calibrate_light.h"
#include "abs_selection_program.h"
#include "abs_control_light_sensor.h"
#include "abs_gyro1_cal.h"
#include "abs_gyro2_cal.h"
#include "abs_start_task.h"
#include "abs_disable_gyro.h"

#define MAX_ALLOWED_GYRO_NOISE 10

void abs_initialize()
{
	disableDiagnosticsDisplay();		//turn off the robotc firmware diagnostic text to clear screen
	servoChangeRate[abdd] = 3;										//============================================================
	servo[roger_slide] = 127;											// set all of the robots outputs to their starting positions
	servo[abdd] = g_abdd_down;										//
	servo[grabber_left] = GRABBER_LEFT_CLOSE;			//-abdd is held down									-right grabber closes
	servo[grabber_right] = GRABBER_RIGHT_CLOSE;		//-left grabber closes								-light sensor servo held up
	servo[light_sensor] = LIGHT_SERVO_UP;					//-light sensor light is turned off
	abs_control_light_sensor(INACTIVE);						//============================================================
	memset(g_input_array,0,INPUT_ARRAY_SIZE);		//set input array to 0, this ensures the robot doesn't get invalid inputs
	abs_selection_program();		//start the selection program to receive the robot's mission from the drivers
	PlaySoundFile("! Click.rso");

	if(g_gyro1_active)
	{
#if CALIBRATE_GYROS_IN_SERIES == 1
		abs_gyro1_cal();
#else
		abs_start_task(abs_gyro1_cal, HIGH_PRIORITY_TASK);
#endif
	}
	else
	{
		abs_disable_gyro(GYRO1);
	}

	if(g_gyro2_active)
	{
#if CALIBRATE_GYROS_IN_SERIES == 1
		abs_gyro2_cal();
#else
		abs_start_task(abs_gyro2_cal, HIGH_PRIORITY_TASK);
#endif
	}
	else
	{
		abs_disable_gyro(GYRO2);
	}

	abs_cscreen("Gyros   ","Calbrtng","  lol   ");
	while(g_gyro1_cal_done == false || g_gyro2_cal_done == false){}

	if(g_gyro_noise1<g_gyro_noise2)
	{
		g_gyro_use=GYRO1;
		abs_dlog(__FILE__ ,"gyro use:", "GYRO1");
	}
	else
	{
		g_gyro_use=GYRO2;
		abs_dlog(__FILE__ ,"gyro use:", "GYRO2");
	}

	if(false)//!HTACreadAllAxes(HTAC, g_x_axis, g_y_axis, g_z_axis))
	{																								//=================================================
		g_error = ERR_ACCELERMOETER;									//-error detection: accelermoeter error,
		g_error_type = ERROR_NONLETHAL;								// EDIT: accelermoeter was removed to make room for the moved angle sensor
		//																						// *accelermoeter is not give the robot readings*
	}																								//-error: nonleathal, robot does not currently use accelermoeter
	if(g_gyro_noise1>MAX_ALLOWED_GYRO_NOISE && g_gyro1_active)	//=================================================
	{																								//-error detection: gyro calibrate fail,
		g_error = ERR_GYRO_CAL1;											// gyro reads value that is too large for not starting yet
		g_error = ERROR_LETHAL;												//
	}																								//-error: leathal, auto needs accurate gyro to run successfully
	if(g_gyro_noise2>MAX_ALLOWED_GYRO_NOISE && g_gyro2_active)	//=================================================
	{																								//-error detection: gyro calibrate fail,
		g_error = ERR_GYRO_CAL2;											// gyro reads value that is too large for not starting yet
		g_error = ERROR_LETHAL;												//
	}																								//-error: leathal, auto needs accurate gyro to run successfully
	if(HTSMUXreadPowerStatus(SENSOR_MUX))						//=================================================
	{																								//-error detection: general sensor mux power fail,
		g_error = ERR_SENSOR_MUX;											// robot reads the sensor mux is not powered
		g_error_type = ERROR_LETHAL;//NONLETHAL;			// EDIT: angle sensor moved, all muxes are needed now
	}																								//-error: *nonleathal, robot can still run missions not using IR*
	if(false)//(HTSMUXreadPowerStatus(GYRO_MUX))							//=================================================
	{																								//-error detection: 1st gyro sensor mux power fail,
		g_error = ERR_GYRO_MUX1;											// robot reads the gyro mux is not powered
		g_error = ERROR_LETHAL;												//
	}																								//-error: leathal, robot needs the gyro to run successfully
	if(false)//HTSMUXreadPowerStatus(GYRO_MUX2))						//=================================================
	{																								//-error detection: 2nd gyro sensor mux power fail,
		g_error = ERR_GYRO_MUX2;											// robot reads the gyro mux is not powered
		g_error = ERROR_LETHAL;												//
	}																								//-error: leathal, robot needs the gyro to run successfully
	//																							//=================================================
	if(g_error != 0)		//if there is an error start beebing and stop program advancement
	{
		switch(g_error)
		{
		case ERR_ACCELERMOETER: abs_cscreen("ERROR N ","Accel   ","        "); break;
		case ERR_GYRO_CAL1: abs_cscreen("ERROR L ","Gryo1   ","cal fail"); break;
		case ERR_GYRO_CAL2: abs_cscreen("ERROR L ","Gryo2   ","cal fail"); break;
		case ERR_SENSOR_MUX: abs_cscreen("ERROR L ","SensrMux","pwr fail"); break;
		case ERR_GYRO_MUX1: abs_cscreen("ERROR L ","Gyro1Mux","pwr fail"); break;
		case ERR_GYRO_MUX2: abs_cscreen("ERROR L ","Gyro1Mux","pwr fail"); break;
		}
		while(true)
		{
			g_gyro_true = true;
			PlayTone (250,25);
			wait1Msec(500);
			if(nNxtButtonPressed == kEnterButton && g_error_type == ERROR_NONLETHAL)break;	//if the error is nonleathal and
		}
	}//driver tries to over-ride skip error
	LogData=true;
	abs_cscreen("Program ","Ready   ","        "); //set the screen to show the program feedback before the auto starts
	if(g_auto_grabber_selection_ramp_options == SUB_SELECTION_RAMP_CONTINUED)
		nxtDisplayBigTextLine(5, "%1d%1d%1d%1d%1d%1d%1d%1d Y ",g_input_array[1],g_input_array[2],g_input_array[3],g_input_array[4],g_input_array[5]);
	else
		nxtDisplayBigTextLine(5, "%1d%1d%1d%1d%1d%1d%1d%1d N ",g_input_array[1],g_input_array[2],g_input_array[3],g_input_array[4],g_input_array[5]);


	abs_start_task(abs_sensors, BACKGROUND_TASK);		//start the screen function, this handels all screen interactions

	abs_reset_angle_sensor_val(HARD_RESET);	//reset the angle sensor

	PlayTone(700, 100);					//play 'happy sound' to tell drivers the robot is ready to run

#if USE_WAIT_FOR_START == 1		//compiler option to change the robots auto start triger from the field to button for tests
	waitForStart();
#else
	while(nNxtButtonPressed == kEnterButton){}
	if(nNxtButtonPressed != kEnterButton) wait1Msec(5000);
#endif

	abs_dlog(__FILE__ , "auto start", "program time", nPgmTime);		//log the start of the mission run

//	abs_start_task(abs_datalog, BACKGROUND_TASK);		//start the screen function, this handels all screen interactions

	eraseDisplay();
	g_start_time = nPgmTime;		//set the start time
	time1[T1]=0;
	while(time1[T1]<g_start_delay*1000)	//wait for start delay, number option tab 2
	{abs_cscreen("Delay   ","","&1d       ",(g_start_delay*1000)-g_start_time);}
	//wait1Msec(g_start_delay*1000);
	eraseDisplay();
}

#endif /* !ABS_INITIALIZE_H */
