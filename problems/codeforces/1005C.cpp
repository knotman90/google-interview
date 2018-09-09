#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

using Map = unordered_map<long, vector<long>>;

int main() {
  Map m;
  long n;
  cin >> n;
  long ans = 0;
  vector<long> numbers;
  for (long i = 0; i < n; i++) {
    long a;
    cin >> a;
    numbers.push_back(a);
    m[a].push_back(i);
  }

  for (long i = 0; i < n; i++) {
    bool found = false;
    long p = 1;

    while (p <= 1000000001 && !found) {
      p *= 2;
      if (numbers[i] >= p) continue;

      auto v = m.find(p - numbers[i]);
      if (v != end(m))
        for (auto idx : v->second) {
          if (idx != i) {
            found = true;

            break;
          }
        }
    }
    if (!found) ans++;
  }
  cout << ans << endl;
  return 0;
}