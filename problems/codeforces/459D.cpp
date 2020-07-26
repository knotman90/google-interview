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

int n;
vector<int> A;
vector<int> C;
vector<int> l,r;

struct ST {
  vector<int> st;
  const int n;
  ST(const int nn) : n(nn) {
    int s = 1 + (1 << (int)ceil(log2(n))+1);
    st.resize(s);
  }

  void increment(const int idx, const int _increment){
    const int curr_v = st[idx + n];
    update(idx, curr_v + _increment);
  }

  void update(int idx, const int v) {
    st[idx + n] = v;
    int p = (idx + n) >> 1;
    for (; p >= 1; p = p >> 1) {
      const int left = p << 1;
      const int right = left + 1;
      st[p] = st[left] + st[right];
    }
  }

  int query(const int l, const int r) { return query_helper(l, r, 1, n, 1); }

  int query_helper(const int l, const int r, const int s, const int e,
                   const int node) {
    if (s > e) return 0;
    if (l > e || r < s) return 0;
    if (l <= s && r >= e) return st[node];

    const int mid = s + (e - s) / 2;
    const int left = node * 2;
    const int right = left + 1;

    return query_helper(l, r, s, mid, left) +
           query_helper(l, r, mid + 1, e, right);
  }
};

unordered_map<int, int> M;

int c = 1;
int main() {
  cin >> n;
  C.resize(n, 0);
  A.reserve(n);
  l.resize(n, 0);
  r.resize(n, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (M[a] == 0) M[a] = c++;

    A.push_back(M[a]);
  }

  for (int i = 0; i < n; ++i) l[i] = ++C[A[i]];
  fill(begin(C), end(C), 0);
  
  for (int i = A.size()-1; i >= 0; --i) r[i] = ++C[A[i]];

  ST tree(n);
  int ans = 0;
  swap(l,r);
  for(int i = A.size()-1, end = A.size()+1; i >=0 ; i--, end--){
    const int f_left = tree.query(r[i]+1, n);
    ans+=(r[i] > f_left) ? 1 : 0;
    tree.increment(l[i],1);
  }

  return 0;
}