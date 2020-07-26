#include <iostream>
#include <vector>

using namespace std;
using l = long;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;


vector<l> DP;
l C(const string& s, const unsigned pos) {
  if (pos >= s.size() - 1) return 1;
  if (DP[pos] >= 0) return DP[pos];

  const char f  = s[pos];
  if(f=='0')
    return 0;

  const char ff = s[pos + 1];

  l ans = 0;
  if (ff != '0') ans += C(s, pos + 1);

  const int n = (f - '0') * 10 + (ff - '0');
  if (n <= 26) ans += C(s, pos + 2);

  DP[pos] = ans;
  return DP[pos];
}

int main() {
  string s;
  cin >> s;
  while (s != "0") {
    DP.clear();
    DP.resize(s.size(),-1);
    cout << C(s, 0)<<endl;
    cin >> s;
  }

  return 0;
}