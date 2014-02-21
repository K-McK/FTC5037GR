/**
*
*  @file math_utils.h
*
*  @brief a collection of math operations
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

/** macros */

/**
* @def gyro_degrees(X)
*      converts gyro value @a X to degrees
*/
#define gyro_degrees(X)(X)

/**
* @def product(X, Y)
*      computes the product of @a X and @a Y
*/
#define product(X, Y) ((X) * (Y))

/**
* @def sum(X, Y)
*      computes the sum of @a X and @a Y
*/
#define sum(X, Y) ((X) + (Y))

/**
* @def min(X, Y)
*      computes the minimum of @a X and @a Y
*/
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

/**
* @def running_avg(X, Y, Z)
*      computes the new average based on current average @a X, new number of data points @a Y, and a new data point @a Z
*/
#define running_avg(X, Y, Z) (((X * (Y - 1)) + Z) / Y)

/**
* @def max(X, Y)
*      computes the maximum of @a X and @a Y
*/
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

//#define range(X, Y) ((X) > (Y) ? (X) : (Y))
#define safe_motor_speed(X) ((abs(X) > 10) ? (X) : 0)

#if DEBUG_MODE == 1

int middle_value_avg()
{
	int _min = g_gyro_values[0];
	int _max = g_gyro_values[0];
	int running_sum = 0;

	for(int i=0;i<GYRO_VALUE_QUEUE_SIZE;i++)
	{
		_min = min(g_gyro_values[i], _min);
		_max = max(g_gyro_values[i], _max);

		running_sum += g_gyro_values[i];
	}

	return ((running_sum - _min - _max) / (GYRO_VALUE_QUEUE_SIZE - 2));
}
#endif

#endif /* !MATH_UTILS_H */\
