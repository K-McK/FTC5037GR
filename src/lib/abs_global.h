/**
 *
 *  @file abs_global.h
 *
 *  @brief  Enter a description of what this file contains
 *
 *  Copyright 2013, Got Robot! FTC Team 5037
 *
 */
#ifndef ABS_GLOBAL_H
#define ABS_GLOBAL_H

/** macros */
/** defines memory size */
#define DYNAMIC_MEMORY_SIZE 40

/** enumerations */

/** structures */
/** defines structure */
typedef struct
{
  float heading;
  int time;
} turn_context;

/** function prototypes */

/** global constant variables */
/** defines pointer */
char* next_available_memory_ptr;
char buffer[DYNAMIC_MEMORY_SIZE];
float drift;
#endif /* !ABS_H */
