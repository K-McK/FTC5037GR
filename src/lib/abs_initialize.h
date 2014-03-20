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

#include "abs_screen.h"
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

void abs_initialize()
{
#if USE_TASK_PRIORITY == 1
	StartTask(abs_screen, BACKGROUND_TASK);		//start the screen function, this handels all screen interactions
#else
	StartTask(abs_screen);		//start the screen function, this handels all screen interactions
#endif

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

#if USE_TASK_PRIORITY == 1
  if(g_gyro1_active)
  {
  	StartTask(abs_gyro1_cal, HIGH_PRIORITY_TASK);
  }
  else
  {
  	g_gyro1_cal_done = true;
  	g_gyro1_drift = 9999;
		g_gyro_noise = 9999;
  }

  if(g_gyro2_active)
  {
	  StartTask(abs_gyro2_cal, HIGH_PRIORITY_TASK);
	}
	else
	{
		g_gyro2_cal_done = true;
		g_gyro2_drift = 9999;
		g_gyro_noise2 = 9999;
	}

#else
  if(g_gyro1_active)
  {
  	StartTask(abs_gyro1_cal);
  }
  else
  {
  	g_gyro1_cal_done = true;
  	g_gyro1_drift = 9999;
		g_gyro_noise = 9999;
  }

  if(g_gyro2_active)
  {
  	StartTask(abs_gyro2_cal);
	}
	else
	{
		g_gyro2_cal_done = true;
		g_gyro2_drift = 9999;
		g_gyro_noise2 = 9999;
	}

#endif

	if(g_gyro_noise<g_gyro_noise2)
	{
		g_gyro_use=GYRO1;
		abs_dlog(__FILE__ ,"gyro use:", "GYRO1");
	}
	else
	{
		g_gyro_use=GYRO2;
		abs_dlog(__FILE__ ,"gyro use:", "GYRO2");
	}

	//g_drift = abs_gyro_cal(g_gyro_cal_time);

	//g_drift = abs_gyro_wrapper();		//calibrate the gyro, we're using our wrapper function to calibrate the gyro 5 times
	//to get the avg of drift and the delta of drift
	if(false)//!HTACreadAllAxes(HTAC, g_x_axis, g_y_axis, g_z_axis))
	{																								//=================================================
		g_error = ERR_ACCELERMOETER;									//-error detection: accelermoeter error,
		g_error_type = ERROR_NONLETHAL;								// EDIT: accelermoeter was removed to make room for the moved angle sensor
		//																						// *accelermoeter is not give the robot readings*
	}																								//-error: nonleathal, robot does not currently use accelermoeter
	if(g_gyro_noise>10)															//=================================================
	{																								//-error detection: gyro calibrate fail,
		g_error = ERR_GYRO_CAL1;											// gyro reads value that is too large for not starting yet
		g_error = ERROR_LETHAL;												//
	}																								//-error: leathal, auto needs accurate gyro to run successfully
	if(false)//g_gyro_noise2>10)										//=================================================
	{																								//-error detection: gyro calibrate fail,
		g_error = ERR_GYRO_CAL2;											// gyro reads value that is too large for not starting yet
		g_error = ERROR_LETHAL;												//
	}																								//-error: leathal, auto needs accurate gyro to run successfully
	if(HTSMUXreadPowerStatus(SENSOR_MUX))						//=================================================
	{																								//-error detection: general sensor mux power fail,
		g_error = ERR_SENSOR_MUX;											// robot reads the sensor mux is not powered
		g_error_type = ERROR_LETHAL;//NONLETHAL;			// EDIT: angle sensor moved, all muxes are needed now
	}																								//-error: *nonleathal, robot can still run missions not using IR*
	if(HTSMUXreadPowerStatus(GYRO_MUX))							//=================================================
	{																								//-error detection: 1st gyro sensor mux power fail,
		g_error = ERR_GYRO_MUX;												// robot reads the gyro mux is not powered
		g_error = ERROR_LETHAL;												//
	}																								//-error: leathal, robot needs the gyro to run successfully
	if(HTSMUXreadPowerStatus(GYRO_MUX2))						//=================================================
	{																								//-error detection: 2nd gyro sensor mux power fail,
		g_error = ERR_GYRO_MUX;												// robot reads the gyro mux is not powered
		g_error = ERROR_LETHAL;												//
	}																								//-error: leathal, robot needs the gyro to run successfully
	//																							//=================================================
	if(g_error != 0)		//if there is an error start beebing and stop program advancement
	{
		g_screen_state = S_ERROR;
		while(true)
		{
			g_gyro_true = true;
			PlayTone (250,25);
			wait1Msec(500);
			if(nNxtButtonPressed == kEnterButton && g_error_type == ERROR_NONLETHAL)break;	//if the error is nonleathal and
		}
	}//driver tries to over-ride skip error
	LogData=true;
	g_screen_state = S_READY;		//set the screen to show the program feedback before the auto starts

	#if USE_TASK_PRIORITY == 1
	StartTask(abs_sensors, BACKGROUND_TASK);		//start the screen function, this handels all screen interactions
#else
	StartTask(abs_sensors);		//start the screen function, this handels all screen interactions
#endif
	abs_reset_angle_sensor_val(HARD_RESET);	//reset the angle sensor

	PlayTone(700, 100);					//play 'happy sound' to tell drivers the robot is ready to run

#if USE_WAIT_FOR_START == 1		//compiler option to change the robots auto start triger from the field to button for tests
	waitForStart();
#else
	while(nNxtButtonPressed == kEnterButton){}
	if(nNxtButtonPressed != kEnterButton) wait1Msec(5000);
#endif

	abs_dlog(__FILE__ , "auto start", "program time", nPgmTime);		//log the start of the mission run

	#if USE_TASK_PRIORITY == 1
	StartTask(abs_datalog, BACKGROUND_TASK);		//start the screen function, this handels all screen interactions
#else
	StartTask(abs_datalog);		//start the screen function, this handels all screen interactions
#endif

	eraseDisplay();
	g_start_time = nPgmTime;		//set the start time
	g_screen_state = S_DELAY_WAIT;
	wait1Msec(g_start_delay*1000);	//wait for start delay, number option tab 2
	eraseDisplay();
	g_screen_state = S_GYRO_SHOW;		//tell screen to show the gyro value
}

#endif /* !ABS_INITIALIZE_H */
