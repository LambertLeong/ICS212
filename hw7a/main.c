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

int readfile(char []);

struct tcp bin;

int main()
{
    struct tcp start;
    int read;
    
    read = 0;
	
    read=readbin("test2.bin");
    printf("read is %d\n", read);
    printf("read tcp is %x\n", bin.sport[0]);
	printf("read tcp is %x\n", bin.sport[1]);
    printf("read tcp is %x\n", bin.dport[0]);
	printf("read tcp is %x\n", bin.dport[1]);
    printf("read tcp is %u\n", bin.sequence);
    printf("address of sport %p\n", &bin.sport);
    printf("address of dport %p\n", &bin.dport);
    return 1;
}
