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
// DESCRIPTION: contains the halfstring function
//
//****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "hw2b.h"

/*****************************************************************
//
// Function name: halfstring
//
// DESCRIPTION: takes two char arrays, copies the second half of first string to the
// second string.  Anything contained in the second string is overridden.  In the case
// that the first string contains an odd number of characters, the function rounds up
// and takes the half with more characters.  In the case that the first string 
// contains nothing, the function returns a message and the unchanged second string.
//
// Parameters: first (char []): input string that the function will cut in half
//             second (char[]): string that the function puts the second half of the //             first string in.
//
// Return values: void
//
//****************************************************************/

void halfstring(char first [], char second [])
{
	int length = stringlength(first);
	int seclength = stringlength(second);
	int start = length/2;
	char half [length];
	int begin = 0;
	int end;
	
	if(first[begin] == '\0')
	{
		printf("ERROR! String is empty! Nothing to add to second string argument\n");
	}
	else
	{
		while(first[start]!='\0')
		{
			half[begin] = first[start];
			start++;
			begin++;
			end = begin;
		}
	
        half[end] = '\0';
        begin = 0;
	
        while(half[begin]!='\0')
        {
            second[begin] = half[begin];
            begin ++;
            seclength++;
            end = begin;
        }
	
        second[end] = '\0';
        begin = 0;
	}
}
