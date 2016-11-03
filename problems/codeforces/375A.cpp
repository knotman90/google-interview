#include <iostream>
#include<algorithm>
using namespace std;

int main(){

    int N[3];
   cin>>N[0]>>N[1]>>N[2];
   sort(N,N+3);
   int res = N[1]-N[0] + N[2]-N[1];
   cout<<res<<endl;
    return 0;
}
