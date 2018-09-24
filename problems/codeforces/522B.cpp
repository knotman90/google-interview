#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <utility>
#include <vector>

using namespace std;

int main() {
 
  int n; cin>>n;
  vector<int> W,H;
  long sumW, sumH;
  sumH = sumW = 0;
  long maxH = -1, maxH1 = -1;
  for (int i = 0; i < n; ++i)
  {
    int a,b;
    cin>>a>>b;
    sumW+=a;
    sumH+=b;
    if( b > maxH ){
      swap(maxH,maxH1);
      maxH = b;
    }
    else if(b > maxH1)
      maxH1 = b;

    W.push_back(a);
    H.push_back(b);
  }

  for (int i = 0; i < n; ++i)
  {
    const int ww = sumW - W[i];
    const int hh = H[i] == maxH ? maxH1 : maxH;
    cout<<ww*hh<< " ";
  }
  cout<<endl;

  return 0;
}