#include "Heap.h"
/*
* Title: Heaps, Priority Queues
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 3
* Description: myHeap implementation, I made some changes on the given heap implementation on the slides.
*/
// Default constructor
Heap::Heap() : size(0) {

}


bool Heap::heapIsEmpty() const {
	return (size == 0);
}

void Heap::heapInsert(const HeapItemType&newItem) {

    if(heapIsEmpty()) {
        items = new HeapItemType[1];
        items[0] = newItem;
        size = 1;
        return;
    }

	// Place the new item at the end of the heap
	HeapItemType temp[size]; // not dynamically allocated

	for(int i = 0; i < size; i++) {
        temp[i] = items[i];
	}

	delete[] items;
	items = new HeapItemType[size + 1];

    for(int i = 0; i < size; i++) {
        items[i] = temp[i];
	}
	items[size] = newItem;

	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[place].getPriority() > items[parent].getPriority()) ) {
		HeapItemType temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++size;
}

void Heap::heapDelete(HeapItemType& rootItem){
	if (heapIsEmpty())
		cout << "HeapException: Heap empty" << endl;
    else if(size == 1) {
	rootItem = items[0];
        delete[] items;
        size = 0;
    }
	else {
		rootItem = items[0];
		items[0] = items[size - 1];

        HeapItemType temp[size--]; // not dynamically allocated
        for(int i = 0; i < size; i++) {
            temp[i] = items[i];
        }

        delete[] items;
        items = new HeapItemType[size];

        for(int i = 0; i < size; i++) {
            items[i] = temp[i];
        }

		heapRebuild(0);
	}
}

void Heap::heapRebuild(int root) {
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < size ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size) &&
		     (items[rightChild].getPriority() > items[child].getPriority()) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( items[root].getPriority() < items[child].getPriority()) {
			HeapItemType temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
		else if( items[root].getPriority() == items[child].getPriority()) {
            if( items[root].getRequestTime() > items[child].getRequestTime()) {
                HeapItemType temp = items[root];
                items[root] = items[child];
                items[child] = temp;

                // transform the new subtree into a heap
                heapRebuild(child);
            }
            else if(items[root].getRequestTime() == items[child].getRequestTime()) {
                if( items[root].getId() > items[child].getId()) {
                HeapItemType temp = items[root];
                items[root] = items[child];
                items[child] = temp;

                // transform the new subtree into a heap
                heapRebuild(child);
                }
            }
		}
    }
}
