/**
*
*  @file abs_selection_advanced.h
*
*  @brief handles the custom selection options for auto mission selection
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_SELECTION_ADVANCED_H
#define ABS_SELECTION_ADVANCED_H

void abs_selection_advanced()
{
	//---------------------------------------
	// Start of cornor time selection
	//---------------------------------------

	g_auto_selection_point = SELECTION_CORNOR_DELAY;
	g_screen_state = S_DELAY;
	g_input_array[CORNOR_DELAY] = 0;

	while(nNxtButtonPressed != kEnterButton)
	{
		g_delay = g_cornor_delay;
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[CORNOR_DELAY] < 30) g_input_array[CORNOR_DELAY]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[CORNOR_DELAY] > 0) g_input_array[CORNOR_DELAY]--;
		}
	}

	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}

	//---------------------------------------
	// Start of ramp delay selection
	//---------------------------------------

	g_auto_selection_point = SELECTION_RAMP_DELAY;
	g_screen_state = S_DELAY;
	g_input_array[RAMP_DELAY] = 0;

	while(nNxtButtonPressed != kEnterButton)
	{
		g_delay = g_ramp_delay;
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[RAMP_DELAY]< 30) g_input_array[RAMP_DELAY]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[RAMP_DELAY] > 0) g_input_array[RAMP_DELAY]--;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
}

#endif /* !ABS_SELECTION_ADVANCED_H */