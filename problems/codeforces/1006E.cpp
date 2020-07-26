#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

using Children = vector<int>;

struct Node {
  Children children{};
  int num_relatives = 0;
  int idx_visit = 0;
};

int count_children(vector<Node>& S, int node, vector<int>& visit) {
  S[node].idx_visit = visit.size();
  visit.push_back(node);
  if (S[node].children.size() <= 0) return 0;

  for (auto child : S[node].children) {
    S[node].num_relatives += 1 + count_children(S, child, visit);
  }
  return S[node].num_relatives;
}

int main() {
  int n;
  cin >> n;
  int q;
  cin >> q;
  vector<Node> S(n + 5);
  vector<int> visit;
  visit.reserve(n + 5);
  for (int i = 2; i <= n; i++) {
    int a;
    cin >> a;
    S[a].children.push_back(i);
  }

  count_children(S, 1, visit);

  while (q--) {
    int u, k;
    cin >> u >> k;
    if (k-1 > S[u].num_relatives)
      cout << -1 << endl;
    else
      cout << *(visit.begin() + S[u].idx_visit + k - 1) << endl;
  }

  return 0;
}
