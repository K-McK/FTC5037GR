/**
*
*  @file abs_drive.h
*
*  @brief it allows the robot to drive forword and backwords
*
*  @param dir Tells the robot what direction to go
*
*  @param dist_method tells the robot how it should know when to stop
*
*  @param dist tells the robot how far to go
*
*  @param speed tells the robot how fast to go
*
*  @param stop_at_end tells the robot if it should stop when it gets to were it needs to go or not
*
*  @return returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_DRIVE_H
#define ABS_DRIVE_H

/** macros */
//=========================
//Drive
//=========================
void abs_drive(e_drive_direction dir, e_move_stopping_method dist_method, int dist, int speed, bool stop_at_end)
{
	HTANGresetAccumulatedAngle(angle_sensor);
	int i = 0;

	nMotorEncoder(right_motor)= 0;
	g_rel_heading = 0;

	//------------------------
	// time stopping method
	//------------------------
	if(dist_method == E_TIME)
	{
		ClearTimer(T1);
		while(time1[T1] < dist)
		{
			abs_gyro_drive(speed,dir);
		}
	}
	//------------------------
	// encoder stopping method
	//------------------------
	else if(dist_method == E_DEGREES)
	{
		while(i<5)
		{
			if(abs(nMotorEncoder(right_motor)) > distance_to_encoder_derees(dist)) i++;
			abs_gyro_drive(speed,dir);
		}
	}
	//------------------------
	// IR stopping method
	//------------------------
	else if(dist_method == E_IR_DETECT)
	{
		if(dir == FORWARD)
		{
			while(abs(HTANGreadAccumulatedAngle(angle_sensor)) < (150*INT_ANGLE_SENSOR_CIRCUMFERENCE))
			{
				if(abs(HTANGreadAccumulatedAngle(angle_sensor)) < (100*INT_ANGLE_SENSOR_CIRCUMFERENCE))
				{
					if(!((g_bearing_ac2 >= dist - 1) || (g_bearing_ac2 == 0))) break;
				}
				else
				{
					if(!((g_bearing_ac2 >= dist) || (g_bearing_ac2 == 0))) break;
				}
				abs_gyro_drive(speed,dir);
			}
			//g_screen_state = S_TIME_SHOW;
			g_debug_time_1 = nPgmTime;
		}
		else if(dir == BACKWARD)
		{
			while(abs(HTANGreadAccumulatedAngle(angle_sensor)) < (150*INT_ANGLE_SENSOR_CIRCUMFERENCE))
			{
				if(abs(HTANGreadAccumulatedAngle(angle_sensor)) < (100*INT_ANGLE_SENSOR_CIRCUMFERENCE))
				{
					if(!((g_bearing_ac1 <= dist + 1) || (g_bearing_ac1 == 0))) break;
				}
				else
				{
					if(!((g_bearing_ac1 <= dist) || (g_bearing_ac1 == 0))) break;
				}
				abs_gyro_drive(speed,dir);
			}
			//g_screen_state = S_TIME_SHOW;
			g_debug_time_1 = nPgmTime;
		}
	}
	//------------------------
	// IR stopping method 2
	//------------------------
	else if(dist_method == E_IR_DETECT2)
	{
		if(dir == FORWARD)
		{
			while(g_ir_bearing2 > dist)
			{
				abs_gyro_drive(speed,dir);
			}
		}
		else
		{
			while(g_ir_bearing2 < dist)
			{
				abs_gyro_drive(speed,dir);
			}
		}
	}
	//------------------------
	// accelermeoter sensor stopping method
	//------------------------
	else if(dist_method == E_TILT)
	{
		int j = 0;
		g_sensor_reference_drive = true;
		while(j<30)
		{
			abs_gyro_drive(speed,dir);
			if(g_accelermoeter_average > dist) j++;
		}
		g_sensor_reference_drive = false;
	}
	//------------------------
	// angle sensor stopping method
	//------------------------
	else
	{
		HTANGresetAccumulatedAngle(angle_sensor);
		while(abs(HTANGreadAccumulatedAngle(angle_sensor)) < (dist*INT_ANGLE_SENSOR_CIRCUMFERENCE))
		{
			abs_gyro_drive(speed,dir);
		}
	}
	if(stop_at_end)
	{
		motor[left_motor] = 0;
		motor[right_motor] = 0;
	}
	g_debug_time_2 = nPgmTime;
}

#endif /* !ABS_DRIVE_H */
