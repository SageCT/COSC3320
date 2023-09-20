#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int robPts = 0, racPts = 0;

int helper(vector<int> &arr1, vector<int> &arr2) {
  int index = 0, tempScore = 0, finalScore = 0;
  while (index < arr2.size()) {
    while (tempScore < arr1.size() && arr2[index] > arr1[tempScore])
      tempScore++;
    finalScore += tempScore;
    index++;
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

  // Rob and Rac Arr Left
  for (int i = 0; i < lMid; i++)
    robArrLeft.push_back(robArr[left + i]),
        racArrLeft.push_back(racArr[left + i]);

  // Rob and Rac Arr Right
  for (int i = 0; i < rMid; i++)
    robArrRight.push_back(robArr[mid + i + 1]),
        racArrRight.push_back(racArr[mid + i + 1]);

  robPts += helper(racArrLeft, robArrRight);
  racPts += helper(robArrLeft, racArrRight);

  int robi = 0, robj = 0;
  int raci = 0, racj = 0;
  int robIndex = left, racIndex = left;

  // ? n1 = lMid n2 = rMid
  // ? rob merge section
  while (robi < lMid && robj < rMid) {
    if (robArrLeft[robi] <= robArrRight[robj]) {
      robArr[robIndex] = robArrLeft[robi++];
    } else {
      robArr[robIndex] = robArrRight[robj++];
    }
    robIndex++;
  }

  while (robi < lMid)
    robArr[robIndex++] = robArrLeft[robi++];

  while (robj < rMid)
    robArr[robIndex++] = robArrRight[robj++];

  // ? n1 = lMid n2 = rMid
  // ? rac merge section
  while (raci < lMid && racj < rMid) {
    if (racArrLeft[raci] <= racArrRight[racj]) {
      racArr[racIndex] = racArrLeft[raci++];
    } else {
      racArr[racIndex] = racArrRight[racj++];
    }
    racIndex++;
  }

  while (raci < lMid)
    racArr[racIndex++] = racArrLeft[raci++];

  while (racj < rMid)
    racArr[racIndex++] = racArrRight[racj++];
}

void mergeSort(vector<int> &arr1, vector<int> &arr2, int left, int right) {

  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(arr1, arr2, left, mid);
    mergeSort(arr1, arr2, mid + 1, right);

    merge(arr1, arr2, left, mid, right);
  }
}

int main() {
  vector<int> robArr, racArr;
  int a;
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

  mergeSort(robArr, racArr, 0, robArr.size() - 1);
  cout << robPts << " " << racPts;
}