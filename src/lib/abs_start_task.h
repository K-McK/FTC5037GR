/**
*
*  @file abs_start_task.h
*
*  @brief 
*
*  @param 
*
*  @return 
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/
#ifndef ABS_START_TASK_H
#define ABS_START_TASK_H

#include "abs_dlog.h"

#define PRIORITY_HIGH_VAL 9999

void abs_start_task(void (*task)(void), int priority = PRIORITY_HIGH_VAL)
{

#if USE_TASK_PRIORITY == 1
	if(priority != PRIORITY_HIGH_VAL)
	{
		abs_dlog(__FILE__ ,"USE_TASK_PRIORITY enabled", "priority", priority);
		StartTask(task, priority);
	}
	else
	{
		abs_dlog(__FILE__ ,"USE_TASK_PRIORITY enabled...no priority specified");
		StartTask(task);
	}
#else
	abs_dlog(__FILE__ ,"USE_TASK_PRIORITY disabled");
	StartTask(task);
#endif
}

#endif /* !ABS_TURN_H */
