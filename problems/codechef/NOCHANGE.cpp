#include <bits/stdc++.h>
#include <random>
using namespace std;
using namespace std::chrono;

using pii = pair<int, int>;
using l   = long;
using ll  = long long;
using ull = unsigned long long;

template <typename T> using vec = vector<T>;

int log2i(int n)
{
  int ans = 0;
  while (n >>= 1)
    ans++;
  return ans;
}

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

ll n, p;
vec<ll> D;

void solve_case()
{
  cin >> n >> p;
  D.clear();
  D.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> D[i];
  }

  const auto it = find_if(begin(D), end(D), [=](auto x) { return p % x != 0; });
  if (it != D.end())
  {
    cout << "YES ";
    for (auto it1 = begin(D); it1 != D.end(); it1++)
    {
      if (it1 != it)
      {
        cout << "0 ";
      }
      else
      {
        cout << (p / (*it)) + 1 <<" ";
      }
    }
  }
  else
  {
    cout << "NO";
  }
  cout << endl;
}

void solve()
{
  int T;
  cin >> T;
  while (T--)
  {
    //D.clear();
    solve_case();
  }
}