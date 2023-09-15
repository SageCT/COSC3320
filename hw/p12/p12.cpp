#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool divideArrHelper(vector<int> &arr, int &k) {
  // * if startIdx == end of the array, return
  if (arr.size() == 0)
    return true;

  // * Find the smallest element in the array and erase it
  int minNum = arr[0];
  arr.erase(arr.begin());

  // * Find the next element in conseq. order
  for (int i = 1; i < k; i++) {
    auto test = find(arr.begin(), arr.end(), ++minNum);
    if (test != arr.end())
      arr.erase(test);
    else
      return false;
  }
  // * Recursively call the function for the next subarray
  return divideArrHelper(arr, k);
}

bool divideArr(vector<int> &arr, int k) {
  sort(arr.begin(), arr.end());

  if (arr.size() % k > 0 || k == 0 || !divideArrHelper(arr, k)) {
    cout << "false";
    return false;
  }

  cout << "true";
  return true;
}

int main() {
  stringstream ss;
  vector<int> arr;
  string line;
  int c, divSize;

  // arr = {1, 2, 3, 3, 4, 5, 5, 6};
  // divSize = 4;

  // * Input Handling
  getline(cin, line);
  ss << line;

  while (ss >> c)
    arr.push_back(c);
  line.clear();
  ss.clear();

  getline(cin, line);
  ss << line;
  ss >> c;
  divSize = c;

  // * Calling the functions
  divideArr(arr, divSize);
}