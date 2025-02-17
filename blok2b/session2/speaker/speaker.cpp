#include <iostream>
#include "woofer.h"
#include "tweeter.h"

int main()
{
  Woofer myWoofer;
  myWoofer.impedance=16; // access internal variable of Woofer directly
  std::cout << "Woofer impedance: " << myWoofer.impedance << std::endl;
  myWoofer.move(0.6);

  Tweeter myTweeter;
  myTweeter.move(0.01);
      myTweeter.setImpedance(4); // access Tweeter variable via a setter
  // read back the impedance value using a getter
  std::cout << "Tweeter impedance: " << myTweeter.getImpedance() << std::endl;

  Tweeter midrangeTweeter;
  midrangeTweeter.move(0.05);

  return 0;
}

