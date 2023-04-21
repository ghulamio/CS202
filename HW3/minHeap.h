#ifndef _MINHEAP_H
#define _MINHEAP_H

#include"Food.h"

class minHeap{
  private:
  Food* foods;
  int size;
  int MAX_SIZE;

  public:
  minHeap() = default;
  minHeap(int MAX);
  ~minHeap();
  bool heapIsEmpty() const;
  void heapInsertItem(Food& newFood);
  void heapDelete(Food& root);
  const Food& peek();

  protected:
  void heapRebuild(int root);
};

#endif