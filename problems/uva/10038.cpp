#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

using dyn_bitset = vector<bool>;

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    dyn_bitset bset(n+1, false);
    
    int a, b;
    cin >> a;
    while (--n) {
      cin >> b;
      bset[abs(a - b)] = true;
      
      a = b;
    }
    auto ans = all_of(begin(bset)+1, end(bset)-1, [](const bool e) { return e; });

    if (ans)
      cout << "Jolly";
    else
      cout << "Not jolly";
    cout << endl;
  }

  return 0;
}