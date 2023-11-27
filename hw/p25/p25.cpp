#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Job {
  int start, end, profit;
};

bool compare(Job a, Job b) { return a.end < b.end; }

// Binary search function to find the latest job (in the sorted array)
// that doesn't conflict with the job[i] and returns its index
int latestNonConflict(vector<Job> &jobs, int i) {
  int low = 0, high = i - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (jobs[mid].end <= jobs[i].start) {
      if (jobs[mid + 1].end <= jobs[i].start)
        low = mid + 1;
      else
        return mid;

    } else
      high = mid - 1;
  }
  return -1;
}

int findMaxProfit(vector<int> &start, vector<int> &end, vector<int> &profit) {
  int n = start.size();
  vector<Job> jobs(n);
  // Setting values for the vector of jobs
  for (int i = 0; i < n; i++)
    jobs[i].start = start[i], jobs[i].end = end[i], jobs[i].profit = profit[i];
  sort(jobs.begin(), jobs.end(), compare);

  vector<int> dp(n);
  dp[0] = jobs[0].profit;

  // Fill the dp table using tabulation

  for (int i = 1; i < n; i++) {
    int inclProfit = jobs[i].profit;
    int l = latestNonConflict(jobs, i);
    if (l != -1)
      inclProfit += dp[l];
    dp[i] = max(inclProfit, dp[i - 1]);
  }

  return dp[n - 1];
}

int main() {
  string temp;
  stringstream ss;
  vector<int> startTimes, endTimes, profits;
  int a;

  // Get start times
  getline(cin, temp);
  ss << temp;
  while (ss >> a)
    startTimes.push_back(a);

  temp.clear();
  ss.clear();

  // Get end times
  getline(cin, temp);
  ss << temp;
  while (ss >> a)
    endTimes.push_back(a);

  temp.clear();
  ss.clear();

  // Get profits
  getline(cin, temp);
  ss << temp;
  while (ss >> a)
    profits.push_back(a);

  cout << findMaxProfit(startTimes, endTimes, profits);
}