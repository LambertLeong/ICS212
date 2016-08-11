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

#include "bird.h"
using namespace std;
/***********************************************************************
//
// Function name:   bird()
//
// DESCRIPTION:     bird constructor
//
// Parameters:      void      
//
// Return values:   void
//
//*********************************************************************/

bird :: bird()
{
    strcpy(sound,"quack");
    data = data | 0x05;
}

/***********************************************************************
//
// Function name:   bird()
//
// DESCRIPTION:     bird destructor
//
// Parameters:      void      
//
// Return values:   void
//
//*********************************************************************/

bird :: ~bird()
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

void bird :: displaydata()
{
    unsigned char temp;
    temp = data;
    string soundstr(sound);
    cout<<"Bird make the "<<soundstr<<" sound\n";
    if((data & 0x01)==0x01)
    {
        cout<<"Bird can fly\n";
    }
    else
    {
        cout<<"Bird cannot fly\n";
    }
    temp = temp>>1;
    cout<<"Bird have "<<(int)temp<<" legs\n";
}

/***********************************************************************
//
// Function name:   clipwings()
//
// DESCRIPTION:     clips the birds wings
//
// Parameters:      void      
//
// Return values:   void
//
//*********************************************************************/

void bird :: clipwings()
{
    data = data & 0x14;
}
