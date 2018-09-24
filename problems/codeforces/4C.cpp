#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

using pii = pair<int, int>;

int main() {
  int n;
  cin >> n;
  unordered_map<string, int> M;
  while (n--) {
    string s;.
    cin >> s;
    if (M.find(s) != end(M)) {
      s += to_string(++M[s]);
      cout << s << endl;
    } else {
      cout << "OK" << endl;
      M[s] = 0;
    }
  }
  return 0;
}