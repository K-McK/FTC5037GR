/**
*
*  @file abs_btn_press.h
*
*  @brief The header file that handles the joystick inputs detection for datalogging
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_BTN_PRESS_H
#define ABS_BTN_PRESS_H

task abs_btn_press()
{
	int k = 0;
	while(true)
	{
		//------------------------------
		// check for button press
		//------------------------------

		if(joy1Btn(k) && dl_joy1_btns[k]==false)
		{
			dl_joy1_btns[k]=true;
			dl_btn_change = true;
		}
		if(joy2Btn(k) && dl_joy2_btns[k]==false)
		{
			dl_joy2_btns[k]=true;
			dl_btn_change = true;
		}

		//------------------------------
		// check for button release
		//------------------------------

		if((joy1Btn(k)==false) && dl_joy1_btns[k]==true)
		{
			dl_joy1_btns[k]=false;
			dl_btn_change = true;
		}
		if((joy2Btn(k)==false) && dl_joy2_btns[k]==true)
		{
			dl_joy2_btns[k]=false;
			dl_btn_change = true;
		}
		k++;
		if(k>12)k=0;
		if(dl_btn_change == true)
		{
			dl_btn_change = false;
			//PlayTone(400,20);
		}
	}
}

#endif /* !ABS_BTN_PRESS_H */
