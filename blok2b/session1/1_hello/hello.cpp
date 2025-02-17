#include <iostream>
#include <string>

int main () {
  std::cout << "Hello, what is your name?" << std::endl;

  std::string yourName;
  std::cin >> yourName;

  std::cout << "Hi " << yourName << std::endl;
}

