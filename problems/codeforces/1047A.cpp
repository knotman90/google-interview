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
using pii = pair<int, int>;

//----------------------------------------------

int main() {
  long n;
  cin >> n;
  const long m = mod(n, 3l);

  cout << n - 2 - (m != 0) << " " << 2 - (m == 0) << " " << 1;

  return 0;
}