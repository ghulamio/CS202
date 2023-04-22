#ifndef _MAXHEAP_H
#define _MAXHEAP_H

#include"Food.h"

class maxHeap{
  public:
    maxHeap(int capacity);
    ~maxHeap();

    bool isEmpty() const;
    const Food& getRoot();

    void insert(Food& foodToInsert);
    void remove(Food& root);

  private:
    Food* foods;
    int size;
    int capacity;
  
    void heapify(int root);
};

#endif