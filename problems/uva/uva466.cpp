#include<iostream>
#include<stdio.h>
using namespace std;


#define SIZE 10

int printM(bool M[SIZE][SIZE], const int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
}

void perimeter( int n, pair<int,int>* perimeter, const int d,int& v_length) {
    v_length=0;
    int i,j;
    i=j=d;
    for(j = d; j < n-d ; j++)
        perimeter[v_length++] = make_pair(i,j);

    for(j-- ,i++; i < n-d ; i++)
        perimeter[v_length++] = make_pair(i,j);

    for( i-- ,j--; j>=d ; j--)
        perimeter[v_length++] = make_pair(i,j);

    for(j++,i--; i>d ; i--)
        perimeter[v_length++] = make_pair(i,j);
}

void rotate(bool M[SIZE][SIZE],  int n) {
    int vlength=0;
    pair<int,int> v[4*SIZE-4]; //SIZE OF THE PERIMITER
    for(int d=0; d < n/2 ; d++) {
        perimeter(n,v,d,vlength);
        int offset = n-1-2*d;
        int vals[4*SIZE-4];
        for(int i=0; i<vlength; i++)
            vals[i] = M[v[i].first][v[i].second];
        for(int i=0; i<vlength; i++)
            M[v[(i+offset)%vlength].first][v[(i+offset)%vlength].second] = vals[i];

    }

}

void h_reflect(bool M[SIZE][SIZE], int n) {
    for(int i=0; i<n/2; i++)
        for(int j=0; j<n; j++)
            swap(M[i][j], M[n-i-1][j]);
}

bool checkMatrix(bool M[SIZE][SIZE], bool M1[SIZE][SIZE], const int n) {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(M[i][j] != M1[i][j])
                return false;

    return true;
}

int main() {
    int n;
    int T=1;
    while(scanf("%d\n",&n)==1) {
        bool M[SIZE][SIZE], M1[SIZE][SIZE];
        for(int i=0; i<n; i++) {
            for(int j=0; j<2*n; j++) {
                char c;
                cin>>c;

                bool v = c=='X';
                if(j < n)
                    M[i][j] = v;
                else
                    M1[i][(j-n)] = v;

            }
        }
       /* if(T==6){
          rotate(M,n);
          printM(M,n);
          rotate(M,n);
          cout<<endl;
          printM(M,n);
          rotate(M,n);
          cout<<endl;
          printM(M,n);
          cout<<endl;
          h_reflect(M,n);

          printM(M,n);
              }**/
        bool done=false;
        bool reflected=false;
        if(checkMatrix(M,M1,n)) {
            cout<<"Pattern "<<T<<" was preserved."<<endl;
            done=true;
        }
 h_reflect(M,n);
      if(!done && checkMatrix(M,M1,n)){
        reflected=true;
      }
 h_reflect(M,n);
        int ref=0,rot=0;
        for(int i=0; !done && i<3; i++) {
            rotate(M,n);
            if(checkMatrix(M,M1,n)) {
                cout<<"Pattern "<<T<<" was rotated "<<(i+1)*90<<" degrees."<<endl;
                done=true;
                break;
            }
        }
        rotate(M,n);//original matrix;
      for(int i=0;!done && i< 3;i++){
        h_reflect(M,n);
        rotate(M,n);
         if(checkMatrix(M,M1,n)) {
                cout<<"Pattern "<<T<<" was reflected vertically and rotated "<<(i+1)*90<<" degrees."<<endl;
                done=true;
                break;
            }
            h_reflect(M,n);

        }


       if(!done && reflected)
         cout<<"Pattern "<<T<<" was reflected vertically."<<endl;

       else if(!done)
          cout<<"Pattern "<<T<<" was improperly transformed."<<endl;

        T++;
    }
    return 0;

}
