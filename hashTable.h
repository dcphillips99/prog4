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

struct entry{

    int pid;
    int vpn;

};

struct Hash {

   struct PageTable **pageTable; // Use 0

   struct Page **pageFrameTable; // Use 1

   int whichOne; // Tells us what hashTable we are using

};

unsigned int hash(struct Process entry, int tableSize);

void insert(struct entry, struct Hash table, int whichOne, K data); 

struct PageTable lookupPageTable(struct entry, struct Hash table);

struct Page lookUpPageFrame(struct entry, struct Hash table);

void delete(struct entry, struct Hash table);

struct Hash createHashTable(int tableSize, int whichOne); 

#endif

