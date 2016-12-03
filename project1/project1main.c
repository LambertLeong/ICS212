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
// FILE:            hw3bmain.c
//
// DESCRIPTION:     Contains the main for running the UI in regular and
//					debug
//
//*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "project1header.h"


int debug = 0;

int main(int argc, char *argv[])
{
    int begin;
    struct record *start = NULL;
    
    if (argc == 1 || (argc == 2 && (strcmp(argv[1], "debug") == 0)))
    {
        if (argc == 2 && (strcmp(argv[1], "debug") == 0))
        {
            debug = 1;
            printf("\n********DEBUG MODE********\n");
            printf("Entered debug Mode\n");
            printf("***************************\n\n");
        }
        /*Test file that doesnt exists
        readfile(&start, "fake.txt");*/
		/*printf("in main, before read, start is at is %p\n", start);*/
        readfile(&start, "input.txt");
		/*printf("in main, after read, start is at is %p\n", start);
		printf("account at start is %d\n",start->accountno);*/
        menuui(&start);
		/*printf("in main, before write, start is at is %p\n", start);*/
        writefile(start, "sorted.txt");
    } 
    else 
    {
        for (begin = 0; begin < argc; begin++)
        {
            printf("ERROR: command %s not found\n", argv[begin]);
        }
    }
}
