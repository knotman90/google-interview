#include <iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

#define MAX (500005)
int N[MAX];
bool used[MAX];
int main(){
    int n; cin>>n;
    int m=INT_MIN;
    for(int i=0;i<n;i++){
          cin>>N[i];
          used[i]=false;
          m=max(m,N[i]);
    }
    sort(N,N+n);
    int u =0;
    for(int i=0;i<n ; i++, u++){
        if(m >= 2*N[i])
            used[i]=true;
        else
            break;
    }
int c=0;
int s=0;int e=u;
while(s < u && e < n){
    if(N[e]>= 2*N[s])
    {
        c++;
        s++;
    }
    e++;
}
        
    

    cout<<n-c<<endl;
    return 0;
}
