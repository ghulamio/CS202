#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

using namespace std;

template <class T>
class linked_list{
    public:

        class node{
            public:
                T data;
                node* next;

                node(T data){
                    this->data = data;
                    this->next = nullptr;
                }
        };

        node* head;
        node* tail;
        int size;

        linked_list();
        void push_front(T data);
        void push_back(T data);
        void insert(T data, int index);
        void remove(T data);
        bool contains(T data);
        T& operator[](int index);
        void print();
};

#endif