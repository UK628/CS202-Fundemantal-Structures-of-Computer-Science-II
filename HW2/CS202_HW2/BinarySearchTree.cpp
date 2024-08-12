#include "BinarySearchTree.h"

/*
* Title: Trees
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 2
* Description: A Binary Search Tree implementation
*/
BinarySearchTree::BinarySearchTree()
{
    size = 0;
    height = 0;
    root = NULL;
    sorted = NULL;
    index = 0;
}

BinarySearchTree::~BinarySearchTree()
{
    for(int i = 0; i < size; i++) {
        delete sorted[i];
    }

    //delete[] sorted;
}

bool BinarySearchTree:: isEmpty() {
    return (size == 0);
}

int BinarySearchTree:: getHeight() {
    return height;
}

int BinarySearchTree:: getNumberOfNodes() {
    return size;
}

bool BinarySearchTree:: add(int newEntry) {

    //check if the entry is less than or equal to zero
    if (newEntry <= 0) {
        //cout << "ENTRY MUST BE GREATER THAN ZERO!!!!" << endl; //It's commented for analyze part
        return false;
    }


    //check if the entry is already exist
    if(contains(newEntry)) {
        //cout << "Entry : " << newEntry << " is already exist in the tree!"<< endl; //For analyze part, it looks bad on console.
        return false;
    }

    //check if it's the first node we are adding
    if(size == 0) {
        root = new BinaryNode;
        height = 1;
        size = 1;
        root->setData(newEntry);
        sorted = new BinaryNode*[1];
        updateSorted();
        return true;
    }

    BinaryNode* currPtr = root;
    bool done = false;
    while(!done) {
        //check if the item is less than or bigger than the current node
        if(newEntry < currPtr->getData()) {
            //check if left child exist
            if(currPtr->getLeftChild() == NULL) {
                //if left child doesn't exist simply the new node is going to be the left child
                BinaryNode* newNode = new BinaryNode;
                newNode->setData(newEntry);
                currPtr->setLeftChild(newNode);
                done = true;
            }
            else{
                currPtr = currPtr->getLeftChild();
            }
        }
        else {
            //if the item is bigger than the current node
            //we already checked it's not equal at the beginning,
            //so even this else implies bigger than or equal to, two datas cannot be equal

            //check if right child exist
            if(currPtr->getRightChild() == NULL) {
                //if right child doesn't exist simply the new node is going to be the right child
                BinaryNode* newNode = new BinaryNode;
                newNode->setData(newEntry);
                currPtr->setRightChild(newNode);
                done = true;
            }
            else{
                currPtr = currPtr->getRightChild();
            }
        }
    }

    size = root->getSize();
    height = root->getHeight();

    delete[] sorted;
    sorted = new BinaryNode*[size];
    updateSorted();

    return true;
}


bool BinarySearchTree:: remove(int anEntry) {

    BinaryNode* removePtr;

    //get the node of the item if it's exist
    if( !getNode(anEntry, removePtr)) {
        //cout << "Error: the item is not exist!" << endl; //For analyze
        return false;
    }

    //Case 1 a leaf node
    if(removePtr->getLeftChild() == NULL && removePtr->getRightChild() == NULL) {
        BinaryNode* parentPtr = removePtr->getParent();

        //check if parentPtr exist(we are deleting the root)
        if(parentPtr == NULL) {
            delete removePtr;
            height = 0;
            size = 0;
            root = NULL;
            delete[] sorted;
            return true;
        }

        //check if it's left or right child
        if(parentPtr->getRightChild() == removePtr) {
            parentPtr->removeRightChild();
            delete removePtr;

            size = root->getSize();
            height = root->getHeight();
            delete[] sorted;
            sorted = new BinaryNode*[size];
            updateSorted();

            return true;
        }

        parentPtr->removeLeftChild();
        delete removePtr;

        size = root->getSize();
        height = root->getHeight();
        delete[] sorted;
        sorted = new BinaryNode*[size];
        updateSorted();

        return true;
    }

    //Case 2 a node with only one child
    if( (removePtr->getLeftChild() == NULL && removePtr->getRightChild() != NULL)
       || (removePtr->getLeftChild() != NULL && removePtr->getRightChild() == NULL) ) {

        BinaryNode* parentPtr = removePtr->getParent();

        //check if parentPtr exist(we are deleting the root)
        if(parentPtr == NULL) {

            if(removePtr->getLeftChild() == NULL) {
                root = removePtr->getRightChild();
            }
            else {
                root = removePtr->getLeftChild();
            }

            root->setParent(NULL);
            delete removePtr;

            size = root->getSize();
            height = root->getHeight();
            delete[] sorted;
            sorted = new BinaryNode*[size];
            updateSorted();

            return true;
        }

        BinaryNode* theChild;

        if(removePtr->getLeftChild() == NULL) {
            theChild = removePtr->getRightChild();
        }
        else {
            theChild = removePtr->getLeftChild();
        }

        //check if the node is left or right child of the parent
        if(parentPtr->getRightChild() == removePtr) {
            parentPtr->setRightChild(theChild); //the child will replace us
            theChild->setParent(parentPtr); //the node's parent will be parent of it's child
            delete removePtr;

            size = root->getSize();
            height = root->getHeight();
            delete[] sorted;
            sorted = new BinaryNode*[size];
            updateSorted();

            return true;
        }

        parentPtr->setLeftChild(theChild);
        theChild->setParent(parentPtr);
        delete removePtr;

        size = root->getSize();
        height = root->getHeight();
        delete[] sorted;
        sorted = new BinaryNode*[size];
        updateSorted();

        return true;
    }


    //Case 3 a node with two child

    //find the inorder successor
    int itemIndex = select(removePtr->getData());
    BinaryNode* succPtr = sorted[itemIndex + 1];

    int data = succPtr->getData();

    //delete the inorder successor's node
    remove(data);

    //move successor's data to the node that will be removed
    removePtr->setData(data);

    size = root->getSize();
    height = root->getHeight();
    delete[] sorted;
    sorted = new BinaryNode*[size];
    updateSorted();

    return true;
}

bool BinarySearchTree:: getNode(int anEntry, BinaryNode*& item) {

    if(root == NULL) {
        return false;
    }

    BinaryNode* currPtr = root;
    bool done = false;
    while(!done) {
        //check if the item is equal to, less than or bigger than the current node
        if(anEntry == currPtr->getData()) {
           item = currPtr;
           return true;
        }
        else if(anEntry < currPtr->getData()) {
            //check if left child exist
            if(currPtr->getLeftChild() == NULL) {
                done = true;
            }
            else{
                currPtr = currPtr->getLeftChild();
            }
        }
        else {
            //check if right child exist
            if(currPtr->getRightChild() == NULL) {
                done = true;
            }
            else{
                currPtr = currPtr->getRightChild();
            }
        }
    }
    return false;
}



bool BinarySearchTree:: contains(int anEntry) {
    BinaryNode* dummy = NULL;
    return getNode(anEntry, dummy);
}


void BinarySearchTree:: inorderTraverse() {

    for(int i = 0; i < size; i++) {
        cout << sorted[i]->getData() << endl;
    }
}



int BinarySearchTree:: getWidth() {
    return root->calculateWidth();
}

int BinarySearchTree:: count(int a, int b) {

    int result = 0;
    bool done = false;

    for (int i = 0; i < size && !done; i++) {

        if(sorted[i]->getData() >= a && sorted[i]->getData() <= b) {
            result++;
        }

        if(sorted[i]->getData() > b) {
            done = true;
        }

    }

    return result;
}
int BinarySearchTree:: select(int anEntry) {

    //this is actually inorder traversal
    //we store our sorted data by doing inorder traversal
    //we could implement and use binary search since we have the sorted array,
    //but if we didn't use extra space to store sorted order of items we had to do inorder traversal,
    //and count the number of elements upto our node, when we find our node the result is it's index.
    for(int i = 0; i < size; i++) {
        if(anEntry == sorted[i]->getData() ) {
            return i;
        }
    }

    //we couldn't find the item
    return -1;
}


int BinarySearchTree:: successor(int anEntry) {
    int itemIndex = select(anEntry);

    //we couldn't find the item
    if(itemIndex == -1)
        return -1;

    //our item is the last index
    if(itemIndex == size - 1)
        return -2;

    //general case(we found the successor)
        return sorted[itemIndex + 1]->getData();
}

/**
* This function uses inorder traverse, to store the items in sorted order
**/
void BinarySearchTree::inorder(BinaryNode *treePtr) {
		if (treePtr != NULL) {
			inorder(treePtr->getLeftChild());
			storeSorted(treePtr);
			inorder(treePtr->getRightChild());
		}
}

void BinarySearchTree:: storeSorted(BinaryNode* item) {
    sorted[index] = item;
    index++;
}

void BinarySearchTree:: updateSorted() {
    index = 0;
    inorder(root);
}


