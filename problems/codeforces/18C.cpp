#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

using pii = pair<int, int>;
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

ll n , d , m, l;
void solve() {
  cin >> n >> d >> m >> l;
  long long plat = 1;
  long long  pos = 0;
  long long gap = m-l;
  while (plat <= n) {

    const long long end_plat = plat * m;
    if (pos < end_plat) {        // in the current platform
      if (pos > end_plat - gap) {  // it is going to fall
        cout << pos << endl;
        return;
      }
      // on the current platform.
      // jump a no of times until it reaches the end
      const long long dist = end_plat - gap - pos;
      const long long dd = dist / d;
      pos += dd * d + d;
    } else {
      long long dist = pos - end_plat;
      long long kk = dist / m;
      plat += kk + 1;
    }
  }
  cout<<pos<<endl;
}