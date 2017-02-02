#include "slist.h"
#include <iostream>


int main() {
  LinkedList<int>* l = new LinkedList<int>(1);
  l->add(2);
  l->add(3);
  l->add(4);

  std::cout << l->toString() << '\n' << std::flush;
  l->exchg(0,3);
  std::cout << l->toString() << '\n';
}
