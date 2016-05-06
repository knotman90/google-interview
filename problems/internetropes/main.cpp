#include <bits/stdc++.h>
// incremental loops
#define loop0n(i, n) for (int i = 0; i < n; ++i)
#define loopse(i, s, e) for (int i = s; i < e; ++i)
#define loopsei(i, s, e, inc) for (int i = s; i < e; i += inc)
// decremental loops
#define dloop0n(i, n) for (int i = n; i >= 0; --i)
#define dloopse(i, s, e) for (int i = s; i >= e; --i)
#define dloopsei(i, s, e, inc) for (int i = s; i >= e; i -= inc)
#define GET_LOOP(_1, _2, _3, _4, NAME, ...) NAME
#define LOOPUP(...) \
  GET_LOOP(__VA_ARGS__, loopsei, loopse, loop0n) \
(__VA_ARGS__)
#define LOOPDWN(...) \
  GET_LOOP(__VA_ARGS__, dloopsei, dloopse, dloop0n) \
(__VA_ARGS__)

using namespace std;



int main(){
    int T; cin>>T;
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    LOOPUP(i,1,T+1){
        int S; cin>>S;
        vector<pair<int,int>> ropes;
        printf("Case #%d: ",i);
        LOOPUP(j ,S){
            pair<int,int> p;
            cin>>p.first>>p.second;
            ropes.push_back(p);
            //printf("\n%d %d \n",p.first,p.second);
        }
        int ans =0;
        LOOPUP(j,ropes.size()){
            LOOPUP(k,j+1,ropes.size()){
                if(((ropes[j].first > ropes[k].first) ^ (ropes[j].second > ropes[k].second) ))
                    ans++;
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}
