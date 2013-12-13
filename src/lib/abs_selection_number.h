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
			if(nNxtButtonPressed == kRightButton)
			{
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed == kRightButton){}
				g_intput_array[g_graph_selection_tab] ++;
			}
			if(nNxtButtonPressed == kLeftButton)
			{
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed == kLeftButton){}
				g_intput_array[g_graph_selection_tab] --;
			}
		}
		while(nNxtButtonPressed == kEnterButton){}
		PlaySoundFile("! Click.rso");
	}
	g_start_point = g_intput_array[1];
	g_start_delay = g_intput_array[2];
	g_mission_number = g_intput_array[3];
	g_end_delay = g_intput_array[4];
	if(g_intput_array[4] < 4 && g_intput_array > 0)
	{
		g_end_point = g_intput_array[5];
		g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_STOP;
	}
	else if(g_intput_array[4] == 4)
	{
		g_end_point = 2;
		g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_CONTINUED;
	}
	else if(g_intput_array[4] == 5) g_end_point = 3;
	{
		g_end_point = 3;
		g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_CONTINUED;
	}

	g_screen_state = S_MISSION_SHOW;
}

#endif /* !ABS_SELECTION_NUMBER_H */
