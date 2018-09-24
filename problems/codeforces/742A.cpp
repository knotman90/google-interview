#include <iostream>
#include <limits>
#include <array>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
  
  int n; cin>>n;

  const array<int,5> D = {8,4,2,6};
  if(n==0)
    cout<<1<<endl;
  else
  cout<< D[(n-1)%4]<<endl;

  return 0;
}