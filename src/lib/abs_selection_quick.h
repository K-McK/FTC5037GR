/**
*
*  @file abs_selection_quick.h
*
*  @brief handles the quick selection options for auto mission selection
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_SELECTION_QUICK_H
#define ABS_SELECTION_QUICK_H

#include "lib/abs_cscreen.h"
#include "lib/abs_ramp_interpret.h"

void abs_selection_quick()
{
	//---------------------------------------
	// quick selection
	//---------------------------------------
	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_quick_mission < g_max_quick_missions)g_quick_mission++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_quick_mission > 1)g_quick_mission--;
		}
		switch(g_quick_mission)
		{
		case 1:
			abs_cscreen("IRobot  ","10102   ","        ");
			g_input_array[1] = 1;
			g_input_array[2] = 0;
			g_input_array[3] = 1;
			g_input_array[4] = 0;
			g_input_array[5] = 2;
			break;
		case 2:
			abs_cscreen("IRobot 2","20103   ","        ");
			g_input_array[1] = 2;
			g_input_array[2] = 0;
			g_input_array[3] = 1;
			g_input_array[4] = 0;
			g_input_array[5] = 3;
			break;
		case 3:
			abs_cscreen("S1D     ","16103   ","        ");
			g_input_array[1] = 1;
			g_input_array[2] = 6;
			g_input_array[3] = 1;
			g_input_array[4] = 0;
			g_input_array[5] = 3;
			break;
		case 4:
			abs_cscreen("S2D     ","26102   ","        ");
			g_input_array[1] = 2;
			g_input_array[2] = 6;
			g_input_array[3] = 1;
			g_input_array[4] = 0;
			g_input_array[5] = 2;
			break;
		case 5:
			abs_cscreen("S1D1    ","26202   ","        ");
			g_input_array[1] = 2;
			g_input_array[2] = 6;
			g_input_array[3] = 2;
			g_input_array[4] = 0;
			g_input_array[5] = 2;
			break;
		case 6:
			abs_cscreen("S2D4    ","26203   ","        ");
			g_input_array[1] = 2;
			g_input_array[2] = 6;
			g_input_array[3] = 2;
			g_input_array[4] = 0;
			g_input_array[5] = 3;
			break;
		case 7:
			abs_cscreen("S1      ","10503   ","        ");
			g_input_array[1] = 1;
			g_input_array[2] = 0;
			g_input_array[3] = 5;
			g_input_array[4] = 0;
			g_input_array[5] = 3;
			break;
		case 8:
			abs_cscreen("S24     ","20203   ","        ");
			g_input_array[1] = 2;
			g_input_array[2] = 0;
			g_input_array[3] = 2;
			g_input_array[4] = 0;
			g_input_array[5] = 3;
			break;
		}
	}
	while(nNxtButtonPressed == kEnterButton){}
	PlaySoundFile("! Click.rso");
	abs_ramp_interpret();
}

#endif /* !ABS_SELECTION_NUMBER_H */
