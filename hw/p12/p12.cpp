#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool divideArrHelper(vector<int> &arr, int k, int startIdx) {
  // if startIdx == end of the array, return
  if (arr.size() == 0)
    return true;

  //* Find the smallest element in the array and erase it
  int minNum = *min_element(arr.begin(), arr.end());
  arr.erase(min_element(arr.begin(), arr.end()));

  // Find the smallest element of
  for (int i = startIdx + 1; i < startIdx + k; i++) {

    if (find(arr.begin(), arr.end(), ++minNum) != arr.end()) {
      arr.erase(find(arr.begin(), arr.end(), minNum));
    } else
      return false;
  }
  // Recursively call the function for the next subarray
  return divideArrHelper(arr, k, startIdx + k);
}

bool divideArr(vector<int> &arr, int k, int startIdx) {
  sort(arr.begin(), arr.end());

  if (arr.size() % k > 0 || k == 0) {
    cout << "false";
    return false;
  }

  if (!divideArrHelper(arr, k, startIdx)) {
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

  // //* Testing Values
  // vector<int> arr = {1, 2, 3, 3, 4, 5, 5, 6};
  // int divSize = 4;

  // arr = {1, 2, 2, 3};
  // divSize = 2;

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
  divideArr(arr, divSize, 0);
}