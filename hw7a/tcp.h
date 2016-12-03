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


struct tcp
{
    unsigned char   sport[2];
    unsigned char   dport[2];
    unsigned char   sequence[4];
    unsigned char   acknum[4];
    unsigned char   DRC[2];
    unsigned char   window[2];
    unsigned char   checksum[2];
    unsigned char   urgent[2];
};
