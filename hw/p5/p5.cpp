#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct node {
  int val;
  node *left, *right;

  node(int v) : val(v), left(nullptr), right(nullptr) {}
};

node *buildTreeHelper(vector<int> &preO, vector<int> &inO, int inStart,
                      int inEnd, int &preIndex,
                      unordered_map<int, int> &inorderMap) {
  if (inStart > inEnd)
    return nullptr;

  node *root = new node(preO[preIndex++]);
  int inIndex = inorderMap[root->val];
  root->left =
      buildTreeHelper(preO, inO, inStart, inIndex - 1, preIndex, inorderMap);
  root->right =
      buildTreeHelper(preO, inO, inIndex + 1, inEnd, preIndex, inorderMap);

  return root;
}

node *buildTree(vector<int> preO, vector<int> inO) {
  int preIndex = 0;

  unordered_map<int, int> inorderMap;
  for (int i : inO)
    inorderMap[inO[i]] = i;

  return buildTreeHelper(preO, inO, 0, inO.size() - 1, preIndex, inorderMap);
}

void buildPostOrder(node *root, vector<int> &v) {
  if (root) {
    buildPostOrder(root->left, v);
    buildPostOrder(root->right, v);
    v.push_back(root->val);
  }
}

int main() {
  //* Testing Inputs
  // vector<int> preOrder = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  // vector<int> inOrder = {3, 2, 5, 4, 6, 1, 8, 7, 9};
  // int N = preOrder.size();

  // Inputs from cin
  vector<int> preOrder, inOrder;
  string line;
  stringstream ss;
  int c;
  getline(cin, line);
  line.clear();

  // Inputs for pre
  getline(cin, line);
  ss << line;
  while (ss >> c)
    preOrder.push_back(c);
  line.clear();
  ss.clear();

  // Inputs for post
  getline(cin, line);
  ss << line;
  while (ss >> c)
    inOrder.push_back(c);

  int N = preOrder.size();
  node *root = buildTree(preOrder, inOrder);
  vector<int> res;
  buildPostOrder(root, res);

  for (int i = 0; i < N; i++) {
    if (i < N - 1)
      cout << res[i] << " ";
    else
      cout << res[i];
  }
}