/**
* Title: Binary Search Trees
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 2
* Description :  HW2 - Binary Search Trees
*/

#include "analysis.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T> void printElement(T t, const int& width){
    cout << left << setw(width) << setfill(' ') << t;
}

analysis::analysis(){
    tree = new BST();
    length = 15000;
    array = new int[length];
    for (int i = 0; i < length; i++){
        array[i] = i;
    }
    shuffleArray();
}

analysis::~analysis(){
    delete tree;
    deleteArray();
}

void analysis::timeAnalysis(){
    cout << endl;
    string linebreak = "-------------------------------------------------------";
    cout << "Part e - Time Analysis of  Binary Search Tree - part 1" << endl;
    cout << linebreak << endl;
    printElement("Tree Size", 20);
    printElement("Time elapsed", 20);
    cout << endl;
    cout << linebreak << endl;
    clock_t start = clock();
    for (int i = 0; i < length; i++){
        tree->insertItem(array[i]);
        if ((i + 1) % 1500 == 0){
            clock_t end = clock();
            double elapsed = double(end - start) / (CLOCKS_PER_SEC/1000);
            printElement(i + 1, 20);
            printElement(elapsed, 8);
            printElement("ms", 5);
            cout << endl;
            // start = clock();
        }
    }
    shuffleArray();
    cout << endl;
    cout << "Part e - Time Analysis of  Binary Search Tree - part 2" << endl;
    cout << linebreak << endl;
    printElement("Tree Size", 20);
    printElement("Time elapsed", 20);
    cout << endl;
    cout << linebreak << endl;
    clock_t start1 = clock();
    for (int i = 0; i < length; i++){
        tree->deleteItem(array[i]);
        if ((i + 1) % 1500 == 0){
            clock_t end1 = clock();
            double elapsed = double(end1 - start1) / (CLOCKS_PER_SEC / 1000);
            printElement(i + 1, 20);
            printElement(elapsed, 8);
            printElement("ms", 5);
            cout << endl;
            // start = clock();
        }
    }
}

void analysis::shuffleArray(){
    for (int i = 0; i < length; i++){
        int random = rand() % length;
        int temp = array[i];
        array[i] = array[random];
        array[random] = temp;
    }
}

void analysis::printArray(){
    for (int i = 0; i < length; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void analysis::deleteArray(){
    delete[] array;
}