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
  
  int m = numeric_limits<int>::max(),M=numeric_limits<int>::min();
  for (int i = 0; i < n; ++i)
  {
    int a; cin>>a;
    m = min (m,a);
    M = max (M,a);
  }
  
  int tot = M-m+1;

  cout<<tot-n<<endl;
  return 0;
}