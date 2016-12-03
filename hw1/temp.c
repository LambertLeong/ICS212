/*****************************************************************
//
// NAME: Lambert Leong
//
// HOMEWORK: 1
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: JUNE 31, 2016
//
// FILE: temp.c
//
// DESCRIPTION: This file contains the driver and the user-interface functions
// for Homework 1 – the temperature conversion program
//
//****************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*****************************************************************
//
// Function name: checkint
//
// DESCRIPTION: Insures that user input is a integer value
// greater than 0
//
// Parameters: void
//
// Return values: The value of the user input
//
//****************************************************************/

int checkint()
{
    int count = 0;
    int maxtemp;
    char c;
    do
    {
        printf("\nEnter an INTEGER value greater than zero: ");

    } while (((scanf("%d%c", &maxtemp, &c)!=2 || c!='\n') && charcheck()) || 
	maxtemp<0);
	
	return maxtemp;
}

/*****************************************************************
//
// Function name: charcheck
//
// DESCRIPTION: checks if there is a char at the current location
//
// Parameters: count void
//
// Return values: 1 : success
//
//****************************************************************/

int charcheck()
{
    while (getchar()!='\n');
    return 1;
}

/*****************************************************************
//
// Function name: round
//
// DESCRIPTION: takes user input and rounds it to the nearest 5
//
// Parameters: input (int) : contains the user input value
//
// Return values: (5 - input % 5) + input
//
//****************************************************************/

int round(int input)
{
	if(input %5==0)
	return input;
	return (5 - input % 5) + input;
}

/*****************************************************************
//
// Function name: convertFtoC
//
// DESCRIPTION: calculates the temp to C from F for every degree of 5 up to the max
//
// Parameters: max (int) : contains the user input value which is the
// max value to convert
//
// Return values: cal
//
//****************************************************************/

float convertFtoC(int max)
{
	float cel;
	float maxf=max;
	cel = 5*(maxf-32)/9;
	/*printf("%d\n",max);
	printf("inside function \n");
	printf("%f\n", cel);*/
	return  cel;
}

/*****************************************************************
//
// Function name: printtable
//
// DESCRIPTION: prints a table for the values until max is reached
//
// Parameters: max (int) : contains the user input value
//
// Return values: void
//
//****************************************************************/

void printtable(int max)
{
	float cel;
	int fah;
	int cap = max;
	int start = 0;
	printf("\nTemperature in F\t  \t Temperature in C\n");
	
	fah=start;
	while(fah<=cap){
		cel=convertFtoC(fah);
		printf("%d\t\t\t\t%f\n",fah,cel);
		fah = fah+5;
	}
}

main(){
	
	int maxtemp;
        int roundmax;
        float celstemp;
	printf("This program will convert tempurature in Fahrenheit to Celsius starting from 0(F), incremening by 5 degrees(F) up to a value selected by the user \n");
	
	maxtemp=checkint();
	/*printf("value saved in maxtemp is \n");
	printf("%d\n",maxtemp);*/

	roundmax = round(maxtemp);
	/*printf("rounded value is now \n");
	printf("%d\n",roundmax);*/

	celstemp = convertFtoC(roundmax);
	/*printf("converted to \n"); 
	printf("%f\n",celstemp);*/
	
	printtable(roundmax);
	printf("valuse shown up until %d(F)\n",roundmax);
}
	
