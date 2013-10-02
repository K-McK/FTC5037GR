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


void my_create_mem_block()
{
  memset(buffer, DYNAMIC_MEMORY_SIZE, 0x0);
  buff_ptr = buffer;
}

#endif
