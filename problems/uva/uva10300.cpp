#include<iostream>

using namespace std;



int main(){
int T; cin>>T;

while(T--){
  int n; cin>>n;
  long int sum=0;
  while(n--){
    int s,a,e;
    cin>>s>>a>>e;
    sum+=s*e;
  }
  cout<<sum<<endl;
}


}
