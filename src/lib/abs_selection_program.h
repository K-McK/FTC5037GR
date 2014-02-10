/**
*
*  @file abs_selection_program.h
*
*  @brief A header file that handles the begining selection for robot actions
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_SELECTION_PROGRAM_H
#define ABS_SELECTION_PROGRAM_H

#include "abs_selection_custom.h"
#include "abs_selection_number.h"
#include "abs_selection_quick.h"

void selection_program()
{
	while(nNxtButtonPressed == kEnterButton){}

	//---------------------------------------
	// number selection, quick selection, or custom selection
	//---------------------------------------

	g_auto_selection_point = SELECTION_SELECTION_TYPE;
	g_screen_state = S_SELECTION_TYPE;

	int j = 1;
	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(j < 3) j++;
			else j = 3;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(j > 1) j--;
			else j = 1;
		}
		switch(j)
		{
		case 1:
			selection_type = SELECTION_TYPE_CUSTOM;
			break;
		case 2:
			selection_type = SELECTION_TYPE_NUMBER;
			break;
		case 3:
			selection_type = SELECTION_TYPE_QUICK;
			break;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// selection executes
	//---------------------------------------
	if(selection_type == SELECTION_TYPE_CUSTOM) abs_selection_custom();
	if(selection_type == SELECTION_TYPE_NUMBER)abs_selection_number();
	if(selection_type == SELECTION_TYPE_QUICK) abs_selection_quick();

	g_start_point=g_input_array[STARTING_POINT];
	g_start_delay=g_input_array[STARTING_DELAY];
	g_mission_number=g_input_array[SCOREING_POINT];
	g_end_delay=g_input_array[END_DELAY];
	//mainly a check to make sure it works fine
	if(g_input_array[END_POINT] < 4 && g_input_array[END_POINT] > 0)g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_STOP;
	if(g_input_array[END_POINT] == 4)
	{
		g_end_point=2;
		g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_CONTINUED;
	}
	if(g_input_array[END_POINT] == 5)
	{
		g_end_point=3;
		g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_CONTINUED;
	}

	//---------------------------------------
	// Start of gyro cal selection
	//---------------------------------------

	g_screen_state = S_CAL_TIME;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_gyro_cal_time < 30) g_gyro_cal_time++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_gyro_cal_time > 0) g_gyro_cal_time--;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();
	g_screen_state = S_GYRO_CAL;
}

#endif /* !ABS_SELECTION_PROGRAM_H */
