#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


#include "Heap.h"// ADT heap operations
typedef HeapItemType PQItemType;
/*
* Title: Heaps, Priority Queues
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 3
* Description: PQueue
*/
class PriorityQueue {
public:
	// default constructor, copy constructor, and destructor
	// are supplied by the compiler

	// priority-queue operations:
	bool pqIsEmpty() const;
	void pqInsert(const PQItemType& newItem);
	void pqDelete(PQItemType& priorityItem);

private:
	Heap h;
};

#endif // PRIORITYQUEUE_H
