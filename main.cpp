
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

void PrintStartOrEndLine() {
  int i;

  PrintAsterisks(27);
  PrintSpaces(4);
  PrintAsterisks(27);

  cout << endl;
}

void PrintClockDisplay(vector<int> timeUnits) {
  int i;
  bool isPm = false;

  PrintAsterisks(1);
  PrintSpaces(6);

  for (i = 0; i < 3; i++) {
    if (i == 0 && timeUnits.at(i) > 12) {
      isPm = true;
    };

    if (timeUnits.at(i) < 10 || (i == 0 && timeUnits.at(i) > 12)) {
      cout << "0";
    }

    if (i == 0 && timeUnits.at(i) > 12) {
      cout << timeUnits.at(i) % 12;
    } else {
      cout << timeUnits.at(i);
    }

    if (i != 2) {
      cout << ':';
    }
  };

  PrintSpaces(2);
  
  if (isPm) {
    cout << "PM";
  } else {
    cout << "AM";
  }

  PrintSpaces(7);
  PrintAsterisks(1);
  PrintSpaces(4);
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

void DisplayMenu() {
  cout << "Display Menu" << endl;
}

void AddHour() {
  cout << "Add Hour" << endl;
}

void AddMinute() {
  cout << "Add Hour" << endl;
}

void AddSecond() {
  cout << "Add Hour" << endl;
}

int Exit() {
  cout << "Exiting Application..." << endl;
  return 0;
}

vector<int> GetInitialInput() {
  int i;
  vector<int> timeUnits(3);

  for (i = 0; i < 3; i++) {
    if (i == 0) {
      cout << "Enter Hours:" << endl;
    } else if (i == 1) {
      cout << "Enter Minutes:" << endl;
    } else if (i == 2) {
      cout << "Enter Seconds:" << endl;
    }
    cin >> timeUnits.at(i);
  }

  for (i = 0; i < 3; i++) {
    cout << timeUnits.at(i);

    if (i != 2) {
      cout << ":";
    }
  }

  cout << endl;

  return timeUnits;
}

int main() {
  vector<int> timeUnits = GetInitialInput();

  // DisplayMenu();
  PrintStartOrEndLine();
  PrintClockLine();
  PrintClockDisplay(timeUnits);
  PrintStartOrEndLine();

  return Exit();
}
