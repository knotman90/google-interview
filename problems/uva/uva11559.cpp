#include<iostream>
#include<stdio.h>
#include<limits.h>

using namespace std;


int main(){

int N,B,H,W;
while(scanf("%d %d %d %d\n",&N,&B,&H,&W) == 4){
  int min = INT_MAX;
  bool go=false;
  while(H--){
    int C; cin>>C;
    int w = W;
    while(w--){
      int cw; cin>>cw;
      if(N*C <= B && cw >= N && N*C < min){
        min = N*C;
        go=true;
      }

     }


  }
  if(go)
    cout<<min;
  else
    cout<<"stay home";

cout<<endl;

}

  return 0;
}
