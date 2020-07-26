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

bool brufe_force(const int val, const int d, array<int, 10> &a)
{
  int rest = val;
  for (int a0 = d; rest > 0 && a0 >= 0; a0--)
  {
    a[0] = a0;

    rest -= a0 * 1;
    if (rest == 0 && accumulate(begin(a), end(a), 0) == d)
      return true;

    for (int a1 = rest / 4; rest > 0 && a1 >= 0; a1--)
    {
      a[1] = a1;
      rest -= a1 * 4;
      if (rest == 0 && accumulate(begin(a), end(a), 0) == d)
        return true;

      for (int a2 = rest / 9; rest > 0 && a2 >= 0; a2--)
      {
        a[2] = a2;
        rest -= a2 * 9;

        if (rest == 0 && accumulate(begin(a), end(a), 0) == d)
          return true;

        for (int a3 = rest / 16; rest > 0 && a3 >= 0; a3--)
        {
          a[3] = a3;
          rest -= a3 * 16;

          if (rest == 0 && accumulate(begin(a), end(a), 0) == d)
            return true;

          rest += a3 * 16;
        } // 4

        rest += a2 * 9;
      } // 3

      rest += a1 * 4;
    } // 2
    rest += a0 * 1;
  } // 1
  return false;
}

bool better(const array<int, 10> &a, const array<int, 10> &b)
{
  for (int i = 0; i < 10; ++i)
  {
    if (a[i] > b[i])
      return true;
    if (a[i] < b[i])
      return false;
  }
  return true;
}

int n;
void solve()
{

  int T;
  cin >> T;
  while (T--)
  {
    cin >> n;
    int l              = ceil(sqrt(n));
    array<int, 10> ans = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = l; i * i <= 81 * n; i++)
    {
       //cout << "trying " << i * i << endl;
      array<int, 10> a = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      if (brufe_force(i * i, n, a) && better(a, ans))
      {
        //cout<<"better "<<i*i<<endl;
        ans = a;
      }
    }
    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < ans[i]; j++)
      {
        cout << i + 1;
      }
    }
    cout << endl;
  }
}