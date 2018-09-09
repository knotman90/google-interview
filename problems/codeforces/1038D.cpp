#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
using namespace std;

using vi = vector<int>;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    long a;
    cin >> a;
    cout << a << endl;
    return 0;
  }

  bool neg = false, pos = false;
  long long sum = 0;
  long long smallest = numeric_limits<long long>::max();

  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    smallest = min(smallest, abs(a));
  
    sum += abs(a);  
    pos|= a > 0;
    neg|= a < 0;
  }

  if (!neg || !pos) sum = sum - smallest * 2;

    cout << sum << endl;

  return 0;
}