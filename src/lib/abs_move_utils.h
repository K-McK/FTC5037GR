/**
 *
 *  @file abs_move_utils.h
 *
 *  @brief abunch of things that help move the robot
 *
 *  @param None n/a
 *
 *  @returns Returns nothing
 *
 *  @copyright Copyright 2013, Got Robot? FTC Team 5037
 *
 */
#ifndef ABS_MOVE_UTILS_H
#define ABS_MOVE_UTILS_H

/**
 *  @enum e_direction This enum is used to let the robot know to turn clockwise or counterclickwise
 *  @var e_direction::CLOCKWISE
 *     turn clockwise
 *  @var e_direction::COUNTERCLOCKWISE
 *     turn counterclockwise
 */
typedef enum
{
	CLOCKWISE,
	COUNTERCLOCKWISE
} e_direction;

/**
 *  @enum e_drive_direction Tells the robot what direction to drive
 *  @var e_drive_direction::FORWARD
 *     Drive forward
 *  @var e_drive_direction::BACKWARD
 *     Drive Backward
 */
typedef enum
{
	FORWARD,
	BACKWARD
} e_drive_direction;

/**
 *  @enum e_move_stopping_method Tells the robot what direction to drive
 *  @var e_move_stopping_method::E_TIME
 *     Drive for a set amount of time spesified in dist
 *  @var e_move_stopping_method::E_DEGREES
 *     Drive for a certain amount of degrees spesified in dist
 *  @var e_move_stopping_method::E_TILT
 *     Drive until the robot tilts a certen amount spesified in dist
 *  @var e_move_stopping_method::E_DISTANCE
 *     Drive a certain amount of centameters spesified in dist
 *  @var e_move_stopping_method::E_IR_DETECT
 *     Drive until the robot detects the IR becon using the first IR sensor spesified in dist
 *  @var e_move_stopping_method::E_IR_DETECT2
 *     Drive until the robot detects the IR becon using the second IR sensor spesified in dist
 *  @var e_move_stopping_method::E_ANGLE
 *     Drive for a certain amount of degrees spesified in dist
 *  @var e_move_stopping_method::E_OPTICAL
 *     Drive until the optical sensor detects the lighting condition specified in dist
 */
typedef enum
{
 	E_TILT,
 	E_TIME,
 	E_DISTANCE,
 	E_DEGREES,
 	E_IR_DETECT,
 	E_IR_DETECT2,
 	E_ANGLE,
  E_OPTICAL} e_move_stopping_method; //will make a method with a tilt sensor(wheel in the middle of the robot

/**
 *  @enum e_turn_method Tells the robot what type of turn it should do
 *  @var e_turn_method::SWING
 *     Perform a swing turn
 *  @var e_turn_method::POINT
 *     Perform a point turn
 */
typedef enum
{
	SWING,
	POINT
} e_turn_method;

/**
 *  @enum e_turn_stopping_method Tells the robot if to should to a certen amount of degreese or just turn
 *  @var e_turn_stopping_method::TURN
 *     Turn a swing turn
 *  @var e_turn_stopping_method::TURN_TO
 *     Turn a point turn
 */
typedef enum
{
	TURN,
	TURN_TO
} e_turn_stopping_method;

/**
 *  @enum e_motor_move Tells the robot what motor to move
 *  @var e_motor_move::ABDD
 *     Move the ABDD and put in a block
 *  @var e_motor_move::LIFT
 *     Move the block lifter
 *  @var e_motor_move::GRABBER
 *     close the block grabber
 *  @var e_motor_move::ROGER_SLIDE
 *     Slide the flag liffter back
 */
typedef enum
{
	ABDD,
	LIFT,
	GRABBER,
	ROGER_SLIDE
} e_motor_move;

/**
 *  @def distance_to_angle_derees(X)
 *  converts @a X to degrees
 */
#define distance_to_angle_derees(X) ((float)(X*360/ANGLE_SENSOR_CIRCUMFERENCE))

/**
 *  @def distance_to_encoder_derees(X)
 *  converts @a X to degrees
 */
#define distance_to_encoder_derees(X) (X*360/DRIVE_WHEELS_CIRCUMFERENCE)

#endif /* !ABS_TURN_UTILS */
