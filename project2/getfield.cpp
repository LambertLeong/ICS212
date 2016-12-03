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

#include "project2header.h"

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
    
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: getfield\nParameters passed:\naddress[ ] location is "<<&address<<"\ncap is "<<cap<<endl;
        cout<<"***************************\n\n";
    #endif
    
     while(exit<1)
    {
        cin.get(c);
		address[index]=c;
        if((address[index-1] == '\n'&& address[index] == '\n') || index >= cap)
        {
            address[index-1]='\0'; /*prevents storing the two extra newline char, helps when adding the !*/
            if(index >= cap)
            {
                address[index+1]='\0';/*prevents storing the extra newline char, helps when adding the !*/
                cin.clear();
                cin.ignore(10000, '\n');  /*clears input buffer*/
               cout<<"Note! Number of characters exceeded.\nOnly the first 78 char were taken\n\n";
            }
            exit=2;
        }
        index++;
    }
}
