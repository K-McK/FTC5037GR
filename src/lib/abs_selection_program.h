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
	screen_state = s_starting_point;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(start_point < auto_starting_points) start_point++;
			else start_point = auto_starting_points;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(start_point > 0) start_point--;
			else start_point = 0;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// Start of start time selection
	//---------------------------------------

	auto_selection_point = SELECTION_START_DELAY;
	screen_state = s_delay;

	while(nNxtButtonPressed != kEnterButton)
	{
		delay = start_delay;
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(start_delay < 30) start_delay++;
			else start_delay = 30;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(start_delay > 0) start_delay--;
			else start_delay = 0;
		}
	}

	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}

	//---------------------------------------
	// Start of mission selection
	//---------------------------------------

	auto_selection_point = SELECTION_MISSION_POINT;
	screen_state = s_mission;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(mission_number < auto_missions) mission_number++;
			else mission_number = auto_missions;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(mission_number > 0) mission_number--;
			else mission_number = 0;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

		//---------------------------------------
	// Start of time selection
	//---------------------------------------

	auto_selection_point = SELECTION_MISSION_DELAY;
	screen_state = s_delay;

	while(nNxtButtonPressed != kEnterButton)
	{
		delay = end_delay;
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(end_delay < 30) end_delay++;
			else end_delay = 30;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(end_delay > 0) end_delay--;
			else end_delay = 0;
		}
	}

	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}

	//---------------------------------------
	// Start of end point selection
	//---------------------------------------

	screen_state = s_ending_point;
	auto_selection_point = SELECTION_END_POINT;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(end_point < auto_ending_points) end_point++;
			else end_point = auto_ending_points;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(end_point > 0) end_point--;
			else end_point = 0;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();

	//---------------------------------------
	// Start of gyro cal selection
	//---------------------------------------

	screen_state = s_cal_time;

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(gyroCalTime < 30) gyroCalTime++;
			else gyroCalTime = 30;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(gyroCalTime > 0) gyroCalTime--;
			else gyroCalTime = 0;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
	eraseDisplay();
	screen_state = s_gyro_cal;
}

#endif /* !ABS_SELECTION_PROGRAM_H */
