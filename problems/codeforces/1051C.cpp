#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// Useful constants
#define INF (int)1e9
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd

#define all(a) begin(a), end(a)
#define in(a, b) ((b).find(a) != (b).end())
#define pb push_back
#define sz(a) ((int)(a.size()))
#define mp make_pair
// Some common useful functions
#define maX(a, b) ((a) > (b) ? (a) : (b))
#define miN(a, b) ((a) < (b) ? (a) : (b))
#define checkbit(n, b) ((n >> b) & 1)

template <typename T>
inline constexpr bool odd(const T& a) {
  return bool(a & 1);
}

template <typename T>
inline constexpr bool even(const T& a) {
  return !odd(a);
}

template <class T>
inline T mod(const T& m, const T& n) {
  return m >= 0 ? m % n : (n - abs(m % n)) % n;
}

using uint = unsigned;
constexpr unsigned S = 105;

using pii = pair<int, int>;

int main() {
  array<int, S> V;
  array<pii, S> ans;
  fill(all(V), 0);
  int n;
  cin >> n;
  const uint nn = n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    V[a]++;
    ans[i] = make_pair(a, 0);
  }
  int num_nice = 0;
  int candidate = -1;
  for (int i = 0; i < S; ++i) {
    if (V[i] == 1)
      num_nice++;
    else if (V[i] >= 3)
      candidate = i;
  }

  if (odd(num_nice) && candidate == -1) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  if (odd(num_nice) && candidate != -1) {
    auto it = find_if(
        all(ans), [&candidate](const auto p) { return p.first == candidate; });
    (*it).second = 1;
  }
  int nice2 = num_nice / 2;
  for (int i = 0; nice2 && i < n; ++i) {
    if (V[ans[i].first] == 1) {
      ans[i].second = 1;
      nice2--;
    }
  }

  for (int i = 0; i < n; ++i) {
    char c = ans[i].second ? 'B' : 'A';
    cout << c;
  }
  cout << endl;

  return 0;
}