/*****************************************************************
//
// NAME: 			Lambert Leong
//
// HOMEWORK:		HW10
//
// CLASS: 			ICS 212
//
// INSTRUCTOR: 		Ravi Narayan
//
// DATE: 			August 8, 2016
//
// FILE: 			cow.h
//
// DESCRIPTION: 	contains the prototypes for cow
//
//****************************************************************/

#ifndef cow_h
#define cow_h

#include "animal.h"
using namespace std;
class cow: public animal
{
    public:   
    cow();
    ~cow();
	void displaydata(); // prints the value of sound and fly 
};

#endif

