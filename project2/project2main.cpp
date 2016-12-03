/***********************************************************************
//
// NAME:            Lambert Leong
//
// HOMEWORK:        project1
//
// CLASS:           ICS 212
//
// INSTRUCTOR:      Ravi Narayan
//
// DATE:            June 28, 2016
//
// FILE:            hw3bmain.c
//
// DESCRIPTION:     Contains the main for running the UI in regular and
//					debug
//
//*********************************************************************/

#include "project2header.h"


int main(int argc, char *argv[])
{
    int quit, menu, modify, print, del, accountnum, namelength, addresscap, birthyear ;
    char name [25], address[80];
    
    llist db;
    llist db2(db);  /*copy constructor*/
    
    /*llist db2("dumb.txt");
    db2 = db;*/     /*over loaded assignement*/
    
	addresscap = 77;
    namelength = 23;
    quit = 0;
    modify = 0;
    print = 0;
    del = 2;
	menu = 0;
   
   #ifdef debug
       cout<<"\n********DEBUG MODE********\n";
       cout<<"Called: \nMenuui()\n";
       cout<<"***************************\n\n";
   #endif
   
    while(menu != 8)
    {
        menu = menuoption();

    /*1 Add a new record in the database*/
        if (menu == 1)
        {
            accountnum = inputaccountnum();
            cout<<"Enter the name on the account\n";
            readbychar(name, namelength);
            cout<<"Enter address\n";
            getfield(address,addresscap);
            birthyear = inputbirth();
            db.addRecord (accountnum, name, address,birthyear);
        }
    /*2 Modify a record in the database using the accountno as the key*/
        if (menu == 2)
        {
            accountnum = inputaccountnum();
            cout<<"Modify Record\nEnter new address for the account\n";
            getfield(address,addresscap);
            modify = db.modifyRecord (accountnum, address);
            if(modify < 1)
            {
                cout<<"Account was not found\nNo account was modified\n";
            }
            memset(name,0,sizeof(name));
        }
    /*3 Print information about a record using the accountno as the key*/
        if (menu == 3)
        {
            accountnum = inputaccountnum();
            print = db.printRecord (accountnum);
            if(print == 0)
            {
                cout<<"Record to print is not contained in database\n";
            }
        }
    /*4 Print all information in the database*/
        if(menu ==4)
        {
            cout<<db;
            /*db.printAll();*/
        }
    /*5 Delete an existing record from the database using the accountno as a key*/
        if(menu == 5)
        {
            accountnum = inputaccountnum();
            del = db.deleteRecord(accountnum);
            if(del != 1)
            {
                cout<<"Record not in database \n";
            }
        }
	/*6 reverse list*/
		if(menu == 6 )
		{
			db.reverse();
		}
    /*8 Print all information in the database*/
        if(menu ==7)
        {
           /* cout<<"From copy constructor\n";*/
            cout<<db2;
            /*db2.~llist();
            cout<<"copied list was distroyed\n";
            /*db.printAll();*/
        }
        
    /*7 Quit the program*/    
    }
    
}
