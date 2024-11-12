#include <iostream>
// written by: Marc Groenewegen


int sumSquares(int* block, int numNumbers)
{
  int sum = 0;

  for(int i = 0; i < numNumbers; i++) sum += block[i] * block[i];
  return sum;
} // sumsquares()


int main()
{
  // new array with static initialisation
  // int lijst[10]={'a','b','c','d','e','f','g','h','i','j'};

  // dynamic array initialization
  int numNums = 10;
  int* numbers = new int[numNums]; // new array

  for(int i=0; i<10; i++) numbers[i] = i; // fill array

  for(int i=0; i<10; i++){ // show array content
    std::cout << *(numbers+i) << std::endl;
  }
  // console out sum of the squares of all values in the array
  std::cout << sumSquares(numbers, numNums) << std::endl;

  return 0;
}
