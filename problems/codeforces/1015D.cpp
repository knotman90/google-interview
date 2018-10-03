#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <vector>

template<class N>
inline N iceil(const N& n, const N& d)
{
  return (n+d-1)/d;
}


using namespace std;

int main() {
  long long n, k, s;
  cin >> n >> k >> s;

  const long long maxd = n - 1;
  if (s > k * maxd || k > s) {
    cout << "NO" << endl;
    return 0;
  }
  
  cout << "YES" << endl;
  int up = 1;
  long long start = 1;
  while (s) {
    const long long leap = iceil(s,k);
    k--;
    s -= leap;
    start += up * leap;
    up = -up;
    cout << start << " ";
  }
  cout << endl;

  return 0;
}