#include <iostream>
#include<limits.h>
using namespace std;

#define MAX (5001)

int graph[MAX][MAX];
int process[MAX];
int parent[MAX];
int wp[MAX];
int dp[MAX];
int rev[MAX];

void printArray(int* a, int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    int n,m,T;
    cin>>n>>m>>T;
    for(int i=0;i<n;i++){
        wp[i] = dp[i] = INT_MIN;
        parent[i] = -1;
        
        for(int j=0;j<n;j++){
            graph[i][j]=-1;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        a--;
        b--;
        graph[a][b] = c;
    }

    
    dp[0]=1;
    wp[0]=0;
    parent[0] = -1;
    int p=0;
    process[p++]= 0;
   int already[n] ={false}; 
    while(p>0){
       int i=process[--p];
       if(!already[i]){
       already[i]=true;
      // cout<<i<<endl;
       
        for(int j = 0; j < n ;j++ ){
            if(graph[i][j] != -1 && graph[i][j]+wp[i] <= T)
            {
                process[p++]=j;
                    if(dp[j] <= dp[i]){
                    dp[j] = dp[i]+1;
                    wp[j] = wp[i] + graph[i][j];
                    parent[j] = i;
                }
                
            }
        }
       
       }
      //  printArray(dp,n);
      // printArray(wp,n);
      // printArray(parent,n);
      // cout<<endl;
    }
    cout<<dp[n-1]<<endl;
    int f = n-1;
    int c=0;
    while(f !=-1){
        rev[c++]=f;
        f= parent[f];
    }
    for(int i=c-1;i>=0;i--)
        cout<<rev[i]+1<<" ";
    cout<<endl;



}
