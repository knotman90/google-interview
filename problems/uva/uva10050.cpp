#include<iostream>
#include<vector>

using namespace std;


int main() {
    int T;
    cin>>T;
    while(T--) {
        int N;
        cin>>N;
        int P;
        cin>>P;
        vector<bool> hartal(N,false);
        while(P--) {
            int hi;
            cin>>hi;
            for(int c=hi-1; c<N; c+=hi)
                hartal[c] = true;

        }
        int c=0;
        for(int i=0; i<N; i++)
            if(hartal[i] && (i%7!=5 && i%7!=6))
                c++;

        cout<<c<<endl;


    }

    return 0;
}
