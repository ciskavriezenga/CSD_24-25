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
    if(value >= 0.0f && value <= 1.0f; ) {
      if (value < 0.5f) {
        return low;
      }
      return high;
    } else {
      // TODO Log error
    }

  }

/*
 * returns the linearly interpolated value of the passed value within the given range
 * value: a normalized value within range [0, 1]
 * low: the lower bound of the range
 * high: the upper bound of the range
 */
  static float linMap(float value, float low, float high) {
    float output = (1.0f - value) * low;
    output += value * high;
    return output;
  }

  /*
   * returns the mapped value from one range to another
   * value: a value (in the 'from' range, but not necessarily)
   * fromLow: the lower bound of the value’s current range.
   * fromHigh: the upper bound of the value’s current range.
   * toLow: the lower bound of the value’s target range.
   * toHigh: the upper bound of the value’s target range.
   */
  static float mapInRange(float value, float fromLow, float fromHigh, float toLow, float toHigh) {
    float deltaFromLow = value - fromLow;
    float fromRange = fromHigh - fromLow;
    float perc = deltaFromLow / fromRange;
    // (prefered strategy)
    float toRange = toHigh - toLow;
    float output = (perc * toRange) + toLow;


#if 0 // other strategy
    float output = (1.0f - perc) * toLow;
    output += perc * toHigh;
#endif

    return output;
  }
};





int main() {




  return 0;
}