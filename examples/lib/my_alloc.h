/**
 *
 *  Filename:  template.c (this should be the name of the function)
 *
 *  Description:  Enter a description of what this function does
 *
 *  Copyright 2013, Got Robot! FTC Team 5037
 *
 */
#ifndef MY_ALLOC_H
#define MY_ALLOC_H


char* my_alloc(int size)
{

  char* tmp = buff_ptr;
  buff_ptr += size;
  return tmp;
}

#endif
