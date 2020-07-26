#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using l = long;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;

vector<int> int_p1, int_p2;
unordered_map<int, int> M;
vector<int> s1, s2;
vector<int> pre1, pre2;
vector<int>DP;

void calculate_pre(){
  int sum = 0;
  int k = 0;
  for(int i = 0 ; i < s1.size() ; i++)
  {
    sum+=s1[i];
    if(k < int_p1.size() && int_p1[k]==i){
      pre1.push_back(sum);
      sum=0;
      k++;
    }
  }
  //if(sum > 0)
  pre1.push_back(sum);

  sum = 0;
  k = 0;
  for(int i = 0 ; i < s2.size() ; i++)
  {
    sum+=s2[i];
    if(k < int_p2.size() && int_p2[k]==i){
      pre2.push_back(sum);
      sum=0;
      k++;
    }
  }
  //if(sum > 0)
  pre2.push_back(sum);
}

void solve()
{
  calculate_pre();
  for(int i = int_p1.size() ; i >=0 ; i--)
  {
    const int l1 = pre1[i] + ((i+1) < DP.size() ? DP[i+1] : 0);
    const int l2 = pre2[i] + ((i+1) < DP.size() ? DP[i+1] : 0);
    DP[i] = max(l1,l2);
  }
  cout<<DP[0]<<endl;
}

int main() {
  int n;
  cin >> n;
  while (n > 0) {
    int_p1.clear();
    int_p2.clear();
    M.clear();
    s1.clear();
    s2.clear();
    pre1.clear();
    pre2.clear();
    DP.clear();


    s1.reserve(n);
    int i = 0;
    while (n--) {
      int a;
      cin >> a;
      s1.push_back(a);
      M[a] = i++;
    }

    cin >> n;
    s2.reserve(n);
    i = 0;
    while (n--) {
      int a;
      cin >> a;
      s2.push_back(a);
      if(M.find(a)!=M.end()){
        int_p1.push_back(M[a]);
        int_p2.push_back(i);
      }
      i++;
    }

    DP.resize(int_p1.size()+1 , 0);
    solve();

    cin >> n;
  }

  return 0;
}