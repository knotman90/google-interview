

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
using ll  = long long;
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
vector<ll> primes;

void reset() { primes.clear(); }
//------------------------

void getPrimesSieve(vector<long long>& primes, const ll n) {
  vector<bool> nums(n + 1, true);
  primes.push_back(2);
  for (ll i = 3; i * i < n + 1; i += 2) {
    if (nums[i]) {
      for (ll j = i * i; j < n + 1; j += 2 * i) {
        nums[j] = false;
      }
    }
  }

  for (ll i = 3; i <= n; i += 2)
    if (nums[i]) primes.push_back(i);
}

pair<int, int> factorize_two(ll p) {
  pii ans;
  for (unsigned i = 0; i < primes.size(); i++) {
    if (p % primes[i] == 0) {
      ans.first = primes[i];
      ans.second = p / primes[i];
      p /= primes[i];
      break;
    }
  }
  return ans;
}

void solve_case(ostringstream& cout) {
  
  int N, L;
  cin >> N >> L;
  vector<ll> nums;
  vector<ll> ans;
  ans.resize(L+1);
  nums.reserve(L);

  constexpr unsigned NPRIMES = 10000+500;
  if(primes.size() <=0)
    getPrimesSieve(primes, NPRIMES);

  for (int i = 0; i < L; ++i) {
    ll a;
    cin >> a;
    nums.push_back(a);
  }

  int i = 0;
  for (i = 0; i < nums.size() - 1; ++i)
  {
    if (nums[i] != nums[i + 1]) 
    {
      pii fi  = factorize_two(nums[i]);
      pii fi1 = factorize_two(nums[i+1]);
      if(fi.first == fi1.first || fi.first == fi1.second){
        ans[i]   = fi.second;
        ans[i+1] = fi.first;
        if(fi.first==fi1.first)
          ans[i+2] = fi1.second;
        else
          ans[i+2] = fi1.first;
      }else{
        ans[i]     = fi.first;
        ans[i+1]   = fi.second;
        if(fi.second==fi1.first)
          ans[i+2] = fi1.second;
        else
          ans[i+2] = fi1.first;        
      }
      break;
    }
  }

  set<int> O;
  //forward
  for(int ii = i+2; ii < nums.size(); ++ii)
  {
    ans[ii+1] = nums[ii]/ans[ii]; 
  }
  //backwards
  for(int ii = i; ii > 0 ; --ii)
  {
    ans[ii-1] = nums[ii]/ans[ii]; 
  }
  for(const auto c : ans)
  {
    O.insert(c);
  }
   for(const auto c : ans){
    auto d = distance(O.begin(),O.find(c));
    const char cc = (char)((int)'A'+d);
    cout<<cc;
  }


}