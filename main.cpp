#include <iostream>
#include <vector>

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

void DisplayClock(vector<int> timeUnits) {
  PrintStartOrEndLine(true);
  PrintClockLine();
  PrintClockDisplay(timeUnits);
  PrintStartOrEndLine(true);
}

void PrintMenuLine(string line) {
  PrintAsterisks(1);
  PrintSpaces(1);
  cout << line;
  PrintSpaces(24 - line.size());
  PrintAsterisks(1);

  cout << endl;
}

void DisplayMenu() {
  cout << endl;

  PrintStartOrEndLine(false);
  PrintMenuLine("1 - Add One Hour");
  PrintMenuLine("2 - Add One Minute");
  PrintMenuLine("3 - Add One Second");
  PrintMenuLine("4 - Exit Program");
  PrintStartOrEndLine(false);

  cout << endl;
}

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
