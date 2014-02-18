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

#endif /* !MATH_UTILS_H */\
