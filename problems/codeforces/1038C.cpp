#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

using vi = vector<int>;
int main() {

  int n;
  cin >> n;
  vi A, B;
  A.reserve(n);
  B.reserve(n);

  for (int i = 0; i < 2 * n; i++) {
    int a;
    cin >> a;
    if (i >= n)
      B.push_back(a);
    else
      A.push_back(a);
  }

  sort(begin(A), end(A), std::greater<int>());
  sort(begin(B), end(B), std::greater<int>());
  
  long long pA = 0, pB = 0;
  int posA = 0, posB = 0;
  for (; posA < n || posB < n;) {
    
    if (posB >=n  || (posA < n && A[posA] >= B[posB])) {
      pA += A[posA];
      posA++;
    } else {
      posB++;
    }

    if (posA >=n || (posB < n && A[posA] <= B[posB])) {
      pB += B[posB];
      posB++;
    } else {
      posA++;
    }
  }
  
  cout << pA - pB << endl;
  return 0;
}