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

int main() { MEASURE_TIME(solve()); }

//---------PROBLEM CODE ------------------


void solve() {
  int n; cin>>n;
  int e,o; e=o=0;
  int i = 1;
  int ee,oo, ans;
  while(n--){
    int a; cin>>a;
    if(!(a&1)){
      ++e;
      ee=i;
    }
    else{
      ++o;
      oo=i;
    }
    
    if((e > 1 || o > 1) && (e==1 || o ==1)){
      if(e==1)
        ans = ee;
      else
        ans = oo;
      break;
    }
    i++;
  }
  cout<<ans<<endl;

}