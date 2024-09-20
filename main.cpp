#include <iostream>
#include <vector>
#include "display.h"
#include "print.h"
using namespace std;

int Exit() {
  cout << "Exiting Application..." << endl;
  return 0;
}

vector<int> GetInitialInput() {
  int i;
  int tempVal;
  vector<int> timeUnits(3);

  for (i = 0; i < 3; i++) {
    if (i == 0) {
      cout << "Enter Hours:" << endl;
    } else if (i == 1) {
      cout << "Enter Minutes:" << endl;
    } else if (i == 2) {
      cout << "Enter Seconds:" << endl;
    }

    cin >> tempVal;
    timeUnits.at(i) = tempVal % 100;
  }

  cout << endl;

  return timeUnits;
};

vector<int> AddOne(vector<int> vect, int index) {
  vect.at(index) += 1;

  return vect;
};

vector<int> UpdateTimeUnitsWithCorrectValues(vector<int> vect) {
  int i;

  for (i = 2; i >= 0; i--) {
    if (i == 0) {
      if (vect.at(i) > 23) {
        vect.at(i) = 0;
      }
    } else if (vect.at(i) > 59) {
      vect.at(i - 1) += 1;
      vect.at(i) = 0;
    }
  }

  return vect;
}

int main() {
  int userInput;
  vector<int> timeUnits = GetInitialInput();

  DisplayClock(timeUnits);
  DisplayMenu();

  cin >> userInput;

  while (userInput == 1 || userInput == 2 || userInput == 3) {
    if (userInput == 3) {
      timeUnits = AddOne(timeUnits, 2);
    } else if (userInput == 2) {
      timeUnits = AddOne(timeUnits, 1);
    } else if (userInput == 1) {
      timeUnits = AddOne(timeUnits, 0);
    };

    timeUnits = UpdateTimeUnitsWithCorrectValues(timeUnits);

    DisplayClock(timeUnits);
    DisplayMenu();

    cin >> userInput;
  };

  return Exit();
}
