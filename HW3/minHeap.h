#ifndef _MINHEAP_H
#define _MINHEAP_H

#include"Food.h"

class minHeap{
  private:
  Food* foods;
  int size;
  int capacity;

  public:
  minHeap() = default;
  minHeap(int capacity);
  ~minHeap();
  bool isEmpty() const;
  void insert(Food& foodToInsert);
  void remove(Food& root);
  const Food& getRoot();

  protected:
  void heapify(int root);
};

#endif