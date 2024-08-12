#include "BinarySearchTree.h"
#include <stdlib.h>
/*
* Title: Trees
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 2
* Description: Analyze the Binary Tree
*/
void analyzeBST() {


    int* arr = new int[10000];
    BinarySearchTree tree;


    //create random array
    for(int i = 0; i < 10000; i++) {
        int randomNumber = rand() % (10000);

        arr[i] = randomNumber;
    }

    cout<< "Random BST size vs. height (Insertion)" << endl;
    cout<< "----------------------------------------" << endl;


    //insert items to BST, at each 100 iteration print the size and height.
    for(int i = 0; i < 10000; i++) {
        tree.add(arr[i]);

        if( (i+1) % 100 == 0) {
            //print the size and height
            cout << tree.getNumberOfNodes() << " ";
            cout << tree.getHeight() << endl;
        }
    }

    //shuflle the arr
    for(int i = 0; i < 5000; i++) {

        int randomIndex = 5000 + (rand() % (5000));

        //swap arr[i] and arr[random]
        int temp = arr[i];
        arr[i] = arr[randomIndex];
        arr[randomIndex] = temp;
    }

    cout <<endl;
    cout<< "Random BST size vs. height (Deletion)" << endl;
    cout<< "----------------------------------------" << endl;

    //delete items from BST, at each 100 iteration print the size and height.
    for(int i = 0; i < 10000; i++) {
        tree.remove(arr[i]);

        if( (i+1) % 100 == 0) {
            //print the size and height
            cout << tree.getNumberOfNodes() << " ";
            cout << tree.getHeight() << endl;
        }
    }

    delete[] arr;

}

int main() {

    analyzeBST();

    /*
    BinarySearchTree aTree;
    //BinaryNode* test;
    cout << aTree.isEmpty() << endl;
    aTree.add(50);
    cout << aTree.isEmpty() << endl;
    aTree.add(20);
    aTree.add(90);
    aTree.add(10);

    //aTree.getNode(20, test);

    aTree.add(30);
    aTree.add(70);
    aTree.add(80);
    aTree.add(60);
    aTree.add(60);
    //aTree.add(100);


    //aTree.remove(70);


    cout << "The width of the tree: " << aTree.getWidth() <<endl;
    cout << "The height of the tree: " << aTree.getHeight() <<endl;
    cout << "Size of the tree: " << aTree.getNumberOfNodes() <<endl;

    //cout << "Size of the node " << test->getSize() << endl;

    cout << endl;
    aTree.inorderTraverse();

    cout << endl;
    cout << aTree.count(20,60) << endl;
    cout << aTree.count(10,30) << endl;
    cout << aTree.count(35,45) << endl;

    cout<<endl;
    cout << aTree.select(10) << endl;
    cout << aTree.select(50) << endl;
    cout << aTree.select(70) << endl;
    cout << aTree.select(40) << endl;

    cout << endl;
    cout << aTree.successor(10) << endl;
    cout << aTree.successor(50) << endl;
    cout << aTree.successor(70) << endl;
    cout << aTree.successor(40) << endl;
    cout << aTree.successor(90) << endl;
    */
    return 0;
}
