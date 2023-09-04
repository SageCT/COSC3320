#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct node {
  int val;
  node *next;
};

vector<int> getPostOrder(int n, vector<int> preO, vector<int> postO) {}

int main() {
  //* Testing Inputs
  int N = 0;
  vector<int> preOrder = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> inOrder = {3, 2, 5, 4, 6, 1, 8, 7, 9};

  // // Inputs from cin
  // vector<int> pre, post;
  // string line;
  // stringstream ss;
  // int c;
  // getline(cin, line);
  // line.clear();

  // // Inputs for pre
  // getline(cin, line);
  // ss << line;
  // while (ss >> c)
  //   pre.push_back(c);

  // // Inputs for post
  // line.clear();
  // getline(cin, line);
  // ss << line;
  // while (ss >> c)
  //   post.push_back(c);
}