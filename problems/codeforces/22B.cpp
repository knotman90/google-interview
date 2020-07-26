#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// incremental loops
#define loop0n(i, n) for (int i = 0; i < n; ++i)
#define loopse(i, s, e) for (int i = s; i < e; ++i)
#define loopsei(i, s, e, inc) for (int i = s; i < e; i += inc)
// decremental loops
#define dloop0n(i, n) for (int i = n; i >= 0; --i)
#define dloopse(i, s, e) for (int i = s; i >= e; --i)
#define dloopsei(i, s, e, inc) for (int i = s; i >= e; i -= inc)

// for map, pair
#define mp make_pair
#define fi first
#define se second

template <class T>
inline unsigned int mod(const T m, const T n) {
  return m >= 0 ? m % n : (n - abs(m % n)) % n;
}

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

constexpr int S = 27;
int M[S][S] = {{0}};

int perimeter(int a, int b) { return 2 * (a) + 2 * (b); }
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      M[i][j] = c == '1' ? 1 : 0;
    }
  }

  int ans2 = 0;
  pii ans(0, 0);
  pii pos(0, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      pii sol(0, 0);
      if (M[i][j] == 1) continue;
      for (int k = 0; k < n; ++k) {
        for (int l = 0; l < m; ++l) {
          if (i + k < n && j + l < m) {
            bool bad = false;
            for (int rr = i; !bad && rr <= i + k; ++rr)
              for (int cc = j; !bad && cc <= j + l; ++cc)
                if (M[rr][cc] == 1) bad = true;

            if (!bad && perimeter(k, l) > perimeter(ans.first, ans.second))
              ans = make_pair(k, l);
          }
        }
      }
    }
  }
  cout << perimeter(ans.fi + 1, ans.se + 1) << endl;
}
