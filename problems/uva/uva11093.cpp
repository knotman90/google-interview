#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;


int main() {
    int T;
    cin>>T;
    int c=1;
    while(T--) {
        cout<<"Case "<<c++<<": ";
        int N;
        cin>>N;
        vector<int> ns(N);
        for(int a,i=0; i<N; i++) {
            scanf("%d ",&a);
            ns[i]=a;
        }
        int sum=0;
        for(int a, i=0; i<N; i++) {
            scanf("%d ",&a);
            ns[i]=ns[i]-a;
            sum+=ns[i];
        }
        if(sum<0) {
            cout<<"Not possible"<<endl;

        } else {


            for(int i=0; i<N ; i++) {
                sum=0;
                if(ns[i]>=0) {
                    for(int c=0, idx=i; c<N &&sum>=0; c++, idx=(idx+1)%N )
                        sum+=ns[idx];

                    if(sum>=0) {
                        cout<<"Possible from station " <<i+1<<endl;
                        break;
                    }
                }
            }

        }
    }

    return 0;
}
