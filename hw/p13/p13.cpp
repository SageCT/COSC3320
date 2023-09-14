#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert values into a binary search tree
TreeNode *insert(TreeNode *root, int val) {
  if (root == nullptr) {
    return new TreeNode(val);
  }
  if (val < root->val) {
    root->left = insert(root->left, val);
  } else {
    root->right = insert(root->right, val);
  }
  return root;
}

// Function to find the lowest common ancestor of two nodes in a binary search
// tree recursively
TreeNode *lowestCommonAncestor(TreeNode *root, int node1, int node2) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->val == node1 || root->val == node2) {
    return root;
  }
  TreeNode *leftLCA = lowestCommonAncestor(root->left, node1, node2);
  TreeNode *rightLCA = lowestCommonAncestor(root->right, node1, node2);
  if (leftLCA && rightLCA) {
    return root;
  }
  return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

// Function to calculate the distance between two nodes in a binary search tree
int findDistance(TreeNode *root, int node1, int node2) {
  TreeNode *lca = lowestCommonAncestor(root, node1, node2);
  int dist1 = 0, dist2 = 0;

  // Calculate distance from LCA to node1
  TreeNode *temp = lca;
  while (temp->val != node1) {
    if (node1 < temp->val) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
    dist1++;
  }

  // Calculate distance from LCA to node2
  temp = lca;
  while (temp->val != node2) {
    if (node2 < temp->val) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
    dist2++;
  }

  return dist1 + dist2;
}

int main() {
  vector<int> values;
  stringstream ss;
  string in;
  int a;

  // * Test values
  //   values = {3, 1, 5, 7, 2, 4};
  //   int node1 = 3, node2 = 4;

  getline(cin, in);
  ss << in;
  while (ss >> a)
    values.push_back(a);
  ss.clear(), in.clear();

  getline(cin, in);
  ss << in;

  int node1, node2;
  ss >> node1 >> node2;
  ss.clear(), in.clear();

  TreeNode *root = nullptr;
  for (int i = 0; i < values.size(); i++)
    root = insert(root, values[i]);

  int distance = findDistance(root, node1, node2);
  cout << distance << endl;

  return 0;
}