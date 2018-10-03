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
  unsigned n;
  cin >> n;
  long long ans = 0;

  vector<unsigned long long> V;
  V.reserve(n);
  for (unsigned i = 0; i < n; ++i) {
    unsigned long long a;
    cin >> a;
    V.push_back(a);
  }

  unsigned long long suml = 0, sumr = 0;
  unsigned long long pl = 0, pr = n - 1;

  while (pl <= pr) {
    if (suml <= sumr) {
      suml += V[pl++];
      if (sumr == suml) ans = suml;

    } else {
      sumr += V[pr--];
      if (sumr == suml) ans = suml;
    }
  }
  cout << ans << endl;

  return 0;
}
