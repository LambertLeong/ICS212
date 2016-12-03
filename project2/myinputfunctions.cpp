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
// FILE:            myinputfunctions.c
//
// DESCRIPTION:     Contains the menu options for the UI
//
//*********************************************************************/

#include "project2header.h"

/*****************************************************************
//
// Function name: menuoption
//
// DESCRIPTION: uses cin function
//              to insure that input is and int between 1 and 7, 
//              this function will be used to navigate the UI menu.
//
//              *if an int is preceeded by any other character upon
//              input, then only the first it will be taken
//
// Parameters:  void 
//
// Return values: int
//
//****************************************************************/
    
int menuoption()
{
    int menu, good;
    char c;
    good = 0;
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: menuoption\nParameters passed:\nvoid\n";
        cout<<"***************************\n\n";
    #endif
    
    cout<<"----------------------------\n";
    cout<<"========MENU OPTIONS========\n";
    cout<<"----------------------------\n";
    cout<<"Enter 1 to add new record  |\n";
    cout<<"Enter 2 to modify a record |\n";
    cout<<"Enter 3 to print a record  |\n";
    cout<<"Enter 4 to print all       |\n";
    cout<<"Enter 5 to delete record   |\n";
	cout<<"Enter 6 to reverse list    |\n";
    cout<<"Enter 7 to Check original  |\n";
    cout<<" from copy constructor     |\n";
    cout<<"Enter 8 to Quit            |\n";
    cout<<"----------------------------\n";
    
	cin >> menu;
    while(good<1)
    {
        if(cin.fail() || menu <1 || menu >8)
        {
            cout<< "ERROR!  Enter an integer betweeen 1 and 8\n";
			cin.clear();
            cin.ignore(10000, '\n');
            cin >> menu;
        }
        else
        {
            good = 1;
        }        
    }
	cin.clear();
    cin.ignore(10000, '\n');
return menu; 
}

/*****************************************************************
//
// Function name: inputaccountnum
//
// DESCRIPTION: uses cin
//              to insure that input is a non-negatice int
//              this function will be used to gather account numbers
//
//              *if an int is preceeded by any other character upon
//              input, then only the first it will be taken
//
// Parameters:  void 
//
// Return values: int
//
//****************************************************************/

int inputaccountnum()
{
    int account, good;
    char c;
	good = 0;
    
    cout<<"Enter account #\n";
	cin>>account;
    
    while (good < 1)
	{
		
        /*account = inputint();
		cout<<"account is "<<account<<endl;*/
        if(cin.fail() || account<1)
        {
            cout<<"Error: Please enter a non-Negative integer, >0 \n";
			cin.clear();
			cin.ignore(10000, '\n');
			cin>>account;
            /*account = inputint();*/
        }
        else
        {
            good = 1;
        }

	}
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: inputaccountnum\nParameters passed:\nvoid\n";
        cout<<"***************************\n\n";
    #endif
    
	cin.clear();
    cin.ignore(10000, '\n');
return account;
}

/*****************************************************************
//
// Function name: inputbirth
//
// DESCRIPTION: uses cin
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
    int account, good;
    char c;
	good = 0;
    
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: inputbirth\nParameters passed:\nvoid\n";
        cout<<"***************************\n\n";
    #endif
    
	cout<<"Enter year of birth (eg. 1990)\n";
	cin>>account;
    while (good < 1)
	{
        if(account<1900 || account > 2016)
        {
            cout<<"Error: Please enter a year between 1900 and 2016\n";
			cin.clear();
            cin.ignore(10000, '\n');
            cin>>account;
        }
        else
        {
            good = 1;
        }
	}
	cin.clear();
    cin.ignore(10000, '\n');
return account;
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
    int exit,index;
    char in, c;
  
    exit = 0;
    index = 0;
    
    #ifdef debug
        cout<<"\n********DEBUG MODE********\n";
        cout<<"Function called: readbychar\nParameters passed:\nname[] location is "<<&name<<"\ncap is "<<cap<<endl;
        cout<<"***************************\n\n";
    #endif
    
    
    while(exit<1)
    {     
        cin.get(c);
		name[index]=c;
        if(name[index] == '\n' || index >= cap)
        {
            if(index >= cap)
            {
                cin.clear();
                cin.ignore(10000, '\n');/*clears input buffer*/
                cout<<"Note! Number of characters exceeded.\nOnly the first 25 char were taken\n\n";
            }
            name[index] = '\0'; /*helps when printing strings*/
            exit=2;
        }
        index++;
    }
}
