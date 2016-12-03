/*****************************************************************
//
// NAME: Lambert Leong
//
// HOMEWORK: 2b
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: JUNE 14, 2016
//
// FILE: halfstring.c
//
// DESCRIPTION: contains the stringlength function
//
//****************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*****************************************************************
//
// Function name: stringlength
//
// DESCRIPTION: uses a loop to determine the length of a char array
//
// Parameters: string (char[]): the string which the length will be returned
//
// Return values: length (int):  integer value of the length of the input string
//
//****************************************************************/

int stringlength(char string [])
{
	int start = 0;
	int length = 0;
	
    while(string[start]!='\0')
    {
		start++;
		length = start;
    }
	return length;
}
