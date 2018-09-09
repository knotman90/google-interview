#include <algorithm>
#include <cctype>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

using Type = long long;

pair<Type, Type> solve(const Type n) {
  pair<Type, Type> ans(std::numeric_limits<Type>::min(),
                       std::numeric_limits<Type>::max());
  for (Type i = 1; i <= cbrt(n); i++)
    for (Type j = i; j <= sqrt(n / i); j++)
      if (n % i == 0) {
        Type k = n / (i * j);
        if (i * j * k == n) {
          Type l, r, c;
          l = i;
          c = j;
          r = k;
          Type val = (l + 1) * (c + 2) * (r + 2) - n;
          ans.first = max(ans.first, val);
          ans.second = min(ans.second, val);

          val = (c + 1) * (l + 2) * (r + 2) - n;
          ans.first = max(ans.first, val);
          ans.second = min(ans.second, val);

          val = (r + 1) * (l + 2) * (c + 2) - n;
          ans.first = max(ans.first, val);
          ans.second = min(ans.second, val);
        }
      }

  return ans;
}
int main() {
  int N;
  cin >> N;
  auto ans = solve(N);
  cout << ans.second << " " << ans.first << endl;
  return 0;
}