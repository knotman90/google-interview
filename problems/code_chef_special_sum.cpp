#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;
using l = long;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;

vector<ll> A, B, pref;
int n;
int main() {
  cin >> n;
  A.resize(n, 0);
  B.resize(n, 0);
  pref.resize(n, 0);
  for (int i = 0; i < n; ++i) cin >> A[i];

  for (int i = 0; i < n; ++i) cin >> B[i];

  pref[0] = B[0];
  for (int i = 1; i < n; ++i) pref[i] = pref[i - 1] + B[i];

  ll maxm1 = A[0] - pref[0];
  ll ans = A[0];
  for (int i = 1; i < n; i++) {
    ans = max(ans, A[i] + pref[i - 1] + maxm1);
    ans = max(ans, A[i]);
    maxm1 = max(maxm1, A[i] - pref[i]);
  }

  ll maxm2 = A[0];
  for (int i = 1; i < n; i++) {
    ans = max(ans, A[i] + pref.back() - pref[i] + maxm2);
    maxm2 = max(maxm2, A[i] + pref[i-1]);
  }
  cout << ans << endl;

  return 0;
}