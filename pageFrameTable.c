////////////////////////////////////////////////////////////////////////////////
//
//      This File: pageFrameTable.c
//      Other Files: pid.c, processlist.c
//      Semsester: CS 537 Fall 2020
//
//      Author(s): Hector Padilla, Dylan Phillips
//      Email: hdpadilla@wisc.edu, dcphillips@wisc.edu
//      CS Login: hector, dylanp
//
////////////////////////////////////////////////////////////////////////////////
#include <unistd.h>
#include <stdlib.h>

/*
 * Creates and initializes a new page
 *
 * Params: int id
 *
 */
struct Page newPage(int id) {

   struct Page *newPage = malloc(sizeof(Page));

   newPage -> ppn = id;

   newPage -> bit = 0;

   newPage -> isNext = 0;

   return newPage;


}
