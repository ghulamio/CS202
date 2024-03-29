/**
* Title: Binary Search Trees
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 2
* Description :  HW2 - Binary Search Trees
*/

#ifndef BST_H
#define BST_H

#include "BSTNode.h"

class BST{
    public: 
        BST();  
        ~BST();
        void insertItem(int key);
        void deleteItem(int key);
        int* inOrderTraversal(int& length);
        bool hasSequence(int* seq, int length);
    private:
        BSTNode* root;
        BSTNode* findMin(BSTNode *node);
        void deleteTree(BSTNode *node);
        void recursiveInsertion(BSTNode *&node, int key);
        void recursiveDeletion(BSTNode *&node, int key);
        int* recursiveTraversal(BSTNode *node, int& size);
        bool hasSequenceRecursive(int* seq, int* soFar, int& soFarLength, int length, int& index, BSTNode* node);
        void printArray(int* arr, int length);
        void sortArray(int* arr, int length);
}; 

#endif