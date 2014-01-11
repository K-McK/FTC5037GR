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

void selection_program()
{
	while(nNxtButtonPressed == kEnterButton){}

	//---------------------------------------
	// number selection, quick selection, or custom selection
	//---------------------------------------

	g_auto_selection_point = SELECTION_SELECTION_TYPE;
	g_screen_state = S_SELECTION_TYPE;

	int j = 1;
	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(j < 3) j++;
			else j = 3;
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

	//---------------------------------------
	// selection executes
	//---------------------------------------
	if(selection_type == SELECTION_TYPE_CUSTOM) abs_selection_custom();
	else if(selection_type == SELECTION_TYPE_NUMBER)
	{
		abs_selection_number();
		dl_mission_number = (g_intput_array[1]*10000)+(g_intput_array[2]*1000)+(g_intput_array[3]*100)+(g_intput_array[4]*10)+(g_intput_array[5]*1);
	}
	else if(selection_type == SELECTION_TYPE_QUICK) abs_selection_quick();

	//---------------------------------------
	// Start of optional sub selection for ramp position
	//---------------------------------------

	if(g_end_point == 2 || g_end_point == 3 && selection_type != SELECTION_TYPE_NUMBER)
	{
		g_auto_selection_point = SELECTION_SUB_RAMP;
		g_screen_state = S_SELECTION_SUB_RAMP;

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
					g_auto_grabber_selection_ramp_options = SUB_SELECTION_RAMP_CONTINUED;
				}
			}
			if(nNxtButtonPressed == kLeftButton)
			{
				PlaySoundFile("! Click.rso");
				while(nNxtButtonPressed == kLeftButton){}
				if(i > 1)
				{
					i--;
					g_auto_grabber_selections = SUB_SELECTION_RAMP_STOP;
				}
			}
		}

		PlaySoundFile("! Click.rso");
		while(nNxtButtonPressed == kEnterButton){}
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
