
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void SortVector(vector<int>& myVec) {   
   sort(myVec.begin(), myVec.end(), greater<int>());
   
   for (auto x : myVec)
      cout << x << ",";
   
   cout << endl;
}

int main() {
   vector<int> myVector;
   int vectorSize;
   unsigned int i;

   
   cin >> vectorSize;
   
   myVector.resize(vectorSize);
   
   for (i = 0; i < myVector.size(); i++) {
      cin >> myVector.at(i);
   }
   
   SortVector(myVector);

   return 0;
}
