#include "slist.h"
#include <string>
#include <iostream>
#include <sstream>

/*

Class Library File

*/


// Constructors
template <class Obj>
LinkedList<Obj>::LinkedList(Obj n) {
  this->head = new node(n);
  this->length = 1;
}

template <class Obj>
LinkedList<Obj>::LinkedList() {
  this->head = NULL;
  this->length = 0;
}

// Destructor
template <class Obj>
LinkedList<Obj>::~LinkedList() {
  this->clear();
}

// add(value)				//Adds a new value to the end of this->list.
template <class Obj>
void LinkedList<Obj>::add(Obj val) {
  if (this->head == NULL) {
    this->head = new node(val);
  }
  else {
    node* current = this->head;
    node* newNode = new node(val);
    for (int i = 1; i < this->length; i++) current = current->next;
    current->next = newNode;
  }
  this->length++;
}

// clear()					//Removes all elements from this->list.
template <class Obj>
void LinkedList<Obj>::clear() {
  node* current = this->head;
  for (int i = 0; i < this->length; i++) {
    node* temp = current->next;
    delete current;
    current = temp;
  }
  this->head = NULL;
  this->length = 0;
}

// equals(list)				//Returns true if the two lists contain the same elements in the same order.
template <class Obj>
bool LinkedList<Obj>::equals(LinkedList<Obj>* list) {
  if (this->length != list->size()) return false;
  node* current1 = this->head;
  for (int i = 0; i < this->length; i++) {
    if (current1->value != list->get(i)) return false;
    current1 = current1->next;
  }
  return true;
}

//get(index)				//Returns the element at the specified index in this->list.
template <class Obj>
Obj LinkedList<Obj>::get(int index) {
  node* current = this->head;
  for (int i = 0; i < index; i++) current = current->next;
  return current->value;
}

//insert(index, value)		//Inserts the element into this->list before the specified index.
template <class Obj>
void LinkedList<Obj>::insert(int index, Obj value) {
  if (index == 0) {
    this->head = new node(value, this->head);
  } else {
    node* current = this->head;
    for (int i = 1; i < index; i++) current = current->next;
    current->next = new node(value, current->next);
  }
  this->length++;
}

//exchg(index1, index2)		//Switches the payload data of specified indexex.
template <class Obj>
void LinkedList<Obj>::exchg(int index1, int index2) {
  if (index1 == index2) {
    return;
  }
  else if (index1 == 0 || index2 == 0) {
    if (index1 > index2) {int t = index1; index1 = index2; index2 = t;}
    node* current = this->head;
    for (int i = 1; i < index2; i++) current = current->next;
    node* currnext = current->next;
    node* temp = currnext->next;
    if (index2 != 1) {
      current->next = this->head;
      currnext->next = this->head->next;
    }
    else currnext->next = this->head;
    this->head->next = temp;
    this->head = currnext;
  }
  else {
    node* current1 = this->head;
    node* current2 = this->head;
    for (int i = 1; i < index1; i++) current1 = current1->next;
    for (int i = 1; i < index2; i++) current2 = current2->next;

    node* curr1next = current1->next;
    node* curr2next = current2->next;
    current1->next = curr2next;
    current2->next = curr1next;

    node* temp = curr1next->next;
    curr1next->next = curr2next->next;
    curr2next->next = temp;

  }
}

// isEmpty()				//Returns true if this->list contains no elements.
template <class Obj>
bool LinkedList<Obj>::isEmpty() {
  return (this->length == 0 ? true : false);
}

template <class Obj>
void LinkedList<Obj>::mapAll(void (*f)(Obj)){
  node* current = this->head;
  for (int i = 1; i < this->length; i++) {
    f(current->value);
    current = current->next;
  }
}

// remove(index)			//Removes the element at the specified index from this->list.
template <class Obj>
void LinkedList<Obj>::remove(int index) {
  if (index == 0) {
    node* temp = this->head;
    this->head = this->head->next;
  } else {
    node* current = this->head;
    for (int i = 1; i < index; i++) current = current->next;
    node* temp = current->next;
    current->next = current->next->next;
  }
  this->length--;
}

// set(index, value)		//Replaces the element at the specified index in this->list with a new value.
template <class Obj>
void LinkedList<Obj>::set(int index, Obj val) {
  node* current = this->head;
  for (int i = 0; i < index; i++) current = current->next;
  current->value = val;
}

// size()					//Returns the number of elements in this->list.
template <class Obj>
int LinkedList<Obj>::size() {
  return this->length;
}

// subList(start, length)	//Returns a new list containing elements from a sub-range of this->list.
template <class Obj>
LinkedList<Obj>* LinkedList<Obj>::subList(int start, int length) {
  if (length == 0) return 0;
  node* current = this->head;
  for (int i = 0; i < start; i++) current = current->next;
  LinkedList<Obj>* newList = new LinkedList<Obj>(current->value);
  for (int i = 1; i < this->length; i++) {
    newList->add(current->next->value);
    current = current->next;
  }
  return newList;
}

// toString()				//Converts the list to a printable string representation.
template <class Obj>
std::string LinkedList<Obj>::toString() {
  std::stringstream ss;
  ss << "[";
  node* current = this->head;
  for (int i = 0; i < this->length; i++) {
    ss << current->value << (i==this->length-1 ? "" : ", ");
    current = current->next;
  }
  ss << "]";
  return ss.str();
}

template class LinkedList<int>;
template class LinkedList<Airport*>;
