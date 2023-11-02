#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *deserializeHelper(istringstream &iss) {
  char c;
  iss >> c; // {

  // Check for empty tree
  if (iss.peek() == '}') {
    iss >> c; // }
    return nullptr;
  }

  int value;
  iss >> value;

  TreeNode *root = new TreeNode(value);
  root->left = deserializeHelper(iss);
  root->right = deserializeHelper(iss);

  iss >> c; // }
  return root;
}

TreeNode *deserialize(string data) {
  istringstream iss(data);
  return deserializeHelper(iss);
}

void inorderTraversal(TreeNode *root) {
  if (root) {
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
  }
}

int main() {
  string input;
  getline(cin, input);
  TreeNode *root = deserialize(input);
  inorderTraversal(root);
  cout << endl;
  return 0;
}