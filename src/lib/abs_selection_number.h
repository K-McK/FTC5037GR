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

#include "lib/abs_cscreen.h"

void abs_selection_number()
{
	//---------------------------------------
	// number selection
	//---------------------------------------

	abs_cscreen("Number  ","00000   ","        ");

	while(g_graph_selection_tab<5)
	{
		g_graph_selection_tab++;
		while(nNxtButtonPressed != kEnterButton)
		{
			nxtDisplayBigTextLine(1, "%1d%1d%1d%1d%1d%1d%1d%1d",g_input_array[1],g_input_array[2],g_input_array[3],g_input_array[4],g_input_array[5]);
			if(nNxtButtonPressed == kRightButton && g_input_array[g_graph_selection_tab] < g_number_max_limit[g_graph_selection_tab])
			{
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed == kRightButton){}
				g_input_array[g_graph_selection_tab] ++;
			}
			if(nNxtButtonPressed == kLeftButton && g_input_array[g_graph_selection_tab] > g_number_min_limit[g_graph_selection_tab])
			{
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed == kLeftButton){}
				g_input_array[g_graph_selection_tab] --;
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
	else g_end_point = 1; //error for if an invaid value is inputed
}

#endif /* !ABS_SELECTION_NUMBER_H */
