#include <bits/stdc++.h>
#include <functional>
#include <numeric>

// Useful constants
#define INF (int)1e9
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
// Useful container manipulation / traversal macros
#define forall(i, a, b) for (int i = a; i < b; i++)
#define foreach(v, c) \
  for (typeof((c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define pb push_back
#define sz(a) ((int)(a.size()))
#define mp make_pair
// Some common useful functions
#define maX(a, b) ((a) > (b) ? (a) : (b))
#define miN(a, b) ((a) < (b) ? (a) : (b))
#define checkbit(n, b) ((n >> b) & 1)
#define DREP(a) \
  sort(all(a)); \
  a.erase(unique(all(a)), a.end())
#define INDEX(arr, ind) (lower_bound(all(arr), ind) - arr.begin())

// incremental loops
#define loop0n(i, n) for (int i = 0; i < n; ++i)
#define loopse(i, s, e) for (int i = s; i < e; ++i)
#define loopsei(i, s, e, inc) for (int i = s; i < e; i += inc)
// decremental loops
#define dloop0n(i, n) for (int i = n; i >= 0; --i)
#define dloopse(i, s, e) for (int i = s; i >= e; --i)
#define dloopsei(i, s, e, inc) for (int i = s; i >= e; i -= inc)
#define GET_LOOP(_1, _2, _3, _4, NAME, ...) NAME
#define LOOPUP(...)                              \
  GET_LOOP(__VA_ARGS__, loopsei, loopse, loop0n) \
  (__VA_ARGS__)
#define LOOPDWN(...)                                \
  GET_LOOP(__VA_ARGS__, dloopsei, dloopse, dloop0n) \
  (__VA_ARGS__)

#define pb push_back
#define ALL(v) v.begin(), v.end()

// for map, pair
#define mp make_pair
#define fi first
#define se second
// char to int
inline constexpr int ctoi(const char c) { return c - '0'; }
// int to char
inline constexpr char itoc(const int n) { return n + '0'; }

template <typename T>
inline T clamp(const T& n, const T& lo, const T& hi) {
  return std::max(lo, std::min(n, hi));
}

template <class T>
inline void sort(T& a) {
  std::sort(ALL(a));
}

template <class T1, class T2>
inline void sort(T1& a, T2 comp) {
  sort(ALL(a), comp);
}

template <class T>
inline int read(T& n) {
  return std::cin >> n ? 1 : -1;
}
// reads multiple arguments
template <typename T, typename... types>
inline int read(T& n, types&... args) {
  return read(n) == -1 ? -1 : read(args...) + 1;
}

template <class T>
inline void write(const T& n) {
  std::cout << n;
}
// reads multiple arguments
template <typename T, typename... types>
inline void write(const char sep, T& n, types&... args) {
  write(n);
  write(sep);
  write(sep, args...);
}

template <typename T>
inline constexpr bool odd(const T a) {
  return bool(a & 1);
}

template <typename T>
inline constexpr bool even(const T a) {
  return !odd(a);
}

template <class T>
inline unsigned int mod(const T m, const T n) {
  return m >= 0 ? m % n : (n - abs(m % n)) % n;
}

template <class T>
class reader {
 public:
  void operator()(T& t) const { std::cin >> t; }
};

template <class CONTAINER, class READ_Fn>
void read(CONTAINER& v, const unsigned int size,
          const READ_Fn& rfn = reader<typename CONTAINER::value_type>()) {
  loop0n(i, size) { rfn(v[i]); }
}

// TYPEDEFS
typedef unsigned long ul;
typedef unsigned long long ull;
typedef signed long l;
typedef signed long long ll;
typedef unsigned int uint;

using vi = std::vector<int>;

typedef std::pair<l, l> pll;
typedef std::pair<int, int> pii;
typedef std::pair<uint, uint> puu;

// sort pair based on their first component. If equal it uses the second ones.
auto pair_cmp = [](const pll& p1, const pll& p2) {
  return (p1.first > p2.first) ||
         (p1.first == p2.first && p1.second < p2.second);
};

// integer power (base^exp)
template <class T>
T ipow(T base, T exp) {
  T result = 1;
  while (exp) {
    if (exp & 1) result *= base;
    exp >>= 1;
    base *= base;
  }

  return result;
}

// case counter variable
static int _case_counter = 1;
template <typename T>
void printCase(const T& arg) {
  std::cout << "Case #" << _case_counter++ << ": ";
  write(arg);
  write('\n');
}

template <typename... types>
void printCase(const char sep = ' ', types&... args) {
  std::cout << "Case #" << _case_counter++ << ": ";
  write(sep, args...);
  write('\n');
}

// gcd of two number
template <class M, class N>
M gcds(M& m, N& n) {
  return std::__gcd(m, n);
}

// gcd of N numbers
template <class M, class N, class... Params>
M gcds(M& m, N& n, Params&... args) {
  return gcd(std::__gcd(m, n), args...);
}
// gcd of a set of numbers in a container
template <typename CONTAINER>
int gcdc(CONTAINER& c) {
  typename CONTAINER::value_type g = c[0];
  for (int i = 1; i < c.size(); i++) {
    g = std::__gcd(g, c[i]);
  }
  return g;
}

// Lambda has type: D -> T -> D
template <typename D, typename Iterator, typename Lambda>
D fold(Iterator s, Iterator e, const D& a, Lambda l) {
  D acc = a;
  while (s != e) {
    acc = l(acc, *s);
    s++;
  }
  return acc;
}

//------ PROBLEM CODE --------------

using namespace std;

int main() {
  int s,v1,v2,t1,t2;
  read(s,v1,v2,t1,t2);
  const int tot1 = s*v1+2*t1;
  const int tot2 = s*v2+2*t2;

  if(tot1 < tot2)
    cout<<"First";
  else if (tot2 < tot1)
    cout<<"Second";
  else
    cout<<"Friendship";
  cout<<endl;

  
  return 0;
}
