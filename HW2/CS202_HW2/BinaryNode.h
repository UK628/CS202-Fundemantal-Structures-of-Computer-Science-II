#ifndef BINARYNODE_H
#define BINARYNODE_H
using namespace std;
#include <iostream>

/*
* Title: Trees
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 2
* Description: A Binary Node header file
*/
class BinaryNode
{
    public:
        BinaryNode();
        ~BinaryNode();

        int getData();
        void setData(int value);
        int getSize();
        void setSize(int value);
        int getHeight();
        void setHeight(int value);
        BinaryNode* getLeftChild();
        void setLeftChild(BinaryNode* node);
        BinaryNode* getRightChild();
        void setRightChild(BinaryNode* node);
        bool removeLeftChild();
        bool removeRightChild();
        BinaryNode* getParent();
        void setParent(BinaryNode* node);
        void updateParent();
        int calculateNumberOfNodes(int level); //calculates the number of nodes at the given level
        int calculateWidth();



    private:
        int data;
        int size;
        int height;
        BinaryNode* leftChild;
        BinaryNode* rightChild;
        BinaryNode* parentPtr;

};

#endif // BINARYNODE_H
