#include <chrono>
#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <array>
#include "segment_tree.h"

using namespace std;
using namespace ctci;

int sum(const int l, const int r) { return l + r; }

int main() {
  int n=12;

  std::vector<int> arr = {10,10,10,10,10,1,1,1,1,4,1,1,1};
  auto mel = *max_element(begin(arr), end(arr));
 
  std::vector<int> arr1 (mel, 0);
  SegmentTree<vector<int>> tree(arr1, sum);


  for (int i = 0; i < arr.size(); i++) {
    tree.update(arr[i]-1 , arr1[arr[i]-1]+1);
    cout<<tree.query(0, i)<<" "<<endl;
  }

  
}