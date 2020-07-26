#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr unsigned long long k = 998244353ll;
using ull = unsigned long long;

ull calculate(const ull Pn, const ull n, const vector<ull>& M) {
  if (Pn == 0) return 0ll;

  const unsigned logPi = std::floor(log2(Pn));
  ull ans = M[n + logPi];
  if (logPi > 0) 
    ans = (ans + calculate(Pn - (1 << logPi), n, M)) % k;

  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  string A, B;
  cin >> A >> B;
  std::reverse(begin(A), end(A));
  std::reverse(begin(B), end(B));

  const int lim = max(n, m);
  vector<ull> M(lim + 5, 0);
  M[0] = 1ll;
  for (int i = 1; i <= m + 4; i++) 
    M[i] = (2 * M[i - 1]) % k;

  vector<ull> P(m, 0);
  P[m - 1] = (B[m - 1] == '1') ? 1 : 0;
  for (int i = m - 2; i >= 0; --i) 
    P[i] = P[i + 1] + ((B[i] == '1') ? 1 : 0);

  ull ans = 0;
  for (int i = 0; i < min(n,m); i++)
    if (A[i] == '1' )
      ans = (ans + calculate(P[i], i, M)) % k;

  cout << ans << endl;

  return 0;
}