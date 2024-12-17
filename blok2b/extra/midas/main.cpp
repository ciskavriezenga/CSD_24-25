#include <iostream>
#include <string>

class Instrument {
public:
  Instrument() : name("default name"), sound("default sound") {
    std::cout << "Constructor - Instrument\n";
  }
  void play() {
    std::cout << "\n" << name << ": " << sound << "\n";
  }
protected:
  std::string name;
  std::string sound;
};

class Trumpet : public Instrument {
public:
  Trumpet() : Instrument() {
    std::cout << "Constructor - Trumpet\n";
    name = "Trumpet";
    sound = "Tetete";
  }
};



int main() {
  Trumpet aTrumpet;
  aTrumpet.play();
}