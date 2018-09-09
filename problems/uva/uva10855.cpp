#include <iostream>
#include <vector>

using namespace std;

using Mat = vector<vector<char>>;

Mat rotate(const Mat& mat) {
  const int n = mat.size();
  Mat out(n, vector<char>(n));

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) out[j][n - 1 - i] = mat[i][j];
  return out;
}

int count(const Mat& big, const Mat& small) {
  const int N = big.size();
  const int n = small.size();
  int ans = 0;
  for (int i = 0; i <= N-n; i++) {
    for (int j = 0; j <= N-n; ++j) {
      bool good = true;
      for (int l = 0; good && l < n; ++l) {
        for (int k = 0; good && k < n; ++k) {
          if(big[i+l][j+k] != small[l][k])
          	good = false;
        }
      }
      if(good)
      	ans++;
    }
  }
  return ans;
}

int main() {
  int N, n;
  cin >> N >> n;
  while (N && n) {
    Mat big(N, vector<char>(N));
    Mat small(n, vector<char>(n));

    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) cin >> big[i][j];

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) cin >> small[i][j];

    Mat m90 = rotate(small);
    Mat m180 = rotate(m90);
    Mat m270 = rotate(m180);

    cout<<count(big,small)<<" ";
    cout<<count(big,m90)<<" ";
    cout<<count(big,m180)<<" ";
    cout<<count(big,m270)<<endl;
    cin >> N >> n;
  }
  return 0;
}