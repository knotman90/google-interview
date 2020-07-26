#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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


void solve() {
  int n; cin>>n;
  vector<int> V;
  while(n--){
    int a; cin>>a;
    V.push_back(a);
  }
  
  sort(begin(V), end(V));

  int ans = -1;
  for (int i = 1; ans==-1 && i <= V.size(); ++i)
    if(V[i-1]!=i )
      ans = i;
  if(ans==-1)
    ans = V.back()+1;

  cout<<ans<<endl;
}