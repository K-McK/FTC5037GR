/**
*
*  @file abs_datalog.h
*
*  @brief
*
*  @param N/A
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_BTN_CHECK_H
#define ABS_BTN_CHECK_H

/** macros */

//=======================================
// main
//=======================================
void abs_btn_check()
{
	int i = 0;
	int joy1_dpad_old = -1;
	dl_step = 0;
	while(true)
	{
		//-----------------------------------------
		// test for buttons pressed
		//-----------------------------------------

		if(joy1Btn(i) && dl_joy1_btn_array[i] == false) 									//test for joystick1 btns
		{
			dl_teleop_btn_press = true;
			dl_joy1_btn_array[i] = true;
		}
		if(joy2Btn(i) && dl_joy2_btn_array[i] == false) 									//test for joystick2 btns
		{
			dl_teleop_btn_press = true;
			dl_joy2_btn_array[i] = true;
		}

		if(joystick.joy1_TopHat != joy1_dpad_old) 												//test for joystick1 d-pad
		{
			dl_teleop_btn_press = true;
			dl_joy1_dpad = joystick.joy1_TopHat;
			joy1_dpad_old = joystick.joy1_TopHat;
		}
		if(joystick.joy2_TopHat != joy2_dpad_old) 												//test for joystick2 d-pad
		{
			dl_teleop_btn_press = true;
			dl_joy1_dpad = joystick.joy2_TopHat;
			joy2_dpad_old = joystick.joy2_TopHat;
		}

		//-----------------------------------------
		// test for buttons unpressed
		//-----------------------------------------

		if(!joy1Btn(i) && dl_joy1_btn_array[i] == true)  									//test for joystick1 btns unpressed
		{
			dl_teleop_btn_press = true;
			dl_joy1_btn_array[i] = false;
		}
		if(!joy2Btn(i) && dl_joy2_btn_array[i] == true)  									//test for joystick2 btns unpressed
		{
			dl_teleop_btn_press = true;
			dl_joy2_btn_array[i] = false;
		}

		i++
		if(i>12)i=0;
	}
}

#endif /* !ABS_BTN_CHECK_H */
