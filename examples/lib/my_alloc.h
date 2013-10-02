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


/**
 * this code returns the current buffer pointer and
 * moves it to the next available block
 *
 * Why use a character pointer?  Because a character
 * is one byte...so the size of the array is equal
 * to the number of bytes.
 *
 * @param size The number of bytes to allocate
 * @returns a pointer to the allocated memory
 */
char* my_alloc(int size)
{

  char* tmp = buff_ptr; // assign the pointer value to a temporary
                        // character pointer
  buff_ptr += size;     // increment the address in the pointer by the
                        // size of memory being alloacted
  return tmp;           // now return the original address
}

#endif
