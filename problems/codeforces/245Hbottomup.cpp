#include <iostream>
#include<string>


using namespace std;

#define MAX (5001)
    int dp[MAX][MAX];
    bool pali[MAX][MAX];
int main(){
    string s; cin>>s;
    int q; cin>>q;
    
    
    int n=s.size();
    for(int i=0;i<n;i++){
        dp[i][i]=1;
        pali[i][i]=1;
        pali[i+1][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<= n-i; j++){
            int inc = pali[j+1][j+i-2] && s[j] == s[j+i-1];
            dp[j][j+i-1] = dp[j][j+i-2] + dp[j+1][j+i-1] - dp[j+1][j+i-2]+inc;
            pali[j][j+i-1]=inc ==1 ? true : false;
        }

    }
    
    while(q--){
        int s,e;
        cin>>s>>e;
        s--;e--;
        cout<<dp[s][e]<<endl;
    }
}
