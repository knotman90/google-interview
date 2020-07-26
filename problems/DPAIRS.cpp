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

void printVector(ostream& stream, vector<pii>& vec) {
  for (const auto a : vec) {
    cout << a.first << " ";
  }
  cout << endl;
}

const string NOT = " not ";
const string FANCY = "Real Fancy";
const string NOTFANCY = "regularly fancy";

void solve() {
  int T = 1000;
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> uniform_dist(1, 100000);

  vector<int> pool(100000*2+1);
  iota(begin(pool), end(pool), -pool.size() / 2);

  for (int test = 0; test < T; test++) {
    random_shuffle(begin(pool), end(pool));
    int n, m;
    n = uniform_dist(mt);
    m = uniform_dist(mt);
    vector<pii> N(n);
    vector<pii> M(m);
    vector<int> N_original(n);
    vector<int> M_original(m);

    vector<pii> ans;

    unsigned added = 0;
    for (int i = 0; i < n; i++) {
      if (added >= pool.size()) {
        cerr << "ERROR" << endl;
        return;
      }
      N[i].first = -pool[added++];
      N[i].second = i;
      N_original[i] = N[i].first;
    }

    for (int i = 0; i < m; i++) {
      if (added >= pool.size()) {
        cerr << "ERROR" << endl;
        return;
      }
      M[i].first = pool[added++];
      M[i].second = i;
      M_original[i] = M[i].first;
    }

    cout << "TEST "<<test << endl;
    cout << n << " " << m << endl;
    /*printVector(cout, N);
    printVector(cout, M);
    cout << endl;*/

    /*cin >> n >> m;
     for (int i = 0; i < n; i++) {
       cin >> N[i].first;
       N[i].second = i;
       N_original[i] = N[i].first;
     }

     for (int i = 0; i < m; i++) {
       cin >> M[i].first;
       M[i].second = i;
       M_original[i] = M[i].first;
     }
   */

    auto cmp = [](const auto a, const auto b) {
      return (a.first < b.first) || (a.first == b.first && a.second < b.second);
    };

    sort(begin(N), end(N), cmp);
    sort(begin(M), end(M), cmp);

    const int bestn = N[N.size() - 1].second;
    const int bestm = M[M.size() - 1].second;

    for (unsigned i = 0; i < M.size(); i++) {
      // cout << bestn << " " << M[i].second << endl;
      ans.push_back(make_pair(bestn, M[i].second));
    }

    for (unsigned i = 0; i < N.size(); i++)
      if (N[i].second != bestn) {
        // cout << N[i].second << " " << M[0].second << endl;
        ans.push_back(make_pair(N[i].second, M[0].second));
      }

    unordered_set<int> sums;
    // cerr << "------------------" << endl;
    for (unsigned i = 0; i < ans.size(); i++) {
      const int curr_sum = N_original[ans[i].first] + M_original[ans[i].second];
      // cout << curr_sum << endl;
      if (sums.find(curr_sum) != end(sums)) {
        cerr << "ERROR" << endl;
        // cerr << "NEW PAIR" << endl;
        printVector(cerr, N);
        printVector(cerr, M);
        return;
      } else {
        sums.insert(curr_sum);
      }
    }

    /*for (int i = 0; i < M.size(); i++)
      cerr << N_original[bestn] + M_original[M[i].second] << endl;
    for (int i = 0; i < N.size() - 1; i++)
      if (N[i].second != bestn)
        cerr << M_original[M[0].second] + N_original[N[i].second] << endl;*/
  }  // while T
}