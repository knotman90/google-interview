#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int switch_ON = 1;
constexpr int switch_OFF = -1;

template <int SWITCH_ON_OFF>
void heater(vector<unsigned>& C, int idx, int radius) {
  C[idx] += SWITCH_ON_OFF;
  for (int i = 1; i <= radius; i++) {
    const int idxl = idx - i;
    const int idxr = idx + i;
    if (idxl >= 0) C[idxl] += SWITCH_ON_OFF;

    if (idxr <= C.size() - 1) C[idxr] += SWITCH_ON_OFF;
  }
}

bool is_useless(vector<unsigned>& C, int idx, int radius) {
  for (int i = 0; i <= radius; i++) {
    const int idxl = idx - i;
    const int idxr = idx + i;
    if ((idxl >= 0 && C[idxl] == 1) || (idxr <= C.size() - 1 && C[idxr] == 1))
      return false;
  }
  return true;
}

int main() {
  int n, r, ans = 0;
  cin >> n >> r;
  r--;
  vector<unsigned> C(n, 0);
  vector<unsigned> H(n, 0);
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;

    if (h) {
      ans++;
      heater<switch_ON>(C, i, r);
      H[i] = h;
    }
  }

  for (int i = 0; i < n; i++) {
    if (C[i] == 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  for (int i = 0; i < n; i++) {
    if (H[i] == 1 && is_useless(C, i, r)) {
      ans--;
      heater<switch_OFF>(C, i, r);
    }
  }
  cout << ans << endl;
  return 0;
}