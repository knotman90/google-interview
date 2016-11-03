#include <iostream>
#include<limits.h>
using namespace std;

int main(){
    int n,d;
    int c=0;
    int m=INT_MIN;
    cin>>n>>d;
    while(d--)
    {
        bool beat=false;
        for(int i=0;i<n;i++){
            char a; cin>>a;
            if(a=='0')
                beat=true;
        }
        c = beat ? c+1 : 0;
        m = max(m,c);
    }
    cout<<m<<endl;
}
