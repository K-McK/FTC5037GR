/**
 *
 *  Filename:  math_utils.h
 *
 *  Description:  a collection of math operations
 *
 *  Copyright 2013, Got Robot! FTC Team 5037
 *
 */
#ifndef ABS_GET_MEM_H
#define ABS_GET_MEM_H

/** macros */

int abs_get_mem(int size)
{
	int old_memory = mem_pointer;
	int mem_pointer = mem_pointer + size;
	return old_memory;
}


#endif /* !MATH_UTILS_H */
