#include <iostream>

using namespace std;

int main() {

    char col='a';
    int row;
    cin>>col>>row;
    int c=0;
    int row1;
    char col1;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            if(!(i==0 && j==0)) {
                row1=row+i;
                col1=col+j;
                if(row1>=1 && row1<=8 && col1>='a' && col1<='h')
                    c++;


            }
        }
    }

    cout<<c<<endl;
}


