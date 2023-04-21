#include"minHeap.h"


minHeap::minHeap(int MAX) {
  MAX_SIZE = MAX;
  foods = new Food[MAX_SIZE];
  size = 0;
};

minHeap::~minHeap() {
  delete[] foods;
}

bool minHeap::heapIsEmpty() const {
  return size == 0;
};

void minHeap::heapInsertItem(Food& newFood) {
  if (size >= MAX_SIZE) return;

  foods[size] = newFood;
  // trickle the new item up to its proper position
  int place = size;
  int parent = (place - 1) / 2;
  while (place > 0 && foods[place].getSpawnTime() < foods[parent].getSpawnTime()) {
    Food temp = foods[place];
    foods[place] = foods[parent];
    foods[parent] = temp;
    place = parent;
    parent = (place - 1) / 2;
  }

  size++;
};

void minHeap::heapDelete(Food& root) {
  root = foods[0];
  foods[0] = foods[--size];
  heapRebuild(0);
};

const Food& minHeap::peek() {
  return foods[0];
}

  
void minHeap::heapRebuild(int root) {
  int child = 2 * root + 1;
  
  if (child < size) {
    int rightChild = child + 1;
    
    if (rightChild < size && foods[child].getSpawnTime() > foods[rightChild].getSpawnTime()) {
      child = rightChild;
    }

    if (foods[root].getSpawnTime() > foods[child].getSpawnTime()) {
      Food temp = foods[root];
      foods[root] = foods[child];
      foods[child] = temp;
      heapRebuild(child);
    }
  }
};