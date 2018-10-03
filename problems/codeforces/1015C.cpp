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
  long long n,m, sum=0;
  cin >> n>>m;

  vector<int> c;
  c.reserve(n);
  while (n--) {
    int a, b;
    cin >> a >> b;
    c.push_back(a - b);
    sum += a;
  }
  sort(begin(c), end(c), std::greater<int>());

  unsigned ans = 0;
  for (; sum > m && ans < c.size(); sum -= c[ans++])
    ;

  if (sum <= m)
    cout << ans;
  else
    cout << -1;
  cout << endl;

  return 0;
}