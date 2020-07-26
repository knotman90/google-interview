#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

using namespace std;
using l = long;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
using pii = pair<int, int>;
/*
struct pairhash {
 public:
  template <typename T, typename U>
  inline std::size_t operator()(const std::pair<T, U>& x) const {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

inline int LCS(const string& s, const string& t, const int i, const int j,
               unordered_map<pii, int, pairhash>& M) {
  if (i < 0 || j < 0) return 0;

  const auto it = M.find(make_pair(i, j));
  if (it != M.end()) return it->second;

  if (s[i] == t[j]) return LCS(s, t, i - 1, j - 1, M) + 1;

  const int res = max(LCS(s, t, i - 1, j, M), LCS(s, t, i, j - 1, M));
  M[make_pair(i, j)] = res;
  return res;
}

void solve(const string& str, unordered_map<pii, int, pairhash>& M) {
  string ss(str);
  reverse(begin(ss), end(ss));
  cout << ss.size() - LCS(str, ss, str.size() - 1, ss.size() - 1, M);
}
*/

int M[6101][6101] = {{0}};

void solve(const string& s) {
  string rev(s);
  reverse(begin(rev), end(rev));

  for (int i = 0; i < s.size(); i++)
    for (int j = 0; j < s.size(); ++j) M[i][j] = 0;

  const int size = s.size();
  for (int i = 0; i < s.size(); i++) {
    M[0][i] = rev[0] == s[i] ? 1 : 0;
  }
  for (int i = 0; i < s.size(); i++) {
    M[i][0] = rev[i] == s[0] ? 1 : 0;
  }
  for (int i = 1; i < s.size(); i++)
    for (int j = 1; j < s.size(); ++j) {
      if (s[j] == rev[i])
        M[i][j] = M[i - 1][j - 1] + 1;
      else
        M[i][j] = max(M[i - 1][j], M[i][j - 1]);
    }
  /*cout << s << endl;
  for (int i = 0; i < s.size(); i++) {
    cout << rev[i] << " ";
    for (int j = 0; j < s.size(); ++j) {
      cout << M[i][j] << " ";
    }
    cout << endl;
  }*/
  cout << size -M[size - 1][size - 1] << " "<<endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    solve(s);
  }
  return 0;
}
