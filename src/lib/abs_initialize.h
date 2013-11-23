/**
*
*  @file abs_initialize.h
*
*  @brief A hedder file that handles the initialization when we start the game
*
*  @param initialize initializes the robot
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_INITIALIZE_H
#define ABS_INITIALIZE_H

//========================================
// starting function
//========================================

void initialize()
{
	StartTask(screen);
	disableDiagnosticsDisplay();
	selection_program();
	drift = abs_gyro_cal(gyroCalTime);

	if (!HTACreadAllAxes(HTAC, _x_axis, _y_axis, _z_axis)) error = e_accelermoeter;
	if (gyro_noise>10) error = e_gyro_cal;
	if(HTSMUXreadPowerStatus(SENSOR_MUX)) error = e_sensor_mux;
	if(HTSMUXreadPowerStatus(GYRO_MUX)) error = e_gyro_mux;

	if(error != 0)
	{
		screen_state = s_error;
		while(true)
		{
			gyroTrue = true;
			PlayTone (250,25);
			wait1Msec(500);
		}
	}

	screen_state = s_ready;
	StartTask(abs_sensors_read);

	waitForStart();
	eraseDisplay();
	starttime = nPgmTime;
	screen_state = s_delay_wait;
	wait1Msec(start_delay*1000);
	eraseDisplay();
	screen_state = s_ac_show;
}

#endif /* !ABS_INITIALIZE_H */
