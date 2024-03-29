/**
* Title: Binary Search Trees
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 2
* Description :  HW2 - Binary Search Trees
*/

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

int* BST::inOrderTraversal(int& length){
    length = 0;
    return recursiveTraversal(root, length);
}

bool BST::hasSequence(int* seq, int length){
    int index = 0;
    int* soFar = new int[length];
    int soFarLength = 0;

    bool returnVal = hasSequenceRecursive(seq, soFar, soFarLength, length, index, root);
    delete[] soFar;
    return returnVal;
}

void BST::printArray(int* arr, int length){
    cout << endl << "Array: ";
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void BST::sortArray(int* arr, int length){
    for (int i = 0; i < length; i++){
        for (int j = i + 1; j < length; j++){
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

bool BST::hasSequenceRecursive(int* seq, int* soFar, int& soFarLength, int length, int& index, BSTNode* node){
    if (node == nullptr){ 
        return false;
    }

    cout << node->item << " ";

    if (node->item != root->item){
        bool alreadyInSoFar = false;
        for (int i = 0; i < soFarLength; i++){
            if (soFar[i] == node->item){
                alreadyInSoFar = true;
                break;
            }
        }
        if (!alreadyInSoFar){
            soFar[soFarLength] = node->item;
            soFarLength++;
        }
    }


    // Traverse left subtree if current node is greater than min value in sequence
    if (index < length && node->item > seq[index]){
        if (hasSequenceRecursive(seq, soFar, soFarLength, length, index, node->left)){
            return true;
        }
    }

    // Check if current node is equal to current value in sequence
    if (node->item == seq[index]){
        index++;
        // Continue traversing right and left subtrees
        if (node->item < seq[index]){
            if (hasSequenceRecursive(seq, soFar, soFarLength, length, index, node->right)){
                return true;
            }
        } else {
            if (hasSequenceRecursive(seq, soFar, soFarLength, length, index, node->left)){
                return true;
            }
        }
    }

    // Traverse right subtree if current node is less than max value in sequence
    if (index < length && node->item < seq[index]){
        if (hasSequenceRecursive(seq, soFar, soFarLength, length, index, node->right)){
            return true;
        }
    }

    // Compare soFar to seq
    if (soFarLength >= length){
        sortArray(soFar, soFarLength);
        for (int i = 0; i < length; i++){
            if (soFar[i] != seq[i]){
                return false;
            }
        }
        return true;
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
