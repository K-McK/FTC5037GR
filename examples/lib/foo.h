/**
 *
 *  Filename:  foo.h
 *
 *  Description:  determines if you want foofoo or doodoo
 *
 *  Copyright 2013, Got Robot! FTC Team 5037
 *
 */
#ifndef FOO_H
#define FOO_H
     
/** constants etc that foo() needs */
#define FOO_FOO 1
#define DOO_DOO 2


/**
 * this is an example function
 *
 * @param value the value that we want to evaluate
 */
void foo(int value)
{
  if(value == FOO_FOO)
  {
    return 111;
  }
  else if(value == DOO_DOO)
  {
    return 222;
  }
  else
  {
    return 333;
  }
}

#endif /* !FOO_H */
