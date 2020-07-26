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
  for (int a0 = d; a0 >= 0; a0--)
  {
    a[0] = a0;
    if (a0 == val)
      return true;

    rest = val - a0;

    for (int a1 = rest / 4; a1 >= 0; a1--)
    {
      a[1] = a1;
      if (a1 == val)
        return true;

      rest = val - a1;

      for (int a2 = rest/9; a2 >= 0; a2--)
      {
        a[0] = a0;
        if (a0 == val)
          return true;

        rest = val - a0;
      }//3

    } // 2

  } // 1
}

map<pii, vector<int>> D;
string ans;
int n;

int C = 0;
vector<int> calc(const int val, const int d)
{
  if (C++ > 500)
    return {};
  vector<int> X;
  static array<int, 9> P = {1, 4, 9, 16, 25, 36, 49, 64, 81};
  if (d == 1 && find(P.begin(), P.end(), val) != P.end())
  {
    X.push_back(sqrt(val));
    return X;
  }

  if (val == 0 && d == 0)
    return {};

  if (val <= 0 || d <= 0)
    return {};

  pii p(val, d);
  if (D.find(p) != D.end())
    return D[p];
  //
  for (int i = 1; val >= i * i && i <= 9; i++)
  {
    int j = 1;
    // for (int j = min(d,val / (i * i)); j >= 1; j--)
    {
      vector<int> r = calc(val - j * (i * i), d - j);
      if (r.size() > 0)
      {
        // cout << val << " possible with " << d << " using " << i << endl;
        // ans[d-1]='0'+i;
        // cout << i;
        for (int k = 0; k < j; k++)
          X.push_back(i);
        X.insert(X.end(), r.begin(), r.end());
        break;
      }
    }
    /*vector<int> r = calc(val - i * i, d - 1);
    if (r.size() > 0)
    {
      // cout << val << " possible with " << d << " using " << i << endl;
      // ans[d-1]='0'+i;
      // cout << i;
      X.push_back(i);
      X.insert(X.end(), r.begin(), r.end());
      break;
    }*/
  }
  D[p] = X;
  return X;
}

void solve()
{

  int T;
  cin >> T;
  while (T--)
  {
    cin >> n;
    ans.resize(n, 0);
    bool go = true;
    // cout << endl << n << endl;
    int l = ceil(sqrt(n));
    vector<int> A(n, 9);
    for (int i = l; i * i <= 81 * n; i++)
    {
      go = true;
      cout << "trying " << i * i << endl;
      C = 0;
      for (int j = n; go && j >= 0; j--)
      {
        vector<int> X = calc(i * i - j, n - j);
        if (X.size() > 0)
        {
          for (int k = 0; k < j; k++)
            X.push_back(1);
          sort(X.begin(), X.begin() + n);
          go = false;

          if (A > X)
          {

            // cout << "good " << i * i << endl;
            A = std::move(X);
          }

          // go = false;
          // break;
        }
      }
    }

    for (int i = 0; i < n; ++i)
    {
      cout << A[i];
    }
    cout << endl;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
      sum += A[i] * A[i];
    }
  }
}