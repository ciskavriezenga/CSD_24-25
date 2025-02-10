#ifndef _PET_H_
#define _PET_H_
#include <iostream>

class Pet
{
public:
  // constructor and destructor
  Pet(std::string name);
  ~Pet();

  // methods
  void sleep();
protected:
  std::string name;
};

#endif
