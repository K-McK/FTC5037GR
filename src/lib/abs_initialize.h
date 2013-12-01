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

//========================================
// starting function
//========================================

void initialize()
{
	StartTask(screen);
	disableDiagnosticsDisplay();
	servoChangeRate[abdd] = 3;
	servo[roger_slide] = 127;
	servo[abdd] = ABDD_DOWN;
	servo[grabber_left] = GRABBER_LEFT_CLOSE;
	servo[grabber_right] = GRABBER_RIGHT_CLOSE;
	selection_program();
	drift = abs_gyro_cal(gyroCalTime);

	if (!HTACreadAllAxes(HTAC, _x_axis, _y_axis, _z_axis)) error = err_accelermoeter;
	if (gyro_noise>10) error = err_gyro_cal;
	if(HTSMUXreadPowerStatus(SENSOR_MUX)) error = err_sensor_mux;
	if(HTSMUXreadPowerStatus(GYRO_MUX)) error = err_gyro_mux;

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
	HTANGresetAccumulatedAngle(angle_sensor);

	waitForStart();
	eraseDisplay();
	starttime = nPgmTime;
	screen_state = s_delay_wait;
	wait1Msec(start_delay*1000);
	eraseDisplay();
	screen_state = s_gyro_show;
}

#endif /* !ABS_INITIALIZE_H */
