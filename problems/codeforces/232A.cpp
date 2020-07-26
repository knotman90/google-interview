#include <cmath>
#include <iostream>
#include <limits>

using namespace std;
using ll = long long;

constexpr int D = 100;
int k = 0;

int G[D][D] = {{0}};

int solve() {
  int cycles = 1;
  int last = 3;

  while (k - cycles > 0) {
    int added = 0;
    int ii = -1;
    for (int i = 0; i < last; i++) {
      if (!G[i][last]) {
        for (int j = 0; j < last; ++j) {
          if (j != i && G[i][j] && G[last][j]) added++;
        }
        if (added <= (k - cycles)) {
          ii = i;
          break;
        }
      }
    }
    if (ii != -1 && added <= (k - cycles)) {
      G[ii][last] = G[last][ii] = 1;
      cycles += added;
      ii = -1;
    } else {
      ++last; // add a new node
    }
  }
  return last;
}

int main() {
  cin >> k;

  G[0][1] = G[0][2] = 1;
  G[1][0] = G[2][0] = 1;
  G[2][1] = G[1][2] = 1;
  int last = 2;
  if (k > 1) last = solve();
  cout<<last+1<<endl;
  for (int i = 0; i <= last; i++) {
    for (int j = 0; j <= last; j++) {
      cout << G[i][j];
    }
    cout << endl;
  }
  return 0;
}