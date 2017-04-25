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
#define fill(a, v) memset(a, v, sizeof a)
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
#define LOOPUP(...) \
  GET_LOOP(__VA_ARGS__, loopsei, loopse, loop0n) \
(__VA_ARGS__)
#define LOOPDWN(...) \
  GET_LOOP(__VA_ARGS__, dloopsei, dloopse, dloop0n) \
(__VA_ARGS__)


#define pb push_back
#define ALL(v) v.begin(), v.end()

//for map, pair
#define mp make_pair
#define fi first
#define se second
//char to int
inline constexpr int ctoi(const char c)
{ return c - '0'; }
//int to char
inline constexpr char itoc(const int n)
{ return n + '0'; }

template<typename T> inline T clamp(const T& n, const T& lo, const T& hi)
{ return std::max(lo, std::min(n, hi)); }

template<class T> inline void sort(T &a)
{ std::sort(ALL(a)); }

template<class T1, class T2> inline void sort(T1 &a, T2 comp)
{ sort(ALL(a), comp); }

template<class T> inline int read(T& n)
{ return std::cin >> n ? 1 : -1; }
//reads multiple arguments
template<typename T, typename... types> inline int read(T &n, types &...args)
{ return read(n) == -1 ? -1 : read(args...) + 1; }

template<class T> inline void write(const T& n)
{ std::cout << n; }
//reads multiple arguments
template<typename T, typename... types> inline void write(const char sep, T &n, types &...args)
{ write(n); write(sep); write(sep, args...); }



template<typename T> inline constexpr bool odd(const T a)
{ return bool(a & 1); }

template<typename T> inline constexpr bool even(const T a)
{ return !odd(a); }

template<class T>
inline unsigned int mod (const T m, const T n)
{ return m >= 0 ? m % n : ( n - abs( m % n ) ) % n; }

template<class T>
class reader {
public:
  void operator()(T& t) const {
    std::cin >> t;
  }
};

template<class CONTAINER, class READ_Fn>
void read(CONTAINER& v, const unsigned int size, const READ_Fn& rfn = reader<typename CONTAINER::value_type>()) {
  loop0n(i, size) {
    rfn(v[i]);
  }
}

//TYPEDEFS
typedef unsigned long ul;
typedef unsigned long long ull;
typedef signed long l;
typedef signed long long ll;
typedef unsigned int uint;

typedef std::pair<l, l> pll;
typedef std::pair<int, int> pii;
typedef std::pair<uint, uint> puu;

//sort pair based on their first component. If equal it uses the second ones.
auto pair_cmp = [](const pll& p1, const pll& p2)
{
  return (p1.first < p2.first) || (p1.first == p2.first && p1.second < p2.second);
};

//integer power (base^exp)
template<class T>
T ipow(T base, T exp) {
  T result = 1;
  while (exp) {
    if (exp & 1)
      result *= base;
    exp >>= 1;
    base *= base;
  }

  return result;
}

//case counter variable
static int _case_counter = 1;
template< typename T>
void printCase(const T& arg) {
  std::cout << "Case #" << _case_counter++ << ": ";
  write(arg);
  write('\n');

}

template< typename... types>
void printCase(const char sep = ' ', types &...args) {
  std::cout << "Case #" << _case_counter++ << ": ";
  write(sep, args...);
  write('\n');

}

//gcd of two number
template<class M, class N >
M gcds(M& m, N& n) {
  return std::__gcd(m, n);
}

//gcd of N numbers
template<class M, class N, class ... Params >
M gcds(M& m, N& n, Params &...args) {
  return gcd(std::__gcd(m, n), args...);
}
//gcd of a set of numbers in a container
template<typename CONTAINER>
int gcdc(CONTAINER& c) {

  typename CONTAINER::value_type g = c[0];
  for (int i = 1; i < c.size(); i++) {
    g = std::__gcd(g, c[i]);
  }
  return g;
}

template <typename T>
int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}
//------ PROBLEM CODE --------------

using namespace std;

int ans[1000];
int T[1000][3];
int n;



/*

bool intersect(int i, int j) {
  array<int, 3> ti ;
  array<int, 3> tj;

  loop0n(k, 3) {
    ti[k] = T[i][k];
    tj[k] = T[j][k];
  }

//ti has late start
  int speedi = sgn(ti[2] - ti[1]);
  int speedj = sgn(tj[2] - tj[1]);
  auto nti = ti;
  auto ntj = tj;

  int maxstart = max(ti[0], tj[0]);

  int duri = abs(ti[1] - ti[2]) + 1;
  int durj = abs(tj[1] - tj[2]) + 1;
  int endi = ti[0] + duri;
  int endj = tj[0] + durj;

  ntj[0] = nti[0] = maxstart;

  if (nti[0] > endi  || ntj[0] > endj)
    return false;

  nti[1] = ti[1] + (maxstart - ti[0]) * speedi;
  ntj[1] = tj[1] + (maxstart - tj[0]) * speedj;

  int nduri = abs(nti[1] - ti[2]) + 1;
  int ndurj = abs(ntj[1] - tj[2]) + 1;
  int mindur = min(nduri,ndurj);

  nti[2] = ti[2] - speedi * (nduri - mindur);
  ntj[2] = tj[2] - speedj * (ndurj - mindur);

  int m = max(min(nti[1],nti[2]) , min(ntj[1],ntj[2]));
  int M = min(max(nti[1],nti[2]) , max(ntj[1],ntj[2]));


  return (speedi!=speedj && m<=M) || (nti[1]==ntj[1]);

}*/


bool intersect(int i, int j) {
  array<int, 3> ti,tj;
    loop0n(k, 3) {
    ti[k] = T[i][k];
    tj[k] = T[j][k];
  }
  int speedi = sgn(ti[2] - ti[1]);
  int speedj = sgn(tj[2] - tj[1]);
  auto nti = ti;
  auto ntj = tj;

  int maxstart = max(ti[0], tj[0]);
  nti[0]=ntj[0] = maxstart;

  nti[1] = ti[1] + speedi*(abs(maxstart-ti[0]));
  ntj[1] = tj[1] + speedj*(abs(maxstart-tj[0]));

  auto lz = [](auto a){return a<=0;};
  if(
      any_of(ALL(nti), lz)            || 
      any_of(ALL(ntj), lz)            || 
      (speedi==1 && nti[2] < nti[1]  )||
      (speedi==-1 && nti[2] > nti[1] )||
      (speedj==1 && ntj[2] < ntj[1]  )|| 
      (speedj==-1 && ntj[2] > ntj[1] )
    )
    return false;
  

  int mindur = min( abs(nti[1]-nti[2]),abs(ntj[1]-ntj[2]) );
  
  nti[2] = nti[1] + speedi*mindur;
  ntj[2] = ntj[1] + speedj*mindur;   

  if(
      any_of(ALL(nti), lz)            || 
      any_of(ALL(ntj), lz)            || 
      (speedi==1 && nti[2] < nti[1]  )||
      (speedi==-1 && nti[2] > nti[1] )||
      (speedj==1 && ntj[2] < ntj[1]  )|| 
      (speedj==-1 && ntj[2] > ntj[1] )
    )
    return false;

int m = max(min(nti[1],nti[2]),min(ntj[1],ntj[2])); 
int M = min(max(nti[1],nti[2]),max(ntj[1],ntj[2]));
  return (nti[1] == ntj[1]) || (speedi!=speedj &&  m <= M);
}

void solve() {

  loop0n(i, n) {
    loopse(j, i + 1, n) {
      if (intersect(i, j))
      {
        ans[i]++;
        ans[j]++;
      }
    }
  }


}


int main() {
  ios_base::sync_with_stdio(false);
  read(n);
  loop0n(i, n) {
    read(T[i][0], T[i][1], T[i][2]);
    ans[i] = 0;
  }

  solve();
  loop0n(i,n){
    cout<<ans[i]<<" ";
  
  }
  cout<<endl;
  return 0;
}

