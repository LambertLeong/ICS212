/***********************************************************************
//
// NAME:           Lamber Leong
//
// HOMEWORK:        project1
//
// CLASS:           ICS 212
//
// INSTRUCTOR:      Ravi Narayan
//
// DATE:            June 21, 2016
//
// FILE:            hw3ui.c
//
// DESCRIPTION:     Contains the menu options for the UI
//
//*********************************************************************/

#include "project1header.h"

extern int debug;

/*****************************************************************
//
// Function name:   menuui
//
// DESCRIPTION:     User interface function which allows user to accomplish 
//                  different banking task.
//
// Parameters:    **start:    The address to the address of the start pointer
//
// Return values: void
//
//****************************************************************/

void menuui(struct record **start)
{
    int quit, menu, modify, print, delete, accountnum, namelength, addresscap, birthyear ;
    char name [25], address[80];

	addresscap = 78;
    namelength = 25;
    quit = 0;
    modify = 0;
    print = 0;
    delete = 2;
   
   /*struct record *start = NULL;*/
   
   if(debug == 1)
   {
       printf("\n********DEBUG MODE********\n");
       printf("Called: \nMenuui()\n");
       printf("Parameters passed:\nStart is %p\n",&start);
       printf("***************************\n\n");
   }
   
    while(menu != 6)
    {
        menu = menuoption();
		
		/*printf("menu start is %p\n",&start);*/
    
    /*1 Add a new record in the database*/
        if (menu == 1)
        {
            memset(address,0,sizeof(address));
            accountnum = inputaccountnum();
            printf("Enter the name on the account\n");
            readbychar(name, namelength);
            printf("Enter address\n");
            getfield(address,addresscap);
            birthyear = inputbirth();
            addRecord (start, accountnum, name, address,birthyear);
            memset(address,0,sizeof(address));
        }
    /*2 Modify a record in the database using the accountno as the key*/
        if (menu == 2)
        {
            memset(address,0,sizeof(address));
            accountnum = inputaccountnum();
            printf("Modify Record\nEnter new name for the account\n");
            readbychar(name, namelength);
            modify = modifyRecord (*start, accountnum, name);
            if(modify < 1)
            {
                printf("Account was not found\nNo account was modified\n");
            }
            memset(name,0,sizeof(name));
        }
    /*3 Print information about a record using the accountno as the key*/
        if (menu == 3)
        {
            accountnum = inputaccountnum();
            print = printRecord (*start, accountnum);
            if(print == 0)
            {
                printf("Record to print is not contained in database\n");
            }
        }
    /*4 Print all information in the database*/
        if(menu ==4)
        {
            printAllRecords(*start);
        }
    /*5 Delete an existing record from the database using the accountno as a key*/
        if(menu == 5)
        {
            accountnum = inputaccountnum();
            /*printf("number to delete \n", accountnum);*/
            delete = deleteRecord(start, accountnum);
            if(delete != 1)
            {
                printf("Record not in database \n");
            }
        }
        
    /*6 Quit the program*/    
    }
}

