#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
using namespace std;

using pii = pair<int, int>;
using vpii = vector<pii>;

struct day {
  int m, M, h;
};

int main() {
  int k, d;
  cin >> k >> d;

  vector<day> D;
  int missing = 0;
  for (int i = 0; i < k; i++) {
    day day;
    cin >> day.m >> day.M;
    day.h = 0;
    if (d > 0) {
      day.h = min(d, day.M);
      d -= day.h;
    }
    if (day.h < day.m) missing += day.m - day.h;

    D.push_back(day);
  }

  for (int i = 0; i < k; i++) {
    if (missing > 0 && D[i].h > D[i].m) {
      const int remove = min(D[i].h - D[i].m, missing);
      missing -= remove;
      D[i].h -= remove;
    }
  }

    //int sum = 0;
  if (d == 0 && missing == 0) {
    cout << "YES" << endl;
    for (int i = 0; i < k; i++) {
      day day = D[i];
      cout << max(day.h, day.m) << " ";
     // sum+=max(day.h, day.m);
    }
  } else {
    cout << "NO";
  }
  cout << endl;
  return 0;
}