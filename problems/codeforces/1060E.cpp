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


using Children = vector<int>;
using Node = pair<Children,int>;

void count_children( Node& node )
{
  if(node.first.size() <= 0)
    return;
 
  for(auto child : node.first)
    node.second+=1+count_children(child);
  

}

int main() {
   int n; cin>>n;
   int q; cin>>q;
   vector<Node>S(n+5);

   for(int i = 2 ; i <= n ; i++)
   {
    int a; cin>>a;
    S[a].first.push_back(i);
   }

   count_children(S[1]);

  return 0;
}


