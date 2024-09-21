#include <iostream>
#include <vector>
#include "display.h"
#include "print.h"
using namespace std;

// exits program
int Exit() {
  cout << "Exiting Application..." << endl;
  return 0;
}

// retrieves initial input from user of hour, minute, and second values to start at
vector<int> GetInitialInput() {
  int i;
  int tempVal;
  vector<int> timeUnits(3); // initialize vector to store values

  for (i = 0; i < 3; i++) {
    if (i == 0) {
      cout << "Enter Hours:" << endl; // get hours val
    } else if (i == 1) {
      cout << "Enter Minutes:" << endl; // get minutes val
    } else if (i == 2) {
      cout << "Enter Seconds:" << endl; // get seconds val
    }

    cin >> tempVal; // store in tempVal
    timeUnits.at(i) = tempVal % 100; // number shouldn't have more than 2 digits
  }

  cout << endl;

  return timeUnits;
};