#include "BST.h"

#include <iostream>

using namespace std;


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