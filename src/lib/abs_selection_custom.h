/**
*
*  @file abs_selection_custom.h
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
#ifndef ABS_SELECTION_CUSTOM_H
#define ABS_SELECTION_CUSTOM_H

void abs_selection_custom()
{
	//---------------------------------------
	// Start point selection 1
	//---------------------------------------

	g_auto_selection_point = SELECTION_START_POINT;
	g_screen_state = S_STARTING_POINT;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[1] < g_auto_starting_points) g_input_array[1]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[1] > 0) g_input_array[1]--;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// Start of start time selection 2
	//---------------------------------------

	g_auto_selection_point = SELECTION_START_DELAY;
	g_screen_state = S_DELAY;

	while(nNxtButtonPressed != kEnterButton)
	{
		g_delay = g_start_delay;
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[2] < 30) g_input_array[2]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[2] > 0) g_input_array[3]--;
		}
	}

	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}

	//---------------------------------------
	// Start of mission selection 3
	//---------------------------------------

	g_auto_selection_point = SELECTION_MISSION_POINT;
	g_screen_state = S_MISSION;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[3] < g_auto_missions) g_input_array[4]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[3] > 0) g_mission_number--;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// Start of time selection 4
	//---------------------------------------

	g_auto_selection_point = SELECTION_MISSION_DELAY;
	g_screen_state = S_DELAY;

	while(nNxtButtonPressed != kEnterButton)
	{
		g_delay = g_end_delay;
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[4]< 30) g_input_array[5]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[4] > 0) g_input_array[5]--;
		}
	}

	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}

	//---------------------------------------
	// Start of end point selection 5
	//---------------------------------------

	g_screen_state = S_ENDING_POINT;
	g_auto_selection_point = SELECTION_END_POINT;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[5] < g_auto_ending_points) g_end_point++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[5] > 0) g_end_point--;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// Start of optional sub selection for ramp position
	//---------------------------------------

	if(g_input_array[5] == 2 || g_input_array[5] == 3)
	{
		g_auto_selection_point = SELECTION_SUB_RAMP;
		g_screen_state = S_SELECTION_SUB_RAMP;

		int i = 1;
		while(nNxtButtonPressed != kEnterButton)
		{
			if(nNxtButtonPressed == kRightButton)
			{
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed == kRightButton){}
				if(i < 2)
				{
					i++;
					g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_CONTINUED;
				}
			}
			if(nNxtButtonPressed == kLeftButton)
			{
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed == kLeftButton){}
				if(i > 1)
				{
					i--;
					g_auto_grabber_selections = SUB_SELECTION_RAMP_STOP;
				}
			}
		}

		PlaySoundFile("! Click.rso");
		while(nNxtButtonPressed == kEnterButton){}
	}
	if(g_auto_grabber_selections == SUB_SELECTION_RAMP_STOP&&g_input_array[5]==2)g_input_array=4;
	if(g_auto_grabber_selections == SUB_SELECTION_RAMP_STOP&&g_input_array[5]==3)g_input_array=5;
}

#endif /* !ABS_SELECTION_CUSTOM_H */
