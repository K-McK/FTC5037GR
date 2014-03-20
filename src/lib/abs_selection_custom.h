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

#include "lib/abs_cscreen.h"

void abs_selection_custom()
{
	//---------------------------------------
	// Start point selection 1
	//---------------------------------------
	g_input_array[STARTING_POINT] = 1;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[STARTING_POINT] < g_auto_starting_points) g_input_array[STARTING_POINT]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[STARTING_POINT] > 0) g_input_array[STARTING_POINT]--;
		}
		abs_cscreen("Starting","point   ","S%1d      ",g_input_array[STARTING_POINT]);
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// Start of start time selection 2
	//---------------------------------------
	g_input_array[STARTING_DELAY] = 0;

	while(nNxtButtonPressed != kEnterButton)
	{
		abs_cscreen("Starting","delay   ","%2d",g_input_array[STARTING_DELAY]);
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[STARTING_DELAY] < 30) g_input_array[STARTING_DELAY]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[STARTING_DELAY] > 0) g_input_array[STARTING_DELAY]--;
		}
	}

	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}

	//---------------------------------------
	// Start of mission selection 3
	//---------------------------------------
	g_input_array[SCOREING_POINT] = 1;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[SCOREING_POINT] < g_auto_missions) g_input_array[SCOREING_POINT]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[SCOREING_POINT] > 0) g_input_array[SCOREING_POINT]--;
		}
		switch(g_input_array[SCOREING_POINT])
		{
		case 0: abs_cscreen("Scoring ","point   ","ERROR   "); break;
		case 1: abs_cscreen("Scoring ","point   ","IR      "); break;
		case 2: abs_cscreen("Scoring ","point   ","CRATE 4 "); break;
		case 3: abs_cscreen("Scoring ","point   ","CRATE 3 "); break;
		case 4: abs_cscreen("Scoring ","point   ","CRATE 2 "); break;
		case 5: abs_cscreen("Scoring ","point   ","CRATE 1 "); break;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// Start of time selection 4
	//---------------------------------------

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[END_DELAY]< 30) g_input_array[END_DELAY]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[END_DELAY] > 0) g_input_array[END_DELAY]--;
		}
		abs_cscreen("Score   ","delay   ","%2d       ",g_input_array[END_DELAY]);
	}

	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}

	//---------------------------------------
	// Start of end point selection 5
	//---------------------------------------
	g_input_array[END_POINT] = 1;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(g_input_array[END_POINT] < g_auto_ending_points) g_input_array[END_POINT]++;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(g_input_array[END_POINT] > 0) g_input_array[END_POINT]--;
		}
		switch(g_input_array[END_POINT])
		{
		case 0: abs_cscreen("End pnt ","ERROR   ","        "); break;
		case 1: abs_cscreen("End pnt ","stop    ","        "); break;
		case 2: abs_cscreen("End pnt ","RAMP 1  ","stop    "); break;
		case 3: abs_cscreen("End pnt ","RAMP 2  ","stop    "); break;
		case 4: abs_cscreen("End pnt ","RAMP 1  ","continue"); break;
		case 5: abs_cscreen("End pnt ","RAMP 2  ","continue"); break;
		case 6: abs_cscreen("End pnt ","RAMP 3  ","stop    "); break;
		case 7: abs_cscreen("End pnt ","RAMP 4  ","stop    "); break;
		case 8: abs_cscreen("End pnt ","RAMP 3  ","continue"); break;
		case 9: abs_cscreen("End pnt ","RAMP 4  ","continue"); break;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	g_start_point = g_input_array[STARTING_POINT];
	g_start_delay = g_input_array[STARTING_DELAY];
	g_mission_number = g_input_array[SCOREING_POINT];
	g_end_delay = g_input_array[END_DELAY];
	if((g_input_array[END_POINT] <= 3 && g_input_array[END_POINT] >= 1)||(g_input_array[END_POINT]==6||g_input_array[END_POINT]==7))
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
	else if(g_input_array[END_POINT] == 8)
	{
		g_end_point = 6;
		g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_CONTINUED;
  }
	else if(g_input_array[END_POINT] == 9)
	{
		g_end_point = 7;
		g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_CONTINUED;
  }
	else g_end_point = 1; //error for if an invaid value is inputed
}

#endif /* !ABS_SELECTION_CUSTOM_H */
