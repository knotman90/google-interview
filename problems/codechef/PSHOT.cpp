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


void solve_case()
{
  int n; cin>>n;
  int a,b;
  a = b = 0;
  int ans = n*2;
  for (int i = 0; i < n; ++i)
  {
    char goalc; cin>>goalc;
    bool goal = goalc=='1';
    a += goal ? 1 : 0;
    if(abs(a-b) > (n-i) && ans==2*n)
    {
      ans = 2*(i)+1;
    }
    cin>>goalc;
    goal = goalc=='1';
    b += goal ? 1 : 0;    
    
    if(abs(a-b) > (n-i) && ans==2*n)
    {
      ans = 2*(i+1);
    }
  }
  cout<<ans<<endl;

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