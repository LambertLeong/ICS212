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

#include "cow.h"
using namespace std;
/***********************************************************************
//
// Function name:   cow()
//
// DESCRIPTION:     cow constructor
//
// Parameters:      void      
//
// Return values:   void
//
//*********************************************************************/

cow :: cow()
{
    strcpy(sound,"moo");
    data = data | 0x08;
}

/***********************************************************************
//
// Function name:   cow()
//
// DESCRIPTION:     cow destructor
//
// Parameters:      void      
//
// Return values:   void
//
//*********************************************************************/

cow :: ~cow()
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

void cow :: displaydata()
{
    unsigned char temp;
    temp = data;
    string soundstr(sound);
    cout<<"Cow make the "<<soundstr<<" sound\n";
    if((data & 0x01)==0x01)
    {
        cout<<"Cow can fly\n";
    }
    else
    {
        cout<<"Cow cannot fly\n";
    }
    temp = temp>>1;
    cout<<"Cow have "<<(int)temp<<" legs\n";
}
