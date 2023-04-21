#ifndef _MAXHEAP_H
#define _MAXHEAP_H

#include"Food.h"

class maxHeap{
  public:
    maxHeap(int MAX);
    ~maxHeap();

    bool heapIsEmpty() const;
    void heapInsertItem(Food& newFood);
    void heapDelete(Food& root);
    const Food& peek();

    Food* getArray(int&);

  private:
    Food* foods;
    int size;
    int MAX_SIZE;
  
  void heapRebuild(int root);
};

#endif