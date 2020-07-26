#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
#include <cstring>
using namespace std;

using pii = pair<int, int>;

constexpr int NC = 100+5;
constexpr int MS = 101*500;
vector<int>C;

int DP[NC][MS];

long long solve(const int c, const int sum1, const int sum2)
{
  const int d = abs(sum1-sum2);
  if(c < 0)
    return d;
  if(DP[c][d] != -1)
    return DP[c][d];

  DP[c][d] = min(
      solve(c-1, sum1+C[c], sum2),
      solve(c-1, sum1, sum2+C[c]) 
      );
  return DP[c][d];
}




int main() {
  int T;
  cin >> T;

  while (T--)
  {
    fill(&DP[0][0], &DP[0][0]+NC*MS,-1);
    int m; cin>>m;
    C.clear();
    C.resize(m);
    for (int i = 0; i < m; ++i)
      cin>>C[i];

    cout<<solve(m-1,0,0)<<endl;
  }

  return 0;
}