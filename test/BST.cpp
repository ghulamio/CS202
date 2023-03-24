#include "BST.h"

#include <iostream>
using namespace std;

BST::BST(){
    root = nullptr;
}

BST::~BST(){
    deleteTree(root);
}

void BST::insertItem(int key){
    recursiveInsertion(root, key);
}

void BST::deleteItem(int key){
    recursiveDeletion(root, key);
}

BSTNode* BST::getItem(int key){
    BSTNode* node = root;
    while (node != nullptr){
        if (key < node->item){
            node = node->left;
        } else if (key > node->item){
            node = node->right;
        } else{
            return node;
        }
    }
    return nullptr;
}

int* BST::inOrderTraversal(int& length){
    length = 0;
    return recursiveTraversal(root, length);
}

bool BST::hasSequence(int* seq, int length){
    int index = 0;
    // Find the min and max in the sequence
    int min = seq[0];
    int max = seq[length-1];

    return hasSequenceRecursive(seq, length, index, root, min, max);
}

bool BST::hasSequenceRecursive(int* seq, int length, int& index, BSTNode* node, int min, int max){
    cout << "Current node: " << node->item << endl;
    cout << "Min value: " << min << endl;
    cout << "Max value: " << max << endl;
    if (node == nullptr){
        return false;
    }
    // Only traverse the left subtree if the current node is greater than the min value
    if (node->item > min){
        if (hasSequenceRecursive(seq, length, index, node->left, min, max)){
            return true;
        }
    }
    // Only traverse the right subtree if the current node is less than the max value
    if (node->item < max){
        if (hasSequenceRecursive(seq, length, index, node->right, min, max)){
            return true;
        }
    }
    // If the current node is equal to the next value in the sequence, increment the index
    if (node->item == seq[index]){
        index++;
        // If the index is equal to the length of the sequence, the sequence was found
        if (index == length){
            return true;
        }
    }
    return false;
}



BSTNode* BST::findMin(BSTNode *node){
    while (node->left != nullptr){
        node = node->left;
    }
    return node;
}

void BST::deleteTree(BSTNode *node){
    if (node != nullptr){
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void BST::recursiveInsertion(BSTNode *&node, int key){
    if (node == nullptr){
        node = new BSTNode(key);
    } else if (key < node->item){
        recursiveInsertion(node->left, key);
    } else if (key > node->item){
        recursiveInsertion(node->right, key);
    }
}

void BST::recursiveDeletion(BSTNode *&node, int key){
    if (node == nullptr){
        return;
    } else if (key < node->item){
        recursiveDeletion(node->left, key);
    } else if (key > node->item){
        recursiveDeletion(node->right, key);
    } else{
        if (node->left == nullptr && node->right == nullptr){
            delete node;
            node = nullptr;
        } else if (node->left == nullptr){
            BSTNode* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr){
            BSTNode* temp = node;
            node = node->left;
            delete temp;
        } else{
            BSTNode* temp = findMin(node->right);
            node->item = temp->item;
            recursiveDeletion(node->right, temp->item);
        }
    }
}

int* BST::recursiveTraversal(BSTNode *node, int& size){
    if (node == nullptr){
        return nullptr;
    }
    int leftSize = 0, rightSize = 0;
    int* left = recursiveTraversal(node->left, leftSize);
    int* right = recursiveTraversal(node->right, rightSize);
    size = leftSize + rightSize + 1;
    int* arr = new int[size];
    for (int i = 0; i < leftSize; i++){
        arr[i] = left[i];
    }
    arr[leftSize] = node->item;
    for (int i = 0; i < rightSize; i++){
        arr[leftSize + i + 1] = right[i];
    }
    delete[] left;
    delete[] right;
    return arr;
}
