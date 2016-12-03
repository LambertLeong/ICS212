/*****************************************************************
//
// NAME: 			Lambert Leong
//
// HOMEWORK:		project1
//
// CLASS: 			ICS 212
//
// INSTRUCTOR: 		Ravi Narayan
//
// DATE: 			JULY 30, 2016
//
// FILE: 			llist.h
//
// DESCRIPTION: 	contains the header for project2
//
//****************************************************************/

#ifndef project2header_H
#define project2header_H
#include <iostream>
#include <iomanip>
#include <string.h>
#include<fstream>
using namespace std;
#include "record.h"
#include "llist.h"

void getfield (char address[ ], int );
int inputaccountnum();
int menuoption();
int inputbirth();
int inputint();
void readbychar (char name[], int cap);

#endif
