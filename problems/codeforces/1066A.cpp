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
int t; cin>>t;
while(t--)
{
  int L,v,l,r; 
  cin>>L>>v>>l>>r;
  const int tot = L/v;
  const int l1 = v*((l+v-1)/v);
  int train = 0;
  if( (l1 <= r) )
    train = 1+(r-l1)/v;
  int ans = max(0,tot-train);
  cout<<ans<<endl;
}

  return 0;
}