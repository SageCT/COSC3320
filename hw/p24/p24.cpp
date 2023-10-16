#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int text_fitting(vector<int> &wordLens, int &width, int &height) {
  // index, holds which word we are on.
  // spaceTaken, holds how many spaces we've used in the current line.
  // heightI, holds the index of the "row" we are on currently.
  // textCounter, holds how many text we have fit so far.
  int index = 0, count = 0, spaceTaken = 0, heightI = 0, textCounter = 0;
  for (auto i : wordLens)
    count += i + 1;

  // Holds the dp values for each word.
  vector<int> dp(height, 0);

  do {
    if (width >= count) {
      int linesFit = width / count;
      textCounter += linesFit;
      dp[heightI] = textCounter;
      spaceTaken = width - (width % count);
    }

    else
      spaceTaken = 0;

    while (wordLens[index] + 1 <= width - spaceTaken) {
      spaceTaken += wordLens[index++] + 1;

      if (index == wordLens.size()) {
        index = 0;
        dp[heightI] = ++textCounter;
      }
    }
    heightI++;
  } while (heightI < height && index != 0);

  int currHeightI = heightI, i = 0;
  while (currHeightI < height) {
    dp[currHeightI++] = textCounter + dp[i++];
    if (i == dp.size())
      i = 0;
  }
  return dp[height - 1];
}

int main() {
  stringstream ss;
  vector<string> words;
  vector<int> wordLens;
  unordered_map<string, int> memo;
  int width = 0, height = 0;
  string c;
  getline(cin, c), height = stoi(c);
  getline(cin, c), width = stoi(c);
  getline(cin, c);

  ss << c;
  while (ss >> c)
    words.push_back(c);

  for (auto i : words)
    wordLens.push_back(i.size());

  cout << text_fitting(wordLens, width, height);
}