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

constexpr int N = 505;
constexpr int M = 505;
constexpr int ALPH = 26;
int n, m;
int COST[N][ALPH][ALPH] = {{{0}}};
bool G_COST[N][ALPH][ALPH] = {{{false}}};
int MEM[N][ALPH][ALPH] = {{{0}}};
bool G_MEM[N][ALPH][ALPH] = {{{false}}};
char I[N][M];
pii P[N][ALPH][ALPH];

int cost(const int r, const int a, const int b) {
  if (G_COST[r][a][b]) return COST[r][a][b];

  int ans = 0;
  for (int i = 0; i < m; i += 2)
    if ((I[r][i] - 'a') != a) ans++;

  for (int i = 1; i < m; i += 2) ans += (I[r][i] - 'a') != b ? 1 : 0;

  G_COST[r][a][b] = true;
  COST[r][a][b] = ans;

  return ans;
}

// cost of subroblem starting at row r where previous row is filled with
// ababab...
int S(const int r, const int a, const int b) {
  if (r >= n) return 0;

  if (G_MEM[r][a][b]) return MEM[r][a][b];

  int ans = numeric_limits<int>::max();
  pii ans_p(-1, -1);
  for (int i = 0; i < ALPH; i++) {
    for (int j = 0; j < ALPH; j++) {
      if (i != j && ( b != j || r == 0)) {
        const int n_ans = cost(r, i, j) + S(r + 1, i, j);
        if (n_ans < ans) {
          ans = n_ans;
          ans_p = make_pair(i, j);
        }
      }
    }
  }
  // cache
  P[r][a][b] = ans_p;
  G_MEM[r][a][b] = true;
  MEM[r][a][b] = ans;

  return ans;
}

void solve() {
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < ALPH; j++)
      for (int k = 0; k < ALPH; k++) P[i][j][k] = make_pair(-1, -1);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> I[i][j];

  cout << S(0, 0, 0) << endl;

  pii color = make_pair(-1, -1);
  int mm = numeric_limits<int>::max();
  for (int i = 0; i < ALPH; i++)
    for (int j = 0; j < ALPH; j++) {
      if (G_MEM[0][i][j] && MEM[0][i][j] < mm) {
        mm = MEM[0][i][j];
        color = P[0][i][j];
      }
    }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!(j & 1))
        cout << (char)('a' + color.first);
      else
        cout << (char)('a' + color.second);
    }
    cout << endl;
    if (i + 1 < n) color = P[i + 1][color.first][color.second];
  }
}