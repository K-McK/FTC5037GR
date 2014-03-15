/**
*
*  @file abs_log_multivalue.h
*
*  @brief  Allows the robot to stay on the ramp even of someone pushes us
*
*  @param
*
*  @return
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/
#ifndef ABS_LOG_MULTIVALUE_H
#define ABS_LOG_MULTIVALUE_H

#define LOG_LIST_SIZE 10
#define NUM_MULTI_LOGS 3

typedef enum
{
	LIST1,
	LIST2,
	LIST3
} e_multivalue_list;

int log_list[NUM_MULTI_LOGS][LOG_LIST_SIZE];

#include "math_utils.h"
#include "global_variables.h"

void abs_log_multivalue(int list, int value)
{
	static int index_list[NUM_MULTI_LOGS] = {0,0,0};

	log_array[list][index_list[list]] = value;

	/** increment the index or reset */
	if(index_list[list] == LOG_LIST_SIZE - 1)
	{
		/** log the array */
		index_list[list] = 0;
		abs_dlog(__FILE__ ,"MULTIVALUE",
			"index 0", log_array[list][0],
			"index 1", log_array[list][1],
			"index 2", log_array[list][2],
			"index 3", log_array[list][3],
			"index 4", log_array[list][4],
			"index 5", log_array[list][5],
			"index 6", log_array[list][6],
			"index 7", log_array[list][7],
			"index 8", log_array[list][8],
			"index 9", log_array[list][9]);
);
	}
	else
	{
		index_list[list]++;
	}
}

#endif /* !STAY_ON_RAMP_H */
