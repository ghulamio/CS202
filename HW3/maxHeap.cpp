#include"maxHeap.h"

maxHeap::maxHeap(int capacity) {
  foods = new Food[capacity];
  size = 0;
  this -> capacity = capacity;
};

maxHeap::~maxHeap() {
  delete[] foods;
}

bool maxHeap::isEmpty() const {
  return size == 0;
};

void maxHeap::insert(Food& foodToInsert) {
  if (size < capacity){
    foods[size] = foodToInsert;
    int index = size;
    int parent = (index - 1) / 2;
    while (index > 0 && foods[index].getQuality() > foods[parent].getQuality()) {
      Food temp = foods[index];
      foods[index] = foods[parent];
      foods[parent] = temp;  

      index = parent;
      parent = (index - 1) / 2;
    }
    size++;
  }
};

void maxHeap::remove(Food& root) {
  root = foods[0];
  foods[0] = foods[--size];
  heapify(0);
};

const Food& maxHeap::getRoot() {
  return foods[0];
}
  
void maxHeap::heapify(int root) {
  int leftChild= 2 * root + 1;
  
  if (leftChild< size) {
    int rightChild = leftChild+ 1;
    
    if (rightChild < size && foods[leftChild].getQuality() < foods[rightChild].getQuality()) {
      leftChild= rightChild;
    }

    if (foods[root].getQuality() < foods[leftChild].getQuality()) {
      Food temp = foods[root];
      foods[root] = foods[leftChild];
      foods[leftChild] = temp;
      heapify(leftChild);
    }
  }
};