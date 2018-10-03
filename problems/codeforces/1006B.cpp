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

int main() {
  using pii = pair<unsigned, unsigned>;
  unsigned n, k;
  cin >> n >> k;
  vector<pii> V ; V.reserve(n);

  for (unsigned i = 0; i < n; ++i) {
    int a;
    cin >> a;
    V.push_back(make_pair(a, i));
  }

  sort(begin(V), end(V),
       [](const auto p, const auto p1) { return p.first > p1.first; });

  sort(begin(V), begin(V) + k,
       [](const auto p, const auto p1) { return p.second < p1.second; });

  unsigned sum = 0;
  for (unsigned i = 0; i < k; ++i) 
    sum += V[i].first;
  
  cout << sum << endl;
  unsigned start = 0;
  for (unsigned i = 0; i < k - 1; ++i) {
    cout << V[i].second - start + 1 << " ";
    start = V[i].second+1;
  }
  cout << n - start ;
  cout << endl;

  return 0;
}
