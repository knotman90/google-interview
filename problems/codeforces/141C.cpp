#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> P;
vector<string> names;
vector<int> H;
int n;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    names.push_back(s);
    int a;
    cin >> a;
    P.push_back(make_pair(a, i));
  }
  H.resize(n,0);
  sort(begin(P), end(P), [](const auto p1, const auto p2) {
    if (p1.first < p2.first) return true;
    if (p1.first == p2.first && p1.second < p2.second) return true;
    return false;
  });

  
  for (int i = 0; i < n; ++i) 
  {
   
    if(P[i].first > i){
      cout<<-1<<endl;
      return 0;
    }
    H[i] = H[i-P[i].first]+n;
  }
  
  for (int i = 0; i < n; ++i) 
  {
    cout<<names[P[i].second]<< " "<<H[i]<<endl;
  }
  return 0;
}
