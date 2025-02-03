#include <iostream>


class Interpolation {
public:
  /*
   * returns the nearest-neighbour value of the passed value within the given range
   * value: a normalized value within range [0, 1]
   * low: the lower bound of the range
   * high: the upper bound of the range
   */
  static float nnMap(float value, float low, float high);

/*
 * returns the linearly interpolated value of the passed value within the given range
 * value: a normalized value within range [0, 1]
 * low: the lower bound of the range
 * high: the upper bound of the range
 */
  static float linMap(float value, float low, float high);

  /*
   * returns the mapped value from one range to another
   * fromLow: the lower bound of the value’s current range.
   * fromHigh: the upper bound of the value’s current range.
   * toLow: the lower bound of the value’s target range.
   * toHigh: the upper bound of the value’s target range.
   */
  static float mapInRange(float value, float fromLow, float fromHigh, float toLow, float toHigh);
};





int main() {




  return 0;
}