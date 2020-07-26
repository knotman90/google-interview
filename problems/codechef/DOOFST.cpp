#include <bits/stdc++.h>
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

constexpr unsigned D = 10000;
vector<bool> N[D];
int mstep = 0;

void solve(const int step, const int start, const int end) {
  if (start >= end) return;
  //cout << start << " " << end << endl;
  mstep = max(mstep, step);
  const int h = (start + end) / 2;
  for (int i = start; i <= h; i++)
    N[step][i] = 1;
 
  solve(step + 1, start, h);
  solve(step + 1, h+1 , end);
}

int log2i(int n) {
  int ans = 0;
  while (n >>= 1) ans++;
  return ans;
}

void solve() {

  int n, m;
  cin >> n >> m;

  const int l = log2i(nn);
  if (n * l > 10e6) {
    cout << -1;
    return;
  }

  for (int i = 0; i < 5+l; i++) N[i].resize(n);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
  }

  solve(0, 0, n-1);
  cout << mstep + (n>1) << endl;
  for (int i = 0; (n > 1) && i <= mstep; i++) {
    for (int j = 0; j < n; ++j) {
      cout << N[i][j];
    }
    cout << endl;
  }
}