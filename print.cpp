#include <iostream>
#include <vector>
#include "display.h"
#include "print.h"

using namespace std;

void PrintAsterisks(int ast) {
  int i;

  for (i = 0; i < ast; i++) {
    cout << "*";
  };
}

void PrintSpaces(int spaces) {
  int i;

  for (i = 0; i < spaces; i++) {
    cout << " ";
  };
}
void PrintStartOrEndLine(bool isDouble) {
  int i;

  PrintAsterisks(27);

  if (isDouble) {
    PrintSpaces(4);
    PrintAsterisks(27);
  }

  cout << endl;
}

void PrintClockDisplay(vector<int> timeUnits) {
  int i;
  bool isPm = false;

  // start 12 hour clock section

  PrintAsterisks(1);
  PrintSpaces(6);

  // for each time unit value
  for (i = 0; i < 3; i++) {
    // if value is hours,
    if (i == 0) {

      // and value is greater than 12, the 12 hour clock is going to be in PM
      if (timeUnits.at(i) > 12) {
        isPm = true;
      };

      // and time units mod 12 are less than 10, we need to add a 0 in front
      if ((timeUnits.at(i) % 12) < 10 && timeUnits.at(i) != 12) {
        cout << "0";
      }

      // and time units are greater than 12
      // then output mod 12 value
      // else just output the value
      if (timeUnits.at(i) > 12) {
        cout << timeUnits.at(i) % 12;
      } else {
        cout << timeUnits.at(i);
      }
    } else {
      if (timeUnits.at(i) < 10) {
        cout << "0";
      }

      cout << timeUnits.at(i);
    }

    // add semicolons inbetween hours and minutes, and minutes and second. 
    if (i != 2) {
      cout << ':';
    }
  }

  PrintSpaces(2);
  
  if (isPm) {
    cout << "PM";
  } else {
    cout << "AM";
  }

  PrintSpaces(7);
  PrintAsterisks(1);
  PrintSpaces(4);

  // end 12 hour clock section

  // start 24 hour clock section

  PrintAsterisks(1);
  PrintSpaces(8);

  for (i = 0; i < 3; i++) {
    if (timeUnits.at(i) < 10) {
      cout << "0";
    }

    cout << timeUnits.at(i);

    if (i != 2) {
      cout << ':';
    }
  }

  PrintSpaces(9);
  PrintAsterisks(1);
  // end 24 hour clock section

  cout << endl;
}

void PrintClockLine() {
  // start 12 hour side
  PrintAsterisks(1);
  PrintSpaces(6);

  cout << "12-Hour Clock";

  PrintSpaces(6);
  PrintAsterisks(1);
  // end 12 hour side

  // spacer
  PrintSpaces(4);

  PrintAsterisks(1);
  PrintSpaces(6);

  cout << "24-Hour Clock";

  PrintSpaces(6);
  PrintAsterisks(1);

  cout << endl;
}

void PrintMenuLine(string line) {
  PrintAsterisks(1);
  PrintSpaces(1);
  cout << line;
  PrintSpaces(24 - line.size());
  PrintAsterisks(1);

  cout << endl;
}