/** 
* Title: Algorithm analysis & Sorting 
* Author : GHULAM AHMED
* ID: 22101001
* Section : 2
* Homework : 1 
* Description : description of your code */ 


#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#include "sorting.cpp"

using namespace std;

void createArrays(int *arr1, int *arr2, int *arr3, int *arr4, int *arr5, int size){
    for (int i = 0; i < size; i++) {
        int random = rand() % size;
        arr1[i] = random;
        arr2[i] = random;
        arr3[i] = random;
        arr4[i] = random;
        arr5[i] = random;
    }
}

template<typename T> void printElement(T t, const int& width){
    cout << left << setw(width) << setfill(' ') << t;
}

void part1(){
    srand(time(NULL));
    int sizes[] = {1000, 5000, 10000, 20000};
    cout << "                      Part 2-b-1: Performance analysis of random integers array" << endl;

    // Iterate through the array sizes
    for (int i = 0; i < 4; i++){
        int size = sizes[i];
        int *arr1 = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];
        int *arr4 = new int[size];
        int *arr5 = new int[size];
        createArrays(arr1, arr2, arr3, arr4, arr5, size);
        int compCount = 0;
        int moveCount = 0;
        clock_t start;
        clock_t end;


        cout << "-------------------------------------------------------------------------------------" << endl;
        printElement(" ", 20);
        printElement("Elapsed time(ns)", 20);
        printElement("Comp. count", 20);
        printElement("Move count", 20);
        cout << endl;
        cout << "Array size: " << size << endl;

        // Insertion sort
        start = clock();
        insertionSort(arr1, size, compCount, moveCount);
        end = clock();
        printElement("Insertion sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;

        // Bubble sort
        compCount = 0;
        moveCount = 0;
        start = clock();
        bubbleSort(arr2, size, compCount, moveCount);
        end = clock();
        printElement("Bubble sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;

        // Merge sort
        compCount = 0;
        moveCount = 0;
        start = clock();
        mergeSort(arr3, size, compCount, moveCount);
        end = clock();
        printElement("Merge sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;
        
        // Quick sort
        compCount = 0;
        moveCount = 0;
        start = clock();
        quickSort(arr4, size, compCount, moveCount);
        end = clock();
        printElement("Quick sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;

        // Hybrid sort
        compCount = 0;
        moveCount = 0;
        start = clock();
        hybridSort(arr5, size, compCount, moveCount);
        end = clock();
        printElement("Hybrid sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        delete [] arr5;
    }
}

void part2(){
    srand(time(NULL));
    int sizes[] = {1000, 5000, 10000, 20000};
    cout << endl;
    cout << endl;
    cout << "           Part 2-b-2: Performance analysis of partially ascending integers array" << endl;

    // Iterate through the array sizes
    for (int i = 0; i < 4; i++){
        int size = sizes[i];
        int *arr1 = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];
        int *arr4 = new int[size];
        int *arr5 = new int[size];
        createArrays(arr1, arr2, arr3, arr4, arr5, size);

        // Partially ascending
        int log2n = log2(size);
        int *temp = new int[log2n];
        for (int j = 0; j < log2n; j++){
            temp[j] = arr1[j];
        }
        random_shuffle(temp, temp + log2n);
        for (int j = 0; j < log2n; j++){
            arr1[j] = temp[j];
        }
        for (int j = 0; j < log2n; j++){
            temp[j] = arr2[j];
        }
        random_shuffle(temp, temp + log2n);
        for (int j = 0; j < log2n; j++){
            arr2[j] = temp[j];
        }
        for (int j = 0; j < log2n; j++){
            temp[j] = arr3[j];
        }
        random_shuffle(temp, temp + log2n);
        for (int j = 0; j < log2n; j++){
            arr3[j] = temp[j];
        }
        for (int j = 0; j < log2n; j++){
            temp[j] = arr4[j];
        }
        random_shuffle(temp, temp + log2n);
        for (int j = 0; j < log2n; j++){
            arr4[j] = temp[j];
        }
        for (int j = 0; j < log2n; j++){
            temp[j] = arr5[j];
        }
        random_shuffle(temp, temp + log2n);
        int compCount = 0;
        int moveCount = 0;
        clock_t start;
        clock_t end;

        delete [] temp;


        cout << "-------------------------------------------------------------------------------------" << endl;
        printElement(" ", 20);
        printElement("Elapsed time(ns)", 20);
        printElement("Comp. count", 20);
        printElement("Move count", 20);
        cout << endl;
        cout << "Array size: " << size << endl;

        // Insertion sort
        start = clock();
        insertionSort(arr1, size, compCount, moveCount);
        end = clock();
        printElement("Insertion sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;

        // Bubble sort
        compCount = 0;
        moveCount = 0;
        start = clock();
        bubbleSort(arr2, size, compCount, moveCount);
        end = clock();
        printElement("Bubble sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;

        // Merge sort
        compCount = 0;
        moveCount = 0;
        start = clock();
        mergeSort(arr3, size, compCount, moveCount);
        end = clock();
        printElement("Merge sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;
        
        // Quick sort
        compCount = 0;
        moveCount = 0;
        start = clock();
        quickSort(arr4, size, compCount, moveCount);
        end = clock();
        printElement("Quick sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;

        // Hybrid sort
        compCount = 0;
        moveCount = 0;
        start = clock();
        hybridSort(arr5, size, compCount, moveCount);
        end = clock();
        printElement("Hybrid sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        delete [] arr5;
    }
}

void part3(){
    srand(time(NULL));
    int sizes[] = {1000, 5000, 10000, 20000};
    cout << endl;
    cout << endl;
    cout << "           Part 2-b-3: Performance analysis of partially descending integers array" << endl;

    // Iterate through the array sizes
    for (int i = 0; i < 4; i++){
        int size = sizes[i];
        int *arr1 = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];
        int *arr4 = new int[size];
        int *arr5 = new int[size];
        createArrays(arr1, arr2, arr3, arr4, arr5, size);

        // Partially descending
        int log2n = log2(size);
        int *temp = new int[log2n];
        for (int j = 0; j < log2n; j++){
            temp[j] = arr1[j];
        }
        sort(temp, temp + log2n, greater<int>());
        for (int j = 0; j < log2n; j++){
            arr1[j] = temp[j];
        }
        for (int j = 0; j < log2n; j++){
            temp[j] = arr2[j];
        }
        sort(temp, temp + log2n, greater<int>());
        for (int j = 0; j < log2n; j++){
            arr2[j] = temp[j];
        }
        for (int j = 0; j < log2n; j++){
            temp[j] = arr3[j];
        }
        sort(temp, temp + log2n, greater<int>());
        for (int j = 0; j < log2n; j++){
            arr3[j] = temp[j];
        }
        for (int j = 0; j < log2n; j++){
            temp[j] = arr4[j];
        }
        sort(temp, temp + log2n, greater<int>());
        for (int j = 0; j < log2n; j++){
            arr4[j] = temp[j];
        }
        for (int j = 0; j < log2n; j++){
            temp[j] = arr5[j];
        }
        sort(temp, temp + log2n, greater<int>());
        for (int j = 0; j < log2n; j++){
            arr5[j] = temp[j];
        }
        delete [] temp;
        

        int compCount = 0;
        int moveCount = 0;
        clock_t start;
        clock_t end;


        cout << "-------------------------------------------------------------------------------------" << endl;
        printElement(" ", 20);
        printElement("Elapsed time(ns)", 20);
        printElement("Comp. count", 20);
        printElement("Move count", 20);
        cout << endl;
        cout << "Array size: " << size << endl;

        // Insertion sort
        start = clock();
        insertionSort(arr1, size, compCount, moveCount);
        end = clock();
        printElement("Insertion sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;

        // Bubble sort
        compCount = 0;
        moveCount = 0;
        start = clock();
        bubbleSort(arr2, size, compCount, moveCount);
        end = clock();
        printElement("Bubble sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;

        // Merge sort
        compCount = 0;
        moveCount = 0;
        start = clock();
        mergeSort(arr3, size, compCount, moveCount);
        end = clock();
        printElement("Merge sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;
        
        // Quick sort
        compCount = 0;
        moveCount = 0;
        start = clock();
        quickSort(arr4, size, compCount, moveCount);
        end = clock();
        printElement("Quick sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;

        // Hybrid sort
        compCount = 0;
        moveCount = 0;
        start = clock();
        hybridSort(arr5, size, compCount, moveCount);
        end = clock();
        printElement("Hybrid sort:", 20);
        printElement((end - start) * 10000 / CLOCKS_PER_SEC, 20);
        printElement(compCount, 20);
        printElement(moveCount, 20);
        cout << endl;
        
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        delete [] arr5;
    }
}

int main(){
    part1();
    part2();
    part3();

    return 0;

}