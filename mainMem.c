////////////////////////////////////////////////////////////////////////////////
//
//      This File: mainMem.c
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

struct Memory {

   struct Page **mainMemory;

   int index;

   int size; // size of mainMemory entries

   int pageSize;

   int memSize;

}

/*
 * Calculates the size of main memory
 *
 * Params: int pageSize, int memSize
 *
 */
int getMemorySize(int pageSize, int memSize) {

   int calcSize = memSize/pageSize;

   return calcSize;

}

/*
 * Adds a page to the simulated main memory
 *
 * Params: struct Memory *mainMem, struct Page page
 *
 */
int addEntry(struct Memory *mainMem, struct Page page) {

 
 if(mainMem -> index != mainMem -> size) {
   if(mainMem -> mainMemory[mainMem -> index] == NULL) {	

      mainMem -> mainMemory[mainMem -> index] = page;

      mainMem -> index++;

   }else {



   }

}

/*
 * Creates the instance of simulated main memory and
 * intializes it all correctly
 *
 * Params: int pageSize, int memSize
 *
 */
struct Memory createMainMemory(int pageSize, int memSize) {

   struct Memory mainMem = malloc(sizeof(Memory));

   int size = getMemorySize(pageSize, memSize);

   mainMem -> mainMemory[size];

   for(int i = 0; i < size; i++) {

      mainMem -> mainMemory[i] = NULL;


   }

   mainMem -> size = 0;

   mainMem -> index = 0;

   return mainMem; 	


}
