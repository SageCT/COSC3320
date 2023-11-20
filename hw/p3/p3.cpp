#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int ans = INT32_MAX;

void solve(vector<int> &a, int j, vector<int> &bags) {
  if (j == a.size()) {
    ans = min(ans, *max_element(bags.begin(), bags.end()));
    return;
  }
  for (int i = 0; i < bags.size(); i++) {
    bags[i] += a[j];
    if (bags[i] < ans)
      solve(a, j + 1, bags);
    bags[i] -= a[j];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.rbegin(), a.rend());

  vector<int> bags(k, 0);
  solve(a, 0, bags);
  cout << ans;
}