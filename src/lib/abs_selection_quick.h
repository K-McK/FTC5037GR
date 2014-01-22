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

void abs_selection_quick()
{
	//---------------------------------------
	// quick selection
	//---------------------------------------

	g_auto_selection_point = SELECTION_QUICK_INPUT;
	g_screen_state = S_QUICK_SELECTION;

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
	}
	while(nNxtButtonPressed == kEnterButton){}
	PlaySoundFile("! Click.rso");

	switch(g_quick_mission)
	{
	case 1:
		g_input_array[1] = 1;
		g_input_array[2] = 0;
		g_input_array[3] = 1;
		g_input_array[4] = 0;
		g_input_array[5] = 2;
		break;
	case 2:
		g_input_array[1] = 2;
		g_input_array[2] = 0;
		g_input_array[3] = 1;
		g_input_array[4] = 0;
		g_input_array[5] = 3;
		break;
	}
}

#endif /* !ABS_SELECTION_NUMBER_H */
