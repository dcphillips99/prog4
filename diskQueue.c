////////////////////////////////////////////////////////////////////////////////
//
//      This File: diskQueue.c
//      Other Files: pid.c, processlist.c
//      Semsester: CS 537 Fall 2020
//
//      Author(s): Hector Padilla, Dylan Phillips
//      Email: hdpadilla@wisc.edu, dcphillips@wisc.edu
//      CS Login: hector, dylanp
//
////////////////////////////////////////////////////////////////////////////////

#include "diskQueue.h"
#include "hashTable.h"
#include "LRU.h"

/*
 * creates the queue.
 *
 * param: current queue node to be the head
 */
struct diskQueue createQueue(struct queueNode * current, struct diskQueue * queue) {
	queue->head = current;
	queue->tail = current;

	queue->count = 1;
	queue->init = 1;
}
/*
 * adds a node to the queue by creating a temp pointer node 
 * and iterating through each node's next node field until 
 * it is null, then setting that next field to the param
 *
 * param: current node to be added
 *
 */
void enqueue(struct queueNode * current, struct diskQueue * queue) {
	
	queue->tail->next = current;
	queue->tail = current;
	queue->count = queue->count++;
}
/*
 * When diskQueue dequeues it will push the head node
 * off the top and return it, while also sending it
 * to be scheduled in the proper scheduling algorithm
 *
 */
struct queueNode * dequeue(struct diskQueue * queue) {
	
	struct queueNode * temp = queue->head;
	queue->head = queue->head->next;

	return temp;
}

/*
 * Param: the struct of which holds the pid/vpn
 *
 * CreateNode takes the PID struct with the vpn and pid and
 * inputs its data into the queueNode struct to be put in the 
 * queue. Either the queue isn't initialized, and we need to make
 * the queue with the first node, or we must add the node to the 
 * end of the queue.
 *
 */
int createNode(struct Process * param, struct diskQueue * queue) {
	
	struct queueNode * tempNode;

	tempNode->data = param;

	if (queue->init != 1) {
		createQueue(tempNode);
		return 0;
	}
	else {
		enqueue(tempNode);
		return 0;
	}
}
