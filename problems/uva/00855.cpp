#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

using Point = pair<int, int>;

long calculate(const Point& p, const vector<Point>& friends) {
  long ans = 0;

  ans = accumulate(
      begin(friends), end(friends), ans, [&p](long ans, const Point& a) {
        return ans + abs(a.first - p.first) + abs(a.second - p.second);
      });

  return ans;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int S, A, F;
    cin >> S >> A >> F;

    vector<Point> friends(F);
    for (int i = 0; i < F; ++i) cin >> friends[i].first >> friends[i].second;
    
    int pos = F / 2 - ((int)F % 2 == 0);

    nth_element(begin(friends), begin(friends) + pos, end(friends),
                [](const Point& a, const& Point b) { return a.first < b.first; });
    
    const int ansi = friends[pos].first;

    nth_element(
        begin(friends), begin(friends) + pos, end(friends),
        [](const Point& a, const Point& b) { return a.second < b.second; });
    
    const int ansj = friends[pos].second;

    cout << "(Street: " << ansi << ", Avenue: " << ansj << ")" << endl;
  }

  return 0;
}