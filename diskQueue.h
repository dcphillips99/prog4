#include "hashTable.h"

#ifndef DISK_QUEUE_H
#define DISK_QUEUE_H
struct PID {
        int pid;
        int vpn;
};

struct diskQueue {

        struct queueNode  * head;
        struct queueNode  * tail;

        int count;
        int init;//checks if queue is initalized

};

struct queueNode {

        int init; //checks if a node is initalized

	struct Process * data;
        struct queueNode * next;
};

int createNode(struct entry param, struct diskQueue * queue);
struct queueNode dequeue(struct diskQueue * queue);
void enqueue(struct queueNode * current, struct diskQueue * queue);
struct diskQueue createQueue(struct queueNode * current, struct diskQueue * queue);


#endif
