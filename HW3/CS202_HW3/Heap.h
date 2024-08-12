#ifndef HEAP_H
#define HEAP_H

#include "Request.h"// definition of Request object
typedef Request HeapItemType;

#include <iostream>
using namespace std;

/*
* Title: Heaps, Priority Queues
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 3
* Description: Heap header
*/
class Heap {
public:
	Heap();				// default constructor
	// copy constructor is supplied by the compiler
	//~Heap() {delete[] items;};

	bool heapIsEmpty() const;
	void heapInsert(const HeapItemType& newItem);
	void heapDelete(HeapItemType& rootItem);

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at
					        // index root into a heap
private:
	HeapItemType* items;	// array of heap items
	int          size;            	// number of heap items
};

#endif // HEAP_H
