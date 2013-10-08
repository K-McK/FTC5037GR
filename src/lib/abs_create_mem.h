/**
 *
 *  @file abs_create_mem.h
 *
 *  @brief a collection of math operations
 *
 *  @copyright Copyright 2013, Got Robot? FTC Team 5037
 *
 */
#ifndef ABS_CREATE_MEM_H
#define ABS_CREATE_MEM_H

void abs_create_mem()
{
	memset(g_buffer, 0x0, DYNAMIC_MEMORY_SIZE);

  /** now store the address of the buffer in the pointer */

  g_next_available_memory_ptr = &g_buffer;
}

#endif /* !ABS_CREATE_MEM_H */
