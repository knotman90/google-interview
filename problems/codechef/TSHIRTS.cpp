#include <iostream>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <algorithm>
#include <cstring>

using namespace std;
using l = long;
using ll = long long;
using ul = unsigned long;

constexpr ll N = 10 + 5;
constexpr ll NS = 100 + 5;
constexpr ll MOD = 1000000007;

int n = 0;
bool SHIRTS[N][NS] = {{0}};
ll DP[1 << N][NS] = {{0}};

ll solve(const int tid, const int mask)
{
  if (tid >= 101 )  
    return __builtin_popcount(mask) == n;
  if (DP[mask][tid] != -1) 
    return DP[mask][tid];

  ll ans = solve(tid+1, mask);
  for (int p = 0; p < n; p++, ans%=MOD) {
    if (!((1 << p) & mask) && SHIRTS[p][tid])
      ans += (solve(tid + 1, mask | (1 << p)));
  }
  DP[mask][tid] = ans%MOD;
  return DP[mask][tid];
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    memset(SHIRTS, false, sizeof(SHIRTS));
    std::fill(&DP[0][0], &DP[0][0] + N*NS, -1);

    cin >> n;
    string line;
    getline(cin, line);
    for (int i = 0; i < n; ++i)
    {
      getline(cin, line);
      istringstream ss(line);
      int num;
      while (ss >> num)
      {
        SHIRTS[i][num] = true;
      }
    }
    cout<<solve(1,0)<<endl;
  }

  return 0;
}