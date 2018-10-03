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
  vector<unsigned> V;
  V.reserve(n);
  unsigned totsum = 0;
  for (unsigned i = 0; i < n; ++i) {
    char a;
    cin >> a;
    V.push_back(a - '0');
    totsum += a - '0';
  }

  if (totsum == 0) {
    cout << "YES" << endl;
    return 0;
  }

  for (unsigned sum = 1; sum < totsum; sum++) {
    unsigned sump = 0;
    unsigned idx = 0;
    bool ok = true;
    while (ok && idx < n) {
      while (sump < sum && idx < n) {
        sump += V[idx++];
      }
      if (sump == sum) {
        sump = 0;
      } else if(sump > 0){
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;

  return 0;
}