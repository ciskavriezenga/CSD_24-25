#include <iostream>
#include "ui.h"


int main()
{
  std::string waveFormOptions[4] = {"sine", "saw", "square", "triangle"};
  int numWaveFormOptions = 4;

  UI console_ui;

  int waveTypeSelection = console_ui.retrieveUserSelection(waveFormOptions,numWaveFormOptions);

  // use the selected option to show the corresponding text
  std::cout << "You selected: " << waveFormOptions[waveTypeSelection] << std::endl;

  float value =  console_ui.retrieveValueInRange(20, 20499);
  std::cout << "You chose the following value: " << value << std::endl;
}

