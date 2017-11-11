#include<iostream>
#include<map>
#include<stdio.h>
#include<vector>
using namespace std;


int main(){

 int T;
 bool f=false;
while(scanf("%d\n",&T) == 1){
  if(f)
    cout<<endl;
  map<string,int> net;
  vector<string> names;

  string s;
  for(int i=0;i<T;i++)
  {
    cin>>s;
    net.insert(pair<string,int>(s,0));
    names.push_back(s);
  }
  for(int i=0;i<T;i++){
    int amount; int number;
    cin>>s>>amount>>number;
    if(number > 0 ){
    const int part = amount/number;
    net[s] -= (amount - (amount- part*number));

    for(int j = 0 ; j < number ; j++){
        cin>>s;
        net[s] = net[s]+part;
    }

  }
  }
    for(int i=0;i<names.size();i++)
    cout<<names[i]<<" "<<net[names[i]]<<endl;
f=true;
}
return 0;

}

