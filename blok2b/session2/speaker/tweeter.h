#include <iostream>

class Tweeter
{
public:
  Tweeter();
  void move(float coilPosition);
  void setImpedance(int impedance);
  int getImpedance();
private:
  int impedance;
  float coilPosition;
};


