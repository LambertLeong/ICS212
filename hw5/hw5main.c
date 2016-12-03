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
// FILE:            hw5main.c
//
// DESCRIPTION:     Contains main and drivers for iofunctions
//
//*********************************************************************/

#include "hw5header.h"

main()
{
    struct account accounts[5];
    int numAccounts;
    int done = 1;
    int slots = sizeof(accounts)/sizeof(accounts[0]);
    int open;
	int populated;
    numAccounts = slots;
    
    readfile(accounts, &numAccounts, "inputfile1.txt");
    readfile(accounts, &numAccounts, "inputfile2.txt");
    open = slots-numAccounts;
	while((open < slots) && done != 0)
	{
        printf("%d more acounts available\n",numAccounts);
		done = menuoption();
		if(done == 1)
		{
			memset(accounts[open].address,0,sizeof(accounts[open].address));
			accounts[open].accountno = inputaccountnum();
			printf("Enter the name on the account\n");
			readbychar(accounts[open].name, 23);
			printf("Enter address\n");
			getfield(accounts[open].address,78);
			accounts[open].yearofbirth = inputbirth();
			open++;
            numAccounts--;
		}
	}
	
	populated = slots - numAccounts; /*sets numAccounts to actual number of accounts populated*/
    writefile(accounts, populated, "output.txt"); 
    readfile(accounts, &numAccounts, "output.txt");
	populated = slots - numAccounts; /*sets numAccounts to actual number of accounts populated*/
	writefile(accounts, populated, "output2.txt");
	
}
