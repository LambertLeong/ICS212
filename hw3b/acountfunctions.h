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
// DATE:			JUNE 21, 2016
//
// FILE: 			acountfunctions.h
//
// DESCRIPTION: 	contains the headers for the account
//					functions
//
//****************************************************************/

int addRecord (struct record **, int, char [ ],char [ ],int);
int printRecord (struct record *, int);
int modifyRecord (struct record *, int, char [ ]);
void printAllRecords(struct record *);
int deleteRecord(struct record **, int);

/*created functions*/
void getfield (char address[ ], int );
int charcheck();
int inputaccountnum();
int menuoption();
int inputbirth();
