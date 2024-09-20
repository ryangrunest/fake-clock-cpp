#include <iostream>
#include <vector>
#include "print.h"

void DisplayClock(std::vector<int> timeUnits) {
  PrintStartOrEndLine(true);
  PrintClockLine();
  PrintClockDisplay(timeUnits);
  PrintStartOrEndLine(true);
}

void DisplayMenu() {
  std::cout << std::endl;

  PrintStartOrEndLine(false);
  PrintMenuLine("1 - Add One Hour");
  PrintMenuLine("2 - Add One Minute");
  PrintMenuLine("3 - Add One Second");
  PrintMenuLine("4 - Exit Program");
  PrintStartOrEndLine(false);

  std::cout << std::endl;
}