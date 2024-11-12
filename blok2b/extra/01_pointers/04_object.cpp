#include <iostream>
#include <sys/time.h>
// written by: Marc Groenewegen

#define BLOCKSIZE 100000

struct timeval tv_zero,tv;
struct timezone tz;


class Block{
public:
    double data1[BLOCKSIZE];
    double data2[BLOCKSIZE];
    double data3[BLOCKSIZE];
    double data4[BLOCKSIZE];
};


// function makes a copy of the object
double sumsquares_copy(Block block)
{
double total=0;

  for(unsigned long i=0; i<BLOCKSIZE; i++){
    total = block.data1[i] * block.data1[i];
  }
} // sumsquares_copy()


// function gets a pointer to the object
double sumsquares_pointer(Block *block)
{
double total=0;

  for(unsigned long i=0; i<BLOCKSIZE; i++){
    total = block->data1[i] * block->data1[i];
  }
} // sumsquares_pointer()



int main()
{
unsigned long duration;

  tz.tz_minuteswest= -60; // set time zone

  Block myblock;

  // show how long it took to complete the function
  gettimeofday(&tv_zero,&tz); // reset tv_zero
  sumsquares_copy(myblock);
  gettimeofday(&tv,&tz);
  duration=(tv.tv_sec-tv_zero.tv_sec)*1000000 + (tv.tv_usec-tv_zero.tv_usec);
  std::cout << duration << std::endl;

  // show how long it took to complete the function
  gettimeofday(&tv_zero,&tz); // reset tv_zero
  gettimeofday(&tv_zero,&tz); // reset tv_zero
  sumsquares_pointer(&myblock);
  gettimeofday(&tv,&tz);
  duration=(tv.tv_sec-tv_zero.tv_sec)*1000000 + (tv.tv_usec-tv_zero.tv_usec);
  std::cout << duration << std::endl;

  return 0;
}
