////////////////////////////////////////////////////////////////////////////////
//
//      This File: pageTable.c
//      Other Files: 
//      Semsester: CS 537 Fall 2020
//
//      Author(s): Hector Padilla, Dylan Phillips
//      Email: hdpadilla@wisc.edu, dcphillips@wisc.edu
//      CS Login: hector, dylanp
//
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>


struct PageTable {

    struct Hash pageFrames;

    int key; // PID 

    struct PageTable next; // used for "Chained" Buckets in Hashtable 


}

