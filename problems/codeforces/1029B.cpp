#include <iostream>
#include <limits>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
  int n; cin>>n;

  vector<int> nums;
  nums.reserve(n);

  while(n--){
    int a; cin>>a;
    nums.push_back(a);
  }

  vector<int>::difference_type best = 0;

  for(auto it = begin(nums); it != end(nums); ++it ){
    const auto right = lower_bound(it , end(nums) , *it*2);
    if(right == end(nums)){
      best += distance(it, right);
      break;
    }
    if(*right > *it*2)
      right--;
    const auto d = distance(it,right);
    if( d > 0)
    {
      best += d;
      
    }
    
  }
  cout<<best<<endl;
  return 0;
}