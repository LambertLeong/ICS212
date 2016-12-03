/*****************************************************************
//
// NAME: Lambert Leong
//
// HOMEWORK: 2b
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: JUNE 14, 2016
//
// FILE: mainhw2.c
//
// DESCRIPTION: Contains the main function with 3 test cases
// case1:   users first string has an even number of characters
// case2:   users first string has an odd number of characters
// case3:   user enters a null string as the first string
//
//****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "hw2b.h"

main()
{
	printf("\nTEST 1 - string of even length");
	char test1string1 [10] = "even";
	char test1string2 [10] = "hi";
	printf("\nBefore halfstring function:\ntest1string1 = %s test1string2 = %s\n", test1string1, test1string2);
	halfstring(test1string1,test1string2);
	printf("After halfstring function:\ntest1string1 = %s test1string2 = %s\n", test1string1, test1string2);
	
    printf("\nTEST 2 - string of odd length");
    char test2string1 [10] = "odd";
    char test2string2 [10] = "goodbye";
    printf("\nBefore halfstring function:\ntest2string1 = %s test2string2 = %s\n", test2string1, test2string2);
    halfstring(test2string1,test2string2);
    printf("After halfstring function:\ntest2string1 = %s test2string2 = %s\n", test2string1, test2string2);
	
    printf("\nTEST 3 - half of nothing");
	char test3string1 [10] = "";
	char test3string2 [10] = "same";
	printf("\nBefore halfstring function:\ntest3string1 = %s test3string2 = %s\n", test3string1, test3string2);
	halfstring(test3string1,test3string2);
	printf("After halfstring function:\ntest3string1 = %s test3string2 = %s\n", test3string1, test3string2);
	

}
