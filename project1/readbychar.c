/*****************************************************************
//
// NAME:		 	Lambert Leong
//
// HOMEWORK:		project1
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

#include "project1header.h"

extern int debug;

/*****************************************************************
//
// Function name:   readbychar
//
// DESCRIPTION:     allows for the user to enter in a string but restricts the
//                  length to the size of the cap 
//
// Parameters:      address (char []):   array where address is stored
//                  cap (int):   the max amount of char allowed to be stored
//
// Return values: void
//
//****************************************************************/

void readbychar (char name[], int cap)
{
    int exit,index;
    char in, c;
  
    exit = 0;
    index = 0;
    
    if (debug == 1)
    {
        printf("\n********DEBUG MODE********\n");
        printf("Function called: readbychar\nParameters passed:\nname[] location is %p\ncap is %d\n",&name,cap);
        printf("***************************\n\n");
    }
    
    
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
            name[index] = '\0'; /*helps when printing strings*/
            exit=2;
        }
        index++;
    }
}
