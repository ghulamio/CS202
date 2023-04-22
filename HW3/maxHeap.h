/**
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 3
* Description : Homework 3 - Heaps and Priority Queues
*/

#ifndef _MAXHEAP_H
#define _MAXHEAP_H

#include"Food.h"

class maxHeap{
  public:
    maxHeap(int capacity);
    ~maxHeap();

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