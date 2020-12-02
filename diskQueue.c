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
	int pid;
	int vpn;

	struct queueNode * next;
};

struct diskQueue queue;

/*
 * creates the queue.
 *
 * param: current queue node to be the head
 */
void createQueue(struct queueNode current) {
	queue.head = &current;
	queue.tail = &current;

	queue.count = 1;
	queue.init = 1;
}
/*
 * adds a node to the queue by creating a temp pointer node 
 * and iterating through each node's next node field until 
 * it is null, then setting that next field to the param
 *
 * param: current node to be added
 *
 */
void addNode(struct queueNode current) {
	struct queueNode * tempNode = queue.head;

	while (tempNode->next->init == 1) {
		tempNode = tempNode->next;
	}

	tempNode->next = &current;
	queue.tail = tempNode->next;
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
int createNode(struct PID param) {
	
	struct queueNode tempNode;

	tempNode.pid = param.pid;
	tempNode.vpn = param.vpn;

	if (queue.init != 1) {
		createQueue(tempNode);
		return 0;
	}
	else {
		addNode(tempNode);
		return 0;
	}
}
