#include "hashTable.h"

const int INIT_VALUE = 0;

struct LRU_List {

	struct LRU_Node * head;
	struct LRU_Node * tail;

	int size;
	int maxSize;
};

struct LRU_Node {

	struct Process * data;
	
	struct LRU_Node * next;
	struct LRU_Node * previous;
	
	int init = INIT_VALUE;
};

struct LRU_List createLRU(struct Process * param, int maxSize) {

	struct LRU_Node * temp;
	temp->data = param;
	temp->init = 1;

	struct LRU_List * list = malloc(sizeof(struct LRU_List));

	list->size = 1;
	list->maxSize = maxSize;
	list->head = temp;
	list->tail = temp;

	return list;
}

void addEntry(struct process * param, struct LRU_List * list) {

	struct LRU_Node * temp = list->head;
	
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
