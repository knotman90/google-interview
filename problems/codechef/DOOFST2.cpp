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

int log2i(int n) {
  int ans = 0;
  while (n >>= 1) ans++;
  return ans;
}

//------------PROBLEM CODE-------------

unordered_map<int, set<int>> G;
vector<set<int>> C;
vector<bool> visited;
set<int> all;

set<int> conn_comp(int start) {
  const auto& out = G[start];
  set<int> res;

  std::set<int> result;
  std::set_difference(all.begin(), all.end(), out.begin(), out.end(),
                      std::inserter(result, result.end()));

  set<int> ans;
  ans.insert(start);
  for (const auto node : result) {
    if (G[node] != out)
      return set<int>();
    else {
      ans.insert(node);
      visited[node] = true;
    }
  }
  visited[start] = true;
  return ans;
}

bool find_conn_comp(const int n) {
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      set<int> c = conn_comp(i);
      if (c.size() <= 0) return false;

      C.push_back(c);
    }
  }
  return true;
}

constexpr unsigned D = 10000;
vector<bool> N[D];

int mstep = 0;

void solve(const int step, const int start, const int end) {
  if (start >= end) return;
  // cout << start << " " << end << endl;
  mstep = max(mstep, step);
  const int h = (start + end) / 2;
  for (int i = start; i <= h; i++) N[step][i] = 1;

  solve(step + 1, start, h);
  solve(step + 1, h + 1, end);
}

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    visited.push_back(false);
    all.insert(i);
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    G[a - 1].insert(b - 1);
    G[b - 1].insert(a - 1);
  }

  if (!find_conn_comp(n)) {
    cout << -1 << endl;
    return;
  }

  int nn = C.size();
  const int l = log2i(nn);
  if (nn * l > 10e6) {
    cout << -1;
    return;
  }

  for (int i = 0; i < 5 + l; i++) N[i].resize(nn);

  solve(0, 0, nn - 1);

  cout << mstep + (nn > 1) << endl;
  for (int i = 0; (nn > 1) && i <= mstep; i++) {
    vector<bool> v;
    v.resize(n);
    for (int j = 0; j < nn; j++) {
      for (const auto nc : C[j]) {
        v[nc] = N[i][j];
      }
    }
    for (const auto k : v) {
      cout << k;
    }
    cout << endl;
  }
}