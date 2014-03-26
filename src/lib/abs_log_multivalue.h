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

#define LOG_LIST_SIZE 4
#define NUM_MULTI_LOGS 3

typedef enum
{
	LIST1,
	LIST2,
	LIST3
} e_multivalue_list;

typedef struct
{
} log_struct;

int log_list[NUM_MULTI_LOGS][LOG_LIST_SIZE];

#include "math_utils.h"
#include "global_variables.h"
#include "abs_dlog.h"

void abs_log_multivalue(int list, int value)
{
	static int index_list[NUM_MULTI_LOGS] = {0,0,0};
	static int arr1[LOG_LIST_SIZE];
	static int arr2[LOG_LIST_SIZE];
	static int arr3[LOG_LIST_SIZE];

	//int log_list[list][index_list[list]] = value;
	if(list == LIST1)
	{
		/** increment the index or reset */
		if(index_list[list] == LOG_LIST_SIZE - 1)
		{
			/** log the array */
			index_list[list] = 0;
			abs_dlog(__FILE__ ,"MULTIVALUE LIST1",
			"index 0", arr1[0],
			"index 1", arr1[1],
			"index 2", arr1[2],
			"index 3", arr1[3]);
		}
		else
		{
			arr1[index_list[list]] = value;
			index_list[list]++;
		}
	}

	if(list == LIST2)
	{
		/** increment the index or reset */
		if(index_list[list] == LOG_LIST_SIZE - 1)
		{
			/** log the array */
			index_list[list] = 0;
			abs_dlog(__FILE__ ,"MULTIVALUE LIST2",
			"index 0", arr2[0],
			"index 1", arr2[1],
			"index 2", arr2[2],
			"index 3", arr2[3]);
		}
		else
		{
			arr2[index_list[list]] = value;
			index_list[list]++;
		}
	}

}

#endif /* !STAY_ON_RAMP_H */
