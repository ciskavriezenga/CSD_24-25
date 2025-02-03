// example based on code examples from: https://coffeebeforearch.github.io/2020/08/04/atomic-vs-mutex.html
#include <iostream>
#include <thread>
#include <atomic>

#define SELECT_EXAMPLE 2
// 1 - issue with synchronisation
// 2 - atomic
// 3 - mutex


int main() {

#if SELECT_EXAMPLE == 1 || SELECT_EXAMPLE == 3
  // Shared value for our threads
  int shared_val = 0;


#elif SELECT_EXAMPLE == 2
   // Shared value for our threads
   std::atomic<int> shared_val = 0;


#endif
  int N = 10000;


#if SELECT_EXAMPLE == 1 || SELECT_EXAMPLE == 2

  // Lambda that performs an increment
  auto inc_func = [&]() {
    for (int i = 0; i < N; i++) shared_val++;
  };

  // Create two threads
  std::thread t1(inc_func);
  std::thread t2(inc_func);



#elif SELECT_EXAMPLE == 3
  std::mutex mutex;
  // Function to increment using a lock

  auto inc_mutex = [&]() {
    for (int i = 0; i < N; i++) {
      std::lock_guard <std::mutex> guard(mutex);
      shared_val++;

    }
  };

  std::thread t1(inc_mutex);
  std::thread t2(inc_mutex);

#endif

// Join the threads
t1.join();
t2.join();

// Print the result
std::cout << "FINAL VALUE IS: " << shared_val << '\n';

return 0;
}