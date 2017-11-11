#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;


int main(){
  int T; cin>>T;


  while(T--){
    int  n; cin>>n;
    int p=0;
    vector<int> moves;
    while(n--){
      string c; cin>>c;
      int inc  ;
      if(c=="LEFT")
        inc=-1;
      else if(c=="RIGHT"){
          inc=1;
      }
      else{
        cin>>c>>c;
        int pos = atoi(c.c_str()) -1;
        inc = moves[pos];
      }
      moves.push_back(inc);
      p+=inc;


    }

    cout<<p<<endl;

  }

  return 0;
}
