#include <iostream>

int main () {
    const int bufferSize = 16;
    std::string buffer[bufferSize * 2]; // Buffer needs to be twice the size to carry samples of both channels

    // Writing to the buffer
    for (auto i = 0; i < bufferSize; ++i) {
        buffer[i * 2] = "L";  // 0, 2 , 4 , 6...
        buffer[i * 2 + 1] = "R"; // 1, 3, 5 , 7...
    }

    // Take a look at an interleaved buffer
    for (auto i = 0; i < bufferSize * 2; ++i){
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;

    // Thoughts
    // Can you think of any uses for interleaving?
    // How would you apply an affect to an interleaved buffer?
    // How would your approach to a Tremolo be different to a Feedback Delay?
    // How would you expand this to allow for even more channels?

    return 0;
}
