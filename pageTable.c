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

    int isNext; // boolean var for status of next variable

    struct Process vpnList; // keeps track of vpns of specified PID.

    int isLink;

}

/*
 * Creates and initializes a new page table
 *
 o*
 * Params: int size, int pid
 *
 */
struct PageTable createPageTable(int size, int pid) {

   struct PageTable *newPageTable = malloc(sizeof(PageTable));

   newPageTable -> pageFrames = createHashTable(size, 1);

   newPageTable -> key = pid;

   newPageTable -> isNext = 0;

   newPageTable -> isLink = 0;

   return newPageTable;

}

