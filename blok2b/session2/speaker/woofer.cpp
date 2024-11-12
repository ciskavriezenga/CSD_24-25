#include <iostream>
#include "woofer.h"


void Woofer::move(float coilPosition)
{
  this->coilPosition = coilPosition;
  std::cout << "Woofer coil position: " << coilPosition << std::endl;
}

