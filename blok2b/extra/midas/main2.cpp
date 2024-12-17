#include <iostream>
#include <string>

class Instrument {
public:
  Instrument() {
    std::cout << "Constructor - Instrument\n";
  }
  virtual void play() {
    std::cout << "\nAn instrument is playing, no idea how it sounds...\n";
  }
};

class Trumpet : public Instrument {
public:
  Trumpet() : Instrument() {
    std::cout << "Constructor - Trumpet\n";
  }
  void play() {
    std::cout << "\nA trumpet is playing: Teteetestete\n";
  }
};



int main() {
  Trumpet aTrumpet;
  aTrumpet.play();
}