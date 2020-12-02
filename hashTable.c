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

/*
 * This functions serves as our hash function to retrieve
 * hash index of our desired placement in the hash table.
 *
 * Params: struct Proccess entry, int tableSize
 *
 */
unsigned int hash(struct Process entry, int tableSize) {
	
   unsigned int index = 0; // Assures no negative value

   int newPid = (entry -> pid) * 2;
    
   int newVpn = (entry -> vpn) * 4;

   index = newPid + newVpn;

   index = index % tableSize;

   return index; 

}

/*
 * Function to insert into a desired hashtable
 *
 * Params: struct Process entry, struct Hash table, int whichOne,
 *       struct PageTable tablet, struct Page page
 *
 */
void insert(struct Process entry, struct Hash table, int whichOne, struct PageTable tablet, struct Page page) {

   if(whichOne == NULL) {

      exit(0); // Need to specify what type of HashTable we are accessing

   }

   int hashValue = hash(entry);
   
   if(whichOne == 0) { // accesses the PageTable type hashtable

      if(table -> pageTable[hashValue] == NULL) { // if entry is empty

         table -> pageTable[hashValue] = tablet;

      }else { // When collisions occur

         table -> pageTable[hashValue] -> next = tablet;

      }

   }

   if(whichOne == 1) { // accesses the Page type hashtable.

      if(table -> pageFrameTable[hashValue] == NULL) { // if entry is empty

         table -> pageFrameTable[hashValue] = page;

      }else { // When collisions occur

         table -> pageFrameTable[hashValue] -> next = page;


      }


   }

}

/*
 * Returns desired PageTable when given a key
 *
 *
 * Params: struct Process entry, struct Hash table
 *
 */
struct PageTable lookupPageTable(struct Process entry, struct Hash table) {

   int hashVal = hash(entry);
 
   if(table -> whichOne != 0) { // Ensures we don't acess wrong hashtable

      exit(0); 

   }

  struct PageTable foundPageTable = table -> pageTable[hashVal];

  return foundPageTable;


}

/*
 * Returns the desired page within a pageTable
 *
 *
 * Params: struct Process entry, struct Hash table
 *
 */
struct Page lookUpPageFrame(struct Process entry, struct Hash table) {

   int hashVal = hash(entry);

   if(table -> whichOne != 1) { // Ensures we don't access wrong hashtable

      exit(0);

   }

   struct Page foundPage = table -> pageFrameTable[hashVal];
   
   return foundPage;

}

/*
 * Deletes an entry in a hashtable and replaces it with NULL
 *
 * Params: struct Process entry, struct Hash table
 *
 */
void delete(struct Process entry, struct Hash table) {

   int hashVal = hash(entry);

   if(table -> whichOne == 0) { // Specifes which hashtable to access

      table -> pageTable[hashVal] = NULL;

   }

   if(table -> whichOne == 1) {

      table -> pageFrameTable[hashVal] = NULL:

   }

}

/*
 * Creates a hashtable when given the size and specifier of which type
 * of hashtable.
 *
 * Specifier:
 * 0 = PageTable type
 * 1 = Page type
 *
 * Params: int tableSize, int whichOne
 *
 */
struct Hash createHashTable(int tableSize, int whichOne) {
	
   struct Hash *newHashTable = malloc(sizeof(Hash)); // Creation of Hash struct

   if(whichOne == 0) { // Creates PageTable type hashtable

      newHashTable -> pageTable[tableSize * 2];

      for(int i; i < tableSize; i++) {

         newHashTable -> pageTable[i] = NULL; // Initializing elements to NULL

      }

      newHashTable -> whichOne = 0; // Setting specifier value to correspond to PageTable type

      return newHashTable;

   }

   if(whichOne == 1) { // Createas Page type hashtable

      newHashTable -> pageFrameTable[tableSize * 2];

      for(int i = 0; i < tableSize; i++) {

         newHashTable -> pageFrameTable[i] = NULL; // Intializing elements to NULL

      }
      
      newHashTable -> whichOne = 1; // Setting specifier value to correspond to Page type

      return newHashTable;

   }
	   
   return NULL; // Returns NULL upon failure

}






