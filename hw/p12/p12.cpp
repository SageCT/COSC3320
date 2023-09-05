#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void divideArr(vector<int> &arr, vector<vector<int>> &res, int k,
               int startIdx) {
  int n = arr.size();
  vector<int> toAdd;

  sort(arr.begin(), arr.end());

  if (startIdx >= n)
    return;

  // Print the subarray of size k starting from the current index
  for (int i = startIdx; i < min(startIdx + k, n); i++)
    toAdd.push_back(arr[i]);

  res.push_back(toAdd);
  // Recursively call the function for the next subarray
  divideArr(arr, res, startIdx + k, k);
}

bool checkIfConsec(vector<vector<int>> &arr, int k) {
  if (k == 0)
    return true;

  int test = -1;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < k; j++) {

      if (test < arr[i][j])
        test = arr[i][j];
      else if (test >= arr[i][j])
        return false;
    }
  }
  return true;
}

int main() {
  stringstream ss;
  vector<int> arr;
  vector<vector<int>> res;
  string line;
  int c, divSize;

  //* Testing Values
  arr = {1, 2, 3, 3, 4, 5, 5, 6};
  divSize = 4;

  // * Input Handling
  // getline(cin, line);
  // ss << line;

  // while (ss >> c)
  //   arr.push_back(c);
  // line.clear();
  // ss.clear();

  // getline(cin, line);
  // ss >> c;
  // divSize = c;

  divideArr(arr, res, divSize, 0);
}