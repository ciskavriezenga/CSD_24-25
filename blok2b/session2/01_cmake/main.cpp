#include <iostream>
#include "tweeter.h"


int main() {
  // create a Tweeter object using the default constructor
  Tweeter aTweeter;

  // create a Tweeter object using the constructor with diameter as parameter
  Tweeter anotherTweeter(1.8);

  std::cout << "The diameter of the tweeter created with the default constructor is "
    << aTweeter.diameter << std::endl;

  std::cout << "The diameter of the tweeter created with the overloaded constructor is "
    << anotherTweeter.diameter << std::endl;
};