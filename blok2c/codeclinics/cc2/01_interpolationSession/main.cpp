#include <iostream>


class Interpolation {
public:
	/*
	* returns the nearest-neighbour value of the passed value within the given range
	* value: a normalized value within range [0, 1]
	* low: the lower bound of the range
	* high: the upper bound of the range
	*/
	static float nnMap(float value, float low, float high) {
    if(value < 0) {
    	std::cout << "Value is lower than 0, please use values in range [0, 1]" << std::endl;
      return low;
    } else if(value > 1) {
	    std::cout << "Value exceeds 1, please use values in range [0, 1]" << std::endl;
    	return high;
    }

    if(int(value + 0.5f) == 0) return low;
    return high;
  };

	/*
	* returns the linearly interpolated value of the passed value within the given range
	* value: a normalized value within range [0, 1]
	* low: the lower bound of the range
	* high: the upper bound of the range
	*/
	static float linMap(float value, float low, float high) {
    if(value < 0) {
    	std::cout << "Value is lower than 0, please use values in range [0, 1]" << std::endl;
      return low;
    } else if(value > 1) {
      std::cout << "Value exceeds 1, please use values in range [0, 1]" << std::endl;
    	return high;
    }

    return (1.0 - value) * low + value * high;
  };

  /*
	* returns the mapped value from one range to another
	* fromLow: the lower bound of the value’s current range.
	* fromHigh: the upper bound of the value’s current range.
	* toLow: the lower bound of the value’s target range.
	* toHigh: the upper bound of the value’s target range.
	*/
  static float mapInRange(float value, float fromLow, float fromHigh, float toLow, float toHigh) {
	// formula for lin interpolation from https://en.wikipedia.org/wiki/Interpolation

  	float partial = (value - fromLow) / (fromHigh - fromLow);
		float delta = toHigh - toLow;

  	return toLow + delta * partial;
  };
};





int main() {
	std::cout << Interpolation::nnMap(0.1, 1.0, 3.0) << std::endl;
  	std::cout << Interpolation::linMap(0.1, 1.0, 3.0) << std::endl;

    std::cout << Interpolation::mapInRange(2.3, 2, 3, 20, 30) << std::endl;


  	return 0;
}