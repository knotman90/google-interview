#include <algorithm>
#include <chrono>
#include <cmath>
#include <future>
#include <iostream>
#include <numeric>
#include <set>
#include <sstream>
#include <thread>
#include <vector>

using namespace std;
using namespace std::chrono;
using ull = unsigned long long;
using ul = unsigned long;
using pii = pair<int, int>;

ostringstream solve();
void solve_case(ostringstream&);
void reset();

int main() {
  unsigned T;
  cin >> T;
  for (unsigned test_id = 1; test_id <= T; test_id++) {
    ostringstream ss = solve();
    const string tc_output(ss.str());
    cout << "Case #" << test_id << ": " << tc_output << endl;
  }
}

ostringstream solve() {
  ostringstream ssout;

  reset();
  solve_case(ssout);

  return ssout;
}
//////////////////////////////////////////////////////
//                                                  //
//-------------------PROBLEM CODE-------------------//
//                                                  //
//////////////////////////////////////////////////////

//////////////////////////
//---Global variables---//
//////////////////////////
void reset() {}
//------------------------

void solve_case(ostringstream& cout) {
  string s, ans;
  int N; cin>>N;
  cin >> s;
  ans.resize(s.size());
  for (unsigned i = 0; i < s.size(); i++) 
    ans[i] = (s[i] == 'E') ? 'S' : 'E';

    cout<<ans;
  
}