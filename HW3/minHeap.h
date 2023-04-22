#ifndef _MINHEAP_H
#define _MINHEAP_H

#include"Food.h"

class minHeap{
  public:
    minHeap(int capacity);
    ~minHeap();

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