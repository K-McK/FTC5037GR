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

//========================================
// Selection Program
//========================================

void selection_program()
{
	while(nNxtButtonPressed == kEnterButton){}

	//---------------------------------------
	// Start point selection
	//---------------------------------------

	auto_selection_point = SELECTION_START_POINT;
	g_screen_state = S_STARTING_POINT;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_start_point < g_auto_starting_points) g_start_point++;
			else g_start_point = g_auto_starting_points;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_start_point > 0) g_start_point--;
			else g_start_point = 0;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// Start of start time selection
	//---------------------------------------

	auto_selection_point = SELECTION_START_DELAY;
	g_screen_state = S_DELAY;

	while(nNxtButtonPressed != kEnterButton)
	{
		delay = g_start_delay;
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_start_delay < 30) g_start_delay++;
			else g_start_delay = 30;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_start_delay > 0) g_start_delay--;
			else g_start_delay = 0;
		}
	}

	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}

	//---------------------------------------
	// Start of mission selection
	//---------------------------------------

	auto_selection_point = SELECTION_MISSION_POINT;
	g_screen_state = S_MISSION;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_mission_number < g_auto_missions) g_mission_number++;
			else g_mission_number = g_auto_missions;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_mission_number > 0) g_mission_number--;
			else g_mission_number = 0;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// Start of time selection
	//---------------------------------------

	auto_selection_point = SELECTION_MISSION_DELAY;
	g_screen_state = S_DELAY;

	while(nNxtButtonPressed != kEnterButton)
	{
		delay = g_end_delay;
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_end_delay < 30) g_end_delay++;
			else g_end_delay = 30;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_end_delay > 0) g_end_delay--;
			else g_end_delay = 0;
		}
	}

	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}

	//---------------------------------------
	// Start of end point selection
	//---------------------------------------

	g_screen_state = S_ENDING_POINT;
	auto_selection_point = SELECTION_END_POINT;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_end_point < g_auto_ending_points) g_end_point++;
			else g_end_point = g_auto_ending_points;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_end_point > 0) g_end_point--;
			else g_end_point = 0;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// Start of optional sub selection for grabbers on the ram
	//---------------------------------------

	if(g_end_point == 2 || g_end_point == 3)
	{
		misc = 1;
		auto_selection_point = SELECTION_SUB_GRABBERS;
		g_screen_state = s_selection_sub_grabbers;

		while(nNxtButtonPressed != kEnterButton)
		{
			if(nNxtButtonPressed == kRightButton)
			{
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed == kRightButton){}
				if(misc < 2)
				{
					misc++;
					auto_grabber_selections = SUB_SELECTION_GRABBERS_OUT;
				}
				else
				{
					g_end_delay = 2;
					auto_grabber_selections = SUB_SELECTION_GRABBERS_OUT;
				}
			}
			if(nNxtButtonPressed == kLeftButton)
			{
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed == kLeftButton){}
				if(misc > 1)
				{
					misc--;
					auto_grabber_selections = SUB_SELECTION_GRABBERS_IN;
				}
				else
				{
					misc = 1;
					auto_grabber_selections = SUB_SELECTION_GRABBERS_IN;
				}
			}
		}

		PlaySoundFile("! Click.rso");
		while(nNxtButtonPressed == kEnterButton){}
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
			else g_gyro_cal_time = 30;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_gyro_cal_time > 0) g_gyro_cal_time--;
			else g_gyro_cal_time = 0;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();
	g_screen_state = S_GYRO_CAL;
}

#endif /* !ABS_SELECTION_PROGRAM_H */
