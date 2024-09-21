// Ryan Grunest
// September 20th, 2024

#include <iostream>
#include <vector>
#include "display.h"
#include "print.h"
#include "math.h"
#include "input.h"
using namespace std;

// main program
int main() {
  int userInput;
  vector<int> timeUnits = GetInitialInput(); // get initial input

  // update units before displaying
  timeUnits = UpdateTimeUnitsWithCorrectValues(timeUnits);

  // display main menu and clock
  DisplayClock(timeUnits);
  DisplayMenu();

  // get user input
  cin >> userInput;

  // enter main while loop of program
  while (userInput == 1 || userInput == 2 || userInput == 3) {
    // 
    if (userInput == 3) { // add second
      timeUnits = AddOne(timeUnits, 2);
    } else if (userInput == 2) { // add minute
      timeUnits = AddOne(timeUnits, 1);
    } else if (userInput == 1) { // add hour
      timeUnits = AddOne(timeUnits, 0);
    };

    // update units before displaying
    timeUnits = UpdateTimeUnitsWithCorrectValues(timeUnits);

    // display menu and clock
    DisplayClock(timeUnits);
    DisplayMenu();

    // retrieve user input again
    cin >> userInput;
  };

  // when loop has ended, exit program
  return Exit();
}
