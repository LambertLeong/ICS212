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
// FILE: 			animal.cpp
//
// DESCRIPTION: 	contains the parent class Animal
//
//****************************************************************/

#include "animal.h"

using namespace std;

/***********************************************************************
//
// Function name:   animal()
//
// DESCRIPTION:     animal constructor
//
// Parameters:      void      
//
// Return values:   void
//
//*********************************************************************/

animal::animal()
{
    sound[0] = '\0';
    data = 0;
}

/***********************************************************************
//
// Function name:   animal()
//
// DESCRIPTION:     animal destructor
//
// Parameters:      void      
//
// Return values:   void
//
//*********************************************************************/

animal :: ~animal()
{
    
}

/***********************************************************************
//
// Function name:   displaydata()
//
// DESCRIPTION:     prints the value of sound, legs, and fly
//
// Parameters:      void      
//
// Return values:   void
//
//*********************************************************************/

/*void animal::displaydata()
{
    cout<<"animal sound is "<<sound<<endl;
    if((data & 0x01) == 0x01)
    {
        cout<<"animal can fly\n";
    }
    else
    {
        cout<<"animal cannot fly\n";
    }
 }*/ 
 
/***********************************************************************
//
// Function name:   displaydata()
//
// DESCRIPTION:     prints the value of sound, legs, and fly
//
// Parameters:      pointer to animal (animal*)     
//
// Return values:   void
//
//*********************************************************************/

void animal::animaldisplaydata(animal * a)
{
    a->displaydata();// Your code goes here...
}
