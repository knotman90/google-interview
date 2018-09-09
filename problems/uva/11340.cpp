#include <algorithm>
#include <cstdio>
#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int n; cin>>n;
  array<int, 256> C;
  
  while (n--) {
    int K; cin>>K;
    double ans = 0;
    fill(begin(C), end(C), 0);
        
    while (K--) {
      char c;
      int p;
      cin >> c;
      cin >> p;
      C[c] = p;
    }
    int M; cin >> M;

    while (M--) {
    string line;
      do {
        getline(cin, line);
      } while (line.length() <= 0);

      for(const auto a : line)
        ans+=C[a];
      
    }

    cout<<std::fixed << std::setprecision(2) <<(ans/100.0)<<"$"<<endl;
  }

  return 0;
}