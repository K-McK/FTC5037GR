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
#include "lib/abs_ramp_interpret.h"


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
			nxtDisplayBigTextLine(3, "%1d%1d%1d%1d%1d%1d%1d%1d",g_input_array[1],g_input_array[2],g_input_array[3],g_input_array[4],g_input_array[5]);
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
			switch(g_graph_selection_tab)
			{
				case 1: nxtDisplayBigTextLine(5, "^       "); break;
				case 2: nxtDisplayBigTextLine(5, " ^      "); break;
				case 3: nxtDisplayBigTextLine(5, "  ^     "); break;
				case 4: nxtDisplayBigTextLine(5, "   ^    "); break;
				case 5: nxtDisplayBigTextLine(5, "    ^   "); break;
			}
		}
		while(nNxtButtonPressed == kEnterButton){}
		PlaySoundFile("! Click.rso");
	}
	abs_ramp_interpret();
}

#endif /* !ABS_SELECTION_NUMBER_H */
