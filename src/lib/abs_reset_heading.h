/**
*
*  @file abs_turn.h
*
*  @brief The header file that alows you to do a point turn
*
*  @param degree Tells the robot how much to turn
*
*  @param dir Tells the robot what way to turn
*
*  @param speed Tells the robot how fast to turn
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_RESET_HEADING_H
#define ABS_RESET_HEADING_H

#include "abs_dlog.h"

/** macros */
typedef enum
{
	RELATIVE,
	CONSTANT,
	RELATIVE_CONSTANT
} e_heading_reset_type;

//=======================================
// turn
//=======================================
int abs_reset_heading(e_heading_reset_type type)
{

	switch(type)
	{
	case RELATIVE:
		g_rel_heading1 = 0;
		g_rel_heading2 = 0;
		g_rel_heading_use = 0;
		return 1;
		break;

	case CONSTANT:
		g_const_heading1 = 0;
		g_const_heading2 = 0;
		g_const_heading_use = 0;
		return 1;
		break;

	case RELATIVE_CONSTANT:
		g_rel_heading1 = 0;
		g_rel_heading2 = 0;
		g_rel_heading_use = 0;
		g_const_heading1 = 0;
		g_const_heading2 = 0;
		g_const_heading_use = 0;
		return 1;
		break;

	default:
		/** log a meaningful error here */
		return 0;
		break;
	}
}

#endif /* !ABS_TURN_H */
