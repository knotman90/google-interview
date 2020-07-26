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

//---------PROBLEM CODE ------------------

array<pair<int, string>, 3> S;

template <typename Iter>
vector<ull> prefix(Iter start, const Iter finish) {
  vector<ull> ans(distance(start, finish));
  int i = 0;
  ull h = 0;
  while (start != finish) {
    h = h + (int)(*start);
    ans[i++] = h;
    start++;
  }
  return ans;
}

string merge(const string& s1, const string& s2) {
  std::size_t found = s1.find(s2);
  if (found != std::string::npos) return s1;

  vector<ull> s1_suffix = prefix(rbegin(s1), rend(s1));
  reverse(begin(s1_suffix), end(s1_suffix));
  vector<ull> s2_prefix = prefix(s2.begin(), s2.end());
  
  int p1 = 0;
  int p2 = 0;
  if (s1.size() >= s2.size()) {
    p1 = s1.size() - s2.size();
    p2 = s2.size() - 1;
  } else {
    p1 = 0;
    p2 = s1.size() - 1;
  }

  while (p2 >= 0 && p1 < s1_suffix.size()) {
    if (s1_suffix[p1] == s2_prefix[p2] &&
        equal(s1.begin() + p1, s1.end(), s2.begin())) {
      return s1.substr(0, p1) + s2;
    }
    p1++;
    p2--;
  }
  return s1 + s2;
}

void solve() {
  cin >> S[0].second >> S[1].second >> S[2].second;
  S[0].first = 0;
  S[1].first = 1;
  S[2].first = 2;
  unsigned res = numeric_limits<unsigned>::max();
  do {
    string k = merge(S[0].second, S[1].second);
    string ans = merge(k, S[2].second);
    if (res > ans.size()) res = ans.size();
  } while (std::next_permutation(S.begin(), S.begin() + 3));
  cout << res << endl;
}