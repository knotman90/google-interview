#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;
using l = long;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;

vector<ll> S;
int N, C;

// distance is at min distance at which two cows can be placed
long long cows_for_distance(const long long distance) {
  int ans = 1;
  int curr_dist = 0;
  for (int i = 1; i < N; i++) {
    const long long dist = (S[i] - S[i - 1]);
    if (curr_dist + dist >= distance) {
      curr_dist = 0;
      ans++;
    } else
      curr_dist += dist;
  }
  return ans;
}

long long min_dist() {
  long long ans = numeric_limits<long long>::max();
  for (int i = 1; i < N; i++) 
    ans = min(ans, (S[i] - S[i - 1]));
  return ans;
}

long long solve() { 
  int lo = min_dist();
  int hi = S.back() - S.front(); 
  while(lo < hi){
    const auto mid = lo + ceil((hi -lo)/2.0);
    const auto cows = cows_for_distance(mid);
    if(cows >= C)
      lo = mid;
    else
      hi = mid - 1;
  }
  return lo;

}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> N >> C;
    S.clear();
    for (int i = 0; i < N; i++) {
      int a;
      cin >> a;
      S.push_back(a);
    }
    sort(begin(S), end(S));
    cout << solve() << endl;
  }
  return 0;
}