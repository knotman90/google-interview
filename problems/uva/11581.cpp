#include <algorithm>
#include <array>
#include <iostream>
#include <unordered_map>
using namespace std;

constexpr unsigned size = 3;

using Type = int;
using vec3 = array<Type, size>;
using Mat = array<vec3, size>;

struct mat_hash {
  inline size_t hash_combine(const size_t& s, const size_t& t) const {
    return 31 * s ^ (t << 1);
  }

  size_t operator()(const Mat& mat) const {
    size_t ans{0};
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++) {
        ans = hash_combine(ans, mat[i][j]);
      }
    return ans;
  }
};

struct mat_equality {
  bool operator()(const Mat& m, const Mat& m1) const {
    bool ans = true;
    for (int i = 0; i < ans && size; i++)
      for (int j = 0; j < ans && size; j++)
        if (m[i][j] != m1[i][j]) {
          ans = false;
          break;
        }
    return ans;
  }
};

Mat evolve(const Mat& mat) {
  Mat ans;
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) {
      int res = 0;

      if (i > 0) res += mat[i - 1][j];
      if (i < size - 1) res += mat[i + 1][j];

      if (j > 0) res += mat[i][j - 1];
      if (j < size - 1) res += mat[i][j + 1];

      ans[i][j] = res % 2;
    }
  return ans;
}

//after how many application of f starts the period?
int solve(Mat mat_i) {
  int ans = -1;

  using Map = unordered_map<Mat, int, mat_hash, mat_equality>;
  Map chain;
  chain[mat_i] = ans;

  bool found = false;
  do {
    mat_i = evolve(mat_i);
    bool found = chain.find(mat_i) != chain.end();

    if (!found) {
      ans++;
      chain[mat_i] = ans;
    } else
      return ans;

  } while (!found);

  return ans;
}

int main() {
  int N;
  cin >> N;

  while (N--) {
    Mat mat;
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++) {
        char c;
        cin >> c;
        mat[i][j] = c - '0';
      }

    cout << solve(mat) << endl;
  }
  return 0;
}