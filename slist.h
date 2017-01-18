/*

Header file for single linked list class library

*/

#ifndef __SLIST_H_INCLUDED__
#define __SLIST_H_INCLUDED__
#endif

#include <string>

template <class Obj>
class LinkedList
{

  struct node {
    Obj value;
    node* next;
    node(Obj val) { value = val;}
    node(Obj val, node* n) { value = val; next = n; }
  };

  node* head;
  int length;


public:

  LinkedList(Obj);
  LinkedList();
  ~LinkedList();

  void add(Obj);				//Adds a new value to the end of this list.

  void clear();					//Removes all elements from this list.

  bool equals(LinkedList<Obj>*);    //Returns true if the two lists contain the same elements in the same order.

  Obj get(int);				//Returns the element at the specified index in this list.

  void insert(int, Obj);		//Inserts the element into this list before the specified index.

  void exchg(int, int);		//Switches the payload data of specified indexex.

  bool isEmpty();				//Returns true if this list contains no elements.

  void mapAll(void (*f)(Obj));				//Calls the specified function on each element of the linkedlist in ascending index order.

  void remove(int);			//Removes the element at the specified index from this list.

  void set(int, Obj);		//Replaces the element at the specified index in this list with a new value.

  int size();					//Returns the number of elements in this list.

  LinkedList<Obj>* subList(int, int);	//Returns a new list containing elements from a sub-range of this list.

  std::string toString();				//Converts the list to a printable string representation.

};
