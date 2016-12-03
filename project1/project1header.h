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
// DATE:			JUNE 21, 2016
//
// FILE: 			acountfunctions.h
//
// DESCRIPTION: 	contains the headers for the account
//					functions
//
//****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"

void menu(struct record **);

int addRecord (struct record **, int, char [ ],char [ ],int);
int printRecord (struct record *, int);
int modifyRecord (struct record *, int, char [ ]);
void printAllRecords(struct record *);
int deleteRecord(struct record **, int);
int readfile(struct record **, char []);
void writefile(struct record *, char []);

/*created functions*/
void getfield (char address[ ], int );
int charcheck();
int inputaccountnum();
int menuoption();
int inputbirth();
