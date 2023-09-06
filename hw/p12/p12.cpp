#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void divideArrHelper(vector<int> &arr, int k, int startIdx, int n) {
  if (startIdx + k > arr.size() || n == k)
    return;

  // Add the subarray of size k starting from the current index
  auto minElement = std::min_element(arr.begin(), arr.end());
  arr.erase(minElement);
  minElement = std::min_element(arr.begin(), arr.end());

  return (arr[*minElement] == n + 1) ? divideArrHelper(arr, k, startIdx, n + 1)
                                     : false;

  // Recursively call the function for the next subarray
  divideArrHelper(arr, k, startIdx + k, n);
}

bool divideArr(vector<int> &arr, int k, int startIdx) {

  sort(arr.begin(), arr.end());

  if (arr.size() % k > 0 || k == 0) {
    cout << "false";
    return false;
  }

  else {
    for (int i = 0; i < arr.size() / k; i++)
      divideArrHelper(arr, k, startIdx + (k * i), arr[k * i]);
    return true;
  }
}

// string checkIfConsec(vector<vector<int>> &arr, int k) {
//   int test = -1;
//   bool asc = true;

//   for (int i = 0; i < arr.size(); i++) {
//     // Check if the section is ascending or descending
//     int test = -1;
//     (arr[i][0] < arr[i][1]) ? asc = true : asc = false;

//     for (int j = 0; j < k; j++) {
//       if (asc) {
//         if (test < arr[i][j])
//           test = arr[i][j];
//         else
//           return "false";
//       } else {
//         test = 2000000000;
//         if (test > arr[i][j])
//           test = arr[i][j];
//         else
//           return "false";
//       }
//     }
//   }
//   return "true";
// }

int main() {
  stringstream ss;
  vector<int> arr;
  vector<vector<int>> res;
  string line;
  int c, divSize;

  // //* Testing Values
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

  if (divideArr(arr, divSize, 0))
    ;
}