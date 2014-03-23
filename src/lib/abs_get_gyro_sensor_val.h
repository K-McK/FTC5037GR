/**
*
*  @file abs_get_gyro_sensor_val.h
*
*  @brief  Enter a description of what this function does
*
*  @param
*
*  @return
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/
#ifndef ABS_GET_GYRO_SENSOR_VAL_H
#define ABS_GET_GYRO_SENSOR_VAL_H

#include "math_utils.h"

int abs_get_gyro_sensor_val(e_gyro_val_type gyro_val,e_gyro_names which_gyro)
{
	static int last_gyro_read_time1 = 0;
	static int last_gyro_read_val1 = 0;

	static int last_gyro_read_time2 = 0;
	static int last_gyro_read_val2 = 0;

	int current_time = nPgmTime;
	int last_val;
	int delta_time;
	if(g_gyro_ran == true)
	{
		if(which_gyro==GYRO1)
		{
		  last_val = last_gyro_read_val1;
	  	delta_time = last_gyro_read_time1 - current_time;
	  	last_gyro_read_time1 = current_time;
	  }
	  else
	 	{
		  last_val = last_gyro_read_val2;
	  	delta_time = last_gyro_read_time2 - current_time;
	  	last_gyro_read_time2 = current_time;
	  }
	}

	//TODO:  we should not be storing both the RAW and non-RAW values into the same static variable otherwise the delta results will be wrong
	if(gyro_val == RAW)
	{
		if(which_gyro==GYRO1) last_gyro_read_val1 = HTGYROreadRot(HTGYRO);
		else last_gyro_read_val2 = HTGYROreadRot(HTGYRO2);
	}
	else
	{
		if(which_gyro==GYRO1) last_gyro_read_val1 = HTGYROreadRot(HTGYRO) - g_original_gyro_val1;
		else last_gyro_read_val2 = HTGYROreadRot(HTGYRO2) - g_original_gyro_val2;
	}

#if DEBUG_MODE == 1

	static bool queue_empty = true;
	static int current_index = 0;
	if(current_index == GYRO_VALUE_QUEUE_SIZE) { current_index = 0; }

	/**
	* if the queue is empty, initialize all values to the first reading
	* otherwise, insert the value to the next point in the queue
	*/
	if(queue_empty)
	{
		queue_empty = false;
		for(int i=0; i<GYRO_VALUE_QUEUE_SIZE; i++)
		{
			g_gyro_values[i] = last_gyro_read_val;
		}
	}
	else
	{
		g_gyro_values[current_index] = last_gyro_read_val;
	}

	current_index++;

	if(current_index%GYRO_VALUE_QUEUE_SIZE==0)
	{
		for(int i=0;i<GYRO_VALUE_QUEUE_SIZE;i++)
		{
			abs_dlog(__FILE__, "Gyro Queue ", "Entry %d = ", i, "%d", g_gyro_values[i]);
		}
		abs_dlog(__FILE__, "Gyro Queue ", "middle_value_avg %d = ", middle_value_avg());
	}
#endif

	if(g_gyro_ran == true)
	{
		int delta_val;

		if(which_gyro==GYRO1)
		{
		  delta_val = abs(last_gyro_read_val1 - last_val);
		}
		else
		{
		  delta_val = abs(last_gyro_read_val2 - last_val);
		}

		if(delta_val / delta_time > MAX_TURN_RATE)
		{
			g_good_gyro = false;
		}
	}

	if(g_gyro_ran == false) g_gyro_ran = true;

	if(which_gyro==GYRO1)
	  return last_gyro_read_val1;
	else
		return last_gyro_read_val2;
}

#endif /* !ABS_GET_GYRO_SENSOR_VAL_H */
