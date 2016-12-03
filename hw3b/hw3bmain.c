/***********************************************************************
//
// NAME:            Lambert Leong
//
// HOMEWORK:        3b
//
// CLASS:           ICS 212
//
// INSTRUCTOR:      Ravi Narayan
//
// DATE:            June 21, 2016
//
// FILE:            hw3bmain.c
//
// DESCRIPTION:     Contains the main for running the UI in regular and
//					debug
//
//*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "record.h"
#include "acountfunctions.h"

int debug = 0;

int main(int argc, char *argv[])
{
    int start;
    
    if (argc == 1 || (argc == 2 && (strcmp(argv[1], "debug") == 0)))
    {
        if (argc == 2 && (strcmp(argv[1], "debug") == 0))
        {
            debug = 1;
        }
            menuui();
    } 
    else 
    {
        printf("ERROR: command");

        for (start = 0; start < argc; start++)
        {
            printf(" %s", argv[start]);
        }

        printf(" not found\n");
    }
}
