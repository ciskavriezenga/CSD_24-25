#include "pet.h"

class Dog : public Pet
{
public:
  //constructor and destructor
  Dog(std::string name);
  ~Dog();

  // methods
  void bark();
};
