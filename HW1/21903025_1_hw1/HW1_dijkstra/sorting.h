#ifndef SORTING_H
#define SORTING_H
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdio>


/*
* Title: Sorting and Algorithm Efficiency
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 2
* Assignment: 1
*/
class sorting
{
    public:
        sorting();
        ~sorting();

    //sorting functions
    void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
    void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
    void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
    void quickSort(int *arr, const int size, int &compCount, int &moveCount);

    //additional functions for merge and quicksort
    void mergesort( int *theArray, int first, int last, int &compCount, int &moveCount, int size);
    void merge( int *theArray, int first, int mid, int last, int &compCount, int &moveCount, int size);

    void quicksort(int *theArray, int first, int last, int &compCount, int &moveCount);
    void partition(int *theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount);

    //array initializer functions and print array function
    void displayArray(const int *arr, const int size);
    void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
    void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
    void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
    void performanceAnalysis();

    private:
        //no data
};

#endif // SORTING_H
