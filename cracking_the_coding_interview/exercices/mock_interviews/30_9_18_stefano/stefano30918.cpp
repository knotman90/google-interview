#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

/*
- input: numero intero (  1 <= n <= 500)
1. convertilo in binario
2. n interazioni `n` <= 30
 - carattere 0 diventa 01
 - carattere 1 diventa 10
 qual è il valore del carattere dopo `n` iterazioni
*/
/*
k=23
n=3
10011
1.
1001011010
2.


0 -> 01 -> 0110 -> 01101001 ->
1 -> 10 -> 1001 -> 10010110
*/

bool solve(const vector<bool>& S, long k, int n, const int d) {
  if (n == 0) {
    return S[d];
  }
  if (k >= (1 << (n - 1))) {  // second
    return !solve(S, k - (1 << (n - 1)), n - 1, d);
  } else {  // first
    return solve(S, k, n - 1, d);
  }
}

vector<bool> bruteforce(vector<bool> S, int n) {
  if (n <= 0) return S;

  vector<bool> S1;
  S1.reserve(S.size() * 2);

  for (int i = 0; i < S.size(); ++i) {
    if (S[i]) {
      S1.push_back(true);
      S1.push_back(false);
    } else {
      S1.push_back(false);
      S1.push_back(true);
    }
  }
  return bruteforce(S1, n - 1);
}

int main() {
  int k = 20;
  int n = 10;
  vector<bool> S = {1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1,
                    1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1,
                    1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1};
  vector<bool> ans = bruteforce(S, n);
  cout << "referece:";
  for (auto a : ans) {
    cout << a;
  }
  cout << endl;
  cout << "answer:  ";
  for (int i = 0; i < S.size() * (1 << n); ++i) {
    k = i;
    long d = k / (1 << n);
    long kk = k % (1 << n);
    const auto ansi = solve(S, kk, n, d);
    if (ansi != ans[i]) cout << "error at position" << i << endl;
    cout << ansi << "";
  }
  cout << endl;
  return 0;
}

