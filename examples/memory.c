/**
 * This example introduces the concept of pointers.  A Pointer is just a
 * variable used to store a memory address.  By using a pointer, you are
 * able to track the location in memory of a structure (or anything else).
 * Here, we are using pointers to store the memory location of a chunk
 * of memory that my_alloc() is returning. By typecasting the pointer that
 * is returned by my_alloc to the specific type of pointer that we want
 * (a pointer to a memory location that is being used to hold data for
 * a "my_struct" structure) we are able to tell the compiler where, in that
 * allocated chuck of data, each of the fields in that structure are located
 * so that we can manipulate their values.
 */

#include <stdio.h>
#include "lib/memory.h"

/* global variables */
char* buff_ptr; // the pointer to the next available memory that can
                // be alloacted
char buffer[DYNAMIC_MEMORY_SIZE]; // the buffer from which the memory will
                                  // be allocated

#include "lib/my_create_mem_block.h"
#include "lib/my_alloc.h"

void main()
{
  /** initialize the memory block that we will use to allocate memory from */
  my_create_mem_block();

  /**
   * get a piece of memory the size of the structure 'my_struct'
   * and then assign it to a my_struct pointer variable.
   * This is where the typecast is happening
   */
  my_struct* structure1 = (my_struct*)my_alloc(sizeof(my_struct));

  /** assign values to each of the fields */
  structure1->field1 = 100;  // when you have a pointer (structure1) you can
                             // reference the members of the structure it is
                             // pointing to using the arrow (->) operator
  structure1->field2 = 200;

  /** now print the values that were just set */
  printf("Structure 1 memory address is %x\n", structure1);
  printf("Structure 1, Field 1 is %d\n", structure1->field1);
  printf("Structure 2, Field 2 is %d\n\n", structure1->field2);

  /**
   * get a piece of memory the size of the structure 'my_struct'
   * and then assign it to a my_struct pointer variable.
   * This is where the typecast is happening
   */
  my_struct* structure2 = (my_struct*)my_alloc(sizeof(my_struct));

  /** assign values to each of the fields */
  structure2->field1 = 300;
  structure2->field2 = 400;

  /** now print the values that were just set */
  printf("Structure 2 memory address is %x\n", structure2);
  printf("Structure 2, Field 1 is %d\n", structure2->field1);
  printf("Structure 2, Field 2 is %d\n", structure2->field2);
}
