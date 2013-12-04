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
	// number selection or custom selection
	//---------------------------------------

	auto_selection_point = SELECTION_SELECTION_TYPE;
	g_screen_state = S_SELECTION_TYPE;

	int j = 1;
	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(j < 2) j++;
			else j = 2;
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
			// in for future use
		case 3:
			selection_type = SELECTION_TYPE_QUICK;
			break;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	if(selection_type == SELECTION_TYPE_CUSTOM)
	{
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
			auto_selection_point = SELECTION_SUB_GRABBERS;
			g_screen_state = S_SELECTION_SUB_GRABBERS;

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
					if(i > 1)
					{
						i--;
						auto_grabber_selections = SUB_SELECTION_GRABBERS_IN;
					}
					else
					{
						i = 1;
						auto_grabber_selections = SUB_SELECTION_GRABBERS_IN;
					}
				}
			}

			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kEnterButton){}
		}
	}
	else if(selection_type == SELECTION_TYPE_NUMBER)
	{
		//---------------------------------------
		// number selection
		//---------------------------------------

		auto_selection_point = SELECTION_GRAPH_NUMBER_INPUT;
		g_screen_state = S_NUMBER_SELECTION;

		int k = 10000;
		while(g_graph_selection_tab<5)
		{
			g_graph_selection_tab++;
			while(nNxtButtonPressed != kEnterButton)
			{
				if(nNxtButtonPressed == kRightButton)
				{
					PlaySoundFile("! Click.rso");
					while(nNxtButtonPressed == kRightButton){}
					//if(g_graph_selection_number < 9*k)
					g_graph_selection_number = g_graph_selection_number + k;
					//else g_graph_selection_number = 9*k;
				}
				if(nNxtButtonPressed == kLeftButton)
				{
					PlaySoundFile("! Click.rso");
					while(nNxtButtonPressed == kLeftButton){}
					//if(g_graph_selection_number > 1*k)
					g_graph_selection_number = g_graph_selection_number - k;
					//else g_graph_selection_number = 1*k;
				}
			}
			while(nNxtButtonPressed == kEnterButton){}
			k = k / 10;
			PlaySoundFile("! Click.rso");
			//g_graph_selection_number = g_graph_selection_parts[1] + g_graph_selection_parts[2] + g_graph_selection_parts[3] + g_graph_selection_parts[4];
		}
		PlaySoundFile("! Click.rso");
		while(nNxtButtonPressed == kEnterButton){}
		eraseDisplay();
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
