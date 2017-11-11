#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;


typedef pair<int,int> pii;
int main(){

 int N; scanf("%d\n",&N);
 while(N){
   int smd=25;
  vector<pii> displacements;
   while(N--){

    int s,e; s=e=0;
    string l; getline(cin,l);
    for(; l[s]=='X' && s < 25; )
      s++;
    e=s;
    for(; l[e]==' ' && e < 25;)
      e++;

  displacements.push_back(make_pair(s,e));
  smd = min(smd,e-s);
//  cout<<s<<" "<<e<<" "<<(e-s)<<endl;

   }
   int v =0;
   for(auto a: displacements)
     v+=(a.second-a.first)-smd;

   cout<<v<<endl;

   scanf("%d\n",&N);
 }


  return 0;
}
