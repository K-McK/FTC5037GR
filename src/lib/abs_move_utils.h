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

#define FORWARD_HEADING 0
#define REVERSE_HEADING 180

typedef enum
{
	CLOCKWISE,
	COUNTERCLOCKWISE
} e_direction;

typedef enum
{
	FORWARD,
	BACKWARD
} e_drive_direction;

typedef enum
{
	E_TIME,
	E_DEGREES,
	E_TILT,
	E_DISTANCE,
	E_IR_DETECT,
	E_ANGLE
} e_move_stopping_method; //will make a method with a tilt sensor(wheel in the middle of the robot

typedef enum
{
	SWING,
	POINT
} e_turn_method;

typedef enum
{
	TURN,
	TURN_TO
} e_turn_stopping_method;

#define distance_to_angle_derees(X) (X*360/ANGLE_SENSOR_CIRCUMFERENCE)
#define distance_to_encoder_derees(X) (X*360/DRIVE_WHEELS_CIRCUMFERENCE)
#endif /* !ABS_TURN_UTILS */
