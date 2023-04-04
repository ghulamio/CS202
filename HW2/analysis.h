/**
* Title: Binary Search Trees
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 2
* Description :  HW2 - Binary Search Trees
*/

#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "BST.h"

class analysis{
    public:
        analysis();
        ~analysis();
        void timeAnalysis();
    private:
        BST* tree;
        int* array;
        int length;
        void shuffleArray();
        void printArray();
        void deleteArray();
};

#endif