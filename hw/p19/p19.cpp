#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int helper(vector<int> &arr1, vector<int> &arr2) {
  int index = 0, tempScore = 0, finalScore = 0;
  while (index < arr2.size() - 1) {
    while (tempScore < arr1.size() && arr2[index] > arr1[tempScore])
      tempScore++;
    finalScore += tempScore, index++;
  }
  return finalScore;
}

void merge(vector<int> &robArr, vector<int> &racArr, int left, int mid,
           int right) {

  vector<int> robArrLeft, robArrRight;
  vector<int> racArrLeft, racArrRight;
  int lMid, rMid;

  lMid = mid - left + 1;
  rMid = right - mid;

  // Rob Arr Left and Right
  for (int i = 0; i < lMid; i++)
    robArrLeft.push_back(robArr[i]);
  for (int i = 0; i < lMid; i++)
    robArrRight.push_back(robArr[mid + i + 1]);

  // Rac Arr Left and Right
  for (int i = 0; i < rMid; i++)
    racArrLeft.push_back(robArr[i]);
  for (int i = 0; i < rMid; i++)
    racArrRight.push_back(robArr[mid + i + 1]);

  int robi, robj;
  int raci, racj;
}

void mergeSort(vector<int> &arr1, vector<int> &arr2, int left, int right) {}

int main() {
  vector<int> robArr, racArr;
  int a, robPts, rackPts;
  string line = "";
  stringstream ss;

  getline(cin, line);
  ss << line;
  while (ss >> a)
    robArr.push_back(a);

  ss.clear();
  line.clear();
  getline(cin, line);
  ss << line;
  while (ss >> a)
    racArr.push_back(a);
}