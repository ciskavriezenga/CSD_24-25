/*
 * Utility code for validating user input
 *
 * Available checks and queries:
 * - expected numeric
 * - value within range
 * - string selection
 */

#include <iostream>
#include <string>

class UI
{
public:
  int retrieveUserSelection(std::string selectionOptions[], int numOptions);
  float retrieveValueInRange(float min, float max);
private:
  std::string retrieveUserInput(std::string selectionOptions[], int numOptions);
};

