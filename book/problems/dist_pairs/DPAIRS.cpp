#include <bits/stdc++.h>
#include <random>
using namespace std;
using namespace std::chrono;

using pii = pair<int, int>;
using l = long;
using ll = long long;
using ull = unsigned long long;

void solve();

#define MEASURE_TIME(function)                                         \
  high_resolution_clock::time_point t1 = high_resolution_clock::now(); \
  { function; }                                                        \
  high_resolution_clock::time_point t2 = high_resolution_clock::now(); \
  const auto duration = duration_cast<milliseconds>(t2 - t1).count();  \
  cout.flush();                                                        \
  cerr << "--------------" << endl;                                    \
  cerr << "Elapsed Time: " << duration << "ms" << endl;                \
  cerr << "--------------" << endl;

int main() {
  MEASURE_TIME({ solve(); })
  return 0;
}

//------------PROBLEM CODE-------------

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pii> N(n);
  vector<pii> M(m);

  for (int i = 0; i < n; i++) {
    cin >> N[i].first;
    N[i].second = i;
  }

  for (int i = 0; i < m; i++) {
    cin >> M[i].first;
    M[i].second = i;
  }

  auto cmp = [](const auto a, const auto b) { return (a.first < b.first); };

  sort(begin(N), end(N), cmp);
  sort(begin(M), end(M), cmp);

  const int bestn = N[N.size() - 1].second;

  for (unsigned i = 0; i < M.size(); i++)
    cout << bestn << " " << M[i].second << endl;

  for (unsigned i = 0; i < N.size(); i++)
    if (N[i].second != bestn) cout << N[i].second << " " << M[0].second << endl;
}


int funzione2(int n) {
  int ans = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j += i) {
      ans += i;
    }
  }
  return ans;
}


int funzione2(int n) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j += 5) {
      ans += i;
      ans += i;
    }
  }
  return ans;
}


n    = O(sqrt(n)) !sbagliato!
logn = O(sqrt(n))
nlogn = O(sqrt(n))!sbagliato!
n^2 = O(n^3)
n^2 = Omega(n^3)
n^2 = Omega(nlogn)
n^2 = O(n^n)



int funzione2(int n) {
  int ans = 0;
  int cont = 1;
  for (int j = 1; j < n; j += cont) {
    ans += i;
    cont++;
  }
  return ans;
}


int funzione2(int n) {
  int ans = 0;
  for (int i = 1; i < n; i *= 2) {
    for (int j = 1; j < n; j *= 2) {
      ans += i;
      ans += i;
    }
  }
  return ans;
}

/*O(log_n)
Omega()*/
int funzione3(int n) {
  int ans = 0;

  for (int j = 1; j < n; j *= 3) {
    ans += i;
    ans += i;
  }

  return ans;
}

int funzione(int n) {
  if (n == 1200) return 1;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += i;
    ans += i;
  }
  return ans;
}
