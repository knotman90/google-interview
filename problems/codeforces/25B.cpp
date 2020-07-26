#include <bits/stdc++.h>

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

int main() { MEASURE_TIME(solve()); }

//---------PROBLEM CODE ------------------

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int i = 0;
  if (n % 2 == 0) {
    while (i < s.size() - 2) {
      cout << s.substr(i, 2) << "-";
      i += 2;
    }
    cout << s.substr(i, 2);
  }else{
    while (i < s.size() - 3) {
      cout << s.substr(i, 2) << "-";
      i += 2;
    }
    cout << s.substr(i, 3);
  }
 
  cout << endl;
}