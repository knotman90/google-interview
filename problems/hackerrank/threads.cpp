#include <bits/stdc++.h>
#include <functional>
#include <numeric>
#include <thread>

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

//------ PROBLEM CODE --------------
using namespace std;

std::atomic<bool> result(false);
static int id = 0;
template <typename Iterator>
static void parallel2_any_of(Iterator begin, Iterator end, const int id,
                             int poll) {
  int cpoll = 0;
  // cout<<"thread "<<id<<" started\n";
  for (auto it = begin; it != end; ++it, ++cpoll) {
    if (result || (*it) != 0) {
      result = 1 + distance(begin, it);
      return;
    }
  }

  /*int found = false;
  for (auto it = begin; it != end; ++it, ++cpoll) {
    if (cpoll == poll) {
      if (result) return;
      cpoll = 0;
    }
    if ((*it) != 0) {
      result = 1 + distance(begin, it);
      return;
    }
  }*/
}

int main() {
  ios_base::sync_with_stdio(false);
  constexpr size_t lim = 3000000000;
  vector<int> input(lim, 0);

  input[lim / 2+lim/3] = 1;
  constexpr int num_threads = 8;
  size_t chunk_size = input.size() / num_threads;

  auto startt = chrono::steady_clock::now();
  std::vector<std::thread> threads;
  cout << "start" << endl;
  const int n = 50000;
  for (size_t i = 0; i < num_threads; ++i) {
    const auto& begin = input.begin() + i * chunk_size;
    const auto& end =
        input.begin() + std::min((i + 1) * chunk_size, input.size());

    threads.emplace_back(thread(parallel2_any_of<decltype(input.begin())>,
                                begin, end, ++id, n + rand() % 1000));
  }
  for (int i = 0; i < threads.size(); i++) threads[i].join();
  auto endt = chrono::steady_clock::now();
  auto diff = endt - startt;
  if (result)
    cout << "found ->" << result << " in "
         << chrono::duration<double, milli>(diff).count() << " ms " << endl;
  return 0;
}
