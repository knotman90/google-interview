#include <iostream>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <algorithm>
#include <cstring>

using namespace std;
using l  = long;
using ll = int;
using ul = unsigned long;

unordered_map<ll, ll> S;
unordered_map<ll, ll> NUM;
ll maxn = -1;

inline ll calculate(const int n)
{
  ll ans = 0;
  for (int i = n; i <= maxn; i += n)
  {
    if (NUM.find(i) != NUM.end())
      ans += NUM[i];
  }
  return ans;
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    S.clear();
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> N(n);
    for (int i = 0; i < n; ++i)
    {
      cin >> N[i];
      NUM[N[i]]++;
      maxn = max(maxn, N[i]);
    }

    for (int i = N.size() - 1; i >= 0; --i)
    {
      NUM[N[i]]--;
      if (S.find(N[i]) == S.end())
      {
        const ll v = calculate(N[i]);
        ans        = max(ans, v);
        S[N[i]]    = v;
      }
    }
    cout<<ans<<endl;
  }

  return 0;
}