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
// FILE:            myinputfunctions.c
//
// DESCRIPTION:     Contains the menu options for the UI
//
//*********************************************************************/


int charcheck()
    {
        while (getchar()!='\n');
        return 1;
    }
int menuoption()
{
    int menu;
    char c;

    printf("Enter 1 to add new record\nEnter 2 to modify a record\nEnter 3 to print a record\nEnter 4 to print all\nEnter 5 to delete record\nEnter 6 to Quit\n");
    while(((scanf("%d%c", &menu, &c)!=2 || c!='\n') && charcheck()) || 
    menu<1 || menu >6)
    {
        printf("ERROR: Try again.\nEnter integer values from 1 to 6\n");
    }
    return menu; 
}

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

int inputbirth()
{
    int account;
    char c;

	printf("Enter year of birth (eg. 1990)\n");
    while (((scanf("%d%c", &account, &c)!=2 || c!='\n') && charcheck()) || 
    account<1900 || account > 2016)
	{
		
	}
	return account;
}
