#include "slist.h"
#include <iostream>


int main() {
  LinkedList<int>* l = new LinkedList<int>(1);
  l->add(2);
  l->add(3);
  l->add(4);
  l->clear();
  std::cout << l->isEmpty() << '\n';
  l->add(2);
  l->add(3);
  l->add(4);
  std::cout << l->toString() << '\n';
  std::cout << l->get(1) << '\n';
  l->set(1,9);
  std::cout << l->get(1) << '\n';
  l->insert(0, -1);
  l->insert(3, 3);
  std::cout << l->toString() << '\n';
  l->exchg(4, 0);
  std::cout << l->toString() << '\n';

  std::cout << l->subList(0, 3)->toString() << '\n';
}
