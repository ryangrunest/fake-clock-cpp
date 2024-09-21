#include <iostream>
#include <vector>
#include "display.h"
#include "print.h"
using namespace std;

// adds one to index of vector at given value
vector<int> AddOne(vector<int> vect, int index) {
  vect.at(index) += 1;

  return vect;
};

// checks vector of ints to see if each time val needs to be rolled over
vector<int> UpdateTimeUnitsWithCorrectValues(vector<int> vect) {
  int i;

  for (i = 2; i >= 0; i--) {
    if (i == 0) { // if at hours index,
      if (vect.at(i) > 23) { // and hours is greater than number of hours in a day
        vect.at(i) = 0; // reset to 0
      }
    } else if (vect.at(i) > 59) { // if at minutes or seconds index and greater than minutes in hour or seconds in minute
      vect.at(i - 1) += 1; // add to previous value, either minute or hour
      vect.at(i) = 0; // reset to 0
    }
  }

  return vect;
}