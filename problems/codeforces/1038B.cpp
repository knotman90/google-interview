#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  const long sum = (n * (n + 1)) / 2;

  int sol = -1;
  for (int i = 2; n >= 3 && i <= n; i++) {
    if ((sum - i) % i == 0) {
      sol = i;
      break; 
    }
  }

  if (sol != -1) {
    cout << "Yes" << endl;
    cout << n - 1 << " ";
    for (int i = 1; i <= n; i++)
      if (i != sol) cout << i << " ";
    cout << endl << "1 " << sol << endl;
  } else
    cout << "No" << endl;

  return 0;
}