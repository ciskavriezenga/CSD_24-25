#include <iostream>
// written by: Marc Groenewegen

int main()
{
  char letter = 'a';

  std::cout << letter << std::endl;

  // print asci decimal set value
  std::cout << (uint) letter << std::endl;


  // maak een pointer en laat wijzen naar letter
  char* letterPointer = &letter;

  // wat staat er in de pointer? Waar wijst 'ie naar?
  std::cout << (unsigned long)letterPointer << std::endl;

  // benader de variabele letter via de pointer
  std::cout << *letterPointer << std::endl;
  *letterPointer = 'b';

  std::cout << letter << std::endl;

  return 0;
}
