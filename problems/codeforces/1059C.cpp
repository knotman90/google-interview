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

void solve(int n, const int multiplier) {
  if (n == 0) return;
  if (n == 1)
    cout << multiplier << " ";
  else if (n == 2)
    cout << multiplier << " " << multiplier * 2<<" ";
  else if (n == 3)
     cout << multiplier << " " << multiplier << " " << multiplier * 3<<" ";
  else{
    for (int i = 0; i < n - n / 2; i++) cout << 1 * multiplier << " ";
    solve(n / 2, multiplier * 2);
  }

}
int main() {
  int n;
  cin >> n;
  solve(n, 1);
  cout << endl;

  return 0;
}
