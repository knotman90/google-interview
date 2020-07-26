#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

#include <cstring>

using namespace std;
using l = long;
using ll = long ;
using ul = unsigned long;

int n;
int L[21][21];
long  DP[1 << 21];

inline ll solve(const int m) {
  const int k = __builtin_popcount(m);
  if (k >= n) return 1;
  if (DP[m] != 0) 
    return DP[m];

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (!L[k][i] || ((1 << i) & m)) 
      continue;
    ans += solve(((1 << i) | m));
  }
  DP[m] = ans;
  return ans;
}
/*

inline ll solve(const int n){
  int max = (1<<n)-1;
  DP[0] = 1;
  for(int m = 0 ; m <= max ; m++)
  {
    const int k = __builtin_popcount(m);
    for(int i = 0 ; i < n ; i++)
    {
      if(L[k][i] && !((1<<i)&m) )
      {
        const int nm = ((1<<i)| m);
        DP[nm] += DP[m];
      }
    }
  }
  return DP[max];
}
*/
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> L[i][j];
      }
    }
    memset(DP, 0, sizeof(DP[0]) * (1 << n));
    cout << solve(0) << endl;
  }

  return 0;
}