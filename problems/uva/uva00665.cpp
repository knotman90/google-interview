#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main() {
    int T;
    cin>>T;

    while(T--) {
        int C,W;
        cin>>C>>W;
        vector<bool> coins(C,false);

        while(W--) {
            int P;
            cin>>P;
            vector<bool> read(C,false);
            for(int i=0; i<2*P; i++) {
                int r;
                cin>>r;
                read[r-1] = true;
            }
            char c;
            cin>>c;
            bool eq = c=='=';
            for(int i=0; i<read.size(); i++)
                if( (read[i] & eq) || (!read[i] && !eq))
                    coins[i]=true;
        }
        int fw = -1;
        for(int i=0; i<coins.size(); i++)
            if(coins[i] == false)
                if(fw==-1)
                    fw=i;
                else {
                    fw=-1;
                    break;
                }

        if(fw==-1)
            cout<<"0";
        else
            cout<<fw+1;
        cout<<endl;
        if(T)
            cout<<endl;
    }

    return 0;
}
