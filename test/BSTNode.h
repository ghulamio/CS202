/**
* Title: Binary Search Trees
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 2
* Description :  HW2 - Binary Search Trees
*/

#ifndef BSTNODE_H
#define BSTNODE_H

class BSTNode{
    public:
        BSTNode(const int item, BSTNode* left = nullptr, BSTNode* right = nullptr);
    private:
        int item;
        BSTNode* left;
        BSTNode* right;
        friend class BST;
};

#endif