#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(int r[9], int n) {
    for(int i=0; i<n-1; i++) {
        cout<<r[i]<<" ";

    }
    if(n>0)
        cout<<r[n-1];
    cout<<endl;
}
int main() {
    int T;
    cin>>T;
    string s;
    while(T--) {
        int r=1;
        getline(cin,s);

        int R[2][9];
        while(r++<=3) {
            getline(cin,s);
        }

        int n=0;
        while(n<7) {
            int a;
            cin>>a;
            R[0][n]=a;
            n+=2;
        }
        n=0;
        while(n<9) {
            int a;
            cin>>a;
            R[1][n]=a;
            n+=2;
        }
        //compute row 9
        vector<int> V;
        for(int i=0; i<9; i++) {
            if(i & 1)
                R[1][i] = (R[0][i-1]-R[1][i-1]-R[1][i+1])/2;
            V.push_back(R[1][i]);

        }
        int b=1;
        int b1=0;
        for(int r=8; r>0; r--) {
            for(int i=0; i<r; i++) {
                R[b1][i] = (R[b][i] + R[b][i+1]);
                V.push_back(R[b1][i]);
            }
            swap(b,b1);
        }
        reverse(V.begin(),V.end());
        int p=0;
        for(int i=1; i<=9; i++) {
            reverse(V.begin()+p,V.begin()+p+i);
            for(int j=0; j<i-1; j++) {
                cout<<V[p++]<<" ";
            }
            if(i>0)
                cout<<V[p++];
            cout<<endl;
        }
        V.clear();
    }
    return 0;

}
