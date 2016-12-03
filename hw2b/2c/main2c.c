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
// FILE: main.c
//
// DESCRIPTION: Main function that runs test for the username function.
//
//****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void username(char first[], char second[]);

main()
{
    printf("test 1, same first and last name\n");
    char firstname2 [100] = "samething";
    char lastname2 [100] = "samething";
    printf("firstname2 = %s, lastname2 = %s\n",firstname2,lastname2);
    username(firstname2, lastname2);
	
    printf("test 2, different first and last name\n");
	char firstname3 [100] = "Bruce";
    char lastname3 [100] = "Wayne";
    printf("firstname3 = %s, lastname3 = %s\n",firstname3,lastname3);
    username(firstname3, lastname3);
}