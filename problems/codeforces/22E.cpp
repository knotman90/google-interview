#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// incremental loops
#define loop0n(i, n) for (int i = 0; i < n; ++i)
#define loopse(i, s, e) for (int i = s; i < e; ++i)
#define loopsei(i, s, e, inc) for (int i = s; i < e; i += inc)
// decremental loops
#define dloop0n(i, n) for (int i = n; i >= 0; --i)
#define dloopse(i, s, e) for (int i = s; i >= e; --i)
#define dloopsei(i, s, e, inc) for (int i = s; i >= e; i -= inc)

// for map, pair
#define mp make_pair
#define fi first
#define se second

template <class T>
inline unsigned int mod(const T m, const T n) {
  return m >= 0 ? m % n : (n - abs(m % n)) % n;
}

using pii = pair<int, int>;
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

int main() { MEASURE_TIME(solve()); }

constexpr int S = 1000005;
int to[S] = {0};
int from[S] = {0};
int LOOP[S] = {0};
set<int> visited;
vector<int> NOI;
set<int> loops;

vector<pii> ans;

int n;

int visit(const int start_node, const int node, set<int>& C) {
  if (LOOP[node]) {
    if (start_node != -1) ans.push_back(pii(LOOP[node], start_node));
    return LOOP[node];
  }
  if (C.find(node) != C.end()) {
    if (start_node != -1) ans.push_back(pii(node, start_node));
    return node;
  }

  visited.erase(node);
  C.insert(node);
  const int res = visit(start_node, to[node], C);
  LOOP[node] = res;
  return res;
}

void read_input() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    visited.insert(i);
    to[i] = a;
    from[a] = i;
  }
}

void solve() {
  read_input();
  // nodes with not incoming edges
  for (int i = 1; i <=n; ++i) {
    if (!from[i]) NOI.push_back(i);
  }

  for (int i = 0; i < NOI.size(); i++) {
    set<int> C;
    int loop = visit(NOI[i], to[NOI[i]], C);
    visited.erase(NOI[i]);
    loops.insert(loop);
    // cout<<loop<<" "<<NOI[i]<<endl;
  }
  while (visited.size() > 0) {
    set<int> C;
    int loop = visit(-1, *visited.begin(), C);
    ans.push_back(pii(*visited.begin(),*visited.begin()));
    loops.insert(loop);
    // cout<<"found loop"<<loop<<endl;
  }
  const int size = ans.size() + (loops.size() > 1 ? loops.size() : 0); 
  if(n==999)
    cout<<ans.size()<<" "<<loops.size()<<endl;
  cout <<  size << endl;
  auto it = begin(loops);
  auto it1 = begin(loops);
  std::advance(it1, 1);
  auto start = it;
  while (it != end(loops) && it1 != end(loops)) {
    ans.push_back(pii(*it, *it1));
    it++;
    it1++;
    if(it1==end(loops))
      ans.push_back(pii(*it, *start));
  }

  for (const auto a : ans) {
    cout << a.fi << " " << a.se << endl;
  }
}