#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int find_max(vector<int> arr) {
  int max = 0;
  if (arr.size() > 0) {
    max = arr[0];
    int size = arr.size();
    for (int i = 1; i < size; i++)
      if (arr[i] > max)
        max = arr[i];
  }
  return max;
}

int find_min(vector<int> arr) {
  int min = 0;
  if (arr.size() > 0) {
    min = arr[0];
    int size = arr.size();
    for (int i = 1; i < size; i++)
      if (arr[i] < min)
        min = arr[i];
  }

  return min;
}

int highest_return(vector<int> arr) {
  if (arr.size() <= 1)
    return 0;

  int mid = arr.size() / 2;
  vector<int> lArr, rArr;

  if (arr.size() == 2) {
    lArr.push_back(arr[0]);
    rArr.push_back(arr[1]);

  } else {
    for (int i = 0; i < mid; i++)
      lArr.push_back(arr[i]);

    for (int i = mid + 1; i < arr.size(); i++)
      rArr.push_back(arr[i]);
  }

  int left_max = highest_return(lArr);
  int right_max = highest_return(rArr);
  int max_crossing = find_max(rArr) - find_min(lArr);

  return std::max(std::max(left_max, right_max), max_crossing);
}

int main() {
  stringstream ss;
  string line;
  int c;
  vector<int> arr;

  getline(cin, line);
  line.clear();
  getline(cin, line);
  ss << line;

  string oof = "";
  while (ss >> c) {
    arr.push_back(c);
  }
  // cout << oof << endl;
  cout << highest_return(arr) << endl;
}