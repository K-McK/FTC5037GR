/**
 *
 *  @file abs_tele_op_initialize.h
 *
 *  @brief  dose some important stuff before we do the teleop program
 *
 *  @copyright Copyright 2013, Got Robot! FTC Team 5037
 */
#ifndef ABS_TELE_OP_INITIALIZE_H
#define ABS_TELE_OP_INITIALIZE_H

void abs_tele_op_initialize()
{
if(joystick.joy1_TopHat == -1) Joy1Enabled = true;
if(joystick.joy2_TopHat == -1) Joy2Enabled = true;

StartTask(screen);
screen_state = s_misc_show;
getJoystickSettings(joystick);
}
#endif /* !TEMPLATE_H */
