#include<common.h>
using namespace std;

int main(){
    using P=pair<int,int>;
    int N; cin>>N;

    LOOPUP(i,N){
        int C; cin>>C;
        int I; cin>>I;
        vector<int> items(I);
        vector<P> ip(I);
        DS::read(items,I);
        DS::for_each_i(ip,0,I,
            [&](auto& el, const int idx){el.first=items[idx]; el.second=idx;}
        );

        DS::quicksort(ip,0,I,DS::lt<P>);
        auto eq_fn = [](const P& p, const int v){ return p.first==v; };
        auto cmp_fn = [](const P& p, const int v){ return p.first<v; };
        LOOPUP(j,ip.size()){
            int val = (C-items[j]);
            int idx = DS::binary_search_idx(ip,0,ip.size(), val ,eq_fn,cmp_fn);
            //found. pickup the one with lowest INDEX
            if(idx!= -1){
                int retidx =idx;
                bool good=false;//check we do not pickup the same element twice
                while(eq_fn(ip[retidx],val) && j!= ip[retidx].second ){
                    retidx--;
                    good=true;
                }
                if(good){
                    int l = j+ 1;
                    int h = ip[retidx+1].second+1;
                    cout<<"Case #"<<i+1<<": "<<min(l,h)<<" "<<max(l,h)<<endl;
                    int sum = items[j] + items[ip[retidx+1].second];
                    assert(sum==C);
                    break;
                }
            }
        }
    }//foreach testcase
    return 0;
}
