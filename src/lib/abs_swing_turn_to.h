/**
*
*  Filename:  abs_swing_turn_to.h (this should be the name of the function)
*
*  Description:  Enter a description of what this function does
*
*  Copyright 2013, Got Robot! FTC Team 5037
*
*/
#ifndef ABS_SWING_TURN TO_H
#define ABS_SWING_TURN TO_H

typedef enum
{
	CLOCKWISE,
	COUNTERCLOCKWISE
} e_direction;

//macros

void abs_swing_turn_to(int dergrees,e_direction dir,int speed)
{
	float rotspeed(
