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
// FILE: 			bird.h
//
// DESCRIPTION: 	contains the prototypes for bird
//
//****************************************************************/

#ifndef bird_h
#define bird_h

#include "animal.h"
using namespace std;
class bird: public animal
{
    public:   
    bird();
    ~bird();
    void clipwings();
	void displaydata(); // prints the value of sound and fly 
};

#endif
