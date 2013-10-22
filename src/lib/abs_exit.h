/**
*
*  @file abs_exit.h
*
*  @brief  Exits the program in case something does wrong
*
*  @param exit tells the program what the exit name is
*
*  @copyright Copyright 2013, Got Robot! FTC Team 5037
*/
#ifndef ABS_EXIT_H
#define ABS_EXIT_H

/** macros */
void abs_exit(e_exit_code exit)
{
	if (exit == NULL_POINTER)
	{
		PlayTone(4000, 050);
		wait10Msec(050);
		PlayTone(4000, 050);
		wait10Msec(050);
		PlayTone(4000, 050);
		wait10Msec(050);
		StopAllTasks();
	}
}
/** enumerations */

/** structures */

/** function prototypes */

/** global constant variables */

#endif /* !TEMPLATE_H */
