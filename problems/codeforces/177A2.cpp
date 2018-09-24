#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  long ans = 0;
  long middle = 0;
  const int n2 = n / 2;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      long a; cin >> a;
      if(i==j && i==n2)
        middle = a;
      if (i == j || i == n2 || j == n2 || (i + j == n - 1))
       {
        ans += a;
      }
    }
    cout<<ans<<endl;
  return 0;
}