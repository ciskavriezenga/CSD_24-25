#include "sine.h"

/*
 * Simple example of overriding methods.
 */

int main()
{

  Oscillator osc;

  Sine sine;


  /*
   * because the base class calculate method is overridden in the subclass,
   * the calculate function of the subclass is called, not the baseclass.
   */
  std::cout << "\nCalling the sine.calculate method." << std::endl;
  sine.calculate();


  /*
   * However ... when we call the calculate function from within a baseclass
   * method, which is the case in the baseclass method tick
   * --> we do not call the subclass method .... whoops.
   */
  std::cout << "\nCalling the sine.tick method, which is a baseclass method.\n"
    << "Inside this baseclass method, the calculate method of the baseclass will be called."
    << std::endl;
  sine.tick();

  std::cout << "\nEnd main.\n";
   /*
   * WE NEED THE KEYWORD 'virtual'!
   * Solution: we need to add the word virtual
   * _______ * * * DIY * * *  _______
   * 1. add the keyword 'virtual' to the header of the baseclass as follows:
   *  virtual void calculate();
   *
   * now rebuild: make clean, make - because you only altered a header!
   * which calculate method is called?
   *
   * 2. create an object of the type Oscillator in the main.cpp:
   * Oscillator osc;
   * (for the sake of this example there is no need to make this dynamic).
   * rebuild and rerun your code. Does it work?
   *
   * 3. Now, change the virtual method definition ('virtual void calculate()')
   * in the baseclass into:
   * virtual void calculate() = 0;
   * AND remove the implementation of this method in the oscillator.cpp file.
   * rebuild your code --> do you succeed?
   * ....
   * ...
   * ..
   * .
   *
   * NO ...
   * You will get the following error:
   * main.cpp:11:14: error: variable type 'Oscillator' is an abstract class
   * Oscillator osc;
   *             ^
   * ./oscillator.h:11:16: note: unimplemented pure virtual method 'calculate' in 'Oscillator'
   * virtual void calculate() = 0;
   *
   * Questions:
   * Why can't you create an instance of the type Oscillator?
   * When you view this from the perspective of categories - e.g. Pet, Cat, Dog
   * does it then 'make sense' that you can not create a Pet? But you can create
   * a Dog or Cat?
   */
}
