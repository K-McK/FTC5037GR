/**
*
*  @file abs_selection_number.h
*
*  @brief handles the number selection options for auto mission selection
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_SELECTION_NUMBER_H
#define ABS_SELECTION_NUMBER_H

void abs_selection_number()
{
	//---------------------------------------
	// number selection
	//---------------------------------------

	g_auto_selection_point = SELECTION_GRAPH_NUMBER_INPUT;
	g_screen_state = S_NUMBER_SELECTION;

	while(g_graph_selection_tab<5)
	{
		g_graph_selection_tab++;
		while(nNxtButtonPressed != kEnterButton)
		{
			if(nNxtButtonPressed == kRightButton && g_intput_array[g_graph_selection_tab] < g_number_max_limit[g_graph_selection_tab])
			{
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed == kRightButton){}
				g_input_array[g_graph_selection_tab] ++;
			}
			else
			{
				PlayTone(200,20);
			}
			if(nNxtButtonPressed == kLeftButton && g_intput_array[g_graph_selection_tab] > g_number_min_limit[g_graph_selection_tab])
			{
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed == kLeftButton){}
				g_input_array[g_graph_selection_tab] --;
			}
			else
			{
				PlayTone(200,20);
			}
		}
		while(nNxtButtonPressed == kEnterButton){}
		PlaySoundFile("! Click.rso");
	}
	g_start_point = g_input_array[STARTING_POINT];
	g_start_delay = g_input_array[STARTING_DELAY];
	g_mission_number = g_input_array[SCOREING_POINT];
	g_end_delay = g_input_array[END_DELAY];
	if(g_input_array[END_POINT] < 4 && g_input_array[END_POINT] > 0)
	{
		g_end_point = g_input_array[END_POINT];
		g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_STOP;
	}
	else if(g_input_array[END_POINT] == 4)
	{
		g_end_point = 2;
		g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_CONTINUED;
	}
	else if(g_input_array[END_POINT] == 5)
	{
		g_end_point = 3;
		g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_CONTINUED;
	}
	else
	{
		g_end_point = 1; //error for if an invaid value is inputed
		PlayTone(400,60);
	}

	g_screen_state = S_MISSION_SHOW;
}

#endif /* !ABS_SELECTION_NUMBER_H */
