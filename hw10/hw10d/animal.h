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
// FILE: 			animal.h
//
// DESCRIPTION: 	contains the prototypes for animal
//
//****************************************************************/


#ifndef animal_h
#define animal_h

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class animal
{
	protected:   
	char sound[10];              // contains "moo", "quack"
    unsigned char data;          // 0 - cannot fly, 1 - can fly
                                // number of legs - 3 bits
	public: 
    animal();
    ~animal();
	virtual void displaydata(); // prints the value of sound and fly 
    /*void animaldisplaydata(animal * a); */
};

#endif

