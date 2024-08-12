#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BinaryNode.h"

/*
* Title: Trees
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 2
* Description: A Binary Search Tree header file
*/
class BinarySearchTree
{
    public:

        BinarySearchTree();
        virtual ~BinarySearchTree();

        bool isEmpty();
        int getHeight();
        int getNumberOfNodes();

        bool add(int newEntry);
        bool remove(int anEntry);
        bool contains(int anEntry);
        void inorderTraverse();

        int getWidth();
        int count(int a, int b);
        int select(int anEntry);
        int successor(int anEntry);

        //helper methods
        bool getNode(int anEntry, BinaryNode*& node);
        void inorder(BinaryNode *treePtr);
        void storeSorted(BinaryNode* item);
        void updateSorted();

    private:
        int size; //number of nods
        int height;
        //int width;
        BinaryNode* root;
        BinaryNode** sorted; //an array to keep the sorted order of items, it stores pointers
        int index; //for the sorted array
};

#endif // BINARYSEARCHTREE_H
