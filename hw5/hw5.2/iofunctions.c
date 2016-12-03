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

void readfile( struct account accounts[ ], int * numAccounts, char filename[ ] )
{
    FILE *file;
    
    int anum;
    char accounum [20];
    char name [25];
    char address [80];
    char birth[4];
    int year;
    int currenta=0;
    int i = 0;
    int accountfield;
    /*int c;*/
    char c;
    
    /*printf("numAccounts is %d\n",*numAccounts);*/
    file = fopen(filename, "r");
    while((*numAccounts > 0) && (c = fgetc(file)) != EOF)
    {
        if(accountfield == 0)
        {
            if(c < '0' || c > '9'|| c=='\n')
            {
                accounts[currenta].accountno = atoi(accounum);
                accountfield = 1;
                /*printf("accountfield is %d, anum done\n",accountfield);*/
                i = 0;
            } 
            else
            {
                accounum[i] = c;
                /*printf("else: accounum is %s\n",accounum);*/
                i++;
            }
        }
        else if(accountfield == 1)
        {
           if(c == '\n' || i > 23)
            {
                /*strcpy(accounts[currenta].name,name);*/
                accounts[currenta].name[i]='\n';
                accounts[currenta].name[i+1]='\0';
                accountfield = 2;
                /*printf("accountfield is %d name done\n",accountfield);*/
                i = 0;
            } 
            else
            {
                accounts[currenta].name[i]=c;
                /*name[i] = c;
                printf("name [] is %c\n",name[i]);
                printf("c is %c\n",c);*/
                i++;
            } 
        }
        else if(accountfield == 2)
        {
            if(c == '!' || i > 78)
            {
                /*strcpy(accounts[currenta].address,address);
                accounts[currenta].address[i]='!';*/
                accounts[currenta].address[i]='\n';
                accounts[currenta].address[i+1]='\0';
                accountfield = 3;
                /*printf("accountfield is %d address done\n",accountfield);*/
                i = 0;
            } 
            else
            {
                accounts[currenta].address[i] = c;
                /*address[i] = c;*/
                i++;
            } 
        }
        else if(accountfield == 3)
        {
            if(i > 4)
            {
                accounts[currenta].yearofbirth = atoi(birth);
                accountfield = 0;
                /*printf("numAccounts before dec is %d\n",*numAccounts);*/
                (*numAccounts)--;
                accountfield = 0;
                /*c = fgetc(file);*/
                i = 0;
                /*anum = atoi(accounum);        
                year = atoi(birth);  
                printf("anum is %d\n",anum);
                printf("name is %s\n",name);
                printf("address is %s\n",address);
                printf("bday is %d\n",year);        
                accounum [0] ='\0';
                name [11] ='\0';
                address [0] ='\0';
                birth [0] = '\0';*/
                printf("%d\n%s%s%d\n",accounts[currenta].accountno, accounts[currenta].name, accounts[currenta].address, accounts[currenta].yearofbirth);
                currenta++;
               /* printf("accountfield is %d bday done\n",accountfield);
                printf("numAccounts is %d\n",*numAccounts);*/
            } 
            else
            {
                birth[i] = c;
                i++;
            } 
        }
    }
    
    fclose(file);

}

void writefile( struct account accounts[ ], int numAccounts, char filename[ ] )
{
    
}

