/**
*
*  @file abs_drive.h
*
*  @brief it allows the robot to drive forword and backwords
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/
#ifndef ABS_DRIVE_H
#define ABS_DRIVE_H

/** macros */
//=========================
//Drive
//=========================
void abs_drive(e_drive_direction dir, e_move_stopping_method dist_method, int dist, int speed, bool stop_at_end)
{
	//HTANGresetAccumulatedAngle(ANGLE_SENSOR);
	int i = 0;

	nMotorEncoder(right_motor)= 0;
	relHeading = 0;

	//------------------------
	// Determines direction
	//------------------------
	if(dir == FORWARD)
	{
		drive_heading = FORWARD_HEADING;
		motor(right_motor)=speed;
		motor(left_motor)=speed;
	}
	else
	{
		drive_heading = REVERSE_HEADING;
		motor(right_motor)=-speed;
		motor(left_motor)=-speed;
	}

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
	else if(dist_method == E_IR_DETECT)
	{
		while(IR_Bearing > dist)
		{
			abs_gyro_drive(speed,dir);
		}
	}
	//------------------------
	// accelermeoter sensor stopping method
	//------------------------
	else if(dist_method == E_ANGLE)
	{
		int j = 0;
		sensor_reference_drive = true;
		while(j<30)
		{
			abs_gyro_drive(speed,dir);
			if(accelermoeter_average > dist) j++;
		}
		sensor_reference_drive = false;
	}
	//------------------------
	// angle sensor stopping method
	//------------------------
	else
	{
		//while(abs(HTANGreadAccumulatedAngle(ANGLE_SENSOR)) < distance_to_angle_derees(dist))
		//{
		//	abs_gyro_drive(speed,dir);
		//}
	}
	if(stop_at_end)
	{
		motor[left_motor] = 0;
		motor[right_motor] = 0;
	}
}

#endif /* !ABS_DRIVE_H */
