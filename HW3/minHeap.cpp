#include"minHeap.h"

minHeap::minHeap(int capacity) {
  foods = new Food[capacity];
  size = 0;
  this -> capacity = capacity;
};

minHeap::~minHeap() {
  delete[] foods;
}

bool minHeap::isEmpty() const {
  return size == 0;
};

void minHeap::insert(Food& foodToInsert) {
  if (size < capacity) {
    foods[size] = foodToInsert;
    int index = size;
    int parent = (index - 1) / 2;
    while (index > 0 && foods[index].getSpawnTime() < foods[parent].getSpawnTime()) {
      Food temp = foods[index];
      foods[index] = foods[parent];
      foods[parent] = temp;  

      index = parent;
      parent = (index - 1) / 2;
    }
    size++;
  }
};

void minHeap::remove(Food& root) {
  root = foods[0];
  foods[0] = foods[--size];
  heapify(0);
};

const Food& minHeap::getRoot() {
  return foods[0];
}

  
void minHeap::heapify(int root) {
  int leftChild= 2 * root + 1;
  
  if (leftChild< size) {
    int rightChild = leftChild+ 1;
    if (rightChild < size && foods[leftChild].getSpawnTime() > foods[rightChild].getSpawnTime()) {
      leftChild= rightChild;
    }
    if (foods[root].getSpawnTime() > foods[leftChild].getSpawnTime()) {
      Food temp = foods[root];
      foods[root] = foods[leftChild];
      foods[leftChild] = temp;
      heapify(leftChild);
    }
  }
};