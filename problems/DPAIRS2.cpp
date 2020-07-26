#include <bits/stdc++.h>
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

const string NOT = " not ";
const string FANCY = "Real Fancy";
const string NOTFANCY = "regularly fancy";

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pii> N(n);
  for (int i = 0; i < n; i++) {
    cin >> N[i].first;
    N[i].second = i;
  }

  vector<pii> M(m);
  for (int i = 0; i < m; i++) {
    cin >> M[i].first;
    M[i].second = i;
  }

  auto cmp =
      [](const auto a, const auto b) {
        return (a.first < b.first) ||
               (a.first == b.first && a.second < b.second);
      };

  sort(begin(N), end(N), cmp);
  sort(begin(M), end(M), cmp);


  const int bestn = N[N.size() - 1].second;
  const int bestm = M[M.size() - 1].second;
  bool sw = false;
  if( (N[bestn].first < 0) && (M[bestm].first >= 0)){
    swap(N,M);
    sw = true;
}

  for (int i = 0; i < M.size(); i++) 
    if(!sw)
        cout << bestn << " " << M[i].second << endl;//" "<< N[bestn].first+ M[M[i].second].first<<endl;
    else
        cout << M[i].second << " " << bestn << endl;// " "<< N[bestn].first+ M[M[i].second].first<<endl;
  
  for (int i = 0; i < N.size(); i++) 
    if (N[i].second != bestn){
       if(!sw) 
         cout << N[i].second << " "<< M[0].second << endl;//" "<< N[N[i].second].first + M[M[0].second].first<<endl;
       else
         cout <<M[0].second  << " "<< N[i].second << endl;// " "<< N[N[i].second].first + M[M[0].second].first<<endl;
    }

 /* cerr << "------------------" << endl;
  for (int i = 0; i < M.size(); i++) 
    cerr << N[bestn].first + M[i].first << endl;
  for (int i = 0; i < N.size()-1; i++)
    if (N[i].second != bestn) {
    
          cerr << M[0].first + N[i].first << endl;
    }*/
}