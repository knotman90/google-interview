#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;


int main(){
int n,m; cin>>n>>m;
vector<int> ng;
vector<int> g;
vector<int>pl;
unordered_map<int,int> bs;
typedef pair<int,int> pii;
unordered_map<int,pii> mods;
for(int i=0;i<m;i++)
    g.push_back(i+1);

    for(int i=0;i<n;i++)
{
    int b; cin>>b;
    pl.push_back(b);
    bs[b]++;
    if(b > m)
        ng.push_back(b);
}
bool mod=true;
int minold=-1;
int mincur;
int nm=0;
while(mod){
    int minim=g[0];
    int maxim=g[0];
    minold=bs[g[0]];
    for(int i=1;i<g.size();i++){
        if(bs[g[i]] < bs[minim] ){
            minim=g[i];
            minold=bs[i];
        }
        if(bs[g[i]]>bs[maxim])
            maxim=g[i];
    }
//provo con uno non buono
    if(ng.size()>0){
        mods[ng.back()]= make_pair(minim,mods[minim].second+1);
        nm++;
        bs[minim]++;
        bs[ng.back()]--;
        ng.pop_back();
        
    }else{
        //find an element in the goods which counter is greater then minimum
        if(bs[maxim]> bs[minim]){
            mods[maxim]=make_pair(minim,mods[minim].second+1);
            nm++;
            bs[minim]++;
            bs[maxim]--;
        }
    }
    minim=g[0];
    maxim=g[0];
     mincur=bs[g[0]];
    for(int i=1;i<g.size();i++){
        if(bs[g[i]] < bs[minim] ){
            minim=g[i];
            mincur=bs[i];
        }
        if(bs[g[i]]>bs[maxim])
            maxim=g[i];
    }
    if(minold >= mincur)
        break;


}


cout<<mincur<<" "<<nm<<endl;
for(int i=0;i<pl.size();i++){
    if(mods[pl[i]].second)
    {
        
        mods[pl[i]].second--;
        pl[i] = mods[pl[i]].first;
    }
    cout<<pl[i]<<" ";
}


    return 0;
}
