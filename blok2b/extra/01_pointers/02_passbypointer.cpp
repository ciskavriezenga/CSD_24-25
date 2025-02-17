#include <iostream>
// written by: Marc Groenewegen

// function gets a pointer to a variable
int sumsquares(int *x)
{
  std::cout << "From within sumsquares: " << *x << std::endl;
  *x = 46;
} // sumsquares()


int main()
{
  int getal = 52;

  std::cout << getal << std::endl;
  sumsquares(&getal); // pass the address of a variable
  std::cout << getal << std::endl;

  return 0;
}
