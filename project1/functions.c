/*****************************************************************
//
// NAME: 			Lambert Leong
//
// HOMEWORK: 		project1
//
// CLASS: 			ICS 212
//
// INSTRUCTOR: 		Ravi Narayan
//
// DATE: 			JUNE 28, 2016
//
// FILE: 			functions.c
//
// DESCRIPTION: 	This file contains the stubs for the account 
//					functions stubs also contain debug outputs
//
//****************************************************************/

#include "project1header.h"

extern int debug;

/*****************************************************************
//
// Function name:   addRecord
//
// DESCRIPTION:     adds a record
//
// Parameters:  *start (record):    start location in heap of database
//              accountno (int):    account number
//              name (char []):     name
//              addres (char []):   address w/ multi lines
//              birthday (int);     birth year
//
// Return values: int
//
//****************************************************************/

int addRecord (struct record **start,  int accountnum, char name[], char address[], int yearofbirth)
{
    struct record *previous, *current, *newrecord;
    int sucess;
    
    newrecord = (struct record *)malloc(sizeof(struct record));
    sucess = 0;
    newrecord->accountno = accountnum;
    strcpy(newrecord->name, name);
    strcpy(newrecord->address, address);
    newrecord->yearofbirth = yearofbirth;
    current = *start;
    previous = NULL;

	/*printf("add start is %p\n",*start);*/

	if (debug == 1)
    {
        printf("\n********DEBUG MODE********\n");
        printf("Called function addRecord\nParameters passed:\nstruct record is %p\naccount number is %d\nname is %s\naddress is %s\nbirth year is %d\n", &start, accountnum, name, address, yearofbirth);
        printf("***************************\n\n");
	}

    
    /*printf("new number to add is %d\n",newrecord->accountno);*/

/*add to an empty list*/
    if(*start == NULL)
    {
        newrecord->next = NULL;
        *start=newrecord;
        sucess = 1;
		/*printf("/add to an empty list/\n");*/
        /*printf("next is %p\n",newrecord->next);*/
    }
    else
    {
        while(current != NULL && sucess == 0)
        {
            /*printf("current acount number is %d\n", current->accountno);*/
            if(newrecord->accountno <= current->accountno)
            {
                newrecord->next = current;
                /*printf("current record is %p\n",current);
                printf("new record next accountno is %d\n",newrecord->next->accountno);*/
/*add to begining*/
                if(previous == NULL)
                {
                    *start=newrecord;
                    sucess = 1;
					/*printf("/add to begining/\n");*/
                    /*printf("next is %p\n",current->next);*/
                }
/*add to in front of*/               
                else
                {
                    previous->next = newrecord;
                    sucess = 1;
					/*printf("/add to in front of/\n");*/
                }
            }
            else if(/*newrecord->accountno > current->accountno &&*/ current->next == NULL)
            {
/*insert between two record or to the end if next field is NULL*/
				/*printf("/insert between two record or to the end if next field is NULL/\n");*/
                /*printf("current acount number is %d\n", current->accountno);*/
                newrecord->next = current->next;
                current->next = newrecord;
                sucess = 1;
            }
/*step or point previous and current to the next node*/  
			else
			{
                /*printf("before move current acount number is %d\n", current->accountno);
                printf("before move next accountno is %d\n",current->next->accountno);
                printf("MOVE\n");*/
				previous = current;
				current=previous->next;
                /*printf("after move current acount number is %d\n", current->accountno);*/
			}
        }
    }
    return sucess;
}

/*****************************************************************
//
// Function name:   printRecord 
//
// DESCRIPTION:     prints a record
//
// Parameters:      *start (record):    start location in heap of database
//                  accountno (int):    account number
//                  
//
// Return values: int
//
//****************************************************************/

int printRecord (struct record *start, int accountno)
{
    int sucess;
    struct record *previous, *current;
    sucess = 0;
    int printaccount;
    printaccount = accountno;
    current = start;
    previous = NULL;
	
    if (debug == 1)
    {
        printf("\n********DEBUG MODE********\n");
        printf("Function called: printRecord\nParameters passed:\nrecord is %p\naccountno is %d\n", start, accountno);
        printf("***************************\n\n");
    }

/*list is empty*/

    if (start == NULL)
    {
        printf("List contains no records\n");
    }

    while(current != NULL)
    {
        if(current->accountno == printaccount)
        {
            printf("Printing records matching account number %d\n",printaccount);
            printf("%d\n%s\n%s\n%d\n",current->accountno,current->name,current->address,current->yearofbirth);
			previous = current;
			current=previous->next;
            sucess = 1;
        }
        else
        {
            previous = current;
			current=previous->next;
        } 
    }
    return sucess;
}

/*****************************************************************
//
// Function name:   modifyRecord
//
// DESCRIPTION:     modifies a record
//
// Parameters:      *start (record):    start location in heap of database
//                  accountno (int):    account number
//                  name (char []):     New name on the account
//
// Return values: void
//
//****************************************************************/

int modifyRecord (struct record *start, int accountno, char name[ ])
{
    int sucess;
    struct record *previous, *current;
    sucess = 0;
    int modifyaccount;
    modifyaccount = accountno;
    current = start;
    previous = NULL;
	
    if (debug == 1)
    {
        printf("\n********DEBUG MODE********\n");
        printf("Function called: modifyRecord\nParameters passed:\nrecord is %p\naccountno is %d\nname is %s\n", start, accountno, name);
        printf("***************************\n\n");
    }

/*list is empty*/

    if (start == NULL)
    {
        printf("List contains no records\n");
    }

    while(current != NULL)
    {
        if(current->accountno == modifyaccount)
        {
            strcpy(current->name, name);
            previous = current;
			current=previous->next;
            sucess = 1;
        }
        else
        {
            previous = current;
			current=previous->next;
        } 
    }
    return sucess;
}

/*****************************************************************
//
// Function name:   printAllRecords 
//
// DESCRIPTION:     prints records
//
// Parameters:      *start (record):    start location in heap of database
//
// Return values: void
//
//****************************************************************/

void printAllRecords(struct record *start)
{
    struct record *previous, *current;
    current = start;
    previous = NULL;
	
    if (debug == 1)
    {
        printf("\n********DEBUG MODE********\n");
        printf("Function called: printAllRecords\nParameters passed:\nrecord is %p\n", start);
        printf("***************************\n\n");
    }

/*list is empty*/

    if (start == NULL)
    {
        printf("List contains no records\n");
    }
    else
    {
        printf("Printing all records\n");
        while(current != NULL)
        {
            printf("%d\n%s\n%s\n%d\n",current->accountno,current->name,current->address,current->yearofbirth);
            previous = current;
            current=previous->next;
        }
    }
}

/*****************************************************************
//
// Function name:   deleteRecord 
//
// DESCRIPTION:     deletes records
//
// Parameters:      *start (record):    start location in heap of database
//                  accountno (int):    account number
//
// Return values: void
//
//****************************************************************/

int deleteRecord(struct record ** start, int accountnum)
{
    struct record *previous, *current, *delete;
    int deleteaccount, sucess;
    
    sucess = 0;
    deleteaccount = accountnum;
    current = *start;
    previous = NULL;
    
    if (debug == 1)
    {
        printf("\n********DEBUG MODE********\n");
        printf("Function called: deletRecord\nParameters passed:\nrecord is %p\naccountno is %d\n", &start, accountnum);
        printf("***************************\n\n");
    }
	
	/*printf("delete start is %p\n",*start);
	printf("start account is %d\n", *start->accountno);
	printf("current account is %d\n", current->accountno);
    
    printf("in delete: account number is %d\n", current->accountno);*/
/*list is empty*/

    if (*start == NULL)
    {
        printf("List contains no records\n");
    }
    else
    {
        while(current != NULL)
        {
            /*printf("enter delete while, acount number at current is %d\n", current->accountno);*/
            if(current->accountno == deleteaccount)
            {
                /*printf("delete match found\n");*/
/*delete only node*/
                if(previous == NULL && current->next == NULL)
                {
                    free(current);
                    current = NULL;
                    *start = NULL;
                    sucess = 1;
                    /*printf("/delete only node/\n");*/
                }
/*delete first node*/
                else if(previous == NULL && current->next != NULL)
                {
                    delete = current;
                    *start = current->next;
                    current = current->next;
                    free(delete);
                    sucess = 1;
                    /*printf("/delete first node/\n");*/
                }
/*delete a node in the middle*/
                else if(previous != NULL)
                {
                    previous->next = current->next;
                    delete = current;
                    current = current->next;
                    free(delete);
                    sucess = 1;
                    /*printf("/delete a node in the middle/\n");*/
                }
            }
            else
            {
/*step previous and current to the next node if not nodes were deleted*/
                previous = current;
                current=previous->next;
            } 
        }
    }
    return sucess;
}


    
