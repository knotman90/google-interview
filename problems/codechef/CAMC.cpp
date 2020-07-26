#include <bits/stdc++.h>
#include <random>
using namespace std;
using namespace std::chrono;

using pii = pair<int, int>;
using l   = long;
using ll  = long long;
using ull = unsigned long long;

template <typename T> constexpr T PINF = numeric_limits<T>::max();

template <typename T> constexpr T NINF = numeric_limits<T>::min();

void solve();

#define MEASURE_TIME(function)                                                 \
  high_resolution_clock::time_point t1 = high_resolution_clock::now();         \
  {                                                                            \
    function;                                                                  \
  }                                                                            \
  high_resolution_clock::time_point t2 = high_resolution_clock::now();         \
  const auto duration = duration_cast<milliseconds>(t2 - t1).count();          \
  cout.flush();                                                                \
  cerr << "--------------" << endl;                                            \
  cerr << "Elapsed Time: " << duration << "ms" << endl;                        \
  cerr << "--------------" << endl;

int main()
{
  MEASURE_TIME({ solve(); })
  return 0;
}

//------------PROBLEM CODE-------------

vector<vector<long>> M;
long n, m;

inline long diffabs(const long a, const long b) { return abs(a - b); }

long calc(long curr)
{
  long minv = -1;
  long maxv = 10e9 + 500;
  bool e = false;
  for (int i = 0; !e && i < M[0].size(); ++i)
  {
    bool good = true;
    long pminv = M[0][i];
    long pmaxv = -1;
    for (int j = 1; j < m; j++)
    {
      const auto b = lower_bound(begin(M[j]), end(M[j]), pminv);
      if (b != end(M[j]))
      {
        pmaxv = max(pmaxv, *b);
      }
      if (b == end(M[j]))
      {
        e = true;
        good = false;
        break;
      }
      if (b == end(M[j]) || diffabs(pmaxv, pminv) > diffabs(maxv, minv))
      {
        break;
      }
    }
    if (good && diffabs(pmaxv, pminv) < diffabs(maxv, minv))
    {
      minv = pminv;
      maxv = pmaxv;
    }
  }

  
  return diffabs(maxv, minv);
  

}
void solve()
{
  int T;
  cin >> T;
  while (T--)
  {
    cin >> n >> m;
    M.clear();
    M.resize(m);
    for (int i = 0, p = 0; i < n; i++, p = i % m)
    {
      long a;
      cin >> a;
      M[p].push_back(a);
    }
    for (int i = 0; i < m; i++)
      sort(begin(M[i]), end(M[i]));

    long ans = numeric_limits<long>::max();

    for (int i = 0; i < m; i++)
    {
      swap(M[i], M[0]);
      ans = min(ans, calc(ans));
      swap(M[i], M[0]);
    }
    cout<<ans<<endl;
  }
}