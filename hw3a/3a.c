/*****************************************************************
//
// NAME: Lambert Leong
//
// HOMEWORK: 2c
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: JUNE 14, 2016
//
// FILE: main.c
//
// DESCRIPTION: Main function that runs test for the username function.
//
//****************************************************************/

#include <stdio.h>
#include <stdlib.h>

main()
{
    int number[] ={1,2,3,4,3,4,3,2,1,5};
    int num = 1;
    int start = 0;
    int size = 10;
    int begin = 0;
    
    printf("array start = ");
    while(begin<size-1)
    {
        printf(" %d ",number[begin]);
        begin++;
    }
    printf("\n");
    begin=0;
   
    while(start<size-1)
    {
        if(number[start]==num)
        {
            int move = start-1;
            
            while(move<size-3)
            {
                number[move+1] = number[move+2];
                move++;
            }
            size--;
        }
        start++;
    }
    printf("final array = ");
    while(begin<size-1)
    {
        printf(" %d ",number[begin]);
        begin++;
    }
    printf("\n");
    begin=0;
}