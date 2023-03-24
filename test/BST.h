#ifndef BST_H
#define BST_H

#include "BSTNode.h"

class BST{
    public: 
        BST();  
        ~BST();
        void insertItem(int key);
        void deleteItem(int key);
        BSTNode* getItem(int key);
        int* inOrderTraversal(int& length);
        bool hasSequence(int* seq, int length);
    private:
        BSTNode* root;
        BSTNode* findMin(BSTNode *node);
        void deleteTree(BSTNode *node);
        void recursiveInsertion(BSTNode *&node, int key);
        void recursiveDeletion(BSTNode *&node, int key);
        int* recursiveTraversal(BSTNode *node, int& size);
        bool hasSequenceRecursive(int* seq, int length, int& index, BSTNode* node, int min, int max);
}; 

#endif