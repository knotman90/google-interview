#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string t;
  cin >> t;

  string ans(t);
  k--;
  for (unsigned int i = 1; k; i++) {
    if (i >= ans.size()) {
      ans += t;
      --k;
      continue;
    }

    const unsigned int dist = min(ans.size() - i, t.size());
    if (std::equal(begin(t), begin(t) + dist, begin(ans) + i)) {
      ans += std::string(begin(t) + dist, t.end());
      --k;
    }
  }
  cout << ans << endl;
  return 0;
}