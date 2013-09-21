#define RHS 81


//==================================================================================================================
void Big_Number (int x, int y, long value, int dp, int fieldwidth)     // display numbers right justified with optional decimal point
{
	int dig, myx, digits=0;
	myx=x+fieldwidth*20;
	bool neg=false;
	char fname[] = "My_0.ric";													// configure filename for RIC file output
	long limit = pow(10,fieldwidth+1)-1;								// max display capability
	if (value<0 | dp!=0) limit/=10;											// one digit less if negative or decimal places
	if (value>limit) value = limit;											// enforce limit
	if (value<0 && abs(value) >limit) value = -limit;		// and also low end if negative
	if (value<0) {value= -value;                        // if negative then work with absolute value
		neg=true;                           							// and say that we need to put up a negative sign
	}
	do
	{
		if ((dp!=0) & (digits==dp)) {nxtDisplayRICFile(myx+13,y, "My_DecDot.ric");   // time to put out the decimal point
			myx-=7;               														// and adjust display position accordingly
		}
		dig=value%10;                                      // figure out what the next digit is to be
		value=value/10;                                    // then adjust the number down by a factor of 10
		if (dig==0)
		{ if ((digits<=dp) | (value!=0)) nxtDisplayRICFile(myx,y, "My_0.ric");		// display a zero only if digit is not a leading zero
			else {if (neg) {nxtDisplayRICFile(myx+10,y, "My_-.ric");          			// display a negative sign if the number is all displayed already
					neg=false;                      																		// only display the sign once
				}
				else nxtEraseRect(myx,y,19+myx,40+y);    // if number is all displayed then use leading spaces to get rid of any old digits
			}
		}
		else
		{fname[3]='0'+dig;									// setup filename for the current digit
			nxtDisplayRICFile(myx,y, fname);	// display the current digit;
		}
		digits+=1;													// another digit done
		myx-=20;														// adjust cursor position for next digit
	} while (digits<=fieldwidth);					// continue until all requested digits are displayed
}


task main()
{
	for (long i=9960;i<999999;i++)
	{	Big_Number(0,3,i,0,4);
		wait1Msec(100);
	}
}
