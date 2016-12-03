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
// DATE:            June 28, 2016
//
// FILE:            iofunctions.c
//
// DESCRIPTION:     Contains two io functions readfile and writefile
//
//*********************************************************************/

#include "project1header.h"

extern int debug;

/*****************************************************************
//
// Function name: readfile
//
// DESCRIPTION: reads records from a .txt file and stores them in 
//              an array of accounts.  Function assumes that record format
//              is as follows:
                    acount number
                    name
                    address!
                    year of birth
//
//              the '!' after address is used to indicate the end of 
//              the address input.  Function also assumes records are complete
// Parameters: struct account accounts[ ]
//             int * numAccounts
//             char filename[ ]
//
// Return values: void
//
//****************************************************************/

int readfile( struct record **start, char filename[ ] )
{
    FILE *file;
    
    int anum, year, i, accountfield, check1, check2, amount, sucess;
    char accounum [20], name [25], address [80], birth[4];

    i = 0;
    accountfield = 0;
    check1 = 0;
    check2 = 0;
    char c = 0;
	amount = 0;
    sucess = 0;
    
    birth[0]='0';
	accounum[0] = '\0';
    
	if (debug == 1)
    {
        printf("\n********DEBUG MODE********\n");
        printf("DEBUG: calling function readFile\nparameters passed\nstruct record is %p\nfilename is in %s\n",&start, filename);
        printf("***************************\n\n");
	}
 
    /*printf("numAccounts is %p\n", *numAccounts);*/
    file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("File does not exists to read\n");
    }
    else
    {
    while((c = fgetc(file)) != EOF)
    {
        if(accountfield == 0)
        {
            
            if(c < '0' || c > '9'|| c=='\n')
            {
				accounum[i] = '\0';
                anum = atoi(accounum);
                accountfield = 1;
                i = 0;
                
            } 
            else
            {
                accounum[i] = c;
                i++;
                /*printf("input read is %c\n",c);*/
            }
        }
        else if(accountfield == 1)
        {
           if(c == '\n' || i > 23)
            {
                name[i]='\0';
                accountfield = 2;
                i = 0;
            } 
            else
            {
                name[i]=c;
                i++;
            } 
        }
        else if(accountfield == 2)
        {
            if(c == '!' || i > 78)
            {
                address[i]='\0';
                accountfield = 3;
                check1=1;
                i = 0;
                
            } 
            else
            {
                address[i] = c;
                i++;
            } 
        }
        else if(accountfield == 3)
        {
            if(i > 4)
            {
                year = atoi(birth);
				/*printf("in read, anum is %d\n",anum);*/
                amount = addRecord(start,  anum, name, address, year);
                /*printf("accountnumber is %d\n", &start->accountno);
				printf("amount is %d\n",amount);*/
                accountfield = 0;
                i = 0;
                accounum[0] = '\0';
                birth[0]='\0';
                check2 = 1;
                sucess =1;
            } 
            else
            {
                birth[i] = c;
                i++;
            } 
        }
    }
    if(check1 == 1 && check2 == 0)
    {
        year = atoi(birth);
        amount += addRecord(start, anum, name, address, year);
        sucess =1;
		/*printf("amount is %d\n",amount);
		printf("accountnumber is %d\n", &start->accountno);*/
    }
    }
    fclose(file);
    return sucess;
}

/*****************************************************************
//
// Function name: writefile
//
// DESCRIPTION: writes records to a .txt file from accounts.  It writes them
//              in the order in which they were input(FIFP).
//              Output format is as follows:
                    acount number
                    name
                    address!
                    year of birth
//              the '!' after address is used to indicate the end of 
//              the address input.
// Parameters: struct account accounts[ ]
//             int numAccounts
//             char filename[ ]
//
// Return values: void
//
//****************************************************************/

void writefile( struct record *start, char filename[ ] )
{
    FILE *fileout;
    
    struct record *current;
    
    fileout = fopen(filename, "w");
    current=start;
    
    if (debug == 1)
    {
        printf("\n********DEBUG MODE********\n");
        printf("DEBUG: calling function writefile\nparameters passed\nstruct record is %p\nfilename is in %s\n",&start, filename);
        printf("***************************\n\n");
	}
    
    while(current != NULL)
    {
        /*printf("entered write file while\n");*/
        fprintf(fileout, "%d\n%s\n%s!\n%d\n", current->accountno, current->name, current->address, current->yearofbirth);
        current=current->next;
    }
    
    fclose(fileout);
}

