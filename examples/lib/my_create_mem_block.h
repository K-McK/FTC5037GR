/**
 *
 *  Filename:  template.c (this should be the name of the function)
 *
 *  Description:  Enter a description of what this function does
 *
 *  Copyright 2013, Got Robot! FTC Team 5037
 *
 */
#ifndef MY_CREATE_MEM_BLOCK_H
#define MY_CREATE_MEM_BLOCK_H

/** this standard C header file contains the memset() definition */
#include <string.h>

/**
 * initializes the buffer to the configured size
 * and sets the buffer pointer.
 */
void my_create_mem_block()
{
  /** this line filles the entire buffer with zeroes (0x0) */
  memset(buffer, 0x0, DYNAMIC_MEMORY_SIZE);

  /** now store the address of the buffer in the pointer */
  buff_ptr = buffer;
}

#endif
