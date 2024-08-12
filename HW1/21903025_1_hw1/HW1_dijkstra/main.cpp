#include <iostream>
#include "sorting.h"
using namespace std;

/*
* Title: Sorting and Algorithm Efficiency
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 1
* Description: tests insertion,bubble,merge,quick sort algorithms, with the given array in the hw1 assignment.
*/
int main () {

    sorting testObj;
    
    int testArr1[] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    int testArr2[] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    int testArr3[] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    int testArr4[] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    int keyComp = 0;
    int dataMove = 0;


    cout << "=================================" << endl;
    cout << "Calling the insertion sort......" << endl;
    cout << endl;
    testObj.insertionSort(testArr1, 16, keyComp, dataMove);

    cout << "Number of key comparisons: " << keyComp << endl;
    cout << "Number of data moves: " << dataMove << endl;
    testObj.displayArray(testArr1, 16);

    //=====================================================================
    keyComp = 0;
    dataMove = 0;

    cout << "=================================" << endl;
    cout << "Calling the bubble sort......" << endl;
    cout << endl;
    testObj.bubbleSort(testArr2, 16, keyComp, dataMove);

    cout << "Number of key comparisons: " << keyComp << endl;
    cout << "Number of data moves: " << dataMove << endl;
    testObj.displayArray(testArr2, 16);

    //=====================================================================

    keyComp = 0;
    dataMove = 0;

    cout << "=================================" << endl;
    cout << "Calling the merge sort......" << endl;
    cout << endl;
    testObj.mergeSort(testArr3, 16, keyComp, dataMove);

    cout << "Number of key comparisons: " << keyComp << endl;
    cout << "Number of data moves: " << dataMove << endl;
    testObj.displayArray(testArr3, 16);


    //=====================================================================
    keyComp = 0;
    dataMove = 0;

    cout << "=================================" << endl;
    cout << "Calling the quick sort......" << endl;
    cout << endl;
    testObj.quickSort(testArr4, 16, keyComp, dataMove);

    cout << "Number of key comparisons: " << keyComp << endl;
    cout << "Number of data moves: " << dataMove << endl;
    testObj.displayArray(testArr4, 16);
    

    testObj.performanceAnalysis();

    return 0;
}
