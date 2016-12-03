/***********************************************************************
//
// NAME:           Lamber Leong
//
// HOMEWORK:        3b
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

#include <stdio.h>
#include <stdlib.h>
#include "record.h"
#include "acountfunctions.h"

extern int debug;

  /* void readbychar (char [], int );
   int charcheck();
   int inputaccountnum();
   int menuoption();
   int inputbirth();*/

menuui()
{
   int quit = 0;
   int menu;
   struct record *start = NULL;
   
   if(debug == 1)
   {
       printf("Entered debug Mode:\n\n");
       printf("Called: Menuui()\n");
   }
   
    while(menu != 6)
    {
        int accountnum;
        int namelength = 25;
        char name [namelength];
        char address[80];
        int addresscap = 78;
        char juke[10];
        int birthyear;
        menu = menuoption();
    
    /*1 Add a new record in the database*/
        if (menu == 1)
        {
            memset(address,0,sizeof(address));
            accountnum = inputaccountnum();
            printf("Enter the name on the account\n");
            readbychar(name, namelength);
            printf("Enter address\n");
            getfield(address,addresscap);
            wait(1);
            birthyear = inputbirth();
            addRecord (&start, accountnum, name, address,birthyear);
            memset(address,0,sizeof(address));
        }
    /*2 Modify a record in the database using the accountno as the key*/
        if (menu == 2)
        {
            memset(address,0,sizeof(address));
            accountnum = inputaccountnum();
            printf("Enter address\n");
            getfield(address,addresscap);
            wait(1);
            modifyRecord (start, accountnum, address);
            memset(address,0,sizeof(address));
        }
    /*3 Print information about a record using the accountno as the key*/
        if (menu == 3)
        {
            accountnum = inputaccountnum();
            printRecord (start, accountnum);
        }
    /*4 Print all information in the database*/
        if(menu ==4)
        {
            printAllRecords(start);
        }
    /*5 Delete an existing record from the database using the accountno as a key*/
        if(menu == 5)
        {
            accountnum = inputaccountnum();
            deleteRecord(&start, accountnum);
        }
        
    /*6 Quit the program*/
        
    }
}

