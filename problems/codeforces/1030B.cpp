#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

using pii = pair<int, int>;

#define ABS(x) (x >=0 ? x : -x)

int main() {
  int n, d, m;
  cin >> n >> d >> m;

  while (m--) {
    int x, y;
    cin >> x >> y;
    const int s = x + y;
    if (s >= d && s <= 2*n - d && x >= ABS(y - d) && y >= ABS(x - d))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}