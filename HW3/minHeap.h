/**
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 3
* Description : Homework 3 - Heaps and Priority Queues
*/

#ifndef _MINHEAP_H
#define _MINHEAP_H

#include"Food.h"

class minHeap{
  public:
    minHeap(int capacity);
    ~minHeap();

    bool isOccupied() const;
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