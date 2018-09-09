#include <iostream>

using namespace std;

int main() {
  int n = 0, m = 0, ans = 0;
  cin >> n >> m;

  for (int i = 0, p = m, ai = 0, ans = 0; i < n; i++) {
    cin >> ai;

    if (ai >= p) {
      const int diff = ai - p;
      ans = 1 + (diff) / m;
      p = m - diff % m;
    } else 
      p -= ai;
    
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}