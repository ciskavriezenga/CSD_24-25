#include <iostream>
#include "math.h"
#include <limits>
#include <iomanip>
// typedef --> create a label for a type e.g
// typedef FV::AUDIO::OSC::Sine sine
typedef std::numeric_limits<float> flt;
typedef std::numeric_limits<double> dbl;


int main(int argc,char **argv)
{

  // change precission of console output
  std::cout << std::setprecision(40);

  // 2 ^ 1 = 2, to create 2 ^ 23 we shift it with 22.
  int mantissa_max = (2 << 22) - 1;
  std::cout << "Maximum mantissa value for a float: " << mantissa_max << "\n";

#if 1
  float maxFlt = mantissa_max;
  std::cout << "Maxium mantissa value in a float: " << maxFlt << "\n";
  // again: 2 ^ - 1 = 0.5
  std::cout << "Maxium exponent: " << pow(2, -127) << "\n";
  float maxMantMinExp = maxFlt * pow(2, -127);
  std::cout << "Max mantissa and min exponent value in a float: " << maxMantMinExp << "\n";
  std::cout << "_______________________________\nPhase example:\n"
    << "\n _____ \n";
  std::cout << "range [0, 1]: " << maxMantMinExp * (float) pow(10, 31)
    << "\n _____ \n";
  std::cout << "range [1, 10]: " << maxMantMinExp * (float) pow(10, 32)
    << "\n _____ \n";
  std::cout << "range [10, 100]: " << maxMantMinExp * (float) pow(10, 33)
    << "\n _____ \n";
  std::cout << "range [100, 1000]: " << maxMantMinExp * (float) pow(10, 34)
    << "\n _____ \n";
  std::cout << "range [1000, 10000]: " << maxMantMinExp * (float) pow(10, 35)
    << "\n _____ \n";
  std::cout << "_______________________________\n";



#endif
  // end of program
  return 0;
}
