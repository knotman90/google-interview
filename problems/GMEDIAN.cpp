#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

using namespace std;
using l = long;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;

constexpr ll mod = 1000000007ll;

vector<int> fact;
vector<int> A;
int n;

void precompute_fact(const ll lim, const ll mod) {
  fact.resize(lim, 0);
  fact[0] = 1;
  for (ll i = 1; i <= lim; i++) fact[i] = (fact[i - 1] * i) % mod;
}

ll ipow(ll a, ll b, ll MOD) {
  ll x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y);
      if (x > MOD) x %= MOD;
    }
    y = (y * y);
    if (y > MOD) y %= MOD;
    b /= 2;
  }
  return x;
}

/* Modular Multiplicative Inverse
 Using Euler's Theorem
 a^(phi(m)) = 1 (mod m)
 a^(-1) = a^(m-2) (mod m) */
ll InverseEuler(ll n, ll MOD) { return ipow(n, MOD - 2, MOD); }

ll choose(ll n, ll r, ll MOD) {
  if(n==0)
    return 0;
  return (fact[n] *
          ((InverseEuler(fact[r], MOD) * InverseEuler(fact[n - r], MOD)) %
           MOD)) %
         MOD;
}

ll solve() {
  ll ans = n % mod;
  sort(begin(A), end(A));
  for (ll i = 0; i < n; i++) {
    ll smaller = max(0ll, i);
    ll larger = n - i - 1;
    for (ll k = 1; k <= min(smaller, larger); k++) {
     ans += (choose(smaller,k, mod )*choose(larger, k , mod))%mod;
    }
  }
  return ans;
}

int main() {
  precompute_fact(1005, mod);

  int T;
  cin >> T;
  while (T--) {
    A.clear();
    cin >> n;
    A.resize(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];

    cout << solve() << endl;
  }

  return 0;
}