#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int text_fitting(
    vector<string> &words, int &width, int &height,
    unordered_map<string, int> memo = unordered_map<string, int>()) {
  int n = words.size();
  vector<int> dp(n, 0);
  for (int i = 0; i < n; i++) {
    int remaining_width = width;
    int remaining_height = height;
    for (int j = i; j < n; j++) {
      if (j > i)
        remaining_width--;
      if (remaining_width < words[j].size())
        break;
      remaining_width -= words[j].size();
      if (remaining_width == 0) {
        remaining_width = width, remaining_height--;
        if (remaining_height < 0)
          break;
      }
      int next_dp = 1;
      if (memo.find(words[j]) != memo.end()) {
        next_dp = memo[words[j]] + 1;
      } else {
        next_dp =
            text_fitting(words, remaining_width, remaining_height, memo) + 1;
        memo[words[j]] = next_dp - 1;
      }
      dp[i] = max(dp[i], next_dp);
    }
  }
  return dp[0];
}

int main() {
  stringstream ss;
  vector<string> words;
  unordered_map<string, int> memo;
  int width = 0, height = 0;
  string c;
  getline(cin, c), height = stoi(c);
  getline(cin, c), width = stoi(c);
  getline(cin, c);

  ss << c;
  while (ss >> c)
    words.push_back(c);

  cout << text_fitting(words, width, height);
}