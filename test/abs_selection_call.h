/**
*
*  @file abs_gyro_read.h
*
*  @brief A hedder file that handles the begining selection for robot actions
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_SELECTION_PROGRAM_H
#define ABS_SELECTION_PROGRAM_H

//========================================
// Selection Program
//========================================

void abs_selection_call(screen_call,min_value,max_value,default_value)
{
	while(nNxtButtonPressed == kEnterButton){}

	screen_state = s_screen_call;
	selection_value = default_value;
	//---------------------------------------

	while(nNxtButtonPressed != kEnterButton)
	{
		if(nNxtButtonPressed == kRightButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kRightButton){}
			if(selection_value < max_value) selection_value++;
			else selection_value = max_value;
		}
		if(nNxtButtonPressed == kLeftButton)
		{
			PlaySoundFile("! Click.rso");
			while(nNxtButtonPressed == kLeftButton){}
			if(selection_value > min_value) selection_value--;
			else selection_value = min_value;
		}
	}
	PlaySoundFile("! Click.rso");
	while(nNxtButtonPressed == kEnterButton){}
}

#endif /* !ABS_SELECTION_PROGRAM_H */
