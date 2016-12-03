/*****************************************************************
//
// NAME: 			Lambert Leong
//
// HOMEWORK:		7a
//
// CLASS: 			ICS 212
//
// INSTRUCTOR: 		Ravi Narayan
//
// DATE: 			JULY 19, 2016
//
// FILE: 			TCP.h
//
// DESCRIPTION: 	contains the header for the datatype called TCP
//
//****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "tcp.h"

extern struct tcp bin;

int readbin(char filename[ ])
{
    FILE *file;
    
    int i, sucess, loop;
	unsigned char test[20];
	
	loop=0;
    i = 0;
    sucess = 0;

    file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("File does not exists to read\n");
    }
    else
    {
        i=fread(bin.sport, 20, 1, file);
		fread(&test, 20, 1, file);
		printf("size is %d\n",i);
		while(loop<20)
		{
			printf("%x  ", test[loop]);
			loop++;
		}
		printf("\n");
        sucess = 1;
    }
    fclose(file);
    return sucess;
}
