/***********************************************************************
//
// NAME:           Lamber Leong
//
// HOMEWORK:        5
//
// CLASS:           ICS 212
//
// INSTRUCTOR:      Ravi Narayan
//
// DATE:            June 28, 2016
//
// FILE:            myhw5functions.c
//
// DESCRIPTION:     Contains addtional functions for user input after 
//                  the record is read from file.
//
//*********************************************************************/

#include "hw5header.h"

/*****************************************************************
//
// Function name: charcheck
//
// DESCRIPTION: checks if there is a char at the current location
//
// Parameters: count void
//
// Return values: 1 : success
//
//****************************************************************/

int charcheck()
    {
        while (getchar()!='\n');
        return 1;
    }
    
/*****************************************************************
//
// Function name: menuoption
//
// DESCRIPTION: uses scanf to and the checkcar function to checkchar
//              to insure that input is and int between 0 and 1, 
//              this function will be used to navigate the UI menu
//
// Parameters:  void 
//
// Return values: int
//
//****************************************************************/
    
int menuoption()
{
    int menu;
    char c;

    printf("Enter 1 to add new record\nEnter 0 when done\n");
    while(((scanf("%d%c", &menu, &c)!=2 || c!='\n') && charcheck()) || 
    menu<0 || menu >1)
    {
        printf("ERROR: Try again.\nEnter integer values from 0 to 1\n\n");
    }
    return menu; 
}

/*****************************************************************
//
// Function name: inputaccountnum
//
// DESCRIPTION: uses scanf to and the checkcar function to checkchar
//              to insure that input is a non-negatice int
//              this function will be used to gather account numbers
//
// Parameters:  void 
//
// Return values: int
//
//****************************************************************/

int inputaccountnum()
{
    int account;
    char c;
    
	printf("Enter account #\n");
    while (((scanf("%d%c", &account, &c)!=2 || c!='\n') && charcheck()) || account<0)
    {
        printf("ERROR:  Enter an integer value\n");
    }
	return account;
}

/*****************************************************************
//
// Function name: inputbirth
//
// DESCRIPTION: uses scanf to and the checkcar function to checkchar
//              to insure that input is and int between 1990 and 2016 
//              this function will be used to gather birth year info
//
// Parameters:  void 
//
// Return values: int
//
//****************************************************************/

int inputbirth()
{
    int account;
    char c;

	printf("Enter year of birth (eg. 1990)\n");
    while (((scanf("%d%c", &account, &c)!=2 || c!='\n') && charcheck()) || 
    account<1900 || account > 2016)
	{
		printf("Error: Please enter a year between 1900 and 2016\n");
	}
	return account;
}
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
            name[index] = '\0'; /*helps when printing strings*/
            exit=2;
        }
        index++;
    }
}
