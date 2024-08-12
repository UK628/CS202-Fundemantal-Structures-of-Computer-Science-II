#include "BinaryNode.h"

/*
* Title: Trees
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 2
* Description: A Binary Node implementation
*/
BinaryNode::BinaryNode()
{
    data = 0;
    size = 1;
    height = 1;
    leftChild = NULL;
    rightChild = NULL;
    parentPtr = NULL;
}

BinaryNode::~BinaryNode()
{
    //dtor
}

int BinaryNode::getData() {
    return data;
}

void BinaryNode::setData(int value) {
    data = value;
}

int BinaryNode:: getSize() {
    return size;
}

void BinaryNode:: setSize(int value) {
    size = value;
}

int BinaryNode:: getHeight() {
    return height;
}

void BinaryNode:: setHeight(int value) {
    height = value;
}

BinaryNode* BinaryNode:: getLeftChild() {
    return leftChild;
}

void BinaryNode:: setLeftChild(BinaryNode* node) {

    if(node == NULL) {
        cout << "ERROR: nullptr " << endl;
        return;
    }

    if(leftChild != NULL) {
        removeLeftChild();
    }

    //set parent of the node
    node->parentPtr = this;

    leftChild = node;
    //set size
    size = size + node->size;

    //set height
    if (rightChild != NULL) {
        if (rightChild->height > leftChild->height) {
            height = rightChild->height + 1;
        }
        else {
            height = leftChild->height + 1;
        }
    }
    else {
        height = leftChild->height + 1;
    }

    updateParent();
}

BinaryNode* BinaryNode:: getRightChild() {
    return rightChild;
}

void BinaryNode:: setRightChild(BinaryNode* node) {

    if(node == NULL) {
        cout << "ERROR: nullptr " << endl;
        return;
    }

    if(rightChild != NULL) {
        removeRightChild();
    }

    //set parent of the node
    node->parentPtr = this;

    rightChild = node;

    //set size
    size = size + node->size;

    //set height
    if(leftChild != NULL) {
        if (rightChild->height > leftChild->height) {
            height = rightChild->height + 1;
        }
        else {
            height = leftChild->height + 1;
        }
    }
    else {
        height = rightChild->height + 1;
    }

    updateParent();

}

bool BinaryNode:: removeRightChild() {
    if(rightChild == NULL) {
        cout << "ERROR: right child is not exist" << endl;
        return false;
    }

    //size = size - rightChild->size;

    if(leftChild == NULL) {
        height = 1;
        rightChild = NULL;
        size = 1;
        updateParent();
        return true;
    }
    size = 1 + leftChild->size;
    height = 1 + leftChild->height;
    rightChild = NULL;
    updateParent();
    return true;
}

bool BinaryNode:: removeLeftChild() {
    if(leftChild == NULL) {
        cout << "ERROR: left child is not exist" << endl;
        return false;
    }

    //size = size - leftChild->size;

    if(rightChild == NULL) {
        height = 1;
        leftChild = NULL;
        size = 1;
        updateParent();
        return true;
    }

    size = 1 + rightChild->size;
    height = 1 + rightChild->height;
    leftChild = NULL;
    updateParent();
    return true;
}

BinaryNode* BinaryNode:: getParent() {
    return parentPtr;
}

void BinaryNode:: setParent(BinaryNode* node) {
    parentPtr = node;
}

/**
*After a change happened in left or right subtree, parent doesn't know about that
* so we should use this function to update values like, height etc.
* By doing so we will be able to update whole tree, Remember this is only a node, not a tree but I chose to handle
* big problems in the node class.
*/
void BinaryNode:: updateParent() {

    if(parentPtr == NULL)
        return;

    if(this == parentPtr->leftChild) {
        (*parentPtr).setLeftChild(this);
        return;
    }

    (*parentPtr).setRightChild(this);
}

/**
*Calculates the number of nodes at the given level Recursively
*/
int BinaryNode:: calculateNumberOfNodes(int level) {


    if(level > height) {
        return 0;
    }

    int leftSize = 0;
    int rightSize = 0;

    //basecase
    if(level == 1) {
        return 1;
    }

    if(leftChild != NULL) {
        leftSize = (*leftChild).calculateNumberOfNodes(level - 1);
    }

    if(rightChild != NULL) {
        rightSize = (*rightChild).calculateNumberOfNodes(level - 1);
    }

    return leftSize + rightSize;

    return 0;
}

int BinaryNode:: calculateWidth() {

    int currWidth;
    int maxWidth = 1;

    for (int i = 1; i <= height; i++) {

        //calculate the i^th level width
        currWidth = calculateNumberOfNodes(i);

        if(currWidth > maxWidth) {
            maxWidth = currWidth;
        }
    }

    return maxWidth;
}


