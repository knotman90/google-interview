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

vector<pair<int, int>> ranges;
vector<ll> fact;
vector<ll> A;
ll n;

void precompute_fact(const ll lim, const ll mod) {
  fact.resize(lim, 0);
  fact[0] = 1;
  for (ll i = 1; i < lim; i++) fact[i] = (fact[i - 1] * i) % mod;
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
  // cout<<n<<" C "<<r<<endl;
  if (n == 0) return 0;
  return (fact[n] *
          ((InverseEuler(fact[r], MOD) * InverseEuler(fact[n - r], MOD)) %
           MOD)) %
         MOD;
}

ll solve() {
  int op = 0;
  ll ans = n % mod;
  sort(begin(A), end(A));
  for (ll i = 0; i < n /*/ 2 + n % 2 == 1*/; i++) {
    ll ansi = 0;
    const ll smaller = max(0ll, i);
    const ll larger = n - i - 1;
    for (ll k = 1; k <= min(smaller, larger); k++) {
      ll v = (choose(smaller, k, mod) * choose(larger, k, mod)) % mod;
      ansi += (choose(smaller, k, mod) * choose(larger, k, mod)) % mod;
      // v *= (n & 1 && i == n / 2) ? 1 : 2;
      ans += v;  // 2*(choose(smaller,k, mod )*choose(larger, k , mod))%mod;

      ans %= mod;
      // op++;
    }
    cout << i << " " << ansi + 1 << endl;
  }
  // cout<<"operations " <<op<<endl;
  // even size
  auto start = A.begin();
  while (start != A.end()) {
    auto rng = equal_range(start, A.end(), *start);
    ranges.push_back(make_pair(distance(A.begin(), rng.first),
                               distance(A.begin(), rng.second - 1)));
    start = rng.second;
  }

  for (const auto p : ranges) {
    if (1 + p.second - p.first >= 2) {
      for (ll i = p.first; i <= p.second; i++) {
        for (ll j = i + 1; j <= p.second; j++) {
          ll smaller = max(0ll, i);
          ll larger = n - j - 1;
          ans += 1;
          // cout<<choose(larger,1,mod)<<endl;
          for (ll k = 1; k <= min(smaller, larger); k++) {
            // cout<<ans<<endl;
            // cout<<"euqual range : i="<<i<<" j="<<j<<"
            /* a_i="<<A[i]<<" smaller="<<smaller<<" larger = "<<larger<<"
             "<<choose(k,smaller,mod)<<" " <<choose(k,larger,mod)<<endl; */
            ans += (choose(smaller, k, mod) * choose(larger, k, mod)) % mod;
          }
        }
      }
    }
  }

  return ans;
}

ll pascal[1005][1005];
void init_pascal(const int n) {
  pascal[0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j >= 1) pascal[i][j] = pascal[i - 1][j - 1];
      if (j < i) pascal[i][j] += pascal[i - 1][j];
      pascal[i][j] %= mod;
      // cout<<pascal[i][j]<<" ";
    }
    // cout<<endl;
  }
}

ll solve2() {
  int op = 0;
  ll ans = 0;
  sort(begin(A), end(A));
  for (ll i = 0; i < n /*/ 2 + n % 2 == 1*/; i++) {
    ans += pascal[n - 1][i];
    ans %= mod;
  }

  auto start = A.begin();
  while (start != A.end()) {
    auto rng = equal_range(start, A.end(), *start);
    ranges.push_back(make_pair(distance(A.begin(), rng.first),
                               distance(A.begin(), rng.second - 1)));
    start = rng.second;
  }

  for (const auto p : ranges) {
    const ll size_range = 1 + p.second - p.first;
   // cout << p.first << " " << p.second << endl;
    for (int i = 2; i <= size_range; i++) {
      //cout << size_range - i + 1 << " intervals of size " << i;
      for (int ff = p.first; ff < p.first + size_range - i + 1; ff++) {
        ans += pascal[n - i][ff];
        ans %= mod;
         //cout<< " add" << pascal[n - i][ff] << endl;
      }
    }
    // ans+= size_range
  }

  return ans;
}

int main() {
  precompute_fact(1005, mod);
  init_pascal(1005);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    A.clear();
    A.resize(n, 0);
    ranges.clear();
    for (int i = 0; i < n; ++i) cin >> A[i];

    cout << solve2() << endl;
  }

  return 0;
}
