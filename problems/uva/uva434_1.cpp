#include<iostream>

#define SIZE 8

using namespace std;

int main(){
  int T; cin>>T;
  while(T--){
  int M[SIZE][SIZE];
  int n; cin>>n;
  int R[SIZE],C[SIZE];
  int i=0;
  while(i<n){
    int a; cin>>a;
    C[i++] = a;
  }
  i=0;
  while(i<n){
    int a; cin>>a;
    R[i++] = a;
  }
  int MAX=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      MAX+= min(R[i] ,C[j]);


int sR[SIZE],sC[SIZE];
for(int i=0;i<n;i++)
  sR[i] = sC[i] = -1;

int MIN=0;
for(int c=1;c<=2;c++)
  for(int i=0; i<n; i++)
    if(sR[i] ==-1)
    for(int j=0;j<n;j++){
      if(c==1){
        if(R[i] == C[j] && sR[i]==-1 && sC[j]==-1){
           MIN+=R[i];
          sR[i]=sC[j] = R[i];
          break;
         }
      }
      else
        if(C[j] >= R[i]){
          MIN+=R[i];
          sR[i] = R[i];

          break;
        }
    }

  for(int j=0; j<n; j++)
    if(sC[j] ==-1)
    for(int i=0;i<n;i++){
        if(R[i] >= C[j]){
          MIN+=C[j];
          sC[j] = C[j];
          break;
        }
    }

cout<<"Matty needs at least "<<MIN<<" blocks, and can add at most "<<MAX-MIN<<" extra blocks."<<endl
    ;


  }
  return 0;
}

