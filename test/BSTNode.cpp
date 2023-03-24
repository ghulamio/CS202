#include "BSTNode.h"

BSTNode::BSTNode(){
}

BSTNode::BSTNode(const int item, BSTNode* left, BSTNode* right){
    this->item = item;
    this->left = left;
    this->right = right;
}
