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


struct Page {

    int ppn;	

    int bit;

    int pageSize;

}
