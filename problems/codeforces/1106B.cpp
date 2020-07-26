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

using Dish = pair<ll,ll>;
struct sort_pair {
  bool operator()(const pii& a, const pii& b) {
    if (a.first < b.first) return true;
    if (a.first == b.first) return a.second < b.second;
    return false;
  }
};
set<Dish, sort_pair> dishes;

constexpr int S = 100000 + 5;
ll A[S] = {0};
ll C[S] = {0};
int n, m;

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> A[i];
  for (int i = 0; i < n; ++i) cin >> C[i];
  for (int i = 0; i < n; ++i) dishes.insert(make_pair(C[i], i));

  for (int i = 0; i < m; ++i) {
    ll t, q;
    cin >> t >> q;
    t--;
    long long ans = 0;
    while (q) {
      if (dishes.find(make_pair(C[t], t)) != dishes.end()) {
        if (q <= A[t]) {
          A[t] -= q;
          ans+=C[t]*q;
          q = 0;
        } else {
          q = q - A[t];
          ans+=C[t]*A[t];
          A[t] = 0;
          dishes.erase(make_pair(C[t], t));
        }
      }else if(dishes.size() > 0){
        auto m = *dishes.begin();
        t = m.second;
      }else{
        ans = q =0;
      }
    }
    cout<<ans<<endl;
  }
}