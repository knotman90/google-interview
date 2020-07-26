#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

using Type = unsigned short;
using ll = long long;
using Node = pair<Type, vector<vector<Type>>>;
constexpr unsigned LIM = 200;
static vector<Node> DP;
/*
void printDP(const int lim)
{
  cout<<endl<<endl<<"-----DP-----"<<endl<<endl;
  for (int i = 0; i < lim; ++i)
  {
    cout<<"Power  "<< i <<" = "<<DP[i].first<<endl;
    for (int j = 0; j < DP[i].second.size(); ++j)
    {
      cout<<"\t[ ";
      for(const auto a : DP[i].second[j] ){
        cout<<a<<", ";
      }
      cout<<"]"<<endl;
    }
  }
}*/


Node m(const unsigned power) {
  if (power <= 1) return make_pair(0, vector<vector<Type>>());
  if (DP[power].second.size() > 0) return DP[power];
cout<<power<<" ";
  Type ans = numeric_limits<Type>::max();
  vector<vector<Type>> ans_factors;
  
  for (unsigned i = power/2; i >=1 ; i--) {
    for (unsigned j = 0; j < DP[power - i].second.size(); j++) {
      const auto& factors1 = DP[power - i].second[j];
      for (unsigned k = 0; k < DP[i].second.size(); k++) {
        const auto& factors2 = DP[i].second[k];

        vector<Type> factors(factors1);
        factors.insert(end(factors), begin(factors2), end(factors2));
        factors.push_back(power);

        sort(begin(factors), end(factors));
        auto it = unique(begin(factors), end(factors));
        auto new_size = std::distance(begin(factors), it);
        if (new_size <= ans) {
          if (new_size < ans) {
            ans_factors.clear();
            ans = new_size;
          }
          ans_factors.push_back(vector<Type>(begin(factors), it));
        }
      }
    }
  }
  DP[power] = make_pair(ans_factors[0].size()-1, ans_factors);
  return DP[power];
}

void solve122() {
  DP.resize(LIM + 1);
  DP[0] = make_pair(0, vector<vector<Type>>{});
  DP[1] = make_pair(0, vector<vector<Type>>{{1}});
  DP[2] = make_pair(1, vector<vector<Type>>{{1, 2}});
  DP[3] = make_pair(2, vector<vector<Type>>{{1, 2, 3}});
  DP[4] = make_pair(2, vector<vector<Type>>{{1, 2, 4}});
   long long ans = 0;
  for (unsigned i = 1; i <= LIM; ++i) {
    ans += m(i).first;
    cout<<ans<<endl;
  }
  cout << ans << endl;
}

int main() { solve122(); }