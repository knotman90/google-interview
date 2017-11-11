#include<math.h>
#include<iostream>

using namespace std;

int main(){
  int T; cin>>T;

  while(T--){
    int n; cin>>n;
    int sm,sj;
    sm=sj=0;
    while(n--){
      int s; cin>>s;

      sm+=(double)s/30.0 + 1;
      sj+=(double)s/60.0 +1;
    }
    sm*=10;
    sj*=15;
    if(sm <= sj)
        cout<<"Mile ";
    if(sm >= sj)
      cout<<"Juice ";

      cout<<min(sm,sj)<<endl;

  }

  return 0;
}
