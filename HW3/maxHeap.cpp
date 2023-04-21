#include"maxHeap.h"

maxHeap::maxHeap(int MAX) {
  MAX_SIZE = MAX;
  foods = new Food[MAX_SIZE];
  size = 0;
};

maxHeap::~maxHeap() {
  delete[] foods;
}

bool maxHeap::heapIsEmpty() const {
  return size == 0;
};

void maxHeap::heapInsertItem(Food& newFood) {
  if (size >= MAX_SIZE) return;

  foods[size] = newFood;
  // trickle the new item up to its proper position
  int place = size;
  int parent = (place - 1) / 2;
  while (place > 0 && foods[place].getFoodQuality() > foods[parent].getFoodQuality()) {
    Food temp = foods[place];
    foods[place] = foods[parent];
    foods[parent] = temp;  

    place = parent;
    parent = (place - 1) / 2;

  }
  size++;
};

void maxHeap::heapDelete(Food& root) {
  root = foods[0];
  foods[0] = foods[--size];
  heapRebuild(0);
};

const Food& maxHeap::peek() {
  return foods[0];
}
  
void maxHeap::heapRebuild(int root) {
  // index of root's left child
  int child = 2 * root + 1;
  
  // root is not a leaf so it has a left child 
  if (child < size) {
    int rightChild = child + 1;
    
    // if root has a right child, find the larger child 
    if (rightChild < size && (
      foods[child].getFoodQuality() < foods[rightChild].getFoodQuality() ||
      foods[child].getFoodQuality() == foods[rightChild].getFoodQuality() && foods[child].getFoodId() > foods[rightChild].getFoodId()
    )) {
      child = rightChild;
    }

    if (foods[root].getFoodQuality() < foods[child].getFoodQuality()) {
      Food temp = foods[root];
      foods[root] = foods[child];
      foods[child] = temp;
      heapRebuild(child);
    }
  }
};

Food* maxHeap::getArray(int& m_size) {
  m_size = size;
  return foods;
}