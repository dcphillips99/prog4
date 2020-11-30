////////////////////////////////////////////////////////////////////////////////
//
//      This File: hashTable.c
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
#include "hashTable.h"


unsigned int hash(struct Process entry, int tableSize) {
	
   unsigned int index = 0;

   int newPid = (entry -> pid) * 2;
    
   int newVpn = (entry -> vpn) * 4;

   index = newPid + newVpn;

   index = index % tableSize;

   return index;

}

void insert(struct entry, struct Hash table, int whichOne, K data) {

   if(whichOne == NULL) {

      exit(0); // Need to specify what type of HashTable we are accessing

   }

   int hashValue = hash(entry);
   
   if(whichOne == 0) {

      table -> pageTable[hashValue] = data // UPDATE THIS!!!!!

   }

   if(whichOne == 1) {

      table -> pageFrameTable[hashValue] = data // UPDATE THIS!!!


   }

}

struct PageTable lookupPageTable(struct entry, struct Hash table) {

   int hashVal = hash(entry);
 
   if(table -> whichOne != 0) {

      exit(0);

   }

  struct PageTable foundPageTable = table -> pageTable[hashVal];

  return foundPageTable;


}

struct Page lookUpPageFrame(struct entry, struct Hash table) {

   int hashVal = hash(entry);

   if(table -> whichOne != 1) {

      exit(0);

   }

   struct Page foundPage = table -> pageFrameTable[hashVal];
   
   return foundPage;

}

void delete(struct entry, struct Hash table) {

   int hashVal = hash(entry);

   if(table -> whichOne == 0) {

      table -> pageTable[hashVal] = NULL;

   }

   if(table -> whichOne == 1) {

      table -> pageFrameTable[hashVal] = NULL:

   }

}

struct Hash createHashTable(int tableSize, int whichOne) {
	
   Hash *newHashTable = malloc(sizeof(Hash));

   if(whichOne == 0) {

      newHashTable -> pageTable[tableSize * 2];

      for(int i; i < tableSize; i++) {

         newHashTable -> pageTable[i] = NULL;

      }

      newHashTable -> whichOne = 0;

      return newHashTable;

   }

   if(whichOne == 1) {

      newHashTable -> pageFrameTable[tableSize * 2];

      for(int i = 0; i < tableSize; i++) {

         newHashTable -> pageFrameTable[i] = NULL;

      }
      
      newHashTable -> whichOne = 1;

      return newHashTable;

   }
	   
   return NULL;

}






