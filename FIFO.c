////////////////////////////////////////////////////////////////////////////////
//
//      This File: FIFO.c
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


struct Queue_FIFO {

   struct QueueNode *head;   
   
   struct QueueNode *tail;

   int queueSize;


}

struct QueueNode {

struct Process data;

int done;

struct QueueNode *next;


}

struct Queue_FIFO createQueue(){

   struct Queue_FIFO *newQueue = malloc(sizeof(Queue_FIFO));

   newQueue -> head = NULL;
   newQueue -> tail = NULL;

   newQueue -> queueSize = 0;

   return newQueue;

}

struct QueueNode createNode(struct Process entry) {

   struct QueueNode *newNode = malloc(sizeof(QueueNode));

   newNode -> data = entry;
   newNode -> done = 1;
   newNode -> next = NULL;

   return newNode;

}

void enqueue(struct Queue_FIFO *queue, struct QueueNode *node) {

   if(queue -> tail != NULL) {

      queue -> tail -> next = node;

   }

   queue -> tail = node;

   if(queue -> head == NULL) {

      queue -> head = node;

   }

   return;

}

struct QueueNode dequeue(struct Queue_FIFO *queue) {

   if(queue -> head == NULL) { // Check to see if queue is empty
	   
	   exit(0); // Exit if queue is empty

   }

   struct QueueNode *tempNode = queue -> head; // Dequeue the head

   queue -> head = queue -> head -> next; // Set the next node to the front

   if(queue -> head == NULL) { // When no more nodes are available

      queue -> tail = NULL;

   }

   return tempNode;

}

void removePages(struct Queue_FIFO *queue, struct Hash table) {

   struct QueueNode tempNode = queue -> head;

   tempNode


}

void update(struct Queue_FIFO *queue) {

   queue -> head -> done = 0;

}

void schedule(struct Queue_FIFO *queue, struct Process entry) {

   enqueue(queue, createNode(entry));

}

