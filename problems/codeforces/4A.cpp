#include <iostream>
 using namespace std;


 int main(){

     int W; cin>>W;
     bool b= (W>3) && !(W&1);
     if(b)
         cout<<"YES";
     else
         cout<<"NO";
     return 0;
 }
