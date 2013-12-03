/**
 *
 *  @file abs_teleop_utils.h
 *
 *  @brief utils for teleop
 *
 *  @param None n/a
 *
 *  @returns returns nothing
 *
 *  @copyright Copyright 2013, Got Robot? FTC Team 5037
 *
 */
#ifndef ABS_TELEOP_UTILS_H
#define ABS_TELEOP_UTILS_H
/**
*  @enum e_joystick_method tells the robot if it should drive linear or parabolic
*  @var e_joystick_method::LINEAR
*     Drive linear
*  @var e_joystick_method::PARABOLIC
*     Drive parabolic
*/
typedef enum
{
	LINEAR,
	PARABOLIC
} e_joystick_method;

#endif /* !ABS_TELEOP_UTILS */
