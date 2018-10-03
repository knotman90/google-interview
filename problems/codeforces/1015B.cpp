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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  
  int pos = 0;
  auto pos_s = s.begin();
  vector<int> ans;
  while (s != t) {
    auto f = find(pos_s, s.end(), t[pos]);
    if (f == s.end()) {
      cout << -1 << endl;
      return 0;
    }
    auto dist = distance(pos_s, f);
    while (dist > 0) {
      dist--;
      ans.push_back(dist + pos + 1);
      iter_swap(pos_s + dist, pos_s + dist + 1);
    }
    pos++;
    pos_s++;
  }

  cout << ans.size() << endl;
  for (auto a : ans) 
    cout << a << " ";  
  cout << endl;

  return 0;
}