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
// DATE: JULY 23, 2016
//
// FILE: temp.cpp
//
// DESCRIPTION: This file contains the driver and the user-interface functions
// for Homework 1 – the temperature conversion program
//
//****************************************************************/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int inputint();
int round(int);
void convertFtoC( int, float &);
void printtable(int);

int main()
{
    cout<<"*****************************************************"<<endl;
	cout<<"This program will convert tempurature in Fahrenheit to Celsius"<<endl<<"starting from 0(F) incremening by 5 degrees(F)"<<endl<<"up to a value selected by the user"<<endl<<endl;

	printtable(inputint());
    return 1;
}

/*****************************************************************
//
// Function name: checkint
//
// DESCRIPTION: Insures that user input is a integer value
// greater than 0.  If valid integer inputs are followed by 
//	non integer values, only the valid integer inputs will be
// accepted and the non integer values will be left out
//
// Parameters: void
//
// Return values: The value of the user input
//
//****************************************************************/

int inputint()
{
    int input;
    int correct;
    
    correct = 0;
    
    cout<<"Please enter an integer value greater than zero: ";
	cin >> input;
    while(correct < 1)
    {
        /*cin >> input;*/
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            input =-1;
            cout << "Invalid!" << endl<<"Please enter an INTEGER value"<<endl;
			cin >> input;
        }
        else if (input<=0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid!" << endl<<"Please enter an INTEGER value GREATER than ZERO"<<endl;
            input =-1;
			cin >> input;
        }
        else
        {
            correct = 1;
        }
    }
    input = round(input);
    return input;
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
	if(input %5!=0)
    {
        input = (5 - input % 5) + input;
    }
	return input;
}

/*****************************************************************
//
// Function name: convertFtoC
//
// DESCRIPTION: calculates the temp to C from F for every degree of 5 up to the max
//
// Parameters: max (int) : contains the user input value which is the
// max value to convert
//              ctemp (float&): contains the reference type to the float
//which will store the value of of the degrees in C
//
// Return values: void
//
//****************************************************************/

/*float convertFtoC(int max)*/
void convertFtoC( int max, float &ctemp)
{
	ctemp = (max - 32.00)*(5.00 / 9.00);

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
	float ctemp;
	int ftemp, cap, start; 
    
    /*float & ctempref = ctemp;*/
    cap = max;
	start = 0;
	/*cout<<"ctemp was "<<ctemp<<endl;
    cout<<"ctempref was "<<ctempref<<endl;*/
    cout<<"\nTemperature in F\t  \t Temperature in C\n";
	
	ftemp=start;
	while(ftemp<=cap){
		/*convertFtoC(ftemp,ctempref);*/
        convertFtoC(ftemp,ctemp);
		cout<<"             "<<ftemp<<"                            "<<fixed<<setprecision(2)<<ctemp<<endl;
		ftemp = ftemp+5;
	}
    cout<<"values shown up to "<<max<<" degrees (F)"<<endl;
    /*cout<<"ctemp is now "<<ctemp<<endl;
    cout<<"ctempref is now "<<ctempref<<endl;*/
}


	
