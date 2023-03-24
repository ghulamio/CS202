#ifndef BSTNODE_H
#define BSTNODE_H

class BSTNode{
    public:
        BSTNode();
        BSTNode(const int item, BSTNode* left = nullptr, BSTNode* right = nullptr);
    private:
        int item;
        BSTNode* left;
        BSTNode* right;
        friend class BST;
};

#endif