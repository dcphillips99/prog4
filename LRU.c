#include "hashTable.h"



struct Scheduling_DS * memToDS(struct memory * mainMem) {
	
	struct Scheduling_DS * temp_DS;
	
	struct DS_Node * previous;
	for (int i = 0; i < mainMem->size; ++) {
		
		struct DS_Node * tempNode;
		tempNode->data = mainMem->mainMemory[i];
		
		if (previous->init == 0) {

			previous = tempNode;
			
			temp_DS->head = previous;
			temp_DS->tail = previous;
			temp_DS->size = 1;
		}
		else {
			tempNode->previous = previous;
			previous->next = tempNode;

			temp_DS->tail = tempNode;

			previous = tempNode;

			temp_DS->size++;
		}
	}

	temp_DS->maxSize = mainMem->memSize;

	return temp_DS;




struct Scheduling_DS * createDS(struct Process * param, int maxSize) {

	struct DS_Node * temp;

	struct Page * tempPage;
	tempPage->ppn = param->vpn;
	temp->data = tempPage;
	temp->init = 1;

	struct LRU_List * list = malloc(sizeof(struct LRU_List));

	list->size = 1;
	list->maxSize = maxSize;
	list->head = temp;
	list->tail = temp;

	return list;
}

void addEntry(struct process * param, struct Memory * mainMem) {

	struct DS_Node * temp = (memToDS(mainMem))->head;
	
	int found = 0;
	while (temp->init != INIT_VALUE && found != 1) {

		if (temp->data->ppn != param->ppn) {

			temp = temp->next;

		}

		else {

			found = 1;
			break;
		}
	}

	if (found == 1) {
			
		return;
	
	}
	
	else {

		if (list->size == list->maxSize) {
			
			temp = list->tail->previous;
			list->tail->init = 0;

			int i = 0;
			while (temp->previous->init != 0) {
				
				temp->next = temp;
				
				if (i == 0) {

					list->tail = temp;
					++i;
				}

				temp = temp->previous;
			}

			struct LRU_Node * newHead;
			newHead->data = param;
			newHead->next = temp;
			list->head = newHead;

		}

		else {
			temp = list->tail;

			while (temp->init != 0) {
				
				temp->next = temp;
				temp = temp->previous;

			}

			struct LRU_Node * newHead;
			newHead->data = param;
			newHead->next = temp;
			list->head = newHead;
			list->size++;
		}
				
	}
}
