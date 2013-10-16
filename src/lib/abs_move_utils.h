/**
 *
 *  @file abs_turn_utils.h
 *
 *  @brief a collection of math operations
 *
 *  @copyright Copyright 2013, Got Robot? FTC Team 5037
 *
 */
#ifndef ABS_TURN_UTILS_H
#define ABS_TURN_UTILS_H

/** macros */
typedef enum
{
	CLOCKWISE,
	COUNTERCLOCKWISE
} e_direction;

typedef struct
{
	float heading;
	int time;
} turn_context;

typedef enum
{
	FORWARD,
	BACKWARD
} e_drive_direction;

typedef enum
{
	E_TIME,
	ENCODER,
	GYRO
} e_stopping_method; //will make a method with a tilt sensor(wheel in the middle of the robot

typedef enum
{
	SWING,
	POINT
} e_turn_method;
#endif /* !ABS_TURN_UTILS */