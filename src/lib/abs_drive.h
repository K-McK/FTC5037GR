/**
*
*  @file template.h (this should be the name of the function)
*
*  @brief  Enter a description of what this function does
*
*  @param
*
*  @return
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
	HTANGresetAccumulatedAngle(ANGLE_SENSOR);
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
		while(IR_Bearing != IR_heading)
		{
			abs_gyro_drive(speed,dir);
		}
	}
	//------------------------
	// angle sensor stopping method
	//------------------------
	else
	{
		while(abs(HTANGreadAccumulatedAngle(ANGLE_SENSOR)) < distance_to_angle_derees(dist))
		{
			abs_gyro_drive(speed,dir);
		}
	}
	if(stop_at_end)
	{
		motor[left_motor] = 0;
		motor[right_motor] = 0;
	}
}

#endif /* !ABS_DRIVE_H */
