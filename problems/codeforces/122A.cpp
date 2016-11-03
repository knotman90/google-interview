#include <iostream>

using namespace std;

bool isLucky(int n){
    bool l = true;
    while(l && n > 0)
    {
        int nd = n%10;
        n/=10;
        if(nd != 7 && nd != 4)
            l=false;
    }
    return l;
}
    int main(){
        int n; cin>>n;
        bool l = false;
        for(int i=4;i<=n && !l;i++)
            if(isLucky(i) && n%i==0)
                l=true;
        if(l)
            cout<<"YES";
        else
            cout<<"NO";

        cout<<endl;
            
                
}
