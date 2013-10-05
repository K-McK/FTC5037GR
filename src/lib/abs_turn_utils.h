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
	int heading;
	int time;
} turn_context;

#endif /* !ABS_TURN_UTILS */
