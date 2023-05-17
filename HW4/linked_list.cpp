#include "linked_list.h"

template <class T>
linked_list<T>::linked_list(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <class T>
void linked_list<T>::push_front(T data) {
  node* new_node = new node(data);

  if (head == nullptr) {
    head = new_node;
    tail = new_node;
  } else {
    new_node->next = head;
    head = new_node;
  }

  size++;
}

template <class T>
void linked_list<T>::push_back(T data) {
  node* new_node = new node(data);

  if (head == nullptr) {
    head = new_node;
    tail = new_node;
  } else {
    tail->next = new_node;
    tail = new_node;
  }

  size++;
}

template <class T>
void linked_list<T>::insert(T data, int index) {
  if (index < 0 || index > size) {
    return;
  }

  if (index == 0) {
    push_front(data);
    return;
  }

  if (index == size) {
    push_back(data);
    return;
  }

  node* new_node = new node(data);
  node* current_node = head;
  for (int i = 0; i < index - 1; i++) {
    current_node = current_node->next;
  }

  new_node->next = current_node->next;
  current_node->next = new_node;

  size++;
}

template <class T>
void linked_list<T>::remove(T data) {
  if (head == nullptr) {
    return;
  }

  if (head->data == data) {
    node* temp = head;
    head = head->next;
    delete temp;
    size--;
    return;
  }

  node* current_node = head;
  while (current_node->next != nullptr) {
    if (current_node->next->data == data) {
      node* temp = current_node->next;
      current_node->next = current_node->next->next;
      delete temp;
      size--;
      return;
    }
    current_node = current_node->next;
  }
}

template <class T>
bool linked_list<T>::contains(T data) {
  node* current_node = head;
  while (current_node != nullptr) {
    if (current_node->data == data) {
      return true;
    }
    current_node = current_node->next;
  }
  return false;
}

template <class T>
T& linked_list<T>::operator[](int index) {
  node* current_node = head;
  for (int i = 0; i < index; i++) {
    current_node = current_node->next;
  }
  return current_node->data;
}

template <class T>
void linked_list<T>::print() {
  node* current_node = head;
  while (current_node != nullptr) {
    cout << current_node->data << " ";
    current_node = current_node->next;
  }
  cout << endl;
}