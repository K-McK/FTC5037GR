/**
*
*  @file abs_cscreen.h
*
*  @brief adds a way to put things on the screen by call
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

#ifndef ABS_CSCREEN_H
#define ABS_CSCREEN_H

void abs_cscreen(const char * header, const char * line1, const char * line2, int value1 = 0, int value2 = 0)
{

	//header
	nxtDisplayBigTextLine(1, header);

	//line1
	nxtDisplayBigTextLine(3, line1);

	//line2
	nxtDisplayBigTextLine(5, line2,value1,value2);
}

#endif
