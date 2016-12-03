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


struct test
{
    char   sport[2];
    char   dport[2];
    char   sequence[4];
    char   acknum[4];
    char   DRC[2];
    char   window[2];
    char   checksum[2];
    char   urgent[2];
	struct test *start;
};