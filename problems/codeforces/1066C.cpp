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

using Shelf = unordered_map<int, int>;

inline void add(const char c, const int idx, Shelf& L, Shelf& R) {
  Shelf& S = (c == 'L') ? L : R;
  S[idx] = S.size();
}

int query(const int idx, const Shelf& L, const Shelf& R) {
  const Shelf* s  = &L;
  const Shelf* s1 = &R;
  auto it = L.find(idx);
  if (it == L.end())
  {
    it = R.find(idx);
    swap(s, s1);
  }
  const int ans1 = s->size() - it->second - 1;
  const int ans2 = s1->size() + it->second;
  return min(ans1, ans2);
}

int main() {
  int n;
  cin >> n;
  Shelf L, R;
  while (n--) {
    char c;
    cin >> c;
    int idx;
    cin >> idx;
    if (c != '?') {
      add(c, idx, L, R);
    } else {
      const int ans = query(idx, L, R);
      cout << ans << endl;
    }
  }

  return 0;
}