#include "PriorityQueue.h"
/*
* Title: Heaps, Priority Queues
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 3
* Description: Priority Queue
*/
bool PriorityQueue::pqIsEmpty() const {
	return h.heapIsEmpty();
}

void PriorityQueue::pqInsert(const PQItemType& newItem){
    h.heapInsert(newItem);
}

void PriorityQueue::pqDelete(PQItemType& priorityItem) {
		h.heapDelete(priorityItem);
}
