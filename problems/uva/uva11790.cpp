#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
#include <cstring>
using namespace std;

using pii = pair<int, int>;




vector<int> H,W;
vector<int> DPI;
vector<int> DPD;

template<typename Fn>
int solve(const int n, Fn binary_predicate, vector<int>& DP )
{
  if(n==0)
    return W[0];
  if(DP[n] != -1)
    return DP[n];

  int ans = W[n];
  for(int i = 0 ; i < n ; i++)
  {
    if(binary_predicate(H[i] , H[n]))
      ans = max(ans, W[n] + solve(i, binary_predicate, DP));
  }

  DP[n] = ans;
  return ans;
}

int main() {
  int T;
  cin >> T;
  int testcase = 1;
  while (T--)
  {
    int n; cin>>n;
    DPI.clear();
    DPD.clear();
    H.clear();
    W.clear();
    H.resize(n);
    W.resize(n);
    DPI.resize(n);
    DPD.resize(n);
    for (int i = 0; i < n; ++i)
    {
      cin>>H[i];
      DPI[i] = DPD[i] = -1;
    }
    for (int i = 0; i < n; ++i)
      cin>>W[i];
    
    auto inc = [](const int a, const int b){ return a < b;};
    auto dec = [](const int a, const int b){ return a > b;};
    
    int A = -1;
    int B = -1;
    for(int i = 0 ; i < n ; i++){
      A = max(A, solve(i,inc, DPI));
      B = max(B, solve(i,dec, DPD));
    }
    
    cout<<"Case "<<testcase++<<". ";
    if(A >= B)
    {
      cout<<"Increasing ("<<A<<"). Decreasing ("<<B<<")."<<endl;
    }else{
      cout<<"Decreasing ("<<B<<"). Increasing ("<<A<<")."<<endl;
    }
  }

  return 0;
}