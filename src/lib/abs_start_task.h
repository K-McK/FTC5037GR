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

#if USE_TASK_PRIORITY == 1
	#define abs_start_task(X,Y) StartTask(X, Y)
#else
	#define abs_start_task(X,Y) StartTask(X)
#endif

//void abs_start_task(void (*tsk)(void), int priority = PRIORITY_HIGH_VAL)
//{

//#if USE_TASK_PRIORITY == 1
//	if(priority != PRIORITY_HIGH_VAL)
//	{
//		abs_dlog(__FILE__ ,"USE_TASK_PRIORITY enabled", "priority", priority);
//		StartTask(tsk, priority);
//	}
//	else
//	{
//		abs_dlog(__FILE__ ,"USE_TASK_PRIORITY enabled...no priority specified");
//		StartTask(tsk);
//	}
//#else
//	abs_dlog(__FILE__ ,"USE_TASK_PRIORITY disabled");
//	StartTask(tsk);
//#endif
//}

#endif /* !ABS_TURN_H */
