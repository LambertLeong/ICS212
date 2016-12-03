/***********************************************************************
//
// NAME:            Lambert Leong
//
// HOMEWORK:        project1
//
// CLASS:           ICS 212
//
// INSTRUCTOR:      Ravi Narayan
//
// DATE:            June 28, 2016
//
// FILE:            painting.c
//
// DESCRIPTION:     Contains the recursive function to calculate the
//                  cost of painting 
//
//*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int costofpainting(double length);

int main()
{
	double index, index2;
	
	index = - 1;
	index2 = -.5;
	
	while(index < 201)
	{
		printf("cost to paint road of length %.2f is %d\n", index,costofpainting(index));
		printf("cost to paint road of length %.2f is %d\n", index2,costofpainting(index2));
		index++;
		index2++;
	}
	
    return 1;
}

/*****************************************************************
//
// Function name:   costofpainting
//
// DESCRIPTION:     This function takes in a double for the length
//					of the road and returns the cost to paint a road.
//					If the road is greater than 2 miles the painter hires
//					a 3 subcontractor for $100.  Those subcontractors abides
//					by the same constructs.  If the length of the road is
//					2 miles or less the painters charge $200.  This function 
//					performs the caculation using recursion.
//
// Parameters:      double:  length
//
// Return values: int cost
//
//****************************************************************/

int costofpainting(double length)
{
    int cost;
	cost = -1;
    
    if(length <= 2.00 && length>0)
    {
        cost = 200;
    }
    else if(length > 2)
    {
        cost = 100;
        cost+=costofpainting(length/3);
        cost+=costofpainting(length/3);
        cost+=costofpainting(length/3);
    }
    return cost;
}
