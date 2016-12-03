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
// FILE:            iofunctions.c
//
// DESCRIPTION:     Contains two io functions readfile and writefile
//
//*********************************************************************/

#include "hw5header.h"

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

void readfile( struct account accounts[ ], int * numAccounts, char filename[ ] )
{
    FILE *file;
    
    int anum;
    char accounum [20];
    char name [25];
    char address [80];
    char birth[4];
    int year;
    int currenta=(5-*numAccounts);
    int i = 0;
    int accountfield;
    int check1 = 0;
    int check2 = 0;
    char c = 0;
	
    accountfield=0;
    
    file = fopen(filename, "r");
    while((*numAccounts > 0) && (c = fgetc(file)) != EOF)
    {
        
        if(accountfield == 0)
        {
            
            if(c < '0' || c > '9'|| c=='\n')
            {
                accounts[currenta].accountno = atoi(accounum);
                accounum[0] = '0';
                accountfield = 1;
                i = 0;
            } 
            else
            {
                accounum[i] = c;
                i++;
            }
        }
        else if(accountfield == 1)
        {
           if(c == '\n' || i > 23)
            {
                accounts[currenta].name[i]='\0';
                accountfield = 2;
                i = 0;
            } 
            else
            {
                accounts[currenta].name[i]=c;
                i++;
            } 
        }
        else if(accountfield == 2)
        {
            if(c == '!' || i > 78)
            {
                accounts[currenta].address[i]='\0';
                accountfield = 3;
                check1=1;
                i = 0;
                
            } 
            else
            {
                accounts[currenta].address[i] = c;
                i++;
            } 
        }
        else if(accountfield == 3)
        {
            if(i > 4)
            {
                accounts[currenta].yearofbirth = atoi(birth);
                accountfield = 0;
                (*numAccounts)--;
                i = 0;
                birth[0]='\0';
                check2 = 1;
                currenta++;
            } 
            else
            {
                birth[i] = c;
                i++;
            } 
        }
    }
    if(check1 == 1 && check2 == 0 && (*numAccounts > 0))
    {
        accounts[currenta].yearofbirth = atoi(birth);
        (*numAccounts)--;
    }
    fclose(file);
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

void writefile( struct account accounts[ ], int numAccounts, char filename[ ] )
{
    FILE *fileout;
    fileout = fopen(filename, "w");
    int currentrecord = 0;

    
    while(currentrecord<numAccounts)
    {
        fprintf(fileout, "%d\n%s\n%s!\n%d\n", accounts[currentrecord].accountno, accounts[currentrecord].name, accounts[currentrecord].address, accounts[currentrecord].yearofbirth);
        currentrecord++;
    }
    
    fclose(fileout);
}

