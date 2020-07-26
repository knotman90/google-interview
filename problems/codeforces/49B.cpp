#include <bits/stdc++.h>
#include <random>
#include <cctype>
using namespace std;
using namespace std::chrono;

using pii = pair<int, int>;
using l = long;
using ll = long long;
using ull = unsigned long long;

void solve();

#define MEASURE_TIME(function)                                         \
  high_resolution_clock::time_point t1 = high_resolution_clock::now(); \
  { function; }                                                        \
  high_resolution_clock::time_point t2 = high_resolution_clock::now(); \
  const auto duration = duration_cast<milliseconds>(t2 - t1).count();  \
  cout.flush();                                                        \
  cerr << "--------------" << endl;                                    \
  cerr << "Elapsed Time: " << duration << "ms" << endl;                \
  cerr << "--------------" << endl;

int main() {
  MEASURE_TIME({ solve(); })
  return 0;
}

//------------PROBLEM CODE-------------
int biggest_digit(int n){
  int ans = 0;
  while(n){
    ans = max(ans, n%10);
    n/=10;
  }
  return ans;
}

int value_in_base(int n, const int base){
  int ans = 0;
  int pow = 1;
  while(n){
    ans+=pow*(n%10);
    pow*=base;
    n/=10;
  }
  return ans;
}

void solve() {
  int a,b;  cin>>a>>b;
  const int base = max(biggest_digit(a) , biggest_digit(b))+1;
  const int sumab = value_in_base(a,base)+value_in_base(b,base);
  cout<<floor(logl(sumab)/logl(base) +1)<<endl;
}