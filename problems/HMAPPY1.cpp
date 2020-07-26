#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

using namespace std;
using l = long;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;

unsigned N, K, Q;
vector<int> A;
vector<int> ans;
bool all0, all1;

struct Seq {
  int idx, len, up;
  Seq() : idx(-1), len(-1), up(-1){};
  Seq(const int i, const int s, const int u) : idx(i), len(s), up(u){};
};

auto cmp = [](const Seq& s1, const Seq& s2) {
  if (s1.len > s2.len) return true;
  if (s1.len == s2.len) return s1.idx < s2.idx;
  return false;
};
auto cmp_idx = [](const Seq& s1, const Seq& s2) {
  if (s1.idx < s2.idx) return true;
  if (s1.idx == s2.idx) return s1.up > s2.up;
  return false;
};

set<Seq, decltype(cmp)> L(cmp);
set<Seq, decltype(cmp_idx)> I(cmp_idx);

void initialize_seqs() {
  int c = 0;
  for (unsigned i = 0; i < A.size(); ++i) {
    if (A[i] == 1)
      c++;
    else {
      if (c != 0) {
        Seq s(i - c, c, 0);
        I.insert(s);
        L.insert(s);
      }
      c = 0;
    }
  }
  if (c != 0) {
    Seq s(A.size() - c, c, 0);
    I.insert(s);
    L.insert(s);
  }
}

void handle_single_case(const int i) {
  Seq last = *(--I.end());

  if (last.idx + last.len + (i - last.up) > N) {
    I.erase(--I.end());
    L.erase(last);

    Seq new_seq(0, 1, i);
    I.insert(new_seq);
    L.insert(new_seq);

    if (last.len > 1) {
      Seq new_last(last.idx + (i - last.up), last.len - 1, i);
      I.insert(new_last);
      L.insert(new_last);
    }
  }
}

void handle_double_case(const int i) {
  Seq last = *(--I.end());
  Seq first = *(I.begin());

  if (last.idx + last.len + (i - last.up) > N) {
    // last overflow
    I.erase(--I.end());
    L.erase(last);
    if (last.len > 1) {
      Seq new_last(last.idx + (i - last.up), last.len - 1, i);
      I.insert(new_last);
      L.insert(new_last);
    }

    if (first.idx + (i - first.up - 1) == 0) {
      // first at position zero
      I.erase(*(I.begin()));
      L.erase(first);
      Seq new_first(0, first.len + 1, i);
      I.insert(new_first);
      L.insert(new_first);

    } else {
      // first not at position zero
      Seq new_first(0, 1, i);
      I.insert(new_first);
      L.insert(new_first);
    }
  }
}

void compute_ans() {
 /* const bool all1 =
      !any_of(A.begin(), A.end(), [](const auto el) { return el == 0; });
  const bool all0 =
      !any_of(A.begin(), A.end(), [](const auto el) { return el == 1; });*/
  if (all0) 
    return;
  
  if (all1) {
    fill(ans.begin(), ans.end(), K);
    return;
  }

  // there is at least one zero.
  for (unsigned int i = 1; i <= N; ++i) {
    if (I.size() == 1) {
      handle_single_case(i);
    } else {
      handle_double_case(i);
    }
    // first element smaller or equal to K
    auto ansit = L.begin();
    ans[i % N] = min(K, (unsigned)ansit->len);

  }
}

int main() {
  cin >> N >> Q >> K;
  ans.resize(N, 0);

  for (unsigned i = 0; i < N; ++i) {
    int a;
    cin >> a;
    A.push_back(a);
    if(a==0)
      all1=false;
    if(a==1)
      all0=false;
  }

  initialize_seqs();
  compute_ans();


  int op = 0;
  for (unsigned i = 0; i < Q; ++i) {
    char c;
    cin >> c;
    if (c == '!')
      op++;
    else
      cout << ans[op % N] << endl;
  }

  return 0;
}