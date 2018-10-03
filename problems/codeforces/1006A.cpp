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
int main() {
  unsigned n;
  cin >> n;

  while (n--) {
    unsigned a;
    cin >> a;
    if (!(a & 1)) a--;
    cout << a << " ";
  }
  cout << endl;

  return 0;
}