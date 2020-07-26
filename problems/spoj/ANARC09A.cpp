#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>

using namespace std;
using l = long;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;

//too slow this solution is cubic!

vector<vector<int>>DP;
string s;

int K(char c, char c1) {
 
  if (c == '{' && c1=='}') return 0;
  if ((c == '{' && c1=='{') || (c == '}' && c1=='}')) return 1;
  return 2;
}

int C(const int i, const int j) {
  if (i > j) return 0;
  
  if (DP[i][j] != -1) return DP[i][j];

  int ans = numeric_limits<int>::max();
  for (int k = i + 1; k <= j; k+=2) {
    const int cost = K(s[i], s[k]) + 
      C(i + 1, k - 1) +
      C(k+1, j) ;
    ans = min(ans, cost);
    if(ans == 0)
      break;
  }
  DP[i][j] = ans;
  return DP[i][j];
}

int main() {
  cin >> s;
  while (s[0] != '-') {
    DP.clear();
    DP.resize(s.size()+1 , vector<int>(s.size()+1,-1));
    cout << C(0, s.size() - 1) << endl;
    cin >> s;
  }

  return 0;
}

/*i,j i<=j


{{{}{{{}
{}{}{}{}
 ^   ^
K(c1,c2) = if (c1+c2 == {}) => 0
           else 1
C(1,8) =
        max( K({{) + C(3,8),
             K({}) +C(2,7)
            )

{{}}{{}}



C(1,8)

C(i,j)
minimize
for(k = i+1 .. j)
{
        K(s[i],s[k]) + C(k+1,j) + C(j+1,S.size());
}


*/
