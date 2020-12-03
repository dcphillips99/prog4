////////////////////////////////////////////////////////////////////////////////
//
//      This File: hashTable.h
//      Other Files:
//      Semsester: CS 537 Fall 2020
//
//      Author(s): Hector Padilla, Dylan Phillips
//      Email: hdpadilla@wisc.edu, dcphillips@wisc.edu
//      CS Login: hector, dylanp
//
////////////////////////////////////////////////////////////////////////////////
#ifndef HASHTABLE_H
#define HASHTABLE_H

struct Process{

    int pid;
    int vpn;

};

struct Entry { // maps the VPN to the PPN

   int vpn; 
   int ppn;

   struct Entry *next; // Bucket for hashtable
   
   int isNext; // boolean value for next var

}

struct Hash {

   struct PageTable **pageTable; // Use 0

   struct Page **pageFrameTable; // Use 1

   struct Entry **invertedPageTable; // Use 2

   int whichOne; // Tells us what hashTable we are using

};

unsigned int hash(struct Process entry, int tableSize);

void insert(struct Process entry, struct Hash table, int whichOne, struct PageTable tablet, struct Page page, struct Entry link); 

struct PageTable lookupPageTable(struct Process entry, struct Hash table);

struct Page lookUpPageFrame(struct Process entry, struct Hash table);

void delete(struct Process entry, struct Hash table);

struct Hash createHashTable(int tableSize, int whichOne); 

#endif

