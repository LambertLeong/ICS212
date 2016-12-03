/*****************************************************************
//
// NAME:		 	Lambert Leong
//
// HOMEWORK:		3b
//
// CLASS: 			ICS 212
//
// INSTRUCTOR: 		Ravi Narayan
//
// DATE: 			JUNE 21, 2016
//
// FILE: 			readbychar.c
//
// DESCRIPTION: 	contains the readbychar function
//
//****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readbychar (char name[], int cap)
{
    int exit = 0;
    int index = 0;
    char in;
    char c;
    
    while(exit<1)
    {        
        /*in = getchar();*/
        name[index] = getchar();
        if(name[index] == '\n' || index >= cap)
        {
            /*printf("cap met \n");*/
            if(index >= cap)
            {
                while((c = getchar()) != '\n' && c != EOF);    /*clears input buffer*/
                printf("Note! Number of characters exceeded.\nOnly the first 25 char were taken\n\n");
            }
            exit=2;
        }
        index++;
    }
}
