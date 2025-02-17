#include "pet.h"

class Cat : public Pet
{
public:
  //constructor and destructor
  Cat(std::string name);
  ~Cat();

  // methods
  void climb();
};
