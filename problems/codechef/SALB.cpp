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
constexpr int INF = numeric_limits<int>::max();
using trip        = tuple<int, int, double>;

vector<trip> T = {{0, 250000, 0.00},       {250001, 500000, 0.05},
                  {500001, 750000, 0.1},   {750001, 1000000, 0.15},
                  {1000001, 1250000, 0.2}, {1250001, 1500000, 0.25},
                  {1500001, INF, 0.30}};

int calculate_tax(trip t, int amount)
{
  if (amount > get<0>(t))
  {
    return (min(amount, get<1>(t)) - get<0>(t) + 1) * get<2>(t);
  }
  return 0;
}

void solve_case()
{
  int n, ans = 0;
  cin >> n;
  for (const auto t : T)
  {
    ans += calculate_tax(t, n);
  }
  cout << n - ans << endl;
}

void solve()
{
  int T;
  cin >> T;
  while (T--)
  {
    solve_case();
  }
}