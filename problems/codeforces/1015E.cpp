#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <vector>

// using int = unsigned;

template <class N>
inline N iceil(const N& n, const N& d) {
  return (n + d - 1) / d;
}

using namespace std;

using Mat = vector<vector<bool>>;
using Star = array<int, 3>;

Star max_star(const Mat& mat, Mat& mat1, const int i, const int j) {
  const int n = mat.size();
  const int m = mat[0].size();
  Star ans{i, j, 0};
  int radius = 1;
  while (i + radius < n && i - radius >= 0 && j + radius < m &&
         j - radius >= 0) {
    if (mat[i + radius][j] && mat[i - radius][j] && mat[i][j + radius] &&
        mat[i][j - radius]) {
      mat1[i + radius][j] = false;
      mat1[i - radius][j] = false;
      mat1[i][j + radius] = false;
      mat1[i][j - radius] = false;
      ans[2] = radius++;
    } else
      break;
  }
  return ans;
}

int main() {
  vector<Star> ans;
  int n, m, num_stars = 0;
  cin >> n >> m;
  Mat mat(n, vector<bool>(m));
  Mat mat1(n, vector<bool>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      mat[i][j] = c == '*';
      mat1[i][j] = mat[i][j];
      if (mat[i][j]) ++num_stars;
    }
  }

  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; ++j) {
      if (mat[i][j]) {
        Star star = max_star(mat, mat1, i, j);
        if (star[2] != 0) {
          mat1[i][j] = false;
          ans.push_back(star);
          num_stars -= 4 * star[2] + 1;
        }
      }
    }
  }

  for (auto a : mat1) {
    for (auto b : a) {
      if (b) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << ans.size() << endl;
  for (const auto s : ans) {
    cout << s[0] + 1 << " " << s[1] + 1 << " " << s[2] << endl;
  }

  return 0;
}