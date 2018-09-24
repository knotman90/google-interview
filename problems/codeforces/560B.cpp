#include <iostream>
#include <limits>
#include <array>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>

using namespace std;

using  Rec = std::pair<int,int> ;

bool fit(Rec b, Rec p1, Rec p2)
{
	if(b.first  >= p1.first + p2.first)
		if(b.second >= max(p1.second, p2.second))
			return true;

	if(b.first >= max(p1.first, p2.first))
		if(b.second >= p1.second + p2.second)
			return true;
		return false;
}

int main() {
  
  Rec b, p1 ,p2;
  cin>>b.first>>b.second;
  cin>>p1.first>>p1.second;
  cin>>p2.first>>p2.second;

  bool ans = false;
  //0 0
  ans |= fit(b,p1,p2);

  //1 0
  swap(p1.first,p1.second);
  ans |= fit(b,p1,p2);
  
  swap(p1.first,p1.second);
  swap(p2.first,p2.second);
  //0 1
  ans |= fit(b,p1,p2);
  //1 1
  swap(p1.first,p1.second);
  ans |= fit(b,p1,p2);

  if(ans)
  	cout<<"YES";
  else
  	cout<<"NO";
  cout<<endl;


  return 0;
}