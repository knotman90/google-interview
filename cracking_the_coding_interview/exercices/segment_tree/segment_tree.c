#include <chrono>

#include <iostream>

#include <map>

#include <vector>

#include <array>
#include "segment_tree.h"

using namespace std;
using namespace ctci;

 

int sum(const int l, const int r){

    return l+r;

}

int main() {

    std::vector<int> arr= {1,2,3,4,5,6,7,8,9};

   SegmentTree<int> tree(arr, sum);

    cout<<tree.tree[2]<<endl;

   

}