/**
*
*  @file abs_drive.h
*
*  @brief it allows the robot to drive forword and backward
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

void abs_drive(e_drive_direction dir, e_move_stopping_method dist_method, int dist, int speed, bool stop_at_end, e_drive_type drive_type)
{
	//abs_log(__FILE__ ,"enter",speed,dist,HTANGreadAccumulatedAngle(angle_sensor),HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE);
	switch(dist_method)
	{
	case E_IR_DETECT:
		abs_log(__FILE__ ,"IR enter",speed,dist,g_bearing_ac2,HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE);
		break;
	case E_IR_DETECT2:
		abs_log(__FILE__ ,"IR2 enter",speed,dist,g_bearing_ac2,HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE);
		break;
	case E_ANGLE:
		abs_log(__FILE__ ,"angle enter",speed,dist,HTANGreadAccumulatedAngle(angle_sensor),HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE);
		break;
	case E_TIME:
		abs_log(__FILE__ ,"time enter",speed,dist,time1[T1],HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE);
		break;
	case E_LIGHT:
		abs_log(__FILE__ ,"light enter",speed,dist,g_light_sensor,HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE);
		break;
	}
	int i = 0;
	dl_step = dl_step+1;

	dl_robot_action_state = dl_gyro_move;
	nMotorEncoder(right_motor)= 0;
	g_rel_heading = 0;
	if(dir==BACKWARD)dl_speed = -speed;
	else dl_speed = speed;
	dl_dist = dist;

	if(stop_at_end == true)	dl_robot_action_detail = dl_move_stop;
	else dl_robot_action_detail = dl_move_no_stop;

	//dl_ce_detail = dl_ce_drive_start;
	//dl_change_event = true;

	//------------------------
	// time stopping method
	//------------------------
	if(dist_method == E_TIME)
	{
		dl_move_break = DL_TIME_BREAK;
		ClearTimer(T1);
		while(time1[T1] < dist)
		{
			if(drive_type == GYRO)
			{
				abs_gyro_drive(speed,dir);
				dl_cur_dist = time1[T1];
			}

			/** No gyro correction*/
			else
			{
				if(dir == FORWARD)
				{
					motor[left_motor] = speed;
					motor[right_motor] = speed;
				}
				else
				{
					motor[left_motor] = -speed;
					motor[right_motor] = -speed;
				}
			}
		}
		abs_log(__FILE__ ,"time break",speed,dist,time1[T1],HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE);
	}
	//------------------------
	// encoder stopping method
	//------------------------
	else if(dist_method == E_DEGREES)
	{
		while(i<5)
		{
			if(abs(nMotorEncoder(right_motor)) > distance_to_encoder_derees(dist)) i++;
			if(drive_type == GYRO)
			{
				abs_gyro_drive(speed,dir);
				dl_cur_dist = nMotorEncoder(right_motor);
			}

			/** No gyro correction*/
			else
			{
				if(dir == FORWARD)
				{
					motor[left_motor] = speed;
					motor[right_motor] = speed;
				}
				else
				{
					motor[left_motor] = -speed;
					motor[right_motor] = -speed;
				}
			}
		}
		abs_log(__FILE__ ,"degree break",speed,dist,nMotorEncoder(right_motor),HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE);
	}
	//------------------------
	// IR stopping method
	//------------------------
	else if(dist_method == E_IR_DETECT)
	{
		HTANGresetAccumulatedAngle(angle_sensor);
		abs_log(__FILE__ ,"reset angle",speed,dist,HTANGreadAccumulatedAngle(angle_sensor),(HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE));

		int total_dist = 0;
		int half_dist = 0;
		if(g_start_point == 1||g_start_point == 2)
		{total_dist = 150;
			half_dist = 100;}
		else //start point = 3
		{total_dist= 100;
			half_dist = 100;}
		dl_move_break = DL_IR_BREAK;
		if(dir == FORWARD)
		{
			while(true)
			{
				dl_cur_dist = g_bearing_ac2;
				if(abs(HTANGreadAccumulatedAngle(angle_sensor)) > total_dist*INT_ANGLE_SENSOR_CIRCUMFERENCE)
				{
					dl_move_break = DL_ANGLE_BREAK;

					abs_log(__FILE__ ,"angle break",speed,dist,HTANGreadAccumulatedAngle(angle_sensor),(HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE));
					break;
				}
				if(abs(HTANGreadAccumulatedAngle(angle_sensor)) < (half_dist*INT_ANGLE_SENSOR_CIRCUMFERENCE))
				{
					if(!((g_bearing_ac2 >= dist - 1) || (g_bearing_ac2 == 0)))
					{
						abs_log(__FILE__ ,"IR break",speed,dist,g_bearing_ac2,HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE);
						break;
					}
				}
				else
				{
					if(!((g_bearing_ac2 >= dist) || (g_bearing_ac2 == 0)))
					{
						abs_log(__FILE__,"IR break",speed,dist,g_bearing_ac2,HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE);
						break;
					}
				}
				if(drive_type == GYRO)
				{
					abs_gyro_drive(speed,dir);
				}

				/** No gyro correction*/
				else
				{
					motor[left_motor] = speed;
					motor[right_motor] = speed;
				}
			}
			//g_screen_state = S_TIME_SHOW;
			g_debug_time_1 = nPgmTime;
		}
		else if(dir == BACKWARD)
		{
			while(abs(HTANGreadAccumulatedAngle(angle_sensor)) < (total_dist*INT_ANGLE_SENSOR_CIRCUMFERENCE))
			{
				if(abs(HTANGreadAccumulatedAngle(angle_sensor)) < (half_dist*INT_ANGLE_SENSOR_CIRCUMFERENCE))
				{
					if(!((g_bearing_ac1 <= dist + 1) || (g_bearing_ac1 == 0)))
					{
						abs_log(__FILE__,"IR break",speed,dist,g_bearing_ac2,HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE);
						break;
					}
				}
				else
				{
					if(!((g_bearing_ac1 <= dist) || (g_bearing_ac1 == 0)))
					{
						abs_log(__FILE__,"IR break",speed,dist,g_bearing_ac2,HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE);
						break;
					}
				}

				/** No gyro correction*/
				if(drive_type == GYRO)
				{
					abs_gyro_drive(speed,dir);
				}
				else
				{
					motor[left_motor] = -speed;
					motor[right_motor] = -speed;
				}
			}
		}
	}
	//------------------------
	// IR stopping method 2
	//------------------------
	else if(dist_method == E_IR_DETECT2)
	{
		HTANGresetAccumulatedAngle(angle_sensor);
		abs_log(__FILE__ ,"reset angle",speed,dist,HTANGreadAccumulatedAngle(angle_sensor),(HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE));

		dl_move_break = DL_IR_BREAK;
		if(dir == FORWARD)
		{
			while(g_ir_bearing2 > dist)
			{
				if(drive_type == GYRO)
				{
					abs_gyro_drive(speed,dir);
				}
				/** No gyro correction*/
				else
				{
					motor[left_motor] = speed;
					motor[right_motor] = speed;
				}
			}
		}
		else
		{
			while(g_ir_bearing2 < dist)
			{
				if(drive_type == GYRO)
				{
					abs_gyro_drive(speed,dir);
				}
				/** No gyro correction*/
				else
				{
					motor[left_motor] = -speed;
					motor[right_motor] = -speed;
				}
			}
		}
	}
	//------------------------
	// accelermeoter sensor stopping method
	//------------------------
	else if(dist_method == E_TILT)
	{
		dl_cur_dist = g_accelermoeter_average;
		int j = 0;
		g_sensor_reference_drive = true;
		while(j<30)
		{
			if(drive_type == GYRO)
			{
				abs_gyro_drive(speed,dir);
			}

			/** No gyro correction*/
			else
			{
				if(dir == FORWARD)
				{
					motor[left_motor] = speed;
					motor[right_motor] = speed;
				}
				else
				{
					motor[left_motor] = -speed;
					motor[right_motor] = -speed;
				}
			}
			if(g_accelermoeter_average > dist) j++;
		}
		g_sensor_reference_drive = false;
	}
	//------------------------
	// angle sensor stopping method
	//------------------------
	else if(dist_method == E_ANGLE)
	{
		HTANGresetAccumulatedAngle(angle_sensor);
		abs_log(__FILE__ ,"reset angle",speed,dist,HTANGreadAccumulatedAngle(angle_sensor),(HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE));
		int temp_angle = HTANGreadAccumulatedAngle(angle_sensor);

		//dl_move_break = DL_ANGLE_BREAK;
		//dl_ce_detail = dl_ce_angle_reset;
		//dl_change_event = true;
		if(abs(HTANGreadAccumulatedAngle(angle_sensor))<40)
		{
			while(abs(HTANGreadAccumulatedAngle(angle_sensor)) < (dist*INT_ANGLE_SENSOR_CIRCUMFERENCE))
			{
				if(drive_type == GYRO)
				{
					dl_cur_dist = HTANGreadAccumulatedAngle(angle_sensor);
					abs_gyro_drive(speed,dir);
				}

				/** No gyro correction*/
				else
				{
					if(dir == FORWARD)
					{
						motor[left_motor] = speed;
						motor[right_motor] = speed;
					}
					else
					{
						motor[left_motor] = -speed;
						motor[right_motor] = -speed;
					}
				}
			}
		}
		else
		{
			abs_log(__FILE__ ,"reset angle fail",speed,dist,HTANGreadAccumulatedAngle(angle_sensor),(HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE));
			while((abs(HTANGreadAccumulatedAngle(angle_sensor))-abs(temp_angle)) < (dist*INT_ANGLE_SENSOR_CIRCUMFERENCE))
			{
				if(drive_type == GYRO)
				{
					dl_cur_dist = HTANGreadAccumulatedAngle(angle_sensor);
					abs_gyro_drive(speed,dir);
				}

				/** No gyro correction*/
				else
				{
					if(dir == FORWARD)
					{
						motor[left_motor] = speed;
						motor[right_motor] = speed;
					}
					else
					{
						motor[left_motor] = -speed;
						motor[right_motor] = -speed;
					}
				}
			}
		}

		abs_log(__FILE__ ,"angle break",speed,dist,HTANGreadAccumulatedAngle(angle_sensor),HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE);
	}
	else if(dist_method == E_LIGHT)
	{
		bool light_fail = false;
		HTANGresetAccumulatedAngle(angle_sensor);
		abs_log(__FILE__ ,"reset angle",speed,dist,HTANGreadAccumulatedAngle(angle_sensor),(HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE));

		while(true)
		{
			if(g_light_sensor>g_light_threshold&&abs(HTANGreadAccumulatedAngle(angle_sensor))<g_light_move_min_dist)
			{
				abs_log(__FILE__ ,"light fail",speed,dist,HTANGreadAccumulatedAngle(angle_sensor),(HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE));
				light_fail = true;
			}

			if(g_light_sensor>g_light_threshold&&light_fail==false)
			{
				dl_move_break = DL_LIGHT_BREAK;
				abs_log(__FILE__ ,"light break",speed,dist,g_light_sensor,(HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE));
				break;
			}
			else if(abs(HTANGreadAccumulatedAngle(angle_sensor)) > (dist*INT_ANGLE_SENSOR_CIRCUMFERENCE))
			{
				dl_move_break = DL_ANGLE_BREAK;

				abs_log(__FILE__ ,"angle break",speed,dist,g_light_sensor,(HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE));

				break;
			}
			dl_cur_dist = g_light_sensor;

			if(drive_type == GYRO)
			{
				dl_cur_dist = HTANGreadAccumulatedAngle(angle_sensor);
				abs_gyro_drive(speed,dir);
			}

			/** No gyro correction*/
			else
			{
				if(dir == FORWARD)
				{
					motor[left_motor] = speed;
					motor[right_motor] = speed;
				}
				else
				{
					motor[left_motor] = -speed;
					motor[right_motor] = -speed;
				}
			}
		}
	}
	else
	{
		motor[left_motor] = 0;
		motor[right_motor] = 0;
		while(true)
		{
			PlayTone(200,20);
			wait1Msec(500);
		}
	}

	//------------------------
	// Stop
	//------------------------
	if(stop_at_end)
	{
		motor[left_motor] = 0;
		motor[right_motor] = 0;
	}
	g_debug_time_2 = nPgmTime;

	dl_ce_detail = dl_ce_drive_end;
	dl_change_event = true;
	servo[light_sensor] = LIGHT_SERVO_UP;

	if(dist_method==E_LIGHT) LSsetInactive(LEGOLS);
	if(dist_record==true)
	{
		if(g_start_point==1)
		{
			if(g_end_point == 3) g_dist_backwards = (abs(HTANGreadAccumulatedAngle(angle_sensor))/18)-10;
			else if(g_end_point == 2) g_dist_backwards = 190-(abs(HTANGreadAccumulatedAngle(angle_sensor))/18);
		}
		else if(g_start_point==2)
		{
			if(g_end_point == 2) g_dist_backwards = (abs(HTANGreadAccumulatedAngle(angle_sensor))/18)-7;
			else if(g_end_point == 3) g_dist_backwards = 196-(abs(HTANGreadAccumulatedAngle(angle_sensor))/18);
		}
		else if(g_start_point==3)
		{
			if(g_end_point==2)	g_dist_backwards = 170-(abs(HTANGreadAccumulatedAngle(angle_sensor))/18);
			else if(g_end_point==3) g_dist_backwards = 75+(abs(HTANGreadAccumulatedAngle(angle_sensor))/18);
		}
		dist_record=false;
	}
	abs_log(__FILE__ ,"exit",speed,dist,HTANGreadAccumulatedAngle(angle_sensor),HTANGreadAccumulatedAngle(angle_sensor)/INT_ANGLE_SENSOR_CIRCUMFERENCE);
}

#endif /* !ABS_DRIVE_H */
