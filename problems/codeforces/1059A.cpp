#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;


int main() {
  int n,L,a,ans=0, start=0;
  cin >> n>>L>>a;
  
  for (int i = 0; i < n; ++i)
  {
    int t,l;
    cin>>t>>l;
    ans+=(t-start)/a;
    start=t+l;    
  }
  ans+=(L-start)/a;
  cout<<ans<<endl;

  return 0;
}
