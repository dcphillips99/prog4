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

struct CLOCK {

   struct CLOCK_NUM **clock;

   struct CLOCK_NUM *current; // Pointer inside clock

};

struct CLOCK_NUM {

   int pid;

   struct Page page;

   int bit;

};

int getSize(int pageSize, int memSize) {

   int newSize = memSize/pageSize;

   return newSize;

}

struct CLOCK_NUM  makeClockEntry(struct Process *entry) {

   struct CLOCK_NUM *newEntry  = malloc(sizeof(CLOCK_NUM));

   newEntry -> pid = entry -> pid

   newEntry -> page = //insert page from pagetable

   newEntry -> bit = 1;

   return newEntry;

}

void evict() {




}

void schedule(struct Process *entry) {

   




}
