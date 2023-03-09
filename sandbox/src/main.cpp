#include <iostream>
#include <vector>

int main() {
  int *foo = new int[10];
  if (*foo == 0) return 1;
  return 0;
}
