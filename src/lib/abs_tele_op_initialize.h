/**
 *
 *  @file abs_tele_op_initialize.h
 *
 *  @brief  does some important stuff before we do the teleop program
 *
 *  @param None n/a
 *
 *  @return Returns nothing
 *
 *  @copyright Copyright 2013, Got Robot? FTC Team 5037
 */
#ifndef ABS_TELE_OP_INITIALIZE_H
#define ABS_TELE_OP_INITIALIZE_H

#include "abs_screen.h"

void abs_tele_op_initialize()
{
	if(joystick.joy1_TopHat == -1) g_joy1_enabled = true;
	if(joystick.joy2_TopHat == -1) g_joy2_enabled = true;

	servo[abdd] = g_abdd_down;

	StartTask(abs_screen);
	g_screen_state = S_MISC_SHOW;
	getJoystickSettings(joystick);
	memset(dl_joy1_btns,0,12);
}
#endif /* ABS_TELE_OP_INITIALIZE_H */
