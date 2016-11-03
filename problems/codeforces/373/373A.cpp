#include <iostream>
#include<cmath>
using namespace std;

int main() {
    int T;
    //cin>>T;
    //while(T--) {
        int r=-1;
        int n;
        cin>>n;
        int m;
        cin>>m;
        r= m==0 ? 1 : r;
        r= m==15 ? 0 : r;
        n--;
        while(n) {
            int m1;
            cin>>m1;
            r=m1>m ? 1 : 0;
            r = m1==15 ? 0:r;
            r= m1==0 ? 1 :r;
            m=m1;
            n--;
        }
        if(r==0)
            cout<<"DOWN";
        else if(r==1)
            cout<<"UP";
        else
            cout<<-1;
        cout<<endl;


    //}
}



