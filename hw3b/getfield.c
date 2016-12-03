/*****************************************************************
//
// NAME:			Lambert Leong
//
// HOMEWORK: 		3b
//
// CLASS: 			ICS 212
//
// INSTRUCTOR:		Ravi Narayan
//
// DATE: 			JUNE 21, 2016
//
// FILE: 			getfield.c
//
// DESCRIPTION: 	This file contains the getfield function.
//
//****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getfield (char address[ ], int cap)
{
    int exit = 0;
    int index = 0;
    char in;
    char c;
    
    while(exit<1)
    {        
        /*in = getchar();*/
        address[index] = getchar();
        if((address[index-1] == '\n'&& address[index] == '\n') || index >= cap)
        {
            /*printf("cap met \n");*/
            if(index >= cap)
            {
                while((c = getchar()) != '\n' && c != EOF);    /*clears input buffer*/
                printf("Note! Number of characters exceeded.\nOnly the first 78 char were taken\n\n");
            }
            exit=2;
        }
        index++;
    }
    
    /*while(exit<1)
    {
        if(index >= cap)
        {
            printf("cap met \n");
            exit=1;
        }
        in = getchar();
        address[index] = in; 
        if(address[index-1] == '\n'&& address[index] == '\n')
        {
            printf("new line condition \n");
            exit=1;
        }
        
        index++;
    }*/
}
