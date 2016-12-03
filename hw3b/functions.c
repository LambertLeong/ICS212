/*****************************************************************
//
// NAME: 			Lambert Leong
//
// HOMEWORK: 		3b
//
// CLASS: 			ICS 212
//
// INSTRUCTOR: 		Ravi Narayan
//
// DATE: 			JUNE 21, 2016
//
// FILE: 			functions.c
//
// DESCRIPTION: 	This file contains the stubs for the account 
//					functions stubs also contain debug outputs
//
//****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "record.h"

extern int debug;

int addRecord (struct record ** start, int accountno, char name[ ],char address[ ],int birthday)
{
    if (debug == 1){
        printf("Called: addRecord \nPassed:  %p to record, %d to accountno, %s to name, %s to address, %d to birthday\n", &start, accountno, name, address, birthday);
    }
    return 0;
}

int printRecord (struct record *start, int accountno)
{
    if(debug == 1)
    {
       printf("Called: addRecord\nPassed:  %p to record, %d to accountno\n", start, accountno);
    }
    return 0;
}

int modifyRecord (struct record *start, int accountno, char address[ ])
{
    if(debug == 1)
    {
       printf("Called: addRecord\nPassed:  %p to record, %d to accountno, %s to address\n", start, accountno, address);
    }
    return 0;
}

void printAllRecords(struct record *start)
{
    if(debug == 1)
    {
       printf("Called: addRecord\nPassed:  %p to record\n", start);
    }
}

int deleteRecord(struct record **start, int accountno)
{
    if(debug == 1)
    {
       printf("Called: addRecord\nPassed:  %p to record, %d to accountno\n", &start, accountno);
    }
    return 0;
}

    
