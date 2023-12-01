
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

class Graph {
  int V;
  vector<vector<int>> adj;

  void fillOrder(int v, vector<bool> &, stack<int> &);

  void DFSUtil(int v, vector<bool> &, vector<int> &);

public:
  Graph(int V);
  void addEdge(int v, int w);

  vector<vector<int>> SCC();

  Graph getTranspose();
};

Graph::Graph(int V) {
  this->V = V;
  adj.resize(V);
}

void Graph::addEdge(int v, int w) { adj[v].push_back(w); }

void Graph::fillOrder(int v, vector<bool> &visited, stack<int> &Stack) {
  visited[v] = true;

  for (int i : adj[v])
    if (!visited[i])
      fillOrder(i, visited, Stack);

  Stack.push(v);
}

void Graph::DFSUtil(int v, vector<bool> &visited, vector<int> &component) {
  visited[v] = true;
  component.push_back(v);

  for (int i : adj[v])
    if (!visited[i])
      DFSUtil(i, visited, component);
}

Graph Graph::getTranspose() {
  Graph g(V);
  for (int v = 0; v < V; v++)
    for (int i : adj[v])
      g.adj[i].push_back(v);

  return g;
}

vector<vector<int>> Graph::SCC() {
  stack<int> Stack;

  vector<bool> visited(V, false);
  for (int i = 0; i < V; i++)
    if (!visited[i])
      fillOrder(i, visited, Stack);

  Graph gr = getTranspose();

  for (int i = 0; i < V; i++)
    visited[i] = false;

  vector<vector<int>> scc;
  while (!Stack.empty()) {
    int v = Stack.top();
    Stack.pop();

    if (!visited[v]) {
      vector<int> component;
      gr.DFSUtil(v, visited, component);
      scc.push_back(component);
    }
  }
  return scc;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n + 1); // adj[0] is unused.
  for (int i = 1; i <= n; i++) {
    int j;
    cin >> j;
    // assert(i == j);
    int d;
    cin >> d;
    // cout << "node " << j << " degree " << d << endl;
    for (int k = 0; k < d; k++) {
      int l;
      cin >> l;
      adj[i].push_back(l);
    }

    for (int j = 1; j <= n; j++) {
      cout << j << ": ";
      for (int k : adj[j]) {
        cout << k << " ";
      }
      cout << endl;
    }
  }

  int count = 0;
  /* compute the number of strong components in the graph adj[1...n]! */
  // scc(adj, n);

  cout << count << endl;
  return 0;
}