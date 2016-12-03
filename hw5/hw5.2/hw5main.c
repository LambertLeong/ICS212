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

void readfile(struct account [], int *, char []);
void writefile(struct account [], int, char []);

main()
{
    struct account accounts[5];
    int numAccounts;
    int done = 1;
    int slots = sizeof(accounts)/sizeof(accounts[0]);
    int open;
    numAccounts = slots;
    
	printf("numAccounts before is %d\n",numAccounts);
    readfile(accounts, &numAccounts, "inputfile2.txt");
	printf("numAccounts after is %d\n",numAccounts);
    /*printf("address in 0 is %s\n",accounts[0].address);
    printf("name in 0 is %s\n",accounts[0].name);
    printf("address in 1 is %s\n",accounts[1].address);
    printf("name in 1 is %s\n",accounts[1].name);*/
    
    printf("numAccounts is %d\ndone is %d\n",numAccounts,done);

		while((numAccounts > 0)&& done != 0)
		{
			open = slots-numAccounts;
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
				printf("record to add includes: \n%d\n%s%s%d\n",accounts[open].accountno, accounts[open].name, accounts[open].address, accounts[open].yearofbirth);
				numAccounts--;
			}
		}
	
    
}
