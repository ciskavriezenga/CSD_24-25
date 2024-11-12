#include <iostream>
// written by: Ciska Vriezenga


int add(int x, int y) {
  return x + y;
}

void addPointer(int* x, int y) {
  *x += y;
}

void addByReference(int& x, int y) {
  x += y;
}


int main() {
  int a = 8;
  int b = 10;

  // -------- add function with a return --------
  std::cout << "\nadd: " << add(a, b);

  // -------- add function with a pointer --------
  /*
   * NOTE: with pointers we can do 'things'
   * we might not want to allow
   */
  //float c = (float)a;
  //addPointer((int*) &c, b);

  int c = 7;
  addPointer(&c, b);
  std::cout << "\naddPointer: " << c;

  // -------- add function, pass by reference --------
  int d = 6;
  addByReference(d, b);
  std::cout << "\naddByReference: " << d;

  std::cout << "\n";
}
