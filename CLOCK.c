////////////////////////////////////////////////////////////////////////////////
//
//      This File: CLOCK.c
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

struct Scheduling_DS {

   struct CLOCK_NUM **clock;

   struct CLOCK_NUM *current; // Pointer inside clock

};

struct DS_Node {

   int pid;

   struct Page page;

   int bit;

};

/*
 * Gets the size of the main memory
 *
 * Params: int pageSize, int memSize
 *
 */
int getSize(int pageSize, int memSize) {

   int newSize = memSize/pageSize;

   return newSize;

}

/*
 * Creates a clock entry to be scheduled
 *
 *
 * Params: struct Process *entry
 *
 */
struct CLOCK_NUM  makeClockEntry(struct Process *entry) {

   struct CLOCK_NUM *newEntry  = malloc(sizeof(CLOCK_NUM));

   newEntry -> pid = entry -> pid

   newEntry -> page = //insert page from pagetable

   newEntry -> bit = 1;

   return newEntry;

}

/*
 * Creates the instance of the clock to keep
 * track of processes pages and schedules them
 * inside the clock.
 *
 * Params: int pageSize, int memSize
 *
 */
struct CLOCK createClock(int pageSize, int memSize) {

   struct CLOCK newClock = malloc(sizeof(CLOCK));

   int size = getSize(pageSize, memSize);

   newClock -> clock[size];

   for(int i = 0; i < size; i++) {

      newClock -> clock[i] = NULL;

   } 

   newClock -> current = NULL;

   return newClock;

}

/*
 * Schedules a clock entry into a clock
 *
 * Params: struct Process *entry
 *
 */
void schedule(struct Process *entry) {



   




}
