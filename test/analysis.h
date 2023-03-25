#include "BST.h"

#include <iostream>
using namespace std;


// Write a global function, void timeAnalysis(), which does the following:
// ● Creates an array of 15000 random numbers and starts inserting them into an empty pointer based BST. 
// At each 1500 insertions, outputs the time elapsed for those insertions (use clock from ctime for calculating elapsed time).
// ● Shuffles the array created in the previous part. Then iterates over it and deletes the numbers from the tree. 
// After each 1500 deletions, outputs the time elapsed for the deletion.

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