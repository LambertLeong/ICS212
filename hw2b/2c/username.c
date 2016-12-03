/*****************************************************************
//
// NAME: Lambert Leong
//
// HOMEWORK: 2c
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: JUNE 14, 2016
//
// FILE: username.c
//
// DESCRIPTION: This file contains the username function which utilizes a handful of // string functions from the string library 
//
//****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************
//
// Function name: username
//
// DESCRIPTION: Takes two char arrays, first and last names, and suggest a possible
// username by combining the first two char of the first name with the last name
// when the two input strings are different.  In the case that a person has the same
// first and last name, then "01" is added to the last name to avoid redundancy 
//
// Parameters: first (char []): string that contains the first name of the user
//             second (char []): string that contains the last name of the user
//
// Return values: void
//
//****************************************************************/

void username(char first[], char second[])
{
    printf("Suggested username based off of first and last names\n");
    char firstname [strlen(first)];
    char lastname [strlen(second)];
    char username1 [(strlen(lastname)+2)];
    char prefix [2];
    int begin = 0;
	
    while(first[begin]!='\0')
		{
			firstname[begin] = first[begin];
            begin++;
			firstname[begin] = '\0';
		}
    begin = 0;
    while(second[begin]!='\0')
		{
			lastname[begin] = second[begin];
            begin++;
			lastname[begin] = '\0';
		}
    begin = 0;
	
    if(strcmp(firstname,lastname)==0)
    {
        strcpy(username1, firstname);
        strcat(username1,"01");
        printf("Your suggested username is %s\n\n",username1);
    }
    else
    {
        strncpy(prefix, firstname, 2);
        strcpy(username1, prefix);
        strcat(username1,lastname);
        
        printf("Your suggested username is %s\n\n",username1);
   }
}
