#include <cmath>
#include <iostream>
#include <limits>

using namespace std;
using ll = long long;

ll S(ll x) {
  ll sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

inline ll F(const ll x) { return x * x + S(x) * x; }

constexpr ll ITER = 30;
ll solve(const ll l, const ll r, int iter, const ll n) {
  if (l > r) return -1;

  ll mid = l + (r - l) / 2;
  mid = min(r, mid + 10);

  while (iter > 0 && mid >= l) {
    if (F(mid) == n) return mid;
    mid--;
    iter--;
  }

  ll mid2 = l + (r - l) / 2;
  if (mid2 == l) mid2++;

  return solve(mid2, r, ITER, n);
}

int main() {
    long long n;
    cin >> n;
    long long x = floor(sqrt(n));
    cout << solve(1, x, ITER, n) << endl;
  
  return 0;
}