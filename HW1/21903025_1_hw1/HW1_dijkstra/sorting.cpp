#include "sorting.h"

/*
* Title: Sorting and Algorithm Efficiency
* Author: Utku Kurtulmus
* ID: 21903025
* Section: 1
* Assignment: 1
*/

sorting::sorting()
{
    //ctor
}

sorting::~sorting()
{
    //dtor
}


void sorting:: insertionSort(int *theArray, int n, int &compCount, int &moveCount ) {

    compCount = 0;
    moveCount = 0;

  for (int unsorted = 1; unsorted < n; unsorted++) {

    int nextItem = theArray[unsorted];
    moveCount++;
    int loc = unsorted; //not an array entry

    compCount++;
    for (  ;(loc > 0) && (theArray[loc-1] > nextItem); loc--) {
        compCount++;
        moveCount++;
        theArray[loc] = theArray[loc-1];
    }

    moveCount++;
    theArray[loc] = nextItem;
  }
}

void sorting:: bubbleSort( int *theArray, int n, int &compCount, int &moveCount) {

    compCount = 0;
    moveCount = 0;
    bool sorted = false;

	for (int pass = 1; (pass < n) && !sorted; pass++) {
        sorted = true;

        for (int index = 0; index < n-pass; index++) {
            int nextIndex = index + 1;

            compCount++;
            if (theArray[index] > theArray[nextIndex]) {

                int temp = theArray[index];
                theArray[index] = theArray[nextIndex];
                theArray[nextIndex] = temp;
                moveCount +=3;
                sorted = false; // signal exchange
         }
      }
   }
}


void sorting:: mergeSort(int *arr, const int size, int &compCount, int &moveCount) {

    //call mergesort
    mergesort(arr, 0, size - 1, compCount, moveCount, size);
}

void sorting:: mergesort( int *theArray, int first, int last,  int &compCount, int &moveCount, int size) {


	if (first < last) {

        int mid = (first + last)/2; // index of midpoint

        mergesort(theArray, first, mid, compCount, moveCount, size);
        mergesort(theArray, mid+1, last, compCount, moveCount, size);

      // merge the two halves
      merge(theArray, first, mid, last, compCount, moveCount, size);
   }
}  // end mergesort

void sorting:: merge( int *theArray, int first, int mid, int last,  int &compCount, int &moveCount, int size) {

    int tempArray[size]; //temporary array

	int first1 = first; 	// beginning of first subarray
    int last1 = mid; 		// end of first subarray
    int first2 = mid + 1;	// beginning of second subarray
    int last2 = last;		// end of second subarray
    int index = first1; // next available location in tempArray

    for ( ; (first1 <= last1) && (first2 <= last2); index++) {

        compCount++;
        if (theArray[first1] < theArray[first2]) {
            tempArray[index] = theArray[first1];
            moveCount++;
            first1++;
        }
        else {
            moveCount++;
            tempArray[index] = theArray[first2];
            first2++;
        }
    }

    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, index++) {
        moveCount++;
        tempArray[index] = theArray[first1];
    }

    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, index++) {
        moveCount++;
        tempArray[index] = theArray[first2];
    }

    // copy the result back into the original array
    for (index = first; index <= last; index++) {
        moveCount++;
        theArray[index] = tempArray[index];
    }

}  // end merge


void sorting:: quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    //call quicksort
    quicksort(arr, 0, size - 1, compCount, moveCount);
}

void sorting:: quicksort(int *theArray, int first, int last, int &compCount, int &moveCount) {
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted.

    int pivotIndex;

    if (first < last) {
        // create the partition: S1, pivot, S2
        partition(theArray, first, last, pivotIndex, compCount, moveCount);

        // sort regions S1 and S2
        quicksort(theArray, first, pivotIndex-1, compCount, moveCount);
        quicksort(theArray, pivotIndex+1, last, compCount, moveCount);
    }
}

void sorting:: partition(int *theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    // Precondition: theArray[first..last] is an array; first <= last.
    // Postcondition: Partitions theArray[first..last] such that:
    //   S1 = theArray[first..pivotIndex-1] < pivot
    //   theArray[pivotIndex] == pivot
    //   S2 = theArray[pivotIndex+1..last] >= pivot

    int pivot = theArray[first]; //choose pivot as the first element
    moveCount++;

    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last; ++firstUnknown) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot

        // move item from unknown to proper region
        compCount++;
        if (theArray[firstUnknown] < pivot) {  	// belongs to S1
            ++lastS1;

            int temp = theArray[firstUnknown];
            theArray[firstUnknown] = theArray[lastS1];
            theArray[lastS1] = temp;
            moveCount += 3;

        }	// else belongs to S2
    }
    // place pivot in proper position and mark its location
    int temp = theArray[first];
    theArray[first] = theArray[lastS1];
    theArray[lastS1] = temp;
    moveCount += 3;
    pivotIndex = lastS1;
}

void sorting:: displayArray(const int *arr, const int size) {

    cout << "contents of the array:";

    for(int i = 0; i < size; i++) {
        cout << " " << arr[i];
    }

    cout << endl;
}

void sorting:: createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {

    for(int i = 0; i < size; i++) {
        int randomNumber = rand() % (size); // the range didn't mentioned in the assignment pdf,
                                            //so I choosed the maximum range to be the size of the array (size - 1 actually)
        arr1[i] = randomNumber;
    }

    // now copy arr1
    for(int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }
}

void sorting:: createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {

    for(int i = 0; i < size; i++) {
        arr1[i] = i;
    }

    for(int x = 0; x < size/20; x++) {
        int i = rand() % (size);
        int j = rand() % (size);

        int temp = arr1[i];
        arr1[i] = arr1[j];
        arr1[j] = temp;
    }

    // now copy arr1
    for(int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }

}

void sorting:: createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {

    for(int i = 0; i < size; i++) {
        arr1[i] = size - i - 1;
    }

    for(int x = 0; x < size/20; x++) {
        int i = rand() % (size);
        int j = rand() % (size);

        int temp = arr1[i];
        arr1[i] = arr1[j];
        arr1[j] = temp;
    }

    // now copy arr1
    for(int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }
}

void sorting:: performanceAnalysis() {

    /*
    #include <ctime>
    #include <math.h>
    */

    int keyComp = 0;
    int moveCount = 0;
    int arrSize[] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000};
    double duration;

    //rows indicate arrSize, column 0 indicate time, column 1 keyComp, and column 2 dataMove
    double insertionSortArr[8][3];
    double bubbleSortArr[8][3];
    double mergeSortArr[8][3];
    double quickSortArr[8][3];

    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < 8; i++) {
            //create arrays
            int* arr1 = new int[arrSize[i]];
            int* arr2 = new int[arrSize[i]];
            int* arr3 = new int[arrSize[i]];
            int* arr4 = new int[arrSize[i]];

            //determine which case it is
            if(j == 0) {
                createRandomArrays(arr1,arr2,arr3,arr4, arrSize[i]);
            }
            else if(j == 1) {
                createAlmostSortedArrays(arr1,arr2,arr3,arr4,arrSize[i]);
            }
            else{
                createAlmostUnsortedArrays(arr1,arr2,arr3,arr4,arrSize[i]);
            }

            //insertion sort
            clock_t startTime = clock();
            insertionSort(arr1,arrSize[i], keyComp, moveCount);
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            insertionSortArr[i][0] = duration;
            insertionSortArr[i][1] = keyComp;
            insertionSortArr[i][2] = moveCount;

            keyComp = 0;
            moveCount = 0;

            //bubble sort
            startTime = clock();
            bubbleSort(arr2,arrSize[i], keyComp, moveCount);
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            bubbleSortArr[i][0] = duration;
            bubbleSortArr[i][1] = keyComp;
            bubbleSortArr[i][2] = moveCount;

            keyComp = 0;
            moveCount = 0;

            //merge sort
            startTime = clock();
            mergeSort(arr3,arrSize[i], keyComp, moveCount);
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            mergeSortArr[i][0] = duration;
            mergeSortArr[i][1] = keyComp;
            mergeSortArr[i][2] = moveCount;

            keyComp = 0;
            moveCount = 0;

            //quick sort
            startTime = clock();
            quickSort(arr4,arrSize[i], keyComp, moveCount);
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            quickSortArr[i][0] = duration;
            quickSortArr[i][1] = keyComp;
            quickSortArr[i][2] = moveCount;

            keyComp = 0;
            moveCount = 0;

            //delete the arrays
            delete[] arr1;
            delete[] arr2;
            delete[] arr3;
            delete[] arr4;


            if(i == 7) {
                //print the table
                cout << endl;
                cout << "========================="<< endl;
                //determine which case it is
                if(j == 0) {
                    cout << "CASE: Random Array" << endl;
                }
                else if(j == 1) {
                    cout << "CASE: Almost Sorted Array" << endl;
                }
                else{
                    cout << "CASE: Almost Unsorted Array" << endl;
                }

                cout << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Analysis of Insertion Sort" << endl;
                cout << "ArraySize       ElapsedTime(ms)       compCount       moveCount" << endl;
                for(int x = 0; x < 8; x++) {
                    printf("%d %13.0f %27.0f %15.0f \n", arrSize[x], insertionSortArr[x][0], insertionSortArr[x][1], insertionSortArr[x][2]);

                    /*
                    cout << arrSize[x] << "               " <<  insertionSortArr[x][0];
                    cout << "                  " <<  insertionSortArr[x][1];
                    cout << "          " <<  insertionSortArr[x][2];
                    cout << endl;
                    */
                }

                cout << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Analysis of Bubble Sort" << endl;
                cout << "ArraySize       ElapsedTime(ms)       compCount       moveCount" << endl;
                for(int x = 0; x < 8; x++) {
                    printf("%d %13.0f %27.0f %15.0f \n", arrSize[x], bubbleSortArr[x][0], bubbleSortArr[x][1], bubbleSortArr[x][2]);
                    /*
                    cout << arrSize[i] << "               " <<  bubbleSortArr[x][0];
                    cout << "                  " <<  bubbleSortArr[x][1];
                    cout << "          " <<  bubbleSortArr[x][2];
                    cout << endl;
                    */
                }

                cout << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Analysis of Merge Sort" << endl;
                cout << "ArraySize       ElapsedTime(ms)       compCount       moveCount" << endl;
                for(int x = 0; x < 8; x++) {
                    printf("%d %13.0f %27.0f %15.0f \n", arrSize[x], mergeSortArr[x][0], mergeSortArr[x][1], mergeSortArr[x][2]);
                    /*
                    cout << arrSize[x] << "               " <<  mergeSortArr[x][0];
                    cout << "                  " <<  mergeSortArr[x][1];
                    cout << "          " <<  mergeSortArr[x][2];
                    cout << endl;
                    */
                }

                cout << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Analysis of Quick Sort" << endl;
                cout << "ArraySize       ElapsedTime(ms)       compCount       moveCount" << endl;
                for(int x = 0; x < 8; x++) {
                    printf("%d %13.0f %27.0f %15.0f \n", arrSize[x], quickSortArr[x][0], quickSortArr[x][1], quickSortArr[x][2]);
                    /*
                    cout << arrSize[x] << "               " <<  quickSortArr[x][0];
                    cout << "                  " <<  quickSortArr[x][1];
                    cout << "          " <<  quickSortArr[x][2];
                    cout << endl;
                    */
                }
            }
        }
    }
}

