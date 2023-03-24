#include "BST.h"

#include <iostream>

using namespace std;

BST* merge(const BST& tree1, const BST& tree2){
    BST* tree = new BST();
    int length1 = 0, length2 = 0;
    // inOrderTraversal is non const, so can't be used on const objects
    int* inOrder1 = tree1.inOrderTraversal(length1); 
    int* inOrder2 = tree2.inOrderTraversal(length2);
    int i = 0;
    int j = 0;
    while (i < length1 && j < length2){
        if (inOrder1[i] < inOrder2[j]){
            tree->insertItem(inOrder1[i]);
            i++;
        } else if (inOrder1[i] > inOrder2[j]){
            tree->insertItem(inOrder2[j]);
            j++;
        } else{
            tree->insertItem(inOrder1[i]);
            i++;
            j++;
        }
    }
    while (i < length1){
        tree->insertItem(inOrder1[i]);
        i++;
    }
    while (j < length2){
        tree->insertItem(inOrder2[j]);
        j++;
    }
    delete[] inOrder1;
    delete[] inOrder2;
    return tree;
}

int main(){
    // BST* tree = new BST();
    BST tree;
    tree.insertItem(8);
    tree.insertItem(4);
    tree.insertItem(13);
    tree.insertItem(3);
    tree.insertItem(6);
    tree.insertItem(12);
    tree.insertItem(15);
    tree.insertItem(1);
    tree.insertItem(5);
    tree.insertItem(10);
    tree.insertItem(14);
    tree.insertItem(2);


    // Printing the tree in order
    int length = 0;
    cout << "In order traversal: ";
    int* inOrder = tree.inOrderTraversal(length);
    for (int i = 0; i < length; i++){
        cout << inOrder[i] << " ";
    }
    cout << endl;
    delete[] inOrder;

    int seq[] = {1, 2, 3, 4, 5, 6};
    cout << "Does the tree have the sequence 1, 2, 3, 4, 5, 6? " << endl;
    if (tree.hasSequence(seq, 6)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    } 

    int seq2[] = {10, 12, 13, 15};
    cout << "Does the tree have the sequence 10, 12, 13, 15? " << endl;
    if (tree.hasSequence(seq2, 4)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }

    int seq3[] = {10, 11, 12};
    cout << "Does the tree have the sequence 10, 11, 12? " << endl;
    if (tree.hasSequence(seq3, 3)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }

    return 0;
}