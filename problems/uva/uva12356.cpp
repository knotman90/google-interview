#include <cstdio>
#include<vector>
#include<iostream>
using namespace std;

typedef pair<int, int> pii;

int main() {

  int S,B;
  while((scanf("%d %d\n", &S,&B) == 2) && (S&&B)){
    vector<pii> limits(S);
    for(int i=1;i<S-1;i++)
      limits[i] = make_pair(i-1,i+1);
    limits[0] = make_pair(-1,1);
    limits[S-1] = make_pair(S-2,-1);
    int l,r;
    while(B--){
     scanf("%d %d\n", &l,&r);
     l--;r--;
     if(limits[r].second>=0)
       limits[limits[r].second].first =limits[l].first;
      if(limi[l].first == -1) cout<<"* ";
      else cout<<limits[l].first+1<<" ";

      if(limits[l].first >= 0)
        limits[limits[l].first].second = limits[r].second;
      if(limits[r].second == -1) cout<<"*"<<endl;
      else cout<<limits[r].second+1<<endl;



    }
    cout<<"-"<<endl;

  }
	return 0;
}
