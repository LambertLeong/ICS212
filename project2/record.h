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
// FILE: 			record.h
//
// DESCRIPTION: 	contains the header for the datatype called record
//
//****************************************************************/


struct record
{
    int              accountno;
    char             name[25];
    char             address[80];
    int              yearofbirth;
    struct record*   next;

};
