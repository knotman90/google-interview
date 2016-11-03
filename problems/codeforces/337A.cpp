#include <iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

#define MAX (50)
int main(){
    int n,m; cin>>n>>m;
    int ns[MAX];
    for(int i=0;i<m;i++)
        cin>>ns[i];
    std::sort(ns,ns+m);
    int s=0;
    int e=s+n-1;
    int D= INT_MAX;
    while(e < m)
        D = min(D,abs(ns[s++]-ns[e++]));

    cout<<D<<endl;
}
