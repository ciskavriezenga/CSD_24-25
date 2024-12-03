#include "ui.h"


std::string UI::retrieveUserInput(std::string selectionOptions[], int numOptions)
{
    // show user the allowed options
    std::cout << "Please enter your selection. You can choose from: ";
    for(int i = 0; i < numOptions - 1; i++) {
        std::cout << selectionOptions[i] << ", ";
    }
    // print last option outside forloop to end with an .
    std::cout << selectionOptions[numOptions - 1] << "." << std::endl;
    // retrieve and return choice
    std::string selection = "";
    std::cin >> selection;
    return selection;
}

int UI::retrieveUserSelection(std::string selectionOptions[], int numOptions)
{
    std::string selection = "";
    while(true) {
        // let user choose from the allowed options
        selection = retrieveUserInput(selectionOptions, numOptions);

        // check if the selection is among the available option
	for(int i=0; i<numOptions; ++i) {
	    if(selection == selectionOptions[i]) {
		return i;
	    }
	}
        // if we end up here, this means the selection is not correct,
	// so log a message to user to try again
        std::cout << "Incorrect selection, please try again";
    } // while
    return -1; // should never be reached
} // retrieveUserSelection()


float UI::retrieveValueInRange(float min, float max)
{
  std::string input;
  float value = 0;
  bool notInRange = true;

  while(notInRange) {
    std::cout << "Please enter a value between " << min << " and " << max
      << std::endl;
    // first capture input in input string
    std::cin >> input;
    // validate if input string can be transformed into a float
    try {
      value = std::stof(input);
      // validate range
      if(value >= min && value <= max) {
        notInRange = false;
      } else {
        // value not in range
        std::cout << "Value out of range, please try again." << std::endl;
      }
    }
    catch (const std::exception& e) {
      // no float as input
      std::cout << "Invalid input, expecting a number."
        << std::endl;
    }
  } // while not in range

  return value;
} // retrieveValueInRange()


