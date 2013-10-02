#include "lib/memory.h"
#include "lib/my_create_mem_block.h"
#include "lib/my_alloc.h"

/* global variables */
my_struct* buff_ptr;
char buffer[40];

void main()
{
  my_create_mem_block();

  /** get a piece of memory the size of the structure */
  my_struct* structure = (my_struct*)my_alloc(sizeof(my_struct));

  /** assign values to each of the fields */
  structure->field1 = 100;
  structure->field2 = 200;

  /** now print the values that were just set */
  printf("Field 1 is %d\n", structure->field1);
  printf("Field 2 is %d\n", structure->field2);
}
