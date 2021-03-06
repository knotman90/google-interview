#include <bits/stdc++.h>

#include <gmpxx.h>
#include <functional>
#include <numeric>

// Useful constants
#define INF (int)1e9
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd
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

#define BIT(n, i) ((n >> i) & 1)
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

template <class T>
int magnitude(T n) {
  int m = 0;
  while (n) {
    m++;
    n /= 10;
  }
  return m;
}

template <class T>
T ipow(T base, uint exp) {
  T result = 1;
  while (exp) {
    if (exp & 1) result *= base;
    exp >>= 1;
    base *= base;
  }

  return result;
}

// remove all elements from col which satisfies the predicate pre
template <typename Collection, typename Predicate>
void filterNot(Collection& col, Predicate pre) {
  auto returnIterator = std::remove_if(col.begin(), col.end(), pre);
  col.erase(returnIterator, std::end(col));
}

// remove elements that do not satisfy the predicate
template <typename Collection, typename Predicate>
void filter(Collection& col, Predicate predicate) {
  filterNot(col, [predicate](typename Collection::value_type i) {
    return !predicate(i);
  });
}

template <typename Collection, typename unop>
void map(Collection& col, unop op) {
  std::transform(col.begin(), col.end(), col.begin(), op);
}
// TYPEDEFS
typedef unsigned long ul;
typedef unsigned long long ull;
typedef signed long l;
typedef signed long long ll;
typedef unsigned int uint;

typedef std::pair<l, l> pll;
typedef std::pair<int, int> pii;
typedef std::pair<double, double> pdd;
typedef std::pair<long double, long double> pldd;
typedef std::pair<uint, uint> puu;

// sort pair based on their first component. If equal it uses the second ones.
auto pair_cmp = [](const pll& p1, const pll& p2) {
  return (p1.first < p2.first) ||
         (p1.first == p2.first && p1.second < p2.second);
};

// high order fucntion functions

//------ PROBLEM CODE --------------

using namespace std;

typedef array<short, 10> digits;

template <class T>
void intToDigits(T n, digits& ds) {
  while (n > 0) {
    ds[n % 10]++;
    n /= 10;
  }
}

bool sameDigits(const digits& ds, const digits& dk, const int s = 0,
                const int e = 10) {
  for (int i = s; i < e; i++)
    if (ds[i] != dk[i]) return false;
  return true;
}

void getPrimesSieve(vector<long long>& primes, const ll n) {
  vector<bool> nums(n + 1, true);
  primes.push_back(2);
  for (ll i = 3; i * i < n + 1; i += 2) {
    if (nums[i]) {
      for (ll j = i * i; j < n + 1; j += 2 * i) {
        nums[j] = false;
      }
    }
  }

  for (ll i = 3; i <= n; i += 2)
    if (nums[i]) primes.push_back(i);
}

void getPrimes(vector<long long>& primes, const ll n, const ll s = 2) {
  if (s <= 2) primes.push_back(2);
  for (int i = s; i <= n; i += 2) {
    bool p = true;
    for (int j = 2; p && j <= sqrt(i); j++) {
      if (i % j == 0) p = false;
    }
    if (p) primes.push_back(i);
  }
}

inline bool goodDigits(const digits& d, const int s, const int e) {
  for (int i = s; i < e; i++)
    if (d[i] > 1) return false;
  return true;
}

void solve38() {
  ll LIM = 987654321;
  digits target = {0};
  intToDigits(LIM, target);
  for (ll i = 1; i < 10000; i++) {
    ll n = 0;
    ll k = 0;
    digits dn = {0};
    intToDigits(n, dn);
    while (!sameDigits(target, dn, 1, 10) && dn[0] == 0) {
      k++;
      n = i * k;
      intToDigits(n, dn);
      if (!goodDigits(dn, 1, 10)) break;
    }
    if (k > 1 && sameDigits(target, dn, 1, 10) && dn[0] == 0) {
      cout << i << "->";
      for (int j = 1; j <= k; j++) cout << i * j << "";
      cout << endl;
    }
  }
}

void solve17() {
  unordered_map<int, int> map;
  ll ans = 4;  // zero
  map[1] = 3;
  map[2] = 3;
  map[3] = 5;
  map[4] = 4;
  map[5] = 5;
  map[6] = 3;
  map[7] = 5;
  map[8] = 5;
  map[9] = 4;
  map[10] = 3;
  map[11] = 6;
  map[12] = 6;
  map[13] = 8;
  map[20] = 6;
  map[30] = 7;
  map[40] = 6;
  map[50] = 5;
  map[60] = 5;
  map[70] = 7;
  map[80] = 6;
  map[90] = 6;
  map[100] = 7;
  for (int i = 1; i < 13; i++) {
    ans += map[i];
  }
  for (int i = 14; i < 20; i++) {
    int d = i % 10;
    ans += map[d] + 4;
  }

  for (int i = 21; i <= 99; i++) {
    int d = i % 10;
    if (d != 0) ans += map[d] + 3 + map[i - d];
  }

  for (int i = 100; i < 1000; i++) {
    int n = i;
    int d0 = n % 10;
    n /= 10;
    int d1 = n % 10;
    n /= 10;
    int d2 = n % 10;
    ans += map[d2] + map[100];
    if (d1) {
      ans += map[d1 * 10];
      if (d2) ans += 1 + map[d1];
    }
  }
}

bool isPandigital(const digits& dn, const int s, const int e) {
  int i = s;
  for (; i < e; i++) {
    if (dn[i] > 1) return false;
    if (!dn[i]) break;
  }
  for (; i < e; i++)
    if (dn[i]) return false;

  return true;
}

void solve43() {
  bool go = true;
  digits dn = {0};
  ll ans = 0;
  for (int i1 = 1; i1 <= 9; dn[i1]--, go = true, i1++) {
    dn[i1]++;
    go = goodDigits(dn, 0, 10);

    for (int i2 = 0; go && i2 <= 9; dn[i2]--, go = true, i2++) {
      dn[i2]++;
      go = goodDigits(dn, 0, 10);

      for (int i3 = 0; go && i3 <= 9; dn[i3]--, go = true, i3++) {
        dn[i3]++;
        go = goodDigits(dn, 0, 10);

        for (int i4 = 0; go && i4 <= 9; dn[i4]--, go = true, i4++) {
          dn[i4]++;
          go = goodDigits(dn, 0, 10);
          int d24 = 100 * i2 + 10 * i3 + i4;
          go = go && (d24 % 2 == 0);

          for (int i5 = 0; go && i5 <= 9; dn[i5]--, go = true, i5++) {
            dn[i5]++;
            go = goodDigits(dn, 0, 10);
            int d35 = 100 * i3 + 10 * i4 + i5;
            go = go && (d35 % 3 == 0);

            for (int i6 = 0; go && i6 <= 9; dn[i6]--, go = true, i6++) {
              dn[i6]++;
              go = goodDigits(dn, 0, 10);
              int d46 = 100 * i4 + 10 * i5 + i6;
              go = go && (d46 % 5 == 0);

              for (int i7 = 0; go && i7 <= 9; dn[i7]--, go = true, i7++) {
                dn[i7]++;
                go = goodDigits(dn, 0, 10);
                int d57 = 100 * i5 + 10 * i6 + i7;
                go = go && (d57 % 7 == 0);

                for (int i8 = 0; go && i8 <= 9; dn[i8]--, go = true, i8++) {
                  dn[i8]++;
                  go = goodDigits(dn, 0, 10);
                  int d68 = 100 * i6 + 10 * i7 + i8;
                  go = go && (d68 % 11 == 0);

                  for (int i9 = 0; go && i9 <= 9; dn[i9]--, go = true, i9++) {
                    dn[i9]++;
                    go = goodDigits(dn, 0, 10);
                    int d79 = 100 * i7 + 10 * i8 + i9;
                    go = go && (d79 % 13 == 0);

                    for (int i10 = 0; go && i10 <= 9;
                         dn[i10]--, go = true, i10++) {
                      dn[i10]++;
                      go = goodDigits(dn, 0, 10);
                      int d810 = 100 * i8 + 10 * i9 + i10;
                      go = go && (d810 % 17 == 0);

                      if (go && isPandigital(dn, 0, 10)) {
                        int nn = 0;
                        // printf("-------%d%d%d%d%d%d%d%d%d%d ---
                        // %d,%d,%d,%d\n",i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,d24,d35,d46,d57);
                        auto multsum = [](const ll& a, ll& n) {
                          n = n * 10 + a;
                        };
                        ll n = 0;
                        multsum(i1, n);
                        multsum(i2, n);
                        multsum(i3, n);
                        multsum(i4, n);
                        multsum(i5, n);
                        multsum(i6, n);
                        multsum(i7, n);
                        multsum(i8, n);
                        multsum(i9, n);
                        multsum(i10, n);
                        ans += n;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}

// problem 60 ----------------------------------

inline long long concat(const long long i, const long long j) {
  return i * pow10(magnitude(j)) + j;
}

bool primalityTest(const long long n) {
  for (long i = 2; i <= sqrt(n) + 1; i++)
    if (n % i == 0) return false;
  return true;
}

void solve60() {
  constexpr const long LIMP = 30000;
  constexpr const int LIM = 2000;
  vector<ll> primes;
  getPrimesSieve(primes, LIMP);

  unordered_map<long long, bool> concatPrime;

  auto isPrime = [&](const long long& n) {
    if (concatPrime.find(n) == concatPrime.end())
      concatPrime[n] = primalityTest(n);

    return concatPrime[n];

  };
  auto goodSet = [&](const array<long long, 5>& vec, const int p) {
    for (int i = 0; i < p; i++) {
      if (!(isPrime(concat(vec[i], vec[p])) && isPrime(concat(vec[p], vec[i]))))
        return false;
    }
    return true;
  };
  bool go = true;
  array<long long, 5> pset = {0, 0, 0, 0, 0};
  for (int i = 1; i < LIM; i++) {
    pset[0] = primes[i];
    for (int j = i + 1; j < LIM; j++) {
      pset[1] = primes[j];
      if (goodSet(pset, 1)) {
        for (int l = j + 1; l < LIM; l++) {
          pset[2] = primes[l];
          if (goodSet(pset, 2)) {
            for (int k = l + 1; k < LIM; k++) {
              pset[3] = primes[k];
              if (goodSet(pset, 3)) {
                // printf("%d %d %d %d \n" , primes[i],primes[j],primes[l] ,
                // primes[k]);
                for (int m = k + 1; m < LIM; m++) {
                  pset[4] = primes[m];
                  if (goodSet(pset, 4)) {
                    printf("%d +%d +%d +%d +%d= %d\n", primes[i], primes[j],
                           primes[l], primes[k], primes[m],
                           primes[i] + primes[j] + primes[l] + primes[k] +
                               primes[m]);
                    return;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

// end of problem 60

void solve41() {
  vector<long long> primes;
  // getPrimesSieve(primes,987654321);
  // no prime can be made by using once all 9 digits because
  // 1+2+3+4+5+6+7+8+9=45
  // which is divisible by 3. Any number which digits are divisible by 3 is
  // divisible by 3!
  // same reasoning for 8. we can limit our search to 7654321
  getPrimesSieve(primes, 7654321);
  for (int i = primes.size() - 1; i >= 0; i--) {
    digits dn = {0};
    intToDigits(primes[i], dn);
    if (isPandigital(dn, 1, 10) &&
        dn[0] == 0) {  // 0 digit has not to be present in 1-n pandigital
      cout << primes[i] << endl;
      break;
    }
  }
}

void solve70(const int size) {
  vector<long long> primes;
  getPrimes(primes, 1000000);
  double m = LONG_MAX;
  for (ll n = 0; n < primes.size(); n++) {
    for (ll k = n + 1; k < primes.size(); k++) {
      ll b = primes[n] * primes[k];
      ll phi = b - primes[n] - primes[k] + 1;
      if (b <= size) {
        digits dn = {0};
        intToDigits(b, dn);
        digits dk = {0};
        intToDigits(phi, dk);
        double ratio = (double)b / (double)phi;
        if (sameDigits(dn, dk) && ratio < m) {
          m = ratio;
          cout << primes[n] << " " << primes[k] << " " << b << " " << phi << " "
               << m << endl;
        }
      } else
        break;
    }
  }
}

#include "InfInt.h"
template <class T>
T MCD(const T& n, const T& d) {
  T r = n - d * (n / d);
  if (r == 0) return d;
  return MCD<T>(d, r);
}

template <class T>
class Rational {
 public:
  T num;
  T den;
  Rational(const T& _num, const T& _den) : num(_num), den(_den) {}

  void simplify() {
    T mcd = MCD(min(num, den), max(num, den));
    while (mcd > 1) {
      num /= mcd;
      den /= mcd;
      mcd = MCD(num, den);
    }
  }
  Rational operator*(const Rational& p) {
    Rational r(*this);
    r.num *= p.num;
    r.den *= p.den;
    r.simplify();
    return r;
  }
  Rational operator/(const Rational& p) {
    Rational pp(p.den, p.num);
    Rational r(*this);
    return r * pp;
  }
  Rational operator+(const Rational& p) {
    Rational r(*this);
    T nden = p.den * r.den;
    T nnum = (nden / r.den) * r.num + (nden / p.den) * p.num;
    r.num = nnum;
    r.den = nden;
    r.simplify();
    return r;
  }
  void show() { cout << num << "/" << den; }
};

typedef Rational<InfInt> Rati;

Rati compute(int it, int k, const int limit) {
  Rati t(1, 1);
  Rati one(1, 1);

  if (it % 3 == 1) {
    k++;
    t.num = 2 * k;
  }

  if (it == limit) return t;

  Rati res = one / compute(it + 1, k, limit);
  Rati ans = (t + res);
  ans.simplify();
  return ans;

  return ans;
}
void solve() {
  int limit = 300;
  int start = 1;

  Rati two(2, 1);
  Rati one(1, 1);
  (two + (one / compute(0, 0, limit))).show();
  // the use the followings on ghci to get the sum of the digits in the
  // numerator
  // let n = intToList (numeratorfromTheOutput)
  // foldr (\x acc-> (digitToInt x) +acc) 0 n
}

void solve72() {
  typedef long double ld;
  ld minimum = -1000;
  int n = 1;
  const int LIM = 1000000;
  while (n < LIM) {
    int limit = (n * 7) / 3;
    int c = 0;
    while (limit <= LIM) {
      if (MCD(n, limit) == 1) { /*&& ratio > minimum*/
        c++;
        printf("new minimum = %d/%d=%d\n", n, limit, c);
        break;
      }

      limit++;
    }
    n++;
  }

  printf("\n");
}
void solve71() {
  typedef long double ld;
  ld minimum = -1000;
  int n = 1;
  const int LIM = 1000000;
  while (n < LIM) {
    int limit = (n * 7) / 3;
    int c = 0;
    while (limit <= LIM) {
      ld ratio = (long double)n / (long double)limit;
      if (ratio < minimum) break;
      if (MCD(n, limit) == 1 && ratio < (3.0 / 7.0) /*&& ratio > minimum*/) {
        ld diff = 3.0 / 7.0 - ratio;
        minimum = ratio;
        printf("new minimum = %d/%d=%.20Lf %.20Lf\n", n, limit, ratio, diff);
        break;
      }

      limit++;
    }
    n++;
  }

  printf("\n");
}

void solve73() {
  ll ans = 0;
  int n = 1;
  const int LIM = 12000;
  while (n < LIM) {
    int lowerBound = 2 * n;
    int upperBound = 3 * n;
    int c = 0;
    int limit = lowerBound + 1;
    while (limit < upperBound && limit <= LIM) {
      if (MCD(n, limit) == 1) {
        ans++;
        // printf("%d/%d\n", n,limit);
      }

      limit++;
    }
    n++;
  }

  printf("%d\n", ans);
}

template <class T>
T phi(T n) {
  T result = n;
  for (T i = 2; i * i <= n; i++) {
    if (n % i == 0) result -= result / i;
    while (n % i == 0) n /= i;
  }
  if (n > 1) result -= result / n;
  return result;
}
void solve72_real() {
  ll limit = 1000000;
  ll ans = 0;
  for (ll i = 2; i <= limit; i++) {
    ans += phi<ll>(i);
  }
  cout << ans << endl;
}

void solve92() {
  array<ll, 10> squares = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
  ll LIM = 10000000;
  ll ans = 0;
  for (ll i = 1; i < LIM; i++) {
    ll n = i;
    while (n != 89 && n != 1) {
      ll n1 = n;
      ll newn = 0;
      while (n1) {
        newn += squares[n1 % 10];
        n1 /= 10;
      }
      n = newn;
    }
    if (n == 89) ans++;
  }
  cout << ans << endl;
}

void solve74() {
  array<ll, 10> factorials = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
  ll LIM = 1000000;
  ll ans = 0;
  for (ll n = 3; n < LIM; n++) {
    ll nn = n;
    vector<ll> chain;
    auto it = chain.begin();
    it = find(chain.begin(), chain.end(), nn);
    while (it == chain.end()) {
      chain.push_back(nn);
      ll sum = 0;
      ll d = nn;
      while (d) {
        sum += factorials[d % 10];
        d /= 10;
      }
      nn = sum;
      it = find(chain.begin(), chain.end(), nn);
    }
    auto it2 = chain.end();

    if (chain.size() == 60) {
      ans++;
      //            cout<<n<<endl;
    }
  }
  cout << ans << endl;
}

void solve77() {
  // how many way you can write 100 as a sum of at leat two numbers?
  vector<ll> primes;
  getPrimes(primes, 10000);
  vector<int> w(10000, 0);
  w[0] = 1;
  int sum = 0;

  int j = 0;
  for (int i = 0; i < primes.size();
       i++) {  // using only the first i primes (i included)
    for (j = primes[i]; j <= primes[primes.size() - 1]; j++) {
      w[j] += w[j - primes[i]];
      if (w[j] > 5000) break;
    }
  }
  for (int i = 0; i <= 100; i++)
    if (w[i] > 5000) {
      cout << i << " " << w[i] << endl;
      break;
    }
}

void solve76() {
  // how many way you can write 100 as a sum of at leat two numbers?
  int w[101] = {0};
  w[0] = 1;
  for (int i = 1; i < 100; i++) {  // using only number <= 99
    for (int j = i; j <= 100; j++) {
      w[j] += w[j - i];
    }
  }
  for (int i = 0; i <= 100; i++) cout << i << " " << w[i] << endl;
}

constexpr const int S = 80;
ll E[S][S];
ll M[S][S];

ll dagMinimum(const int r, const int c) {
  if (E[r][c] != -1) return E[r][c];

  ll right = r + 1 < S ? dagMinimum(r + 1, c) : LLONG_MAX;
  ll left = c + 1 < S ? dagMinimum(r, c + 1) : LLONG_MAX;
  ll ans = M[r][c] + min(left, right);
  E[r][c] = ans;
  return ans;
}

void solve81() {
  loop0n(i, S) {
    loop0n(j, S) {
      ll a;
      scanf("%lld,", &a);
      M[i][j] = a;
      E[i][j] = -1;
    }
  }
  E[S - 1][S - 1] = M[S - 1][S - 1];
  ll ans = dagMinimum(0, 0);
  cout << ans << endl;
}

// required dijkstra. min is implemented naively. use a priority queue instead.
// yet works.
void solve82() {
  loop0n(i, S) {
    loop0n(j, S) {
      ll a;
      scanf("%lld,", &a);
      M[i][j] = a;
      E[i][j] = -1;
    }
  }

  ll min = LLONG_MAX;
  ll W[S][S];
  bool V[S][S];
  typedef pair<ll, pii> pllii;
  priority_queue<pllii> Q;
  for (int i = 0; i < S; i++) {
    // init dijkstra
    loop0n(k, S) {
      loop0n(l, S) {
        W[k][l] = LLONG_MAX;
        V[l][k] = false;
      }
    }
    W[i][0] = 0;

    auto getMin = [&](auto& x, auto& y) {
      x = -1;
      y = -1;
      ll m = LLONG_MAX;
      loop0n(i, S) {
        loop0n(j, S) {
          if (!V[i][j] && W[i][j] < m) {
            m = W[i][j];
            x = i;
            y = j;
          }
        }
      }
    };

    int x, y;
    getMin(x, y);
    while (x != -1 && y != -1) {
      V[x][y] = true;
      if (x > 0 && !V[x - 1][y] && W[x][y] + M[x - 1][y] < W[x - 1][y]) {
        W[x - 1][y] = W[x][y] + M[x - 1][y];
      }
      if (x < S - 1 && !V[x + 1][y] && W[x][y] + M[x + 1][y] < W[x + 1][y]) {
        W[x + 1][y] = W[x][y] + M[x + 1][y];
      }
      if (y < S - 1 && !V[x][y + 1] && W[x][y] + M[x][y + 1] < W[x][y + 1]) {
        W[x][y + 1] = W[x][y] + M[x][y + 1];
      }
      getMin(x, y);
    }

    loop0n(j, S) {
      if (W[j][S - 1] < min) {
        min = W[j][S - 1];
        cout << "min is " << W[j][S - 1] + M[i][0] << " " << i << "->" << j
             << endl;
      }
    }
  }
}

// required dijkstra. min is implemented naively. use a priority queue instead.
// yet works.
void solve83() {
  loop0n(i, S) {
    loop0n(j, S) {
      ll a;
      scanf("%lld,", &a);
      M[i][j] = a;
      E[i][j] = -1;
    }
  }

  int i = 0;
  ll min = LLONG_MAX;
  ll W[S][S];
  pii P[S][S];
  bool V[S][S];
  typedef pair<ll, pii> pllii;
  priority_queue<pllii> Q;
  // init dijkstra
  loop0n(k, S) {
    loop0n(l, S) {
      W[k][l] = LLONG_MAX;
      V[l][k] = false;
      P[k][l] = mp(-1, -1);
    }
  }
  W[i][0] = M[i][0];

  auto getMin = [&](auto& x, auto& y) {
    x = -1;
    y = -1;
    ll m = LLONG_MAX;
    loop0n(i, S) {
      loop0n(j, S) {
        if (!V[i][j] && W[i][j] <= m) {
          m = W[i][j];
          x = i;
          y = j;
        }
      }
    }
  };

  int x, y;
  getMin(x, y);
  while (x != -1 && y != -1) {
    V[x][y] = true;
    if (x > 0 && !V[x - 1][y] && W[x][y] + M[x - 1][y] < W[x - 1][y]) {
      W[x - 1][y] = W[x][y] + M[x - 1][y];
      P[x - 1][y] = mp(x, y);
    }
    if (x < S - 1 && !V[x + 1][y] && W[x][y] + M[x + 1][y] < W[x + 1][y]) {
      W[x + 1][y] = W[x][y] + M[x + 1][y];
      P[x + 1][y] = mp(x, y);
    }
    if (y < S - 1 && !V[x][y + 1] && W[x][y] + M[x][y + 1] < W[x][y + 1]) {
      W[x][y + 1] = W[x][y] + M[x][y + 1];
      P[x][y + 1] = mp(x, y);
    }
    if (y > 0 && !V[x][y - 1] && W[x][y] + M[x][y - 1] < W[x][y - 1]) {
      W[x][y - 1] = W[x][y] + M[x][y - 1];
      P[x][y - 1] = mp(x, y);
    }
    getMin(x, y);
  }

  if (W[S - 1][S - 1] < min) {
    min = W[S - 1][S - 1];
    cout << "min is " << min << " " << i << "->" << endl;
    /*   pii s = mp(S-1,S-1);
       while(s.first != -1 && s.second!=-1){
           cout<<"("<<s.first<<" "<<s.second<<") -> ";
           s=P[s.first][s.second];
       }
       cout<<endl;*/
  }
}

// problem 61
bool found = false;
array<bool, 6> type = {false};

class node {
 public:
  node(const int nn, const int tt) {
    n = nn;
    t = tt;
  }
  int n;
  int t;
  vector<node*> neigh;
};

vector<node> G;
vector<node> c;

auto last = [](const int n) { return n % 100; };
auto first = [](const int n) { return n / 100; };
inline bool canVisit(node n) { return !type[n.t]; }
void visit(node n, int l) {
  for (auto nn : n.neigh) {
    if (l >= 5 && canVisit(*nn) && last((*nn).n) == first(c[0].n)) {
      found = true;
      c.push_back(*(nn));
      return;
    }
    if (canVisit(*nn)) {
      c.push_back(*nn);
      type[(*nn).t] = true;
      visit(*nn, l + 1);
      if (found) {
        return;
      } else {
        c.pop_back();
        type[(*nn).t] = false;
      }
    }
  }
}

ll numRec(const ll r, const ll m) { return (r * m * (r + 1) * (m + 1)) / 4; }
void solve85() {
  ll m;
  ll n;
  m = n = 4;
  constexpr const ll LIM = 2000000;
  bool go = true;
  int i = 1;
  ll k = -1;
  ;
  ll min = LLONG_MAX;
  ll mm = 10000, nn = 10000;
  ll ans = 0;

  int L = 2000;
  for (m = 1; m < L; m++) {
    for (n = m; n < L; n++) {
      ans = numRec(n, m);
      if (abs(ans - LIM) < abs(min - LIM)) {
        min = ans;
        mm = m;
        nn = n;
      }
      if (ans > LIM) break;
    }
  }
  cout << min << " at " << mm << "* " << nn << "= " << nn * mm << endl;
}

// problem 96 -----------------------------------------
constexpr int size = 9;
constexpr int bsize = 3;
// sudoku
bool checkBlock(int S[size][size], const int x, const int y) {
  array<int, size> f = {0};
  for (int i = bsize * x; i < (bsize)*x + bsize; i++)
    for (int j = bsize * y; j < (bsize)*y + bsize; j++) {
      int d = S[i][j];
      if (d > 0) {
        f[d - 1]++;
        if (f[d - 1] > 1) return false;
      }
    }
  return true;
}

bool checkCol(int S[size][size], const int col) {
  array<int, size> f = {0};
  loop0n(i, size) {
    if (S[i][col] > 0) {
      int d = S[i][col];
      f[d - 1]++;
      if (f[d - 1] > 1) return false;
    }
  }
  return true;
}

bool checkRow(int S[size][size], const int row) {
  array<int, size> f = {0};
  loop0n(i, size) {
    if (S[row][i] > 0) {
      int d = S[row][i];
      f[d - 1]++;
      if (f[d - 1] > 1) return false;
    }
  }
  return true;
}

void printGrid(int S[size][size]) {
  loop0n(i, size) { cout << "---"; }
  cout << endl;
  loop0n(i, size) {
    loop0n(j, size) {
      if (S[i][j])
        cout << S[i][j] << " ";
      else
        cout << "  ";
      if (j % bsize == 2) cout << " ";
    }
    cout << endl;
    if (i % bsize == 2) cout << endl;
  }
}

bool solveSudoku(int S[size][size], int L[size][size], vector<pii> guessable) {
  int i = 0;
  while (i < guessable.size()) {
    pii p = guessable[i];
    if (i == 0 && L[p.first][p.second] > 9) return false;
    //  cout<<i<<" "<<p.first<<" "<<p.second << "->
    //  "<<L[p.first][p.second]<<endl;
    S[p.first][p.second] = L[p.first][p.second];
    if (L[p.first][p.second] > 9) {
      L[p.first][p.second] = 1;
      S[p.first][p.second] = 0;
      i--;
      continue;
    }
    if (!(checkRow(S, p.first) && checkCol(S, p.second) &&
          checkBlock(S, p.first / bsize, p.second / bsize))) {
      // choice not good. backtrack
      S[p.first][p.second] = 0;
      L[p.first][p.second]++;
    } else {
      // good choice
      i++;
      L[p.first][p.second]++;
    }
    // printGrid(S);
  }

  return true;
}
void solve96() {
  int S[size][size];
  int L[size][size];
  vector<pii> Q;
  ll ans = 0;
  for (int i = 0; i < 50; i++) {
    string s;
    cin >> s;
    cin >> s;  // first row useless
    for (int r = 0; r < size; r++) {
      // parse row
      cin >> s;
      for (int c = 0; c < size; c++) {
        int d = s[c] - '0';
        S[r][c] = d;
        d ? L[r][c] = -1 : L[r][c] = 1;
        if (!d) Q.push_back(mp(r, c));
      }
    }
    //  printGrid(S);
    bool solved = solveSudoku(S, L, Q);
    if (solved) {
      // printGrid(S);

      ans += S[0][0] * 100 + 10 * S[0][1] + S[0][2];
    } else
      cout << "NO SOLUTION!" << endl;
    Q.clear();
  }
  cout << ans << endl;
}

void solve61() {
  auto addNode = [&](const int n, const int t) {
    if (n >= 1000 && n <= 10000) {
      node nn(n, t);
      G.push_back(nn);
    }
  };
  auto tri = [](const int i) { return (i * (i + 1)) / 2; };
  auto oct = [](const int i) { return (i * (3 * i - 2)); };
  auto pent = [](const int i) { return (i * (3 * i - 1)) / 2; };
  auto hex = [](const int i) { return (i * (2 * i - 1)); };
  auto hep = [](const int i) { return (i * (5 * i - 3)) / 2; };
  auto square = [](const int i) { return (i * (i)); };

  int n = 0;
  int i = 0;
  while (n <= 10000) {
    n = square(i);
    addNode(n, 0);
    n = oct(i);
    addNode(n, 1);
    n = pent(i);
    addNode(n, 2);
    n = hex(i);
    addNode(n, 3);
    n = hep(i);
    addNode(n, 4);
    n = tri(i);
    addNode(n, 5);
    i++;
  }

  for (auto& v : G) {
    for (auto& q : G) {
      if (v.t != q.t && last(v.n) > 9 && last(v.n) == first(q.n))
        v.neigh.push_back(&q);
    }
  }

  for (auto& v : G) {
    c.push_back(v);
    type[v.t] = true;
    visit(v, 1);
    if (found) break;
    c.pop_back();
    type[v.t] = false;
  }
  int sum = 0;
  if (found) {
    for (int i = 0; i < c.size(); i++) sum += c[i].n;
    cout << "found sol " << sum << endl;
  }
}

int periodic2(vector<int>& v) {
  if (v.size() < 2 || v.size() % 2 != 0) return -1;
  int h = v.size() / 2;
  for (int i = 0; i < h; i++) {
    // if( (i <(h-1 ) && v[i] != v[i+h]) || ( i==(h-1) && abs(v[i]-v[i+h]) > 1))
    if (v[i] != v[i + h]) return -1;
  }
  return h;
}

void solve64() {
  typedef float FLOAT;
  constexpr const int LIM = 10000;
  constexpr const FLOAT EPS2 = 0.00001;
  int ans = 0;
  for (int i = 2; i <= LIM; i++) {
    int a0, a1, den, denold;
    a0 = 0;
    den = 1;
    denold = 1;
    FLOAT intpart;
    FLOAT tgt = -1;
    FLOAT fracpart = modf(sqrt(i), &intpart);
    a0 = intpart;
    int sign = 1;
    int it = 0;
    if (fracpart >= EPS2) do {
        den = (i - a0 * a0);
        FLOAT R1 = (denold * (sqrt((FLOAT)i) + sign * (FLOAT)a0)) / den;
        modf(R1, &intpart);
        den /= denold;
        denold = 1;
        a1 = intpart;
        int na = (-a1 * den) + abs(a0);
        a0 = na;
        fracpart = den / (sqrt(i) + a0);
        denold = den;
        sign = -1;
        if (it == 0) tgt = fracpart;
        it++;
      } while (fabs(fracpart - tgt) >= EPS2 || it <= 1);
    if (it > 1 && ((it - 1) % 2) != 0) {
      ans++;
    }
  }
  cout << "sol: " << ans << endl;
}

template <class T>
bool isPerfectSquare(const T d) {
  long double intpart, fractpart;
  fractpart = modf(sqrtl(d), &intpart);
  return fractpart <= 0.000001;
}

void solve66() {
  typedef ll T;
  InfInt max = -1;
  for (T d = 62; d <= 1000; d++) {
    if (!isPerfectSquare<T>(d)) {
      bool go = true;
      for (T x = 1; go; x++) {
        long double y2 = ((long double)x) / sqrtl((long double)d);
        long double intp, floatp;
        floatp = modf(y2, &intp);
        long double p = 0.0001;  // 1.0/(long double)pow10(magnitude<T>(x));
        // cout<<setprecision(10)<<d<<" "<<x<<" "<<y2<<" "<<p<<endl;;
        long double diff = fabs(1.0 - floatp);
        if (intp > 0 && (floatp <= p || diff <= p)) {
          long double candintp;
          if (diff <= p) {
            intp = intp + 1;
          }
          InfInt xi = x;
          InfInt di = d;
          InfInt intpi = (ll)intp;
          InfInt res = xi * xi - di * intpi * intpi;
          // printf("CANDIDATE-> %lld^2 - %lld*%lld^2 = 1\n",x,d,(T)intp);
          // cout<<res<<endl;

          InfInt one = 1;
          if (one == res) {
            printf("GOOD-> %lld^2 - %lld*%lld^2 = 1\n", x, d, (T)intp);
            cout << res << endl;
            if (xi > max) max = xi;
            go = false;
          }
        }
      }
    }
  }
  cout << max << endl;
}

template <class T>
void print(const vector<T>& V) {
  for (const auto& a : V) {
    cout << a << " ";
  }
  cout << endl << endl;
}

// problem 93---------------------------------
typedef vector<double> vi;
vi two[10][10] = {{}};
vi three[10][10][10] = {{}};
vi four[10][10][10][10] = {{}};
int s = 1;
void filltwo() {
  for (int i = s; i <= 9; i++) {
    for (int j = s; j <= 9; j++) {
      if (i != j) {
        int l = i;
        int m = j;
        if (l > m) swap(l, m);
        two[l][m].push_back(i + j);
        two[l][m].push_back(i - j);
        two[l][m].push_back(j - i);
        two[l][m].push_back(i * j);
        two[l][m].push_back(j * i);
        if (j != 0) two[l][m].push_back((double)i / (double)j);
        if (i != 0) two[l][m].push_back((double)j / (double)i);
      }
    }
  }
  cout << endl;
}

void fillthree() {
  for (int i = s; i < 10; i++) {
    for (int j = s; j < 10; j++) {
      if (i != j)
        for (int k = s; k < 10; k++) {
          if (i != k && j != k) {
            array<int, 3> coord = {i, j, k};
            sort(coord.begin(), coord.end());
            int jj = j;
            int kk = k;
            if (jj > kk) swap(jj, kk);
            vi ns = two[jj][kk];
            for (auto n : ns) {
              double op = (double)i;
              three[coord[0]][coord[1]][coord[2]].push_back(op + n);
              three[coord[0]][coord[1]][coord[2]].push_back(op - n);
              three[coord[0]][coord[1]][coord[2]].push_back(n - op);
              three[coord[0]][coord[1]][coord[2]].push_back(op * n);
              three[coord[0]][coord[1]][coord[2]].push_back(n * op);
              if (n != 0) three[coord[0]][coord[1]][coord[2]].push_back(op / n);
              if (op != 0)
                three[coord[0]][coord[1]][coord[2]].push_back(n / op);
            }
          }
        }
    }
  }
}

bool isGood(const double n) {
  double intp, fracp;
  if (n >= 1) {
    fracp = modf(n, &intp);
    if (fracp <= 0.0001) return true;
  }
  return false;
}

void fillfour() {
  for (int i = s; i < 10; i++) {
    if (i == 4) cout << endl;
    for (int j = s; j < 10; j++) {
      if (i != j)
        for (int k = s; k < 10; k++) {
          if (j != k && k != i)
            for (int l = s; l < 10; l++) {
              if (l != k && l != j && l != i) {
                array<int, 3> cc = {j, k, l};
                sort(cc.begin(), cc.end());
                auto ns = three[cc[0]][cc[1]][cc[2]];
                array<int, 4> coord = {i, j, k, l};
                sort(coord.begin(), coord.end());
                for (auto n : ns) {
                  // metti anche l DIVISIONE AL CONTRATIO. tutte le operazioni
                  // non commutative vanno doppi
                  ////metti anche l DIVISIONE AL CONTRATIO. tutte le operazioni
                  ///non commutative vanno doppiee
                  double op = (double)i;
                  if (isGood(op + n))
                    four[coord[0]][coord[1]][coord[2]][coord[3]].push_back(op +
                                                                           n);
                  if (isGood(op - n))
                    four[coord[0]][coord[1]][coord[2]][coord[3]].push_back(op -
                                                                           n);
                  if (isGood(n - op))
                    four[coord[0]][coord[1]][coord[2]][coord[3]].push_back(n -
                                                                           op);

                  if (isGood(n * op))
                    four[coord[0]][coord[1]][coord[2]][coord[3]].push_back(n *
                                                                           op);

                  if (op != 0)
                    if (isGood((double)n / (double)op))
                      four[coord[0]][coord[1]][coord[2]][coord[3]].push_back(
                          n / op);

                  if (isGood(op * n))
                    four[coord[0]][coord[1]][coord[2]][coord[3]].push_back(op *
                                                                           n);

                  if (n != 0)
                    if (isGood((double)op / (double)n))
                      four[coord[0]][coord[1]][coord[2]][coord[3]].push_back(
                          op / n);
                }
              }
            }
        }
    }
  }
}
void solve93() {
  filltwo();
  fillthree();
  fillfour();
  int max = 0;
  int c = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) {
      for (int k = j + 1; k < 10; k++) {
        for (int l = k + 1; l < 10; l++) {
          auto ns = four[i][j][k][l];
          vector<int> nss;
          for (int m = 0; m < ns.size(); m++) {
            if (isGood(ns[m])) nss.push_back(ns[m]);
          }
          set<int> s(nss.begin(), nss.end());
          nss.assign(s.begin(), s.end());
          if (ns.size() > 0) {
            int start = 1;
            int c = 0;
            for (int m = 0; m < nss.size(); m++, c++, start++) {
              if (nss[m] != start) break;
            }
            if (c > max) {
              max = c;
              printf("\n%d %d %d %d: %d", i, j, k, l, c);
            }
          }
        }
      }
    }
  }
}

// end of problem 93

// problem94
inline pair<long double, long double> solveEq2(const long double a,
                                               const long double b,
                                               const long double c) {
  pair<long double, long double> res = {-1, -1};
  long double delta = b * b - 4 * a * c;
  if (delta > 0.0) {
    res.first = (-b + sqrtl(delta)) / (2 * a);
    res.second = (-b - sqrtl(delta)) / (2 * a);
  }
  return res;
}

bool isIntegral(const long double l) {
  long double intp, fracp;
  if (modfl(l, &intp) <= 0.000000000001) return true;
  return false;
}

// this works but consider using solution of the Pell's equation for getting
// speedup
//
void solve94_c() {
  ll ans = 0;
  long double a = 2;

#pragma omp parallel for reduction(+ : ans)
  for (ll c = 2; c < 333333333; c++) {
    long double a = (long double)c;
    long double a23 = 3.0 * a * a;
    long double a12 = 0.5 * a;

    long double res = (3.0 * (a * a) - 2.0 * a - 1.0) / 4.0;
    if (isIntegral(sqrt(res))) {
      // ll aa=a;
      // printf("%ld %ld %ld\n", aa , aa , aa+1);
      ans += 3 * a + 1;
    }
    long double res2 = (3.0 * (a * a) + 2.0 * a - 1.0) / 4.0;
    if (isIntegral(sqrt(res2))) {
      //  ll aa=a;
      // printf("%ld %ld %ld\n", aa , aa , aa+1);

      ans += 3 * a - 1;
    }
    a++;
  }
  cout << ans << endl;
}

// end of problem 94

// problem 95
constexpr const int LIM = 15000000;
array<ll, LIM + 1> SD;  // SD[i] contains the sum of proper divisor of i

void initSD() {
#pragma omp parallel for shared(SD)
  for (int i = 0; i <= LIM; i++) {
    SD[i] = 1;
    // cout<<i<<" "<<SD[i]<<endl;
  }
#pragma omp parallel for
  for (int i = 2; i <= LIM / 2; i++) {
    int k = 2;
    int p = k * i;
#pragma parallel for schedule(guided) private(k, p)
    for (; p <= LIM; k++, p = k * i) {
#pragma omp atomic
      SD[p] += i;
    }
  }
}
void solve95() {
  initSD();
  int L, M;
  L = INT_MIN;
  M = INT_MAX;
#pragma omp parallel for shared(L, M)
  for (int i = 4; i <= LIM; i++) {
    unordered_map<int, bool> map;
    int l = 1;
    int m = i;
    map[i] = true;
    int c = SD[i];
    bool go = c != 1;
    while (!map[c] && c > 1 && c <= LIM) {
      map[c] = true;
      ++l;
      c = SD[c];
      if (c < m) m = c;
      go = (c > 1) && (c <= LIM);
    }
#pragma omp critical
    {
      if (go && c == i && l > L) {
        L = l;
        M = m;
      }
    }
  }
  cout << M << endl;
}

// end of problem 95

void solve86NEEDTOBESOLVED() {
  constexpr const int LIM = 101;
  double EPS2 = 0.00000000001;
  int ans = 0;
  int l = 0;
  vector<int> Q(LIM, 0);
  for (int i = 1; i < LIM; i++) {
    for (int j = i; j < LIM; j++) {
      for (int k = j; k < LIM; k++) {
        int m = max(max(i, j), k);
        double intp;
        double a, b, c;

        a = modf(sqrt(i * i + (j + k) * (j + k)), &intp);
        b = modf(sqrt(j * j + (i + k) * (i + k)), &intp);
        c = modf(sqrt(k * k + (i + j) * (i + j)), &intp);
        if ((a < EPS) || (b < EPS) || (c < EPS)) {
          Q[m]++;
          ans++;
          printf("%d %d %d -> %d\n", i, j, k, Q[m]);
        }
      }
    }
  }
  cout << ans << endl;
}

void solve91() {
#define PI 3.14159265
  typedef array<int, 2> vec2i;
  auto dot = [](const vec2i& a, const vec2i& b) {
    return a[0] * b[0] + a[1] * b[1];
  };

  auto magn = [](const vec2i& a) -> double {
    return sqrt(a[0] * a[0] + a[1] * a[1]);
  };

  auto angle = [&](const vec2i& a, const vec2i& b) {
    auto magna = magn(a);
    auto magnb = magn(b);
    auto dotab = dot(a, b);
    return acos((dotab) / magna * magnb);
  };

  vec2i a = {1, 0};
  vec2i b = {0, 2};

  auto minus = [](const vec2i a, const vec2i& b) {
    vec2i ret = {a[0] - b[0], a[1] - b[1]};
    return ret;
  };
  auto negate = [](const vec2i a) {
    vec2i b = {-a[0], -a[1]};
    return b;
  };

  auto equal = [](double a, double b, double _EPS) {
    return fabs(a - b) < _EPS;
  };
  auto isGood = [&](const vec2i a, const vec2i b, double _EPS) {
    if (a[0] == b[0] && a[1] == b[1]) return false;
    if (a[0] == 0 && a[1] == 0) return false;
    if (b[0] == 0 && b[1] == 0) return false;
    auto ang1 = angle(a, b);
    auto ang2 = angle(negate(b), minus(a, b));
    auto ang3 = angle(negate(a), minus(b, a));
    const double PI2 = M_PI / 2.0;
    return (equal(ang1, PI2, _EPS) || equal(ang1, -PI2, _EPS)) ||
           (equal(ang2, PI2, _EPS) || equal(ang2, -PI2, _EPS)) ||
           (equal(ang3, PI2, _EPS) || equal(ang3, -PI2, _EPS));

  };
  int ans = 0;
  int LIM = 50;
  vec2i zero = {0, 0};
#pragma omp parallel for collapse(2) reduction(+ : ans)
  for (int i = 0; i <= LIM; i++) {
    for (int j = 0; j <= LIM; j++) {
      vec2i one = {j, i};
      if (i != 0 || j != 0)
        for (int k = i; k <= LIM; k++) {
          for (int l = 0; l <= LIM; l++) {
            vec2i two = {l, k};
            if (l <= j && k <= i) continue;
            if (isGood(one, two, 0.000001)) {
              // printf("(0,0) (%d,%d), (%d,%d)\n",j,i,l,k);
              ans++;
            }
          }
        }
    }
  }
  cout << ans << endl;
}

void solve87() {
  vector<ll> primes;
  getPrimesSieve(primes, 7100);
  constexpr const int LIM = 50000000;
  vector<int> squares;
  vector<int> cubes;
  vector<int> fourths;
  loop0n(i, primes.size()) {
    if (primes[i] * primes[i] < LIM)
      squares.push_back(primes[i] * primes[i]);
    else
      break;
  }
  loop0n(i, primes.size()) {
    if (primes[i] * primes[i] * primes[i] < LIM)
      cubes.push_back(primes[i] * primes[i] * primes[i]);
    else
      break;
  }
  loop0n(i, primes.size()) {
    if (primes[i] * primes[i] * primes[i] * primes[i] < LIM)
      fourths.push_back(primes[i] * primes[i] * primes[i] * primes[i]);
    else
      break;
  }

  unordered_map<int, bool> map;
  int ans = 0;
  loop0n(i, squares.size()) {
    loop0n(j, cubes.size()) {
      loop0n(k, fourths.size()) {
        int n = squares[i] + cubes[j] + fourths[k];
        if (n < LIM && (map.find(n) == map.end())) {
          map[n] = true;
          ++ans;
        }
      }
    }
  }
  cout << ans << endl;
}

// PROBLEM 88 -----------------------------------
void combine(vector<vector<int>>& w, const int n) {
  for (auto& s : w) {
    s.push_back(n);
  }
}

vector<vector<int>> asMultiplication(const int n, vector<ll>& primes) {
  vector<vector<int>> W;
  int nn = n;
  vector<int> r = {{nn}};
  W.push_back(r);
  int nnn = 1;
  loopse(i, 2, n / 2 + 1) {
    if (nn == primes[i]) {
      break;
      ;
    }
    if (nn % i == 0) {
      vector<int> A = {nn / i, i};
      W.push_back(A);
      vector<vector<int>> wnn = asMultiplication(nn / i, primes);
      for (auto& ww : wnn) {
        sort(ww.begin(), ww.end());
      }
      sort(wnn.begin(), wnn.end());
      auto it = unique(wnn.begin(), wnn.end());
      wnn.resize(distance(wnn.begin(), it));

      combine(wnn, i);
      W.insert(W.end(), wnn.begin(), wnn.end());
    }
    if (nn < primes[i]) break;
  }

  for (auto& ww : W) {
    sort(ww.begin(), ww.end());
  }
  sort(W.begin(), W.end());
  auto it = unique(W.begin(), W.end());
  W.resize(distance(W.begin(), it));
  return W;
}

void solve88() {
  set<int> S;
  const int LIM = 12000;
  vector<ll> primes;
  getPrimesSieve(primes, LIM);
  vector<vector<vector<int>>> WM(2 * LIM);

#pragma omp parallel for shared(WM)
  for (int i = 1; i <= 2 * LIM; i++) {
    WM[i - 1] = asMultiplication(i, primes);
  }

#pragma omp parallel for shared(S)
  for (int k = 2; k <= LIM; k++) {
    bool go = true;
    int i = k - 1;
    for (; go && i < WM.size(); i++) {
      for (int n = 0; go && n < WM[i].size(); n++) {
        vector<int> w = WM[i][n];
        if (w.size() <= k) {
          int sum = 0;
          for (const auto c : w) sum += c;

          int d = k - w.size();
          if (d + sum == i + 1) {
            go = false;
// cout<<k<<" "<<i+1<<endl;
#pragma omp critical
            S.insert(i + 1);
          }
        }
      }
    }
    if (go) {
      cout << "WRONGGGGGGGG" << k << endl;
      exit(-1);
    }
  }
  ll ans = 0;
  for (auto& w : S) {
    ans += w;
    // cout<<w<<endl;
  }
  cout << ans << endl;
}
// END OF PROBLEM88 -----------------------------------------

// problem 90

void combination(const unsigned short n, const unsigned short k,
                 vector<vector<int>>& C) {
  int LIM = pow(2, n) - 1;  // bits max number using n bits
  int LOW = pow(2, k) - 1;
  for (int i = LOW; i < LIM; i++) {
    // counts bit set
    int bs = 0;
    for (int b = 0; bs <= k && b < n; b++) {
      if (BIT(i, b)) bs++;
    }

    if (bs == k) {  // good permutation
      vector<int> p(k);
      for (int bit = 0; bit < n; bit++)
        if (BIT(i, bit)) p[--bs] = (bit);

      C.push_back(p);
    }
  }
}

bool isGood(const vector<int>& C0, const vector<int>& C1) {
  bool sn1 = C1.end() != find(ALL(C1), 6);
  sn1 = sn1 || (C1.end() != find(ALL(C1), 9));

  bool sn0 = C0.end() != find(ALL(C0), 6);
  sn0 = sn0 || (C0.end() != find(ALL(C0), 9));
  for (int i = 1; i <= 9; i++) {
    int ii = i * i;
    int a = ii % 10;
    int b = (ii / 10) % 10;

    bool a0, b0, a1, b1;
    a0 = C0.end() != find(C0.begin(), C0.end(), a);
    b0 = C0.end() != find(C0.begin(), C0.end(), b);
    a0 = a0 || ((a == 6 || a == 9) && sn0);
    b0 = b0 || ((b == 6 || b == 9) && sn0);

    a1 = C1.end() != find(C1.begin(), C1.end(), a);
    b1 = C1.end() != find(C1.begin(), C1.end(), b);

    a1 = a1 || ((a == 6 || a == 9) && sn1);
    b1 = b1 || ((b == 6 || b == 9) && sn1);

    if (!((a0 && b1) || (b0 && a1))) return false;
  }
  return true;
}

void solve90() {
  vector<vector<int>> C;
  combination(10, 6, C);
  int ans = 0;
  for (int i = 0; i < C.size(); i++) {
    for (int j = i; j < C.size(); j++) {
      if (isGood(C[i], C[j])) ans++;
    }
  }
  cout << ans << endl;
}

void solve102() {
  auto dot = [](const int x0, const int y0, const int x1, const int y1) {
    return x0 * x1 + y0 * y1;
  };
  auto magn = [](const int x0, const int y0) {
    return sqrt(x0 * x0 + y0 * y0);
  };
  auto anglebetween = [&](const int x0, const int y0, const int x1,
                          const int y1) {
    return acos(dot(x0, y0, x1, y1) / (magn(x0, y0) * magn(x1, y1)));
  };

  int ans = 0;
  int x0, y0, x1, y1, x2, y2;
  int l = 1000;
  while (--l) {
    scanf("%d,%d,%d,%d,%d,%d\n", &x0, &y0, &x1, &y1, &x2, &y2);
    double angle = 0;
    angle += anglebetween(x0, y0, x1, y1);
    angle += anglebetween(x1, y1, x2, y2);
    angle += anglebetween(x2, y2, x0, y0);
    if (fabs(angle - 2 * M_PI) <= 0.0001) {
      ans++;
    }
  }
  cout << ans << endl;
}

// problem 101------------

/*
 * In order to find the (UNIQUE!) minimal degree polynomial which interpolate n
 * numbers
 * we here use the lagrangian polynomial.
 * */

double LagrangePolynomial(const int i, const vector<pldd>& points,
                          const pldd& p) {
  long double res = 1.0;
  loop0n(m, points.size()) {
    if (m != i) {
      res *= (p.first - points[m].first) / (points[i].first - points[m].first);
    }
  }
  return res;
}

long double interpolateLagrange(const vector<pldd>& points, const pldd& p) {
  long double res = 0;
#pragma omp parallel for reduction(+ : res)
  loop0n(i, points.size()) {
    res += points[i].second * LagrangePolynomial(i, points, p);
  }
  return res;
}

void solve101() {
  vector<pldd> points;
  int maxd = 11;
  auto evalcube = [&](const long double n) -> long double { return n * n * n; };
  auto eval = [&](const long double n) -> long double {
    return 1 - pow(n, 1) + pow(n, 2) - pow(n, 3) + pow(n, 4) - pow(n, 5) +
           pow(n, 6) - pow(n, 7) + pow(n, 8) - pow(n, 9) + pow(n, 10);

  };

  loopse(i, 0, maxd) {
    const pldd p = mp(i + 1, eval(i + 1));
    points.push_back(p);
  }

  long double ans = 0;
  loopse(i, 1, maxd) {
    vector<pldd> _points(points.begin(), points.begin() + i);
    ans += interpolateLagrange(_points, mp(i + 1, -1));
  }
  cout << (long long int)ans << endl;
}

bool checkDuplicateSum(vector<vector<int>>& S, const int v) {
  vector<int> n;
  n.push_back(v);
  loop0n(i, S.size()) {
    loop0n(j, S[i].size()) { n.push_back(S[i][j] + v); }
  }

  bool ok = true;
  loop0n(k, n.size()) {
    if (ok) loop0n(i, S.size()) {
        if (ok) loop0n(j, S[i].size()) {
            if (n[k] == S[i][j]) {
              ok = false;
              cout << "can write " << n[k] << endl;
              break;
            }
          }
      }
  }
  if (ok) S.push_back(n);

  return ok;
}

// in a sorted set checkes wether
// is A,B are subset of M then
// sum(A) > sum(B) iff A contains more elements than B
template <class NUM, uint D>
bool noDuplicateSum(const array<NUM, D>& M, const uint size = D) {
  array<NUM, D> L;
  array<NUM, D> R;
  L[0] = M[0];
  for (int i = 1; i < size; i++) {
    L[i] = M[i] + L[i - 1];
  }
  R[size - 1] = M[size - 1];
  for (int i = size - 2; i >= 0; i--) {
    R[i] = M[i] + R[i + 1];
  }

  bool ok = true;
  for (int i = size - 1; ok && i >= 0; i--) {
    for (int j = 1 + size - 1 - i; ok && j < size; j++) {
      if (R[i] > L[j]) ok = false;
    }
  }
  return ok;
}

void solve103() {
  constexpr const int D = 7;
  int minsum = INT_MAX;
  constexpr int LIM = 50;
  array<int, D> M = {0, 0, 0, 0, 0, 0, 0};  //,0,0,0};
  array<int, D> minA;
  vector<vector<int>> S;
  int i = 0;
  int sum = 0;
  do {
    M[i]++;
    sum = 0;
    loop0n(k, i + 1) { sum += M[k]; }
    bool ok = true;
    bool odd = sum % 2 != 0;
    bool inc = i == 0;
    inc = inc || (i > 0 && M[i] > M[i - 1]);
    if (i >= 2)
      for (int j = i; inc && ok && j > 1; j--)
        if (M[0] + M[1] <= M[j]) ok = false;

    if (ok && inc && M[i] <= LIM)
      if (checkDuplicateSum(S, M[i])) i++;

    if (i >= D) {
      if (noDuplicateSum<int, D>(M) && sum < minsum) {
        minsum = sum;
        loop0n(k, D) { minA[k] = M[k]; }
      }
      ok = false;
    }

    if ((!odd && i == D) || !ok || M[i] >= LIM) {
      do {
        sum -= M[i];
        M[i] = 0;
        S.pop_back();
        i--;
      } while (M[i] >= LIM);
    }

  } while (M[0] < LIM);
  cout << minsum << endl;
  loop0n(k, D) { cout << minA[k]; }
  cout << endl;
}

// end of  problem 101  ------------

// problem 105---------
template <class NUM, uint D>
int goodCombo(array<NUM, D>& S, const uint size) {
  sort(S.begin(), S.begin() + size);
  int sum = std::accumulate(S.begin(), S.begin() + size, 0, std::plus<int>());
  bool ok = noDuplicateSum<int, 12>(S, size);  // sum%2==1;
  if (ok) {
    vector<vector<int>> sums;
    int i = 0;
    do {
      ok = ok && checkDuplicateSum(sums, S[i]);

      i++;
    } while (ok && i < size);
  }
  if (!ok) sum = -1;

  return sum;
}

void solve105() {
  ifstream file("p105_sets.txt", ios::in);
  uint ans = 0;
  if (file.good()) {
    string str;
    while (getline(file, str)) {
      // cout<<str<<endl;
      istringstream ss(str);
      uint num;
      char c;
      array<int, 12> N;
      uint ins = 0;
      while (ss >> num) {
        N[ins++] = num;
        // cout<<num<<" ";
        ss >> c;
      }
      int sum = goodCombo<int, 12>(N, ins);
      if (sum > 0) {
        cout << "ok->" << str << endl;
        ans += sum;
      }
      // cout<<endl;
    }
  }
  cout << ans << endl;
}

// end of problem 105

// problem 106---------------
int fact(int n) {
  if (n == 0) return 1;
  int rr = n;
  while (--n) {
    rr *= n;
  }
  return rr;
}

int catalan(const int n) { return (fact(2 * n) / (fact(n + 1) * fact(n))); }

int combinations(const int n, const int k) {
  return fact(n) / (fact(k) * fact(n - k));
}

void solve106() {
  constexpr const int D = 12;
  int ans = 0;
  int k = 2;

  while (2 * k <= D) {
    ans += combinations(D, 2 * k) * (0.5 * combinations(2 * k, k) - catalan(k));

    k++;
  }
  cout << ans << endl;
}

//---------------
// problem 104  ------------

bool checkPandigitally(digits& ds, int s, int e) {
  for (int i = s; i < e; i++) {
    if (ds[i] != 1) return false;
  }
  return true;
}

// strategy. compute the last 9 digits of each fibonacci number
// making computation only modulo 10^9
// once you find a number whcih is pandigital in its last digits
// then compute the full number and check if it's also pandigital
// in its most 9 significant digits
// this saves you a lot of computation with large numbers
void solve104() {
  constexpr const uint LIM = 1000000;
  mpz_class fn_1;
  mpz_class fn;

  uint i = 2500;
  mpz_class p109 = ipow<unsigned long int>(10, 9);
  mpz_fib2_ui(fn.get_mpz_t(), fn_1.get_mpz_t(), i);
  mpz_class f9;
  mpz_class next;
  while (i < LIM) {
    next = fn + fn_1;
    mpz_mod(next.get_mpz_t(), next.get_mpz_t(), p109.get_mpz_t());
    fn_1 = fn;
    fn = next;
    i++;

    digits last9 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    unsigned long int lnui = mpz_get_ui(fn.get_mpz_t());
    intToDigits<unsigned long int>(lnui, last9);

    if (checkPandigitally(last9, 1, 10)) {
      mpz_class fn_real;
      mpz_fib_ui(fn_real.get_mpz_t(), i);
      // converting to string
      char* str;
      char str_first9[10];
      str = mpz_get_str(NULL, 10, fn_real.get_mpz_t());
      uint ln = strlen(str) + 1;
      strncpy(str_first9, str, 9);
      str_first9[9] = '\0';

      unsigned long int fnui = stoul(str_first9);
      digits first9 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      intToDigits<unsigned long int>(fnui, first9);
      if (checkPandigitally(first9, 1, 10)) {
        cout << i;
        return;
      }
    }
  }
}
// end of problem 104------

// problem 107----
template <class T>
using min_priority_queue = priority_queue<T, std::vector<T>, std::greater<T>>;

typedef tuple<int, int, int> arc;
void kruskal(min_priority_queue<arc>& Q, const int D,
             vector<tuple<int, int, int>>& K) {
  vector<set<int>> N;
  loop0n(i, D) {
    set<int> nn;
    nn.insert(i);
    N.push_back(nn);
  }

  while (!Q.empty()) {
    auto e = Q.top();
    int f1 = 0;
    loop0n(i, N.size()) {
      if (N[i].find(get<1>(e)) != N[i].end()) {
        f1 = i;
        break;
      }
    }

    int f2 = 0;
    loop0n(i, N.size()) {
      if (N[i].find(get<2>(e)) != N[i].end()) {
        f2 = i;
        break;
      }
    }

    // this arc connects two disjoint subgraph
    if (f1 != f2) {
      set<int> nnn;
      nnn.insert(N[f1].begin(), N[f1].end());
      nnn.insert(N[f2].begin(), N[f2].end());

      int m = min(f1, f2);
      int M = max(f1, f2);
      N.erase(N.begin() + m, N.begin() + m + 1);
      N.erase(N.begin() + M - 1, N.begin() + M);
      N.push_back(nnn);
      K.push_back(e);
    }
    Q.pop();
  }
}

void solve107() {
  min_priority_queue<arc> Q;
  constexpr const int D = 40;
  int w;

  int S = 0;
  loop0n(i, D) {
    loop0n(j, D) {
      char c;
      int w = 0;
      string s;
      cin >> s;
      char* p;
      int converted = strtol(s.c_str(), &p, 10);
      if (*p) {
        ;
      } else {
        w = converted;
        if (j > i) S += w;
        auto a = make_tuple(w, i, j);
        // cout<<get<0>(a)<<" "<<get<1>(a)<<" "<<get<2>(a)<<endl;
        Q.push(a);
      }
    }
  }

  vector<tuple<int, int, int>> K;

  kruskal(Q, D, K);

  int W =
      std::accumulate(K.begin(), K.end(), 0,
                      [](const int w, const auto& t) { return w + get<0>(t); });
  cout << S - W << endl;
}

// end of problem 107--

// problem 108 ---

bool factorize(ll p, vector<pii>& F, vector<ll>& primes) {
  int i = 0;
  int c = 0;
  while (p > 1) {
    if (i >= primes.size()) return false;
    if (p % primes[i] == 0) {
      c++;
      p /= primes[i];
    } else {
      if (c > 0) {
        F.push_back(make_pair(primes[i], c));
        c = 0;
      }
      i++;
    }
  }
  if (c > 0) {
    F.push_back(make_pair(primes[i], c));
    c = 0;
  }
  return true;
}

ll divisors(ll p, const vector<ll>& primes) {
  ll ans = 1;
  int i = 0;
  int c = 0;
  while (p > 1) {
    if (p % primes[i] == 0) {
      c++;
      p /= primes[i];
    } else {
      if (c > 0) {
        ans *= c + 1;
        c = 0;
      }
      i++;
    }
  }
  if (c > 0) {
    ans *= c + 1;
    c = 0;
  }
  return ans;
}

ll divisors(vector<pii>& F) {
  ll ans = 1;
  loop0n(i, F.size()) { ans *= F[i].second + 1; }
  return ans;
}

void solve108() {
  constexpr const long LIMP = 17;
  vector<ll> primes;
  getPrimesSieve(primes, LIMP);
  ull m = 0;
  int min;

  for (ll n = 2;; n++) {
    vector<pii> F;
    ll n2 = n * n;
    if (factorize(n, F, primes)) {
      ll div = divisors(F) / 2;  // getting number of divisors of n^2. compute
                                 // factor of n and double all the power of
                                 // factor of n

      if (div > 1000) {
        cout << n;
        break;
      }
    }
  }
}

// end of problem 108--

// problem 109-------
template <unsigned int NP>
ll divisors109(array<uint, NP>& exps, const int f) {
  ll ans = 1;
  loop0n(i, exps.size()) {
    if (exps[i] > 0) ans *= f * exps[i] + 1;
  }
  return ans;
}

template <unsigned int NP>
mpz_class expsToNumber(const vector<ll>& primes, const array<uint, NP>& exps) {
  mpz_class m1 = -1;
  mpz_class ans = 1;
  loop0n(i, NP) {
    if (exps[i] > 0) {
      mpz_class e = ipow<unsigned long int>(primes[i], exps[i]);
      ans = ans * e;
    }
  }
  return ans > 1 ? ans : m1;
}

constexpr const ll TGT109 = 4000000;
template <unsigned int NP>
void findN(const vector<ll>& primes, array<uint, NP>& exps,
           const array<uint, NP>& expsLimits, const int i, mpz_class& ans) {
  for (int k = 1; k < expsLimits[i]; k++) {
    exps[i] = k;
    ll div =
        divisors109<NP>(exps, 2) / 2;  // check how many divisors the square has
    if (div > TGT109) {
      auto n = expsToNumber<NP>(primes, exps);
      if (mpz_sgn(n.get_mpz_t()) >= 1 &&
          mpz_cmp(ans.get_mpz_t(), n.get_mpz_t()) > 0) {
        ans = n;
      }

      // nop need in searching further on this path. other numbers would be
      // larger than smallestN

      break;
    } else
      findN<NP>(primes, exps, expsLimits, i + 1, ans);
  }
  exps[i] = 0;
}

void solve109() {
  constexpr const long LIMP = 50;
  constexpr const uint NP = 20;  // using only the first 10 primes
  constexpr const uint expL = 5;
  vector<ll> primes;
  getPrimesSieve(primes, LIMP);
  array<uint, NP> exps;
  array<uint, NP> expsLimits;
  loop0n(i, NP) {
    exps[i] = 0;
    expsLimits[i] = 5;
  }
  mpz_class ans(ULONG_MAX);
  findN<NP>(primes, exps, expsLimits, 0, ans);
  cout << ans << endl;
}
// end of problem 109--

// strategy: for each number of the same number of digits
// iterate all over all subset of digits and find all numbers which happen to
// have the subset identified by the number k
// of the same digits is a good candidate.
// for example when k=3 you are checking that digits 1 and 2 are the same. then
// you take the rest of the number as a key
//(56003 => rest of the number is 563)
void solve51() {
  uint maxM = 0;
  uint maxrest = 0;
  uint maxC = 0;
  ull minmin = 0;
  constexpr const long LIMP = 1000000;
  vector<ll> primes;
  getPrimesSieve(primes, LIMP);
  // m represent the number of digits of primes[i]
  // iterate over all subset of m elements => see how bits of numbers from
  // 1->2^m changes to get the subsets
  array<vector<int>, 100000> NUMS;

  // for each set of prime number with the same number of digits
  for (int m = 2; m <= magnitude(primes.back()); m++) {
    // for each subset of digits
    for (unsigned long k = 1; k < ipow(2, m); k++) {
      bitset<20> b(k);
      if (b.count() == 1) continue;
      for (int i = 0; i < primes.size() && primes[i] <= (ipow(10, m) - 1);
           i++) {
        if (primes[i] >= ipow(10, m - 1)) {
          vector<int> D;
          ull number = primes[i];
          while (number) {
            D.push_back(number % 10);
            number /= 10;
          }

          bool eq = true;
          int nn = -1;
          loop0n(i, m) {
            if (!eq) break;
            if (!b[i]) continue;
            if (nn == -1) nn = D[i];

            if (nn != D[i]) eq = false;
          }
          // this is a good number: has all the digits of the subset equals
          if (eq) {
            // compute the int corresponding to bit not set in b
            int rest = 0;
            int p = 1;
            loop0n(i, m) {
              if (!b[i]) {
                rest += D[i] * p;
                p *= 10;
              }
            }
            NUMS[rest].push_back(primes[i]);
          }
        }
      }

      // cout<<"Magnitude:"<<m<<" "<<k<<endl;
      loop0n(q, 100000) {
        if (NUMS[q].size() > 0) {
          // cout<<"rest "<<q<<endl;
          loop0n(p, NUMS[q].size()) {
            if (NUMS[q].size() > maxC) {
              maxC = NUMS[q].size();
              minmin = *min_element(NUMS[q].begin(), NUMS[q].end());
            }
          }
          NUMS[q].clear();
        }
      }
    }
  }

  cout << minmin << endl;
}

void solve52() {
  constexpr const uint LIM = 1000000;
  constexpr const uint MAXMULT = 6;
  vector<digits> DS(LIM);
  loop0n(i, LIM) {
    digits ds = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    intToDigits(i, ds);
    DS[i] = ds;
  }

  int n = -1;
  uint i = 1;
  while (n < 0 && ++i < LIM / 6) {
    bool good = true;
    for (int x = 2; good && x <= MAXMULT; x++) {
      if (!sameDigits(DS[i], DS[i * x])) good = false;
    }
    if (good) n = i;
  }

  cout << n << endl;
}

// problem 53-----
void solve53() {
  // first create a 100*100 pascal triangle
  constexpr const int DIM = 101;
  constexpr const int ONEM = 1000000;
  ull pt[DIM][DIM] = {0};
  loop0n(i, DIM) { pt[i][0] = pt[i][i] = 1; }
  int ans = 0;
  for (int i = 1; i < DIM; i++) {
    for (int j = 1; j < i; j++) {
      pt[i][j] = pt[i - 1][j] + pt[i - 1][j - 1];
      if (pt[i][j] > ONEM) {
        ++ans;
        cout << i << ":" << j << endl;
      }
    }
  }

  cout << ans << endl;
}
// end of problem 53-----

// problem 120-----
bool repeated(vector<ull>& vec) {
  if (vec.size() % 2 != 0) return false;
  int s2 = vec.size() / 2;
  loop0n(i, s2) {
    if (vec[i] != vec[i + s2]) return false;
  }
  return true;
}
void solve120() {
  constexpr const ull LIMA = 1000;
  ull sum = 0;
  for (ull a = 3; a <= LIMA; a++) {
    const ull A1 = a - 1;
    const ull A2 = a + 1;
    ull rmax = 0;
    vector<ull> REMS;
    ull a1 = a - 1;
    ull a2 = a + 1;
    ull as = a * a;
    do {
      REMS.push_back((a1 + a2) % as);
      a1 = (a1 * A1) % as;
      a2 = (a2 * A2) % as;
    } while (!repeated(REMS));

    int M = *max_element(REMS.begin(), REMS.end());
    sum += M;
  }
  cout << sum << endl;
}

// end of problem 120-----

// Problem 205

void solve205() {
  vector<int> N[9];
  // there is no need to store all the single sums (since there are only 36 of
  // them)
  // is much better to store only the frequencies. but this is still working
  // fast so....(i'm lazy) =)
  array<int, 4> O = {1, 2, 3, 4};
  loop0n(i, 4) { N[0].push_back(O[i]); }
  for (int i = 1; i < 9; i++) {
    for (const auto& nii : N[i - 1]) loop0n(j, 4) {
        N[i].push_back(O[j] + nii);
      }
  }

  vector<int> M[6];
  array<int, 6> Om = {1, 2, 3, 4, 5, 6};
  loop0n(i, 6) { M[0].push_back(Om[i]); }
  for (int i = 1; i < 6; i++) {
    for (const auto& nii : M[i - 1]) loop0n(j, 6) {
        M[i].push_back(Om[j] + nii);
      }
  }

  vector<int> NN(37, 0);
  vector<int> MM(37, 0);

  for (const auto& nii : N[8]) {
    NN[nii]++;
  }
  for (const auto& nii : M[5]) {
    MM[nii]++;
  }
  int ntot = N[8].size();
  int mtot = M[5].size();
  long double prob = 0.0;
  for (int i = 9; i < 37; i++) {
    int cless = 0;
    for (int j = i - 1; j >= 6; j--) {
      cless += MM[j];
    }

    long double p =
        ((double)NN[i] / (double)ntot) * ((double)cless / (double)mtot);
    prob += p;
  }
  printf("%.7Lf\n", prob);
}

// end of Problem 205

// problem 119--
void solve199() {
  constexpr const int L = 1000000;
  constexpr const int PL = 20;
  constexpr const unsigned long long LIM = ULLONG_MAX;

  vector<ull> NUMS;

  for (int i = 2; i < L; i++) {
    const ull bLIM = log(LIM) / log((double)i);
    for (int j = 1; j <= bLIM; j++) {
      ull n = ipow<ull>(i, j);
      digits ds = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      intToDigits(n, ds);
      int sumd = 0;
      loop0n(k, 10) { sumd += ds[k] * k; }
      if (sumd == i && n >= 10) NUMS.push_back(n);
    }
  }
  sort(ALL(NUMS));

  cout << NUMS[29] << endl;
}

// end of problem 119--

// problem 187----
void solve187() {
  constexpr const ull LIM = 100000000;
  constexpr const ull LIMP = LIM / 2;
  ull ans = 0;
  vector<ll> primes;
  getPrimesSieve(primes, LIMP);  // primes up to LIMP
  for (int i = 0; i < primes.size(); i++) {
    const ull pl = LIM / primes[i];
    auto p = upper_bound(ALL(primes), pl);
    p--;
    if (*p >= primes[i]) {
      auto dist = abs(distance(p, primes.begin() + i)) + 1;
      ans += dist;
    }
  }
  cout << ans << endl;
}
// end of problem 187----

// problem 125----
bool isPalindromic(ull n) {
  vector<short> D;
  while (n) {
    D.push_back(n % 10);
    n /= 10;
  }
  for (int i = 0; i < D.size() / 2; i++) {
    if (D[i] != D[D.size() - i - 1]) return false;
  }
  return true;
}

void solve125() {
  constexpr const ull LIM = 100000000;
  const ull n = sqrt(LIM);
  ll ans = 0;
  vector<ll> squares(n);

  loop0n(i, n + 1) { squares[i] = i * i; }
  set<ull> NUMS;
  for (int i = 1; i <= n; i++) {
    ull sum = squares[i];
    for (int j = i + 1; j < n; j++) {
      sum += squares[j];
      if (sum < LIM) {
        if (isPalindromic(sum) && NUMS.find(sum) == NUMS.end()) {
          NUMS.insert(sum);
          ans += sum;
        }
      } else {
        break;
      }
    }
  }
  cout << ans << endl;
}
// end of problem 125----

// problem 68---
template <class COLLECTION>
bool cmp_arr(const COLLECTION& v1, const COLLECTION& v2) {
  for (int i = 0; i < v1.size(); i++) {
    if (v1[i] == v2[i]) continue;
    if (v1[i] < v2[i])
      return true;
    else
      return false;
  }
  return false;
}

void solve68() {
  constexpr const int NG = 5;
  constexpr const uint LIM = NG * 3 - NG;
  array<int, NG * 3> NS;
  vector<array<int, NG * 3>> SOLS;
  bitset<LIM> b(0);                // which number has been used?
  for (int i = 0; i < LIM; i++) {  // 1
    b[i] = 1;
    for (int j = 0; j < LIM; j++) {  // 1
      if (!b[j]) {
        b[j] = 1;
        for (int k = 0; k < LIM; k++) {  // 1
          if (!b[k]) {
            b[k] = 1;
            int sum = i + j + k + 3;
            for (int l = 0; l < LIM; l++) {  // 2
              if (!b[l]) {
                b[l] = 1;
                for (int l1 = 0; l1 < LIM; l1++) {  // 2
                  if (!b[l1]) {
                    b[l1] = 1;
                    int sum0 = l + k + l1 + 3;
                    for (int l2 = 0; sum == sum0 && l2 < LIM; l2++) {  // 3
                      if (!b[l2]) {
                        b[l2] = 1;
                        for (int l3 = 0; l3 < LIM; l3++) {  // 3
                          if (!b[l3]) {
                            b[l3] = 1;
                            int sum1 = l2 + l1 + l3 + 3;
                            for (int l4 = 0; sum1 == sum0 && l4 < LIM;
                                 l4++) {  // 4
                              if (!b[l4]) {
                                b[l4] = 1;
                                for (int l5 = 0; l5 < LIM; l5++) {  // 4
                                  if (!b[l5]) {
                                    b[l5] = 1;
                                    int sum2 = l4 + l3 + l5 + 3;

                                    for (int l6 = 0; l6 < LIM; l6++) {  // 5
                                      int sum3 = l6 + l5 + j + 3;
                                      if (!b[l6] && sum3 == sum2) {
                                        NS = {i + 1,  j + 1,  k + 1,  l + 1,
                                              k + 1,  l1 + 1, l2 + 1, l1 + 1,
                                              l3 + 1, l4 + 1, l3 + 1, l5 + 1,
                                              l6 + 1, l5 + 1, j + 1};
                                        // min element between elements of
                                        // indices idx*3
                                        int min = 0;
                                        for (int idx = 3; idx < NG * 3;
                                             idx += 3) {
                                          if (NS[idx] < NS[min]) min = idx;
                                        }
                                        // rotate ns st the minimum element is
                                        // at position 0
                                        rotate(NS.begin(), NS.begin() + min,
                                               NS.end());
                                        SOLS.push_back(NS);
                                      }
                                    }  // 5 - l6
                                    b[l5] = 0;
                                  }
                                }  // 4 - l5
                                b[l4] = 0;
                              }
                            }  // 4 - l4

                            b[l3] = 0;
                          }
                        }  // 3 - l3
                        b[l2] = 0;
                      }
                    }  // 3 - l2
                    b[l1] = 0;
                  }
                }  // 2 - l1
                b[l] = 0;
              }
            }  // 2 - l
            b[k] = 0;
          }
        }  // 1 -k
        b[j] = 0;
      }
    }  // 1- j
    b[i] = 0;
  }  // 1 -i

  auto ans =
      *std::max_element(SOLS.begin(), SOLS.end(), cmp_arr<array<int, NG * 3>>);
  for (const auto& a : ans) {
    cout << a;
  }
  cout << endl;
}

// solve 179---
void solve179() {
  constexpr const int LIM = 10000000;
  l ans = 0;
  vector<int> DIVS(LIM + 1, 0);
  DIVS[1] = 1;
#pragma omp parallel for num_threads(4) schedule(dynamic, 600)
  for (int i = 2; i <= LIM / 2; i++) {
    for (int j = i; j <= LIM; j += i) {
#pragma omp atomic
      DIVS[j]++;
    }
  }
#pragma omp parallel for schedule(dynamic, 600) reduction(+ : ans)
  for (int i = 2; i <= LIM - 1; i++) {
    if (DIVS[i] == DIVS[i + 1]) {
      ans++;
    }
  }
  cout << ans << endl;
}
// end of solve 179---

// end of problem 68---

// end of problem 108

// problem 112---------------
template <class T, class CMP_FN>
bool isIncDec(T n, CMP_FN fn) {
  bool inc = true;
  int d0 = n % 10;
  n /= 10;
  while (n) {
    int d1 = n % 10;
    n /= 10;
    if (!fn(d0, d1)) return false;
    d0 = d1;
  }
  return true;
}

template <class T>
bool isBouncy(T n) {
  return !isIncDec(n, std::less_equal<T>()) &&
         !isIncDec(n, std::greater_equal<T>());
}

void solve112() {
  // using int from problem statement. proportion is 90% up to  21780
  int n = 21780;
  int b = n * 0.9;
  bool end = false;
  double fracp, intp;
  while (!end) {
    n++;
    if (isBouncy(n)) {
      b++;
    }
    fracp = modf(n * 0.990, &intp);
    end = intp == b && fabs(fracp) <= EPS;
  }

  cout << n << endl;
}

// end of problem 112---------------

// problem 145 ------

void solve145_(const unsigned int N, int p, vector<bool>& R, int& ans,
               vector<int>& M) {
  if (p >= N) {
    /* loop0n(i,N){
       cout<<M[i]<<" ";
     }
     cout<<endl;*/
    ans += 1;
    return;
  }

  if (p < N / 2 + (N % 2 != 0))
    for (int i = 0; i < 10; i++) {
      int Pi = i % 2;
      if (!p && !i) continue;
      for (int j = 0; j < 10; j++) {
        int Pj = j % 2;
        if (!p && !j) continue;
        if (N % 2 == 1 && p == N / 2 && i != j) continue;
        R[p + 1] = (i + j) >= 10;
        R[N - p] = R[p + 1];
        if ((R[p] && Pi == Pj) || (!R[p] && Pi != Pj)) {
          M[p] = i;
          M[N - p - 1] = j;
          solve145_(N, p + 1, R, ans, M);
        }
      }
    }
  else {
    if (((M[p] + M[N - p - 1] + R[p]) % 10) % 2 != 0)
      solve145_(N, p + 1, R, ans, M);
  }
}

void solve145() {
  int ans = 0;
  for (int i = 2; i < 10; i++) {
    vector<bool> R(i, false);
    vector<int> M(i, 0);
    solve145_(i, 0, R, ans, M);
    // cout<<i << " "<<ans<<endl;
  }
  cout << ans << endl;
}

// end of problem 145-----

// problem 113----
constexpr const int LIM113 = 101;
ll inc_map[LIM113][10];
ll dec_map[LIM113][10];

ll ninc(const int size, const int s, vector<int>& A, bool f) {
  /*  if(size==0)
      loop0n(i,A.size()){
        cout<<A[i]<<" ";
      }
    cout<<endl;*/
  if (inc_map[size][s] != -1) return inc_map[size][s];

  if (size == 0) {
    inc_map[size][s] = 1;
    return 1;
  }

  ll ans = 0;
  for (int i = s; i <= 9; i++) {
    A[size - 1] = i;
    ans += ninc(size - 1, i, A, false);
  }
  inc_map[size][s] = ans;
  return ans;
}

ll ndec(const int size, const int s, vector<int>& A, bool f) {
  if (size == 0) {
    return 1;
  }

  if (dec_map[size][s] != -1) {
    // cout<<size<<" "<<s<<" "<<dec_map[size][s]<<endl;
    return dec_map[size][s];
  }

  ll ans = 0;
  for (int i = s; i >= f; i--) {
    A[size - 1] = i;
    ans += ndec(size - 1, i, A, false);
  }
  dec_map[size][s] = ans;

  // cout<<size<<" "<<s<<" "<<ans<<endl;
  return ans;
}

void solve113() {
  constexpr const int ND = 100;
  ll ans = 0;
  for (int i = 2; i <= ND; i++) {
    loop0n(i, LIM113 + 1) {
      loop0n(j, 11) { inc_map[i][j] = dec_map[i][j] = -1; }
    }

    vector<int> A(i, 0);
    ll inc, dec;
    inc = ninc(i, 1, A, true);
    // cout<<inc<<endl;
    dec = ndec(i, 9, A, true);
    // cout<<dec<<endl;
    ans += inc + dec - 9;
  }
  cout << ans + 9 << endl;
}

// problem 191----
constexpr const int SIZE191 = 30;
constexpr const int LIMIT_L_191 = 1;
constexpr const int LIMIT_AROW_191 = 2;
enum class C191 { L, O, A };
std::array<C191, SIZE191> str191;

void printstr() {
  loop0n(i, SIZE191) {
    switch (str191[i]) {
      case C191::O:
        cout << "O";
        break;
      case C191::L:
        cout << "L";
        break;
      case C191::A:
        cout << "A";
        break;
    }
  }
  cout << endl;
}
void _solve191(int p, C191 val, int AinRow, int nL, long& ans) {
  if (AinRow > LIMIT_AROW_191 || nL > LIMIT_L_191)
    return;
  else {
    // str191[p] = val;
    if (val == C191::O) AinRow = 0;

    if (val == C191::L) {
      AinRow = 0;
      nL++;
    }
    if (val == C191::A) {
      AinRow++;
    }
    if ((p + 1) == SIZE191 && AinRow <= LIMIT_AROW_191 && nL <= LIMIT_L_191) {
#pragma omp atomic
      ans++;
      // printstr();
    } else {
      _solve191(p + 1, C191::O, AinRow, nL, ans);
      _solve191(p + 1, C191::L, AinRow, nL, ans);
      _solve191(p + 1, C191::A, AinRow, nL, ans);
    }
  }
}
void solve191() {
  int Ainrow = 0;
  int nL = 0;
  long ans = 0;
#pragma omp parallel sections reduction(+ : ans)
  {
#pragma omp section
    { _solve191(0, C191::L, 0, 0, ans); }
#pragma omp section
    { _solve191(0, C191::O, 0, 0, ans); }

#pragma omp section
    { _solve191(0, C191::A, 0, 0, ans); }
  }
  cout << ans << endl;
}

void solve100() {
  // by brute forcing some solutions  you can easily notice that
  // given B_i R_i (a solution) the next one is obtainable by
  // R_{i+1} = 2B_i+R_i-1;
  // B_{i+1} = 2*R_{i+1}*+B_i
  long long R_i, B_i;
  R_i = 6;
  B_i = 15;
  while (R_i + B_i < 1e12) {
    R_i = 2 * B_i + R_i - 1;
    B_i = 2 * R_i + B_i;
  }
  cout << B_i << endl;
}

void listDivisors(ll n, vector<ll>& div) {
  for (int i = 1; i <= sqrt(n) + 1; i++) {
    if (n % i == 0) {
      div.push_back(i);
      if (n / i != i) div.push_back(n / i);
    }
  }
}

void solve75() {
  constexpr const ll SS = 10000;
  std::map<ll, ll> M;
  ll ans = 0;

  for (ll i = 12; i <= 1500000; i += 2) {
    vector<ll> divisors;
    set<array<ll, 3>> T;
    ll i2 = i / 2;
    listDivisors(i2, divisors);
    for (int l = 0; l < divisors.size(); l++) {
      for (int k = l + 1; k < divisors.size(); k++) {
        ll m = divisors[l];
        ll s = divisors[k];
        if (s > m && s < 2 * m && (i2 % (m * s)) == 0) {
          ll kk = ((i2 / s) / m);
          ll y = s - m;

          ll a = kk * (m * m - y * y);
          ll b = kk * 2 * m * y;
          ll c = kk * (m * m + y * y);
          array<ll, 3> tr = {a, b, c};
          sort(ALL(tr));

          T.insert(tr);
          // cout<<i<<":"<<kk*(m*m-y*y)<<" "<<kk*2*m*y<<" "<<kk*(m*m+y*y)<<endl;
        }
      }
    }

    if (T.size() == 1) {
      M[i] = T.size();
      ans++;
    }
  }
  /*for (auto a : M) {
      if (a.second > 0)
          cout << a.first << " " << a.second << endl;
  }*/
  cout << ans << endl;
}

/// problem 98----------
using SC = set<char>;

void solve98() {
  constexpr const int LIM = 50000;
  // read words;
  vector<string> words;
  unordered_map<string, vector<string>> anagrams;

  string word;
  cin >> word;
  string ss;
  for (int i = 0; i < word.size(); i++) {
    if (word[i] == ',') {
      words.push_back(ss);
      ss.clear();
    } else if (word[i] != '"') {
      ss += word[i];
    }
  }
  words.push_back(ss);
  for (auto s : words) {
    string ssorted = s;
    sort(ssorted.begin(), ssorted.end());
    anagrams[ssorted].push_back(s);
  }

  unordered_map<int, vector<ll>> squares;
  int m = 1;
  int d = 1;
  for (int i = 0; i < LIM; i++) {
    if (i * i > 10 * m) {
      m *= 10;
      d++;
    }
    squares[d].push_back(i * i);
  }

  auto isGood = [](string w, ll num, auto& mapping) {

    unordered_map<int, char> RM;
    for (int i = w.size() - 1; i >= 0; i--) mapping[w[i]] = -1;
    for (int i = 0; i <= 9; i++) RM[i] = '!';

    for (int i = w.size() - 1; i >= 0; i--) {
      int d = num % 10;
      if (mapping[w[i]] != -1 && d != mapping[w[i]]) return false;
      if (RM[d] != '!' && w[i] != RM[d]) return false;

      mapping[w[i]] = d;
      RM[d] = w[i];

      if (i == 0 && d == 0) return false;

      num /= 10;
    }
    return true;
  };

  auto getNumFromMapping = [](string ww, auto& mapping) {
    ll retNum = 0;
    int m = 1;
    for (auto c : ww) {
      retNum *= 10;
      retNum += mapping[c];
      if (retNum == 0)  // no zero as first digit
        return -1ll;
    }
    return retNum;
  };

  ll maxAN = LLONG_MIN;
  for (auto an : anagrams) {
    if (an.second.size() > 1) {  // at least two anagrams
      for (int i = 0; i < an.second.size();
           i++) {  // for each word anagram with those letters
        string w = an.second[i];
        for (auto num : squares[w.size()]) {  // check all squares numbers of
                                              // that specific num of digits
          unordered_map<char, int> mapping;
          if (isGood(w, num, mapping)) {  // if the current square is a good
                                          // than get the mapping letter to
                                          // digit
            for (int j = i + 1; j < an.second.size(); j++) {
              string ww = an.second[j];
              ll wwnumber = getNumFromMapping(
                  ww, mapping);  // from the given mapping, calculate the number
                                 // for the word ww
              if (binary_search(
                      ALL(squares[w.size()]),
                      wwnumber)) {  // if also that is a square we are good
                maxAN = max(maxAN, wwnumber);
                // cout << w << " " << ww << " " << num << " " << wwnumber << "
                // " << endl;
              }
            }
          }
        }
      }
    }
  }
  cout << maxAN << endl;
}

/// problem 124----------

void solve124() {
  constexpr const int LIM124 = 100001;
  vector<ll> primes;
  getPrimesSieve(primes, 100001);
  vector<pair<ll, ll>> NR(LIM124);
  NR[1] = make_pair(1, 1);
  for (int i = 2; i < LIM124; i++) {
    vector<pii> F;
    if (binary_search(ALL(primes), i)) {
      NR[i] = make_pair(i, i);
    } else if (factorize(i, F, primes)) {
      ll radical = 1;
      for (int j = 0; j < F.size(); j++) radical *= F[j].first;

      NR[i] = make_pair(radical, i);
    }
  }

  sort(ALL(NR));

  cout << NR[10000].second << endl;
}

// problem 114 --------------
ll ans114 = 0;
vector<ll> map114[2];
ll count(const int m, const int l, bool insert) {
  if (map114[insert][l] != -1) return map114[insert][l];
  ll pans = 0;
  // filling the restwith empty cells only
  if (l == 0) return 1;
  if (l == m && insert) return 1;

  // only one way to fill 3 space with emptiness
  if (l <= m && !insert) return 1;
  // no space for inserting
  if (l < m && insert) return 0;

  // l>=3 && insert
  if (insert)
    for (ll i = m; i <= l; i++) {
      pans += count(m, l - i, false);
    }
  // l
  else
    for (ll i = 1; i <= l; i++) {
      pans += count(m, l - i, true);
    }

  map114[insert][l] = pans;
  return pans;
}
void solve114() {
  loop0n(j, 2) {
    map114[j].resize(51);
    std::fill(ALL(map114[j]), -1);
  }
  int s = 50;
  cout << count(3, s, true) + count(3, s, false);
}

void solve115() {
  // use count of problem 114 search on the value of n
  int m = 50;
  int s = 50;
  loop0n(j, 2) {
    map114[j].resize(1000);
    std::fill(ALL(map114[j]), -1);
  }
  while (count(m, s, true) + count(m, s, false) < 1000000) {
    loop0n(j, 2) { std::fill(ALL(map114[j]), -1); }
    // cout << count(m, s, true) + count(m, s, false) << endl;
    s++;
  }
  cout << s << endl;
}

// problem 118--------------
bool insertPrime(const ll prime, digits& digits118) {
  digits dprimes;
  std::fill(ALL(dprimes), 0);
  intToDigits(prime, dprimes);
  if (dprimes[0])  // 0 not included
    return false;
  loop0n(i, 10) {
    if (dprimes[i] > 1) return false;
    if (dprimes[i] && digits118[i]) return false;
  }
  // all good can update digits118
  loop0n(i, 10) {
    if (dprimes[i]) digits118[i] = dprimes[i];  //=1
  }
  return true;
}

void removePrime(const ll prime, digits& digits118) {
  digits dprimes;
  std::fill(ALL(dprimes), 0);
  intToDigits(prime, dprimes);
  loop0n(i, 10) {
    if (dprimes[i]) digits118[i] = 0;
  }
}

ll ans118 = 0;
constexpr const int LIM118 = 123456789;
vector<ll> solution118;
void solve_118(vector<ll>& primes, int i, int dc, digits& digits118) {
  // cout <<i<<" "<< primes.size() <<" "<<primes[i]<< endl;
  int numD = magnitude(primes[i]);
  if (dc == 0) {
    ans118++;
    // print all solutions
    /* loop0n(i, solution118.size()) {
         cout << solution118[i] << " ";
     } cout << endl;*/
  }
  if (numD > dc) return;
  int j = i;

  while (numD <= dc && j < primes.size()) {
    if (insertPrime(primes[j], digits118)) {
      // solution118.push_back(primes[j]);
      dc = dc - numD;
      solve_118(primes, j + 1, dc, digits118);
      removePrime(primes[j], digits118);
      dc = dc + numD;
      // solution118.pop_back();
    }
    j++;
    numD = magnitude(primes[j]);
  }
}
void solve118() {
  vector<ll> primes;
  getPrimesSieve(primes, LIM118);

  auto badPrime = [](const auto& p) {
    digits dd;
    std::fill(ALL(dd), 0);
    intToDigits(p, dd);
    if (dd[0]) return true;
    loopse(i, 1, 10) {
      if (dd[i] > 1) return true;
    }
    return false;
  };
  // remove all prime containing duplicate digits and
  // zero. those are note part of any subset
  auto end = std::remove_if(ALL(primes), badPrime);
  primes.resize(distance(begin(primes), end));

  digits digits118;
  std::fill(ALL(digits118), 0);
  solve_118(primes, 0, 9, digits118);
  cout << ans118 << endl;
}

// problem 111-----
bool isPrime111(const ll p, const vector<ll>& primes) {
  for (int i = 0; i < primes.size(); i++) {
    if (primes[i] > sqrt(p) + 1) break;
    if (p % primes[i] == 0) return false;
  }
  return true;
}

ll digitsToInt(int numD, digits& d) {
  ll n = 0;
  for (int i = 0; i < numD; i++) {
    n *= 10;
    n += d[i];
  }
  return n;
}

ll minusOne(int numD, int d, const vector<ll>& primes) {
  ll s = 0;
  digits num;
  std::fill(begin(num), begin(num) + numD, d);
  for (int i = 0; i < numD; i++) {
    for (int j = 0; j < 10; j++) {
      num[i] = j;
      if (num[0] == 0 || num[numD - 1] % 2 == 0) {
        num[i] = d;
        continue;
      }
      ll number = digitsToInt(numD, num);
      // cout << "trying " << number ;
      if (isPrime111(number, primes)) {
        s += number;
        // cout<<number <<"-> prime\n";
      }
      // cout<< endl;
      num[i] = d;
    }
  }
  return s;
}

// all digits of a number of numD digits are filled with digit d
// only two positions are changed to another digit
ll minusTwo(int numD, int d, const vector<ll>& primes) {
  ll s = 0;
  digits num;
  std::fill(begin(num), begin(num) + numD, d);
  for (int i = 0; i < numD; i++) {
    for (int j = 0; j < 10; j++) {
      num[i] = j;
      if (j == d || num[0] == 0) {
        num[i] = d;
        continue;
      }
      for (int k = i + 1; k < numD; k++) {
        for (int l = 0; l < 10; l++) {
          num[k] = l;
          if (l == d || num[0] == 0 || num[numD - 1] % 2 == 0) {
            num[k] = d;
            continue;
          }
          ll number = digitsToInt(numD, num);
          // cout << "trying (" << i<<" "<<j<<","<<k<<" "<<l<<") "<<number ;
          if (isPrime111(number, primes)) {
            s += number;
            // cout <<"-> prime\n";
          }
          // cout<< endl;
          num[k] = d;
        }
      }
      num[i] = d;
    }
  }
  return s;
}

void solve111() {
  constexpr const long numD = 10;
  const ll LIM111 = ipow<ll>(10, numD);

  vector<ll> primes;
  getPrimesSieve(primes, sqrt(LIM111) + 1);

  ll sumsum = 0;
  for (int d = 0; d < 10; d++) {
    ll sum = minusOne(numD, d, primes);
    if (!sum) {
      // cout << " :2: ";
      sum = minusTwo(numD, d, primes);
    }
    sumsum += sum;
    // cout << d << " " << sum << endl;
  }
  cout << sumsum << endl;
}

// problem 142------
void solve142() {
  constexpr int LIM142 = 10000;
  vector<ll> squares;
  for (ll i = 1; i < LIM142; i++) {
    squares.push_back(i * i);
  }
  ll minSum = LLONG_MAX;

  for (int k = 0; k < LIM142; k++) {
    for (int m = 0; m < k; m++) {  // m<k
      ll kkk = squares[k];
      ll mmm = squares[m];
      ll qqq = kkk - mmm;  // has to be a perfect square

      if (!binary_search(ALL(squares), qqq)) continue;

      for (int l = k - 1; l >= 0; l--) {  // l<k
        ll lll = squares[l];

        ll nnn = kkk + lll - mmm;
        ll xx = ((double)(kkk / 2.0) + (double)(lll / 2.0));

        ll ppp = mmm - lll;
        if (!binary_search(ALL(squares), ppp))  // n has to be a square
          continue;

        // make sure that xx and yy are integers
        if ((even(kkk) && odd(lll)) || ((even(lll) && odd(kkk)))) continue;
        if (mmm <= xx ||
            !binary_search(ALL(squares), nnn))  // n has to be a square
          continue;

        ll yy, zz;
        xx = (double)kkk / 2.0 + (double)lll / 2.0;
        yy = (double)kkk / 2.0 - (double)lll / 2.0;
        zz = mmm - (double)(kkk / 2.0) - (double)(lll / 2.0);
        ll sum142 = xx + yy + zz;
        if (sum142 < minSum) {
          cout << kkk << " " << mmm << " " << qqq << " " << lll << " " << nnn
               << " | ";
          cout << xx << " " << yy << " " << zz << " = " << sum142 << endl;
          minSum = sum142;
        }
      }
    }
  }
}

// problem 149----------------------------------------------------
// similar to  kadane's algorithm
/**
 Kadane's Algorithm.
 @param v is the array on which tje algorithm runs
 @param cmp is a comparing function which expect the partial sum as its first
 argument (max or min)

*/
template <class T, class CMP>
inline T kadane(const vector<T>& v, CMP cmp) {
  T maxSum = LLONG_MIN;
  T partSum = 0;
  for (int i = 0; i < v.size(); i++) {
    partSum += v[i];
    if (cmp(partSum, maxSum)) {
      maxSum = partSum;
    }
    if (partSum < 0) partSum = 0;
  }
  return maxSum;
}

void solve149() {
  constexpr int SIZE = 2000;
  vector<ll> M[SIZE + 1];
  loopse(i, 1, SIZE + 1) {
    M[i].resize(SIZE + 1);
    // std::fill(ALL(M[i]), 0);
  }
  vector<ll> tmp(SIZE * SIZE + 1, 0);
  constexpr ll modulus = 1000000;
  for (ll i = 1; i <= 55; i++)
    tmp[i] = (100003 - 200003 * i + 300007 * i * i * i) % modulus - 500000;
  for (ll i = 56; i <= SIZE * SIZE; i++)
    tmp[i] = (tmp[i - 24] + tmp[i - 55] + 1000000) % modulus - 500000;

  int i_tmp = 1;
  for (int i = 1; i <= SIZE; i++)
    for (int j = 1; j <= SIZE; j++, i_tmp++) M[i][j] = tmp[i_tmp];

  tmp.clear();
  ll maxSum = LLONG_MIN;
  auto cmp = [](const ll& a, const ll& b) { return std::max(a, b); };
// max among rows
#pragma omp parallel for reduction(max : maxSum)
  for (int i = 1; i <= SIZE; i++) maxSum = std::max(maxSum, kadane(M[i], cmp));

// max among columns
#pragma omp parallel for reduction(max : maxSum)
  for (int i = 1; i <= SIZE; i++) {
    vector<ll> col(SIZE);
    for (int j = 1; j <= SIZE; j++) col[j - 1] = M[j][i];
    maxSum = std::max(maxSum, kadane(col, cmp));
  }

// max among main digonals
#pragma omp parallel for reduction(max : maxSum)
  for (int i = 1; i <= SIZE; i++) {
    vector<ll> diag;
    for (int k = i, j = 1; k <= SIZE && j <= SIZE; k++, j++)
      diag.push_back(M[k][j]);
    maxSum = std::max(maxSum, kadane(diag, cmp));
  }
// max among main digonals
#pragma omp parallel for reduction(max : maxSum)
  for (int j = 2; j <= SIZE; j++) {
    vector<ll> diag;
    for (int k = j, i = 1; k <= SIZE && i <= SIZE; k++, i++)
      diag.push_back(M[i][k]);
    maxSum = std::max(maxSum, kadane(diag, cmp));
  }

// max among anti-digonals
#pragma omp parallel for reduction(max : maxSum)
  for (int i = 1; i <= SIZE; i++) {
    vector<ll> diag;
    for (int k = i, j = SIZE; k <= SIZE && j >= 1; k++, j--)
      diag.push_back(M[k][j]);
    maxSum = std::max(maxSum, kadane(diag, cmp));
  }
// max among anti-digonals
#pragma omp parallel for reduction(max : maxSum)
  for (int j = SIZE - 1; j >= 1; j--) {
    vector<ll> diag;
    for (int k = j, i = 1; k >= 1 && i <= SIZE; k--, i++)
      diag.push_back(M[i][k]);
    maxSum = std::max(maxSum, kadane(diag, cmp));
  }

  cout << maxSum << endl;
}

// problem 150----------------
void solve150() {
  // generate the triangular matrix
  vector<vector<ll>> M;
  constexpr int LIM150 = 500500;
  ll t = 0;
  const ll two20 = ipow<ll>(2, 20);
  const ll two19 = ipow<ll>(2, 19);
  int row_c = 0;
  for (int i = 0; i < 500500;) {
    vector<ll> row(row_c + 1);
    ll psum = 0;
    for (int j = 0; i < 500500 && j < row_c + 1; j++, i++) {
      t = (615949l * t + 797807l) % two20;
      row[j] = t - two19;
    }
    M.push_back(row);
    row_c++;
  }

  // compute prefix sum
  loop0n(i, M.size()) {
    loopse(j, 1, M[i].size()) { M[i][j] += M[i][j - 1]; }
  }

  // for each pair of columns
  for (int i = 0; i < M.size(); i++) {
    for (int j = i; j < M.size(); j++) {
      vector<ll> row_ij;  //
      for (int k = i; k <= j; k++) {
        ll s = i == 0 ? M[k][j] ? M[k][j] - M[i - 1][j];
        row_ij.push_back(s);
      }
    }
  }

  cout << M[0][0] << " " << M[1][1] - M[1][0] << " " << endl;
}


int main() {
  ios_base::sync_with_stdio(false);
  solve150();

  return 0;
}
