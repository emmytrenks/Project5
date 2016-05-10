#include "tree.hpp"
#include <iostream>

int main(int argc, char **argv) {
  Tree<int> t;
  t.setRoot(0);
  auto n = t.insert(t.getRoot(), 5);
  t.insert(n, 10);
  t.insert(n, 15);
  auto br = t.pre_order();
  auto s = br.begin();
  for (; s != br.end(); ++s) std::cout << *s << " ";
  std::cout << '\n';
  br = t.in_order();
  s = br.begin();
  for (; s != br.end(); ++s) std::cout << *s << " ";
  std::cout << '\n';
  br = t.post_order();
  s = br.begin();
  for (; s != br.end(); ++s) std::cout << *s << " ";
  std::cout << '\n';
  return 0;
}
