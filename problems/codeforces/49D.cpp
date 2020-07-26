#include <bits/stdc++.h>
#include <cctype>
#include <random>
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


/** 
SOLUTION
  A solution looks like one of the following:
    - 01010101...
    - 10101010...
We can brute force the input to look like on of the two combo:
In one move you can fix one pair of the input, and move the next one.
You might be left with a single element at the end if n is odd.
*/

void solve() {
  int n;  cin >> n;
  string s;  cin >> s;
  int ans = numeric_limits<int>::max();
  const int is_odd = n%2==1;
  for (const auto p : {"01", "10"})
  {
    int count = 0;
    for (int i = 0; i < n - (is_odd ? 1 : 0); i += 2) {
      count += (s[i]!=p[0]) || (s[i+1]!=p[1]) ? 1 : 0;
    }
    if(is_odd)
      count += (s.back()!=p[0]) ? 1 : 0;

    ans = min(count, ans);
  }
  cout<<ans<<endl;
}