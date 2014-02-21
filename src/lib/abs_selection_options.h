/**
*
*  @file abs_selection_options.h
*
*  @brief
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_SELECTION_OPTIONS_H
#define ABS_SELECTION_OPTIONS_H

void abs_selection_options()
{
	//---------------------------------------
	// first turn
	//---------------------------------------

	g_screen_state = S_END_TURN_OPTIONS;
	g_selection_turn = 1;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_em_first_turn_type == END_MISSION_FIRST_TURN_REL) g_em_first_turn_type = END_MISSION_FIRST_TURN_CONST;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_em_first_turn_type == END_MISSION_FIRST_TURN_CONST) g_em_first_turn_type = END_MISSION_FIRST_TURN_REL;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// second turn selection
	//---------------------------------------

	g_selection_turn = 2;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_em_second_turn_type == END_MISSION_SECOND_TURN_REL) g_em_second_turn_type = END_MISSION_SECOND_TURN_CONST;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_em_second_turn_type == END_MISSION_SECOND_TURN_CONST) g_em_second_turn_type = END_MISSION_SECOND_TURN_REL;
		}
	}

	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
}

#endif /* !ABS_SELECTION_OPTIONS_H */
