#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;


void printMat(int M[8][8] , const int size){
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      cout<<M[i][j]<< " ";
    }
    cout<<endl;
  }
}


int main() {

    int T;
    cin>>T;
    int M[8][8];
    int R[8];
    int C[8];
    while(T--) {
        int n;
        cin>>n;
        int i=0;
        while(i<n)
            scanf("%d ",&R[i++]);
        i=00;
        while(i<n)
            scanf("%d ",&C[i++]);

//    compute the building with maximum number of blocks
        int MAX=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) {
                M[i][j] = min(R[i],C[j]);
                MAX+= M[i][j];
            }
        cout<<"MAX IS:"<<endl;
        printMat(M,n);
//cout<<"MAX IS "<<MAX<<endl;
//compute the max for each rows and cols
        int mR[8];
        memset(mR,0,sizeof(int)*8);
        int mC[8];
        memset(mC,0,sizeof(int)*8);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) {
                if(M[i][j] > mR[i])
                    mR[i] = M[i][j];
                if(M[i][j] > mC[j])
                    mC[j] = M[i][j];
            }


        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(M[i][j] < mR[i])
                    M[i][j] = 0;
        cout<<"PRE MAX IS:"<<endl;
        printMat(M,n);


        for(int i=0; i<n; i++){
        bool met=false;
            for(int j=0; j<n; j++){
                if(M[j][i] < mC[i] || (M[j][i]==mC[i] && met) )
                    M[j][i] = 0;
                if(M[j][i] == mC[i])
                  met=true;
    }
        }

        memset(mR,0,sizeof(int)*8);
        memset(mC,0,sizeof(int)*8);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) {
                if(M[i][j] > mR[i])
                    mR[i] = M[i][j];
                if(M[i][j] > mC[j])
                    mC[j] = M[i][j];
            }
/*
for(int i=0;i<n;i++)
  if(mR[i] == 0 && )
    M[i][0] = R[i];

for(int i=0;i<n;i++)
  if(mC[i] == 0)
    M[0][i] = C[i];
*/

        cout<<"MAX IS:"<<endl;
        printMat(M,n);


                int MIN=0;
      for(int i=0; i<n; i++)
          for(int j=0; j<n; j++)
            MIN+=M[i][j];
cout<<"Matty needs at least "<<MIN<<" blocks, ad can add at most "<<MAX-MIN<<" extra blocks."<<endl
  ;

    }
    return 0;
}
