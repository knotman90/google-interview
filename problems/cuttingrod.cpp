#include<iostream>
#include<limits.h>
using namespace std;

#define MAX (100)
int solveCuttingRod(int N, int* price,int* memo) {
    if(N==0)
        return 0;
    if(memo[N-1]!= -1)
        return memo[N-1];

    int m = INT_MIN;
    for(int i=1; i<=N; i++)
        m = max(m,price[i-1]+solveCuttingRod(N-i,price,memo));

    memo[N-1]=m;
    return m;
}

int solveBottomUp(int N, int* prices){
    int best[N+1];
    best[0]=0;
    for(int i=1;i<=N;i++){
        int m=0;
        for(int j=1;j<=i;j++){
            m = max(m, prices[j-1]+best[i-j]);
        }
        best[i] = m;
    }
return best[N];
}

int main() {
    int prices[MAX];
    int memo[MAX];
    int T;
    cin>>T;
    while(T--) {
        for(int i=0; i<MAX; i++)
            memo[i]=-1;
        int N;
        cin>>N;
        int i=0;
        while(i<N)
            cin>>prices[i++];

        int s2 = solveCuttingRod(N,prices,memo);
        int s = solveBottomUp(N,prices);
        cout<<"solution is "<<s<<" "<<s2<<endl;
    }
    return 0;
}
