#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  array<int, 26> a;
  fill(begin(a), end(a), 0);

  int n, k;
  cin >> n >> k;
  string s; cin>>s;
  
  for (const auto c : s) 
    a[c - 'A']++;
  
  auto m = *min_element(begin(a) , begin(a)+k );
  int count = accumulate(begin(a)+k, end(a), 0);

  cout << m*k + count << endl;

  return 0;
}