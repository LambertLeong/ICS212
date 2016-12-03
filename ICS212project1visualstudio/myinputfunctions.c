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

extern int debug;

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
        if (debug == 1)
        {
            printf("\n********DEBUG MODE********\n");
            printf("Function called: charcheck\nParameters passed:\nvoid\n");
            printf("***************************\n\n");
        }
        while (getchar()!='\n');
        return 1;
    }
    
/*****************************************************************
//
// Function name: menuoption
//
// DESCRIPTION: uses scanf to and the checkcar function to checkchar
//              to insure that input is and int between 1 and 6, 
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

    if (debug == 1)
    {
        printf("\n********DEBUG MODE********\n");
        printf("Function called: menuoption\nParameters passed:\nvoid\n");
        printf("***************************\n\n");
    }
    
    printf("----------------------------\n");
    printf("========MENU OPTIONS========\n");
    printf("----------------------------\n");
    printf("Enter 1 to add new record  |\n");
    printf("Enter 2 to modify a record |\n");
    printf("Enter 3 to print a record  |\n");
    printf("Enter 4 to print all       |\n");
    printf("Enter 5 to delete record   |\n");
    printf("Enter 6 to Quit            |\n");
    printf("----------------------------\n");
    
    while(((scanf("%d%c", &menu, &c)!=2 || c!='\n') && charcheck()) || 
    menu<1 || menu >6)
    {
        printf("ERROR: Try again.\nEnter integer values from 1 to 6\n\n");
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
    
    if (debug == 1)
    {
        printf("\n********DEBUG MODE********\n");
        printf("Function called: inputaccountnum\nParameters passed:\nvoid\n");
        printf("***************************\n\n");
    }
    
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
    
    if (debug == 1)
    {
        printf("\n********DEBUG MODE********\n");
        printf("Function called: inputbirth\nParameters passed:\nvoid\n");
        printf("***************************\n\n");
    }
    
	printf("Enter year of birth (eg. 1990)\n");
    while (((scanf("%d%c", &account, &c)!=2 || c!='\n') && charcheck()) || 
    account<1900 || account > 2016)
	{
		printf("Error: Please enter a year between 1900 and 2016\n");
	}
	return account;
}
