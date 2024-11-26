#include "saw.h"
#include "sine.h"

/*
 * Simple example of overriding methods.
 */

int main()
{
  std::cout << "Creating objects\n";
  Oscillator oscillator;
  Sine sine;
  Saw saw;


  std::cout << "\nCall to calculate\n";
  // no subclass --> oscillator calculator is called.
  oscillator.calculate();
  /*
   * because the base class calculate method is overridden in the subclass,
   * the calculate function of the subclass is called, not the baseclass.
   */
  sine.calculate();
  saw.calculate();

  std::cout << "\nEnd main.\n";
}
