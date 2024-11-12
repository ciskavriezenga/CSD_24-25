#include "dog.h"

//constructor and destructor

Dog::Dog(std::string name) : Pet(name)
{
  std::cout << "Dog::Dog - constructor, name: "
    << name << "\n";
}
Dog::~Dog()
{
  std::cout << "Dog::~Dog - destructor, name: "
    << name << "\n";
}
