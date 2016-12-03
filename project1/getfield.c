/*****************************************************************
//
// NAME:			Lambert Leong
//
// HOMEWORK: 		project1
//
// CLASS: 			ICS 212
//
// INSTRUCTOR:		Ravi Narayan
//
// DATE: 			JUNE 28, 2016
//
// FILE: 			getfield.c
//
// DESCRIPTION: 	This file contains the getfield function.
//
//****************************************************************/

#include "project1header.h"

extern int debug;

/*****************************************************************
//
// Function name:   getfield
//
// DESCRIPTION:     allows for the user to enter in addresses or char
//                  input with mutilple lines.  two new line char allows
//                  allows function to exit.  if input is greater than the 
//                  the 'cap' then the input up to the 'cap' length is taken
//
// Parameters: address (char []):   array where address is stored
//             cap (int):   the max amount of char allowed to be stored   
//
// Return values: void
//
//****************************************************************/

void getfield (char address[ ], int cap)
{
    int exit, index;
    char in;
    char c;
    
    exit = 0;
    index = 0;
    
    if (debug == 1)
    {
        printf("\n********DEBUG MODE********\n");
        printf("Function called: getfield\nParameters passed:\naddress[ ] location is %p\ncap is %d\n\n",&address,cap);
        printf("***************************\n\n");
    }
    
     while(exit<1)
    {        
        /*in = getchar();*/
        address[index] = getchar();
        if((address[index-1] == '\n'&& address[index] == '\n') || index >= cap)
        {
            address[index-1]='\0'; /*prevents storing the two extra newline char, helps when adding the !*/
            /*printf("cap met \n");*/
            if(index >= cap)
            {
                address[index+1]='\0';/*prevents storing the extra newline char, helps when adding the !*/
                while((c = getchar()) != '\n' && c != EOF);    /*clears input buffer*/
                printf("Note! Number of characters exceeded.\nOnly the first 78 char were taken\n\n");
            }
            exit=2;
        }
        index++;
    }
}
